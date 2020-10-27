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

// función que genera el grid, con el color correspondiente, a partir de
// la lista de peatones y el tamaño del universo deseado
std::vector<std::vector<std::string>> func_colored_grid(
                                        int W,
                                        std::vector<pedestrian> lista_peatones){


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
  
  return tesellation;
}


// barrido sobre toda la lista de peatones y creación de una nueva lista
std::vector<pedestrian> func_new_list_pedestrian(
                          int W,
                          std::vector<pedestrian> lista_peatones;
                          std::string geometry,
                          std::vector<std::vector<std::string>> tesellation){

  // inicialización de una nueva lista de peatones
  std::vector<pedestrian> new_list_pedestrian;

  // barrido sobre todos los elementos de la lista de peatones usando un iterador
  for (std::vector<pedestrian>::iterator it = lista_peatones.begin(); it != lista_peatones.end(); it++){

    // resultado queda guardado en new_list_pedestrian
    // función en evolutionRules.h
    inner_functions_4each_pedestrian(
          W,
          *it,
          geometry,
          new_list_pedestrian,
          tesellation);
  }

  //devolvemos la nueva lista actualizada
  return new_list_pedestrian;
}
