/**********************************************************************
g++ -pipe -O2 -std=c++14 unifier.cpp -lm -lncurses
***********************************************************************/

#include <utility>
#include <string>
#include <iostream>
#include <experimental/random> // random int
#include <algorithm>    // std::swap
#include <random>
#include <chrono>
#include <unordered_map>
#include <curses.h> // dibujar el grid en consola
#include <thread>  // sleep
#include <assert.h> /////////// DEBUG


#include "utils/randomness.h"
#include "utils/global_vars.h"
#include "utils/structures.h"
#include "utils/test_lists.h"
#include "utils/evolutionRules.h"
#include "utils/gridNpedestrian_functs.h"
#include "utils/geometry_dependant_functions.h"  // selecciona los pasos a dar dependiendo de la geometría


using namespace std;

int main(int arg, char **argv){

  // lectura de la info pasada como argumentos al programa
  string geometry = argv[1];
  float rho_0 = stof(argv[2]);
  int W = stoi(argv[3]);
  int n_pasos_tiempo = stoi(argv[4]);



  // aplicar las reglas para todos los elementos:
  vector<pedestrian> lista_inicial = two_in_front(W, rho_0);

  vector<vector<string>> tesellation = func_colored_grid(W, lista_inicial);

  neighborhood vec_p0 = neighborhood_selection( W, geometry, lista_inicial[0],   tesellation);
  neighborhood vec_p1 = neighborhood_selection( W, geometry, lista_inicial[1],   tesellation);

  cout << "posiciones dadas:\t" << lista_inicial[0].position.first << "\t" << lista_inicial[1].position.first <<"\n";
  cout << "posiciones tesel:\t" << lista_inicial[0].position.first << "\t" << lista_inicial[1].position.first <<"\n";
  //cout << tesellation[lista_inicial[0]]
  cout << "vecindad peaton1\n";
  imprimir_vecindad(vec_p0);

  cout << "vecindad peaton2\n";
  imprimir_vecindad(vec_p1);

  return 0;
}
