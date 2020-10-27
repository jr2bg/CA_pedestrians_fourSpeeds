// función de evolución para el peaton que va a la derecha
std::string evolution2right(neighborhood vec_peaton){

  // peatón
  cell peaton = vec_peaton.xy;

  // probabilidades de paso para cada celda dependiendo de la situación
  float p_a11 = 0.25;
  float p_b11 = 0.25;
  float p_w11 = 0.5;

  float p_b12 = 0.5;
  float p_w12 = 0.5;

  float p_a13 = 0.5;
  float p_w13 = 0.5;

  float p_a21 = 0.1;
  float p_b21 = 0.4;
  float p_w21 = 0.5;

  float p_b22 = 0.5;
  float p_w22 = 0.5;

  float p_a23 = 0.1;
  float p_w23 = 0.9;

  float p_w24 = 1.;

  float p_a31 = 0.4;
  float p_b31 = 0.1;
  float p_w31 = 0.5;

  float p_b32 = 0.1;
  float p_w32 = 0.9;

  float p_a33 = 0.9;
  float p_w33 = 0.1;


  //Fig 2
  // a)
  if (vec_peaton.xP1.type == "libre") return "next";

  // b)
  if (vec_peaton.xP1.type == "peaton" &&
      vec_peaton.xP1.direction == peaton.direction &&
      vec_peaton.xP1.velocity >= peaton.velocity &&
      vec_peaton.yM1.type == "libre" &&
      vec_peaton.yP1.type == "libre"){
    // aplicar un random para deterimnar cuál es el que se obtiene
    double aleatorio = uniform_dist_0_1(generator);
    if (aleatorio <= p_a11) return "left";
    else if (aleatorio <= p_a11 + p_w11) return "wait";
    else return "right";
  }

  // c)
  if (vec_peaton.xP1.type == "peaton" &&
      vec_peaton.xP1.direction == peaton.direction &&
      vec_peaton.xP1.velocity >= peaton.velocity &&
      vec_peaton.yM1.type != "libre" &&
      vec_peaton.yP1.type == "libre"){
    // aplicar un random para deterimnar cuál es el que se obtiene
    double aleatorio = uniform_dist_0_1(generator);
    if (aleatorio <= p_w12) return "wait";
    else return "right";
  }

  // d)
  if (vec_peaton.xP1.type == "peaton" &&
      vec_peaton.xP1.direction == peaton.direction &&
      vec_peaton.xP1.velocity >= peaton.velocity &&
      vec_peaton.yM1.type == "libre" &&
      vec_peaton.yP1.type != "libre"){
    // aplicar un random para deterimnar cuál es el que se obtiene
    double aleatorio = uniform_dist_0_1(generator);
    if (aleatorio <= p_w13) return "wait";
    else return "right";
  }

  // e)
  if (vec_peaton.xP1.type == "peaton" &&
      vec_peaton.xP1.direction != peaton.direction &&
      vec_peaton.yM1.type == "libre" &&
      vec_peaton.yP1.type == "libre"){
    // aplicar un random para deterimnar cuál es el que se obtiene
    double aleatorio = uniform_dist_0_1(generator);
    if (aleatorio <= p_w21) return "wait";
    else if (aleatorio <= p_w21 + p_a21) return "left";
    else return "right";
  }

  // f)
  if (vec_peaton.xP1.type == "peaton" &&
      vec_peaton.xP1.direction != peaton.direction &&
      vec_peaton.yM1.type != "libre" &&
      vec_peaton.yP1.type == "libre"){
    // aplicar un random para deterimnar cuál es el que se obtiene
    double aleatorio = uniform_dist_0_1(generator);
    if (aleatorio <= p_w22) return "wait";
    else return "right";
  }

  // g)
  if (vec_peaton.xP1.type == "peaton" &&
      vec_peaton.xP1.direction != peaton.direction &&
      vec_peaton.yM1.type == "libre" &&
      vec_peaton.yP1.type != "libre"){
    // aplicar un random para deterimnar cuál es el que se obtiene
    double aleatorio = uniform_dist_0_1(generator);
    if (aleatorio <= p_w23) return "wait";
    else return "left";
  }

  // h)
  if (vec_peaton.xP1.type != "libre" &&
      vec_peaton.yM1.type != "libre" &&
      vec_peaton.yP1.type != "libre"){
    // aplicar un random para deterimnar cuál es el que se obtiene
    return "wait";
  }


  //Fig 3
  // a)
  if (((vec_peaton.xP1.type == "peaton" &&
      vec_peaton.xP1.direction == peaton.direction &&
      vec_peaton.xP1.velocity < peaton.velocity )||
      vec_peaton.xP1.type == "obstaculo") &&
      vec_peaton.yM1.type == "libre" &&
      vec_peaton.yP1.type == "libre"){
    // aplicar un random para deterimnar cuál es el que se obtiene
    double aleatorio = uniform_dist_0_1(generator);
    if (aleatorio <= p_w31) return "wait";
    else if (aleatorio <= p_w31 + p_a31) return "left";
    else return "right";
  }

  // b)
  if (((vec_peaton.xP1.type == "peaton" &&
      vec_peaton.xP1.direction == peaton.direction &&
      vec_peaton.xP1.velocity < peaton.velocity )||
      vec_peaton.xP1.type == "obstaculo") &&
      vec_peaton.yM1.type != "libre" &&
      vec_peaton.yP1.type == "libre"){
    // aplicar un random para deterimnar cuál es el que se obtiene
    double aleatorio = uniform_dist_0_1(generator);
    if (aleatorio <= p_w32) return "wait";
    else return "right";
  }

  // c)
  if (((vec_peaton.xP1.type == "peaton" &&
      vec_peaton.xP1.direction == peaton.direction &&
      vec_peaton.xP1.velocity < peaton.velocity )||
      vec_peaton.xP1.type == "obstaculo") &&
      vec_peaton.yM1.type == "libre" &&
      vec_peaton.yP1.type != "libre"){
    // aplicar un random para deterimnar cuál es el que se obtiene
    double aleatorio = uniform_dist_0_1(generator);
    if (aleatorio <= p_w32) return "wait";
    else return "left";
  }
}


// cambio de dirección de la celda para que parezca que el peatón va
// hacia la derecha
std::string change_direction_cell(std::string direction_center,
                                  std::string direction_cell){

  return map_cells_rotation[direction_center][direction_cell];
}


// rotación de la vecindad para que parezca que va a la derecha
neighborhood vec2right(neighborhood vecindad){
  cell peaton = vecindad.xy;
  neighborhood rotated_neigh;

  if (peaton.direction == "E") return vecindad;
  else if (peaton.direction == "W") {
    rotated_neigh.xP1 = vecindad.xM1;
    rotated_neigh.xM1 = vecindad.xP1;
    rotated_neigh.yP1 = vecindad.yM1;
    rotated_neigh.yM1 = vecindad.yP1;
    rotated_neigh.xy  = vecindad.xy;
  }
  //else if (peaton.direction == "N")
  //else if (peaton.direction == "S")

  //------------ cambio de dirección de las celdas con peatón
  if (rotated_neigh.xP1.type == "peaton")
    rotated_neigh.xP1.direction = change_direction_cell(peaton.direction,
                                                  rotated_neigh.xP1.direction);

  if (rotated_neigh.xM1.type == "peaton")
    rotated_neigh.xM1.direction = change_direction_cell(peaton.direction,
                                                  rotated_neigh.xM1.direction);

  if (rotated_neigh.yP1.type == "peaton")
    rotated_neigh.yP1.direction = change_direction_cell(peaton.direction,
                                                  rotated_neigh.yP1.direction);

  if (rotated_neigh.yM1.type == "peaton")
    rotated_neigh.yM1.direction = change_direction_cell(peaton.direction,
                                                  rotated_neigh.yM1.direction);

  if (rotated_neigh.xy.type  == "peaton")
    rotated_neigh.xy.direction = change_direction_cell(peaton.direction,
                                                  rotated_neigh.xy.direction);

  return rotated_neigh;
}


// devolvemos el paso de ese peatón para el siguiente tiempo
// paso_SRP -> paso desde el sistema de referencia del peatón
std::pair<int,int> next_cell_grid(std::string paso_SRP,
                                  std::string direccion_original,
                                  std::pair<int,int> posicion_original){
  // para conocer el paso que dará el peatón desde un punto de vista euleriano
  // debemos conocer la dirección original del peaton && el paso que dió
  std::pair<int,int> paso_a_dar = map_directs[direccion_original][paso_SRP];

  return {posicion_original.first  + paso_a_dar.first,
          posicion_original.second + paso_a_dar.second};

}

// función que devuelve el paso a dar desde el sistema de referencia del peaton
// => vecindad
// <= string con el movimiento a dar
std::pair<int,int> movement_any_direction(neighborhood vec_peaton,
                                          std::pair<int,int> posicion_original){
  // cambio de la vecindad hacia "E"
  neighborhood vec_peaton_E = vec2right(vec_peaton);

  // aplicar la función de evolución de "E"
  std::string resultSRP = evolution2right(vec_peaton_E);

  // hacer el cambio de la dirección de right a la original
  std::pair<int,int> result = next_cell_grid(resultSRP,
                                            vec_peaton.xy.direction,
                                            posicion_original);
  return result;
}
