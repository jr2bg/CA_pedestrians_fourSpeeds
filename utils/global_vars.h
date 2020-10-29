std::unordered_map<std::string, std::unordered_map <std::string, std::pair<int,int>>>  map_directs ({
  {"E", {{"left"  , {0,-1}},
         {"right" , {0, 1}},
         {"wait",   {0, 0}},
         {"next",   {1, 0}}}
  },
  {"W", {{"left"  , {0, 1}},
         {"right" , {0,-1}},
         {"wait",   {0, 0}},
         {"next",   {-1, 0}}}
  },
  {"N", {{"left"  , {-1,0}},
         {"right" , {1, 0}},
         {"wait",   {0, 0}},
         {"next",   {0,-1}}}
  },
  {"S", {{"left"  , {1, 0}},
         {"right" , {-1,0}},
         {"wait",   {0, 0}},
         {"next",   {0, 1}}}
  }
});

std::unordered_map<std::string, std::unordered_map<std::string,std::string>> map_cells_rotation({
  // peatón central va al oeste
  {"W", {{"E","W"},
         {"W","E"}}}
});

// map de los colores a valores de la celda
std::unordered_map<std::string, std::unordered_map<std::string,std::string>> map_infoFromColor({
  {"white",{{"direction", "X"},
            {"velocity", "0"},
            {"type", "libre"}}},

  {"black",{{"direction", "X"},
            {"velocity", "0"},
            {"type", "obstaculo"}}},

  {"blue",{{"direction", "E"},
            {"velocity", "1.5"},
            {"type", "peaton"}}},

  {"green",{{"direction", "E"},
            {"velocity", "1"},
            {"type", "peaton"}}},

  {"red",{{"direction", "W"},
            {"velocity", "1.5"},
            {"type", "peaton"}}},

  {"pink",{{"direction", "W"},
            {"velocity", "1"},
            {"type", "peaton"}}},
});

// mapea strings a velocidades
std::unordered_map<std::string, float> map_string2floatVelocity ({
  {"1.5", 1.5},
  {"1" , 1.}
});

// colores a usar en la GUI
std::unordered_map<std::string, std::string> map_colors_GUI({
  {"blue"  , "#08E4F7"},
  {"green" , "#08F71B"},
  {"red"   , "#F71B08"},
  {"pink"  , "#F708E4"},
  {"white" , "#FFFFFF"},
  {"black" , "#000000"}
});

std::unordered_map<std::string, std::string> map_string2charsConsole({
  {"white", " "},
  {"black", "#"},
  {"blue", ">"},
  {"green", "}"},
  {"red", "<"},
  {"pink", "{"}
});

// hm de los colores con su correspondiente densidad para el grid,
// multiplicar por densidad inicial de peatones rho_0
std::unordered_map<std::string,float> map_initial_densities({
  {"blue"  , 0.5},
  {"green" , 0.5},
  {"red"   , 0.5},
  {"pink"  , 0.5}
});
