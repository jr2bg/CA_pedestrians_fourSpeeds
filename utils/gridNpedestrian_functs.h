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
