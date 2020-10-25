std::string evolution2right(pedestrian peaton, neighborhood vec_peaton, float vel){

  // posición del peaton
  int x = peaton.position.first;
  int y = peaton.position.second;

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
    double aleatorio;
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
    double aleatorio;
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
    double aleatorio;
    if (aleatorio <= p_w13) return "wait";
    else return "right";
  }
  // e)
  if (vec_peaton.xP1.type == "peaton" &&
      vec_peaton.xP1.direction != peaton.direction &&
      vec_peaton.yM1.type == "libre" &&
      vec_peaton.yP1.type == "libre"){
    // aplicar un random para deterimnar cuál es el que se obtiene
    double aleatorio;
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
    double aleatorio;
    if (aleatorio <= p_w22) return "wait";
    else return "right";
  }
  // g)
  if (vec_peaton.xP1.type == "peaton" &&
      vec_peaton.xP1.direction != peaton.direction &&
      vec_peaton.yM1.type == "libre" &&
      vec_peaton.yP1.type != "libre"){
    // aplicar un random para deterimnar cuál es el que se obtiene
    double aleatorio;
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
  if (vec_peaton.xP1.type != "libre" &&
      ((vec_peaton.xP1.direction == peaton.direction &&
      vec_peaton.xP1.velocity < peaton.velocity )||
      vec_peaton.xP1.type == "obstaculo") &&
      vec_peaton.yM1.type == "libre" &&
      vec_peaton.yP1.type == "libre"){
    // aplicar un random para deterimnar cuál es el que se obtiene
    double aleatorio;
    if (aleatorio <= p_w31) return "wait";
    else if (aleatorio <= p_w31 + p_a31) return "left";
    else return "right";
  }

  // b)
  if (vec_peaton.xP1.type != "libre" &&
      ((vec_peaton.xP1.direction == peaton.direction &&
      vec_peaton.xP1.velocity < peaton.velocity )||
      vec_peaton.xP1.type == "obstaculo") &&
      vec_peaton.yM1.type != "libre" &&
      vec_peaton.yP1.type == "libre"){
    // aplicar un random para deterimnar cuál es el que se obtiene
    double aleatorio;
    if (aleatorio <= p_w32) return "wait";
    else return "right";
  }

  // c)
  if (vec_peaton.xP1.type != "libre" &&
      ((vec_peaton.xP1.direction == peaton.direction &&
      vec_peaton.xP1.velocity < peaton.velocity )||
      vec_peaton.xP1.type == "obstaculo") &&
      vec_peaton.yM1.type == "libre" &&
      vec_peaton.yP1.type != "libre"){
    // aplicar un random para deterimnar cuál es el que se obtiene
    double aleatorio;
    if (aleatorio <= p_w32) return "wait";
    else return "left";
  }



}