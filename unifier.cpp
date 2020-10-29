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

  // inicialización del screen
  initscr();

  // selección de la función de barrido de tiempo a usar
  if (geometry == "open"){
    open_geometry(W, n_pasos_tiempo, rho_0);
  }

  else if (geometry == "periodic"){
    periodic_geometry(W, n_pasos_tiempo, rho_0);
  }

  // cerrado del screen
  endwin();

  return 0;
}
