// teselación donde cada elemento es un string, que corresponde al elemento
// que está en ese lugar: peaton, con sus características, o libre o obstaculo
// lo anterior está dado por el color
std::vector<std::vector<std::string>> grid_starter(int W){
  std::vector<std::vector<std::string>> cells;
  // hay un total de W+2 filas
  cells.resize(W+2, std::vector<std::string> (W, "white"));

  // determinar si en las fronteras hay paredes; consideraremos que sí, 1ra y última
  for (int i = 0; i < W; i++){
    cells[0][i]   = "black";
    cells[W+1][i] = "black";
  }
  return cells;
}


// generador de una lista de transeuntes
// a dar el número de peatones, lista con el tipo de peatón y lista con la posición
std::vector<pedestrian> generator_list_pedestrians(
                          int n,
                          std::vector<std::string> lista_colores,
                          std::vector<std::pair<int,int>> lista_posiciones){
  std::vector<pedestrian> result (n);

  // pedestrians con los valores de color y posición adecuados
  for(int i = 0; i < n; i++){

    result[i].color = lista_colores[i];
    result[i].position = lista_posiciones[i];
  }

  return result;
}

//función para agregar información de los obstáculos al grid
std::vector<std::vector<std::string>> func_obstacles_grid(
                                        std::vector<std::pair<int,int>> lista_obstaculos,
                                        std::vector<std::vector<std::string>> tesellation
                                      ){
  // barremos sobre la lista de obstaculos para anexarlos
  for (std::vector<pair<int,int>>::iterator it = lista_obstaculos.begin(); it != lista_obstaculos.end(); it++){

    // posición
    int x = (*it).position.first;
    int y = (*it).position.second;

    // cambio de color
    tesellation[y+1][x] = "black";
  }

  return tesellation;
}


// función que genera el grid, con el color correspondiente, a partir de
// la lista de peatones y el tamaño del universo deseado
std::vector<std::vector<std::string>> func_colored_grid(
                                        int W,
                                        std::vector<pedestrian> lista_peatones,
                                        std::vector<std::pair<int,int>> lista_obstaculos
                                      ){


  // inicializamos un grid
  std::vector<std::vector<std::string>> tesellation = grid_starter(W);

  // barremos sobre la lista de peatones para conocer los colores
  for (std::vector<pedestrian>::iterator it = lista_peatones.begin(); it != lista_peatones.end(); it++){

    // posición
    int x = (*it).position.first;
    int y = (*it).position.second;

    // cambio de color
    tesellation[y][x] = (*it).color;
  }
  tesellation = func_obstacles_grid( W, lista_obstaculos, tesellation);

  return tesellation;
}


// barrido sobre toda la lista de peatones y creación de una nueva lista
std::vector<pedestrian> func_new_list_pedestrian(
                          int W,
                          int tiempo,
                          std::vector<pedestrian> lista_peatones,
                          std::string geometry,
                          std::vector<std::vector<std::string>> &tesellation){

  // inicialización de una nueva lista de peatones
  std::vector<pedestrian> new_list_pedestrian;

  // barrido sobre todos los elementos de la lista de peatones usando un iterador
  for (std::vector<pedestrian>::iterator it = lista_peatones.begin(); it != lista_peatones.end(); it++){

    pedestrian peatoncito = *it;

    // debemos corroborar si el peatón puede caminar en ese tiempo
        // peaton a 1.5
    if ((( peatoncito.color == "blue"  || peatoncito.color == "red") && tiempo % 2 == 0) ||
        // peaton a 1
        (( peatoncito.color == "green"  || peatoncito.color == "pink") && tiempo % 3 == 0)){
      // resultado queda guardado en new_list_pedestrian
      // función en evolutionRules.h
      inner_functions_4each_pedestrian(
            W,
            *it,
            geometry,
            new_list_pedestrian,
            tesellation);
    }
    // si a ese tiempo el peatón no caminó,
    // entonces solo debemos agregar el peatoncito a nuestra lista de peatones
    else {
      new_list_pedestrian.push_back(peatoncito);
    }

  }

  //devolvemos la nueva lista actualizada
  return new_list_pedestrian;
}

// función que imprime el grid en terminal
void print_grid(std::vector<std::vector<std::string>> tesellation){
  std::string to_print;

  //char enter2continue [10];
  // creación del string a imprimir. Barre la teselación y va anexando elementos
  for(auto row:tesellation){
    for (auto cll: row){
      to_print += map_string2charsConsole[cll];
    }
    to_print += "\n";
  }
  char *chars2print = &to_print[0];

  clear();
  addstr(chars2print);

  refresh();
  //getnstr( enter2continue, sizeof( enter2continue ) - 1 );
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

// función para obtener las celdas ocupadas a la izquierda o derecha, dependiendo
// de la variable extremo
std::vector<int> get_obst_xtrm(
                   int W,
                   std::string extremo,
                   std::vector<std::vector<std::string>> tesellation){

  std::vector<int> occupied (W);
  int ps = 0;
  int extremo_int;
  if (extremo == "left") extremo_int = 0;
  else if (extremo == "right") extremo_int = W-1;

  // barrido sobre todos los elementos de la izquierda de teselation
  // para encontrar elementos que no sean vacíos
  for (int i = 1; i < W +1; i++){
    if (tesellation[i][extremo_int] != "white") {
      occupied[ps] = i;
      ps++;
    }
  }

  // redefinimos el tamaño del vector
  occupied.resize(ps);

  // lo ordenamos
  std::sort(occupied.begin(), occupied.end());

  return occupied;
}

// función de inicialización de peatones para una frontera periódica
// la teselación nos dirá si hay algún obstáculo en el punto elegido
std::vector<pedestrian> func_init_list_pedestrians_periodic(
                          int W,
                          float rho_0,
                          std::vector<std::vector<std::string>> tesellation){

  int surface = W * W;
  // numero de peatones de cada tipo
  int n_blue  = rho_0 * map_initial_densities["blue"]  * surface;
  int n_green = rho_0 * map_initial_densities["green"] * surface;
  int n_red   = rho_0 * map_initial_densities["red"]   * surface;
  int n_pink  = rho_0 * map_initial_densities["pink"]  * surface;

  // vector de tamaño W*W y le aplicamos el shuffle
  std::vector<std::pair<int,int>> to_shuffle_grid (surface) ;

  for (int i = 0; i < W; i++){
    for (int j = 0; j < W; j++){
      to_shuffle_grid[i*W + j] = {i,j+1};
    }
  }
  // shuffle
  Fisher_Yates_shuffle_pairs(to_shuffle_grid);

  std::vector<pedestrian> init_pedestrians;

  // cada for consta de la inicialización del peatón + su anexión al vector

  for (int i = 0; i < n_blue; i++){
    pedestrian peaton_agregar ("blue", to_shuffle_grid[i]);
    init_pedestrians.push_back(peaton_agregar);
  }

  for (int i = 0; i < n_green; i++){
    pedestrian peaton_agregar ("green", to_shuffle_grid[n_blue + i]);
    init_pedestrians.push_back(peaton_agregar);
  }

  for (int i = 0; i < n_red; i++){
    pedestrian peaton_agregar ("red", to_shuffle_grid[n_blue + n_green + i]);
    init_pedestrians.push_back(peaton_agregar);
  }

  for (int i = 0; i < n_pink; i++){
    pedestrian peaton_agregar ("pink", to_shuffle_grid[n_blue + n_green + n_red +i]);
    init_pedestrians.push_back(peaton_agregar);
  }

  return init_pedestrians;

}

// cada 6 pasos de tiempo debe haber otros peatones ingresando al grid
// se usará esta función para determinarlos así como su ubicación
std::vector<pedestrian> func_init_list_pedestrians_open(
                          int W,
                          float rho_0,
                          std::vector<std::vector<std::string>> tesellation){
  // aquí basta hacer un random del tamaño de W para conocer cuál es
  int n_blue  = rho_0 * map_initial_densities["blue"]  * W;
  int n_green = rho_0 * map_initial_densities["green"] * W;
  int n_red   = rho_0 * map_initial_densities["red"]   * W;
  int n_pink  = rho_0 * map_initial_densities["pink"]  * W;

  // casillas en los bordes izquierdo y derecho que no están ocupadas
  std::vector<int> borde_izq (W);
  std::vector<int> borde_der (W);

  // casillas izquierdas ocupadas
  std::vector<int> occup_left = get_obst_xtrm( W, "left", tesellation);
  // casillas derechas ocupadas
  std::vector<int> occup_right = get_obst_xtrm( W, "right", tesellation);

  // contadores para left o right
  int  l = 0,   r = 0;
  int bl = 0,  br = 0;
  // inicialización de la lista
  for (int i = 0; i < W; i++){
    // si está ocupado en la posición i, entonces al l le sumamos 1
    // el vector debe tener valores
    // borde izquierdo
    if (occup_left.size > l && occup_left[l] == i + 1){ // i + 1 por considerar las paredes
      l++;
    }
    else {
      borde_izq[bl] = i + 1;
      bl++;
    }
    // borde derecho
    if (occup_right.size > r && occup_right[r] == i + 1){ // i + 1 por considerar las paredes
      r++;
    }
    else {
      borde_der[br] = i + 1;
      br++;
    }
  }

  // resize de ambos vectores
  borde_izq.resize(bl);
  borde_der.resize(br);

  // shuffle
  Fisher_Yates_shuffle_ints(borde_izq);
  Fisher_Yates_shuffle_ints(borde_der);

  // inicialización del vector con los peatones a añadir
  std::vector<pedestrian> to_add_peds_open;

  //cálculo del número de peatones por color
  
  for (int i = 0; i < n_blue; i++){
    pedestrian peaton_agregar ("blue", {0, borde_izq[i]});
    to_add_peds_open.push_back(peaton_agregar);
  }

  for (int i = 0; i < n_green; i++){
    pedestrian peaton_agregar ("green", {0, borde_izq[i + n_blue]});
    to_add_peds_open.push_back(peaton_agregar);
  }

  for (int i = 0; i < n_red; i++){
    pedestrian peaton_agregar ("red", {W-1, borde_der[i]});
    to_add_peds_open.push_back(peaton_agregar);
  }

  for (int i = 0; i < n_pink; i++){
    pedestrian peaton_agregar ("pink", {W-1, borde_der[i + n_red]});
    to_add_peds_open.push_back(peaton_agregar);
  }

  return to_add_peds_open;

}
