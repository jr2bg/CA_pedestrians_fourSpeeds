# CA_pedestrians_fourSpeeds

Implementation of a CA-based model for pedestrians walking in two directions. Each direction with 2 different speeds.

This project is developed in C++.

The inputs are:
* W: dimension (int)
* Frontier: periodic of open
* Obstacles: draw them
* Pedestrian density to right 1: float
* Pedestrian density to right 1.5: float
* Pedestrian density to left 1: float
* Pedestrian density to left 1.5: float

The neighborhood of this CA is the von Neumann neighborhood.

Based on the article:
Weng , W., Chen, T., & Yuan, H. _Cellular automaton simulation for pedestrian counter flow with different walk velocities._ Physical Review E, Octuber 2006.
