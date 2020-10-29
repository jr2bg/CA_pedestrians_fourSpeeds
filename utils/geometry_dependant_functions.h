/*********************************************************************
***
*** Funciones que dependen de la geometría {open, periodic}
***
**********************************************************************/

// geometría periodic



// geometría open
// N -> número de ciclos
void open_geometry(int W, int N, float rho_0){

  // inicializamos lista de transeuntes
  std::vector<pedestrian> lista_peatones, peatones_anexar;

  // inicializar teselación
  std::vector<std::vector<std::string>> tesellation = grid_starter(W);

  // ciclo sobre el número de iteraciones
  for (int k = 0; k < N ; k++){
    // barrer sobre todos los peatones
    lista_peatones = func_new_list_pedestrian(
                              W,
                              k,
                              lista_peatones,
                              "open",
                              tesellation)

    // se anexan peatones cada 6 pasos de tiempo
    if (k % 6 == 0){
      peatones_anexar = func_init_list_pedestrians_open( W, rho_0);
      lista_peatones.insert(lista_peatones.end(),
                            peatones_anexar.begin(),
                            peatones_anexar.end());
    }

    // pasar la info de los peatones al grid
    // func_colored_grid crea un grid en blanco y trabaja sobre él
    tesellation = func_colored_grid(  W,  lista_peatones);

    // imprimir en pantalla
    print_grid(tesellation);

  }

}

// geometría periodic
// N -> número de ciclos
void periodic_geometry(int W, int N, float rho_0){

  // inicializamos lista de transeuntes
  std::vector<pedestrian> lista_peatones,  peatones_anexar;

  // inicializar teselación
  std::vector<std::vector<std::string>> tesellation = grid_starter(W);

  // ciclo sobre el número de iteraciones
  for (int k = 0; k < N ; k++){
    // barrer sobre todos los peatones
    lista_peatones = func_new_list_pedestrian(
                              W,
                              k,
                              lista_peatones,
                              "periodic",
                              tesellation)

    // se anexan peatones al inicio
    if (k == 0){
      peatones_anexar = func_init_list_pedestrians_periodic( W, rho_0);
      lista_peatones.insert(lista_peatones.end(),
                            peatones_anexar.begin(),
                            peatones_anexar.end());
    }

    // pasar la info de los peatones al grid
    // func_colored_grid crea un grid en blanco y trabaja sobre él
    tesellation = func_colored_grid(  W,  lista_peatones);

    // imprimir en pantalla
    print_grid(tesellation);

  }


}
