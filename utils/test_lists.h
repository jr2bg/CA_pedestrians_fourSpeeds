// init list pedestrians open open test
std::vector<pedestrian> func_ilpo_test(int W, float rho_0){
  int half = W/2;
  std::vector<pedestrian> result;
  pedestrian peaton_agregar;

  for (int i = 0; i < 3; i++){
    peaton_agregar = pedestrian  ("blue", {0, half + i+1});
    result.push_back(peaton_agregar);

    peaton_agregar = pedestrian ("red", {W-1, half + i});
    result.push_back(peaton_agregar);

  }
  return result;
}

std::vector<pedestrian> two_in_front(int W, float rho_0){
  int half = W/2;
  std::vector<pedestrian> result;
  pedestrian peaton_agregar;

  peaton_agregar = pedestrian  ("blue", {half, half});
  result.push_back(peaton_agregar);

  peaton_agregar = pedestrian ("red", {half+1, half });
  result.push_back(peaton_agregar);

  return result;
}

void imprimir_vecindad(neighborhood vecindad){
  std::cout << "*****\n";
  std::cout << "* "<< map_string2charsConsole[vecindad.yM1.color] << " *\n";
  std::cout << "*"
            << map_string2charsConsole[vecindad.xM1.color]
            << map_string2charsConsole[vecindad.xy.color]
            << map_string2charsConsole[vecindad.xP1.color]
            << "*\n";
  std::cout << "* " << map_string2charsConsole[vecindad.yP1.color] << " *\n";
  std::cout << "*****\n\n";
}
