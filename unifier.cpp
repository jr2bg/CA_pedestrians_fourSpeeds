#include <utility>
#include <string>
#include <iostream>
#include <random>
#include <unordered_map>

#include "utils/global_vars.h"
#include "utils/structures.h"
#include "utils/evolutionRules.h"


using namespace std;

int main(){
  //cout << map_directs["E"]["left"].first << "\t" << map_directs["E"]["left"].second<< "\n";
  neighborhood test_n;
  cell helper1 ("red"), helper2("blue");
  test_n.xM1 = helper2;
  test_n.xy  = helper1;


  // vecindad a usar para las funciones de evolución
  test_n = vec2right(test_n);
  cout << test_n.xy.direction << "\t"  << test_n.xP1.direction << "\n";

  cout << test_n.xy.velocity;


}
