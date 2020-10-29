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

  string geometry = argv[1];
  float rho_0 = stof(argv[2]);
  int W = stoi(argv[3]);
  int n_pasos_tiempo = stoi(argv[4]);
  //cout << geometry <<initial_density<< W << n_peatones << "\n";

  vector<vector<string>> test1_tesellation ({{"black","black","black"},
                                          {"blue","white","green"},
                                          {"white","white","pink"},
                                          {"white","red","white"},
                                          {"black","black","black"}
                                        });

  vector<vector<string>> test2_tesellation ({{"black","black","black"},
                                          {"white","white","blue"},
                                          {"white","red","white"},
                                          {"green","white","white"},
                                          {"black","black","black"}
                                        });

  initscr();
  for (int i = 0; i < 100; i++){
    print_grid(test1_tesellation);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    print_grid(test2_tesellation);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
  endwin();


  //cout << map_directs["E"]["left"].first << "\t" << map_directs["E"]["left"].second<< "\n";
  // neighborhood test_n;
  // cell h_xy ("pink"), h_xM1("green"),h_xP1("blue"),h_yM1("blue"),h_yP1("blue");
  //
  // test_n.xy  = h_xy;
  // test_n.xP1 = h_xP1;
  // test_n.xM1 = h_xM1;
  // test_n.yP1 = h_yP1;
  // test_n.yM1 = h_yM1;
  //
  //
  // std::pair<int,int> result = movement_any_direction(test_n, {0,0});


  //cout << "x:  "<< result.first << "\ty:  " << result.second << "\n";
  // vecindad a usar para las funciones de evolución
  //test_n = vec2right(test_n);
  //cout << test_n.xy.direction << "\t"  << test_n.xP1.direction << "\n";

  // for(int i = 0; i < 10000; i++){
  //   string result =evolution2right(test_n);
  //   cout << result;
  //   assert(result == "next");
  //   //assert(result == "wait" || result == "left" || result == "right");
  // }



  // inicializador Grid
  //vector<vector<string>> actual_grid = grid_starter(10);
  //cout << actual_grid[11][0] << "\n";

  // testear generador de listas de pedestrians
  //int W = 2; // número de "casillas disponibles" para transitar

  //int n_peatones = 2;
  //vector<string> lista_colores ({"green", "blue"});
  //vector<pair<int,int>> lista_posiciones ({{1,2},{3,5}});
  // vector<pedestrian> lista_peatones = generator_list_pedestrians(
  //                                       n_peatones,
  //                                       lista_colores,
  //                                       lista_posiciones);
  //
  // cout << lista_peatones[0].color << lista_peatones[0].position.first << lista_peatones[0].position.second << "\n";
  // cout << lista_peatones[1].color << lista_peatones[1].position.first << lista_peatones[1].position.second << "\n";

  // pair<int,int> one_position ({1,1});
  // cout << is_valid_position_open(W,one_position) << '\n';
  // position_band(W,one_position);
  // cout << one_position.first << '\n';
  return 0;
}

vector<vector<string>> test_tesellation {{"black","black","black"},
                                        {"blue","white","green"},
                                        {"white","white","pink"},
                                        {"white","red","white"},
                                        {"black","black","black"}
                                      };
