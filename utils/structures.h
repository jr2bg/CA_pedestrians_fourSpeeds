struct pedestrian {
  std::pair<int,int> position;
  float velocity;
  std::string direction;

};

struct cell {
  std::string direction;
  float velocity;
  std::string type;
};

struct neighborhood {
  cell xM1;
  cell xP1;
  cell yM1;
  cell yP1;
  cell xy;
};