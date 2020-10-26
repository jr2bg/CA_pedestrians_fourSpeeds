// struct pedestrian {
//   std::pair<int,int> position;
//   float velocity;
//   std::string direction;
//
// };

struct cell {
  std::string direction; // direction \in {"E", "O", "N", "S"}
  float velocity;
  std::string type; // type \in {"libre", "peaton", "obstaculo"}
  std::string color;

  // constructor de la celda
  cell(std::string clr = "white"){
    direction = map_infoFromColor[clr]["direction"];
    type = map_infoFromColor[clr]["type"];
    color = clr;
    // volvemos float al string
    velocity = std::stof(map_infoFromColor[clr]["velocity"]);
  }
};

struct neighborhood {
  cell xM1;
  cell xP1;
  cell yM1;
  cell yP1;
  cell xy;
};
