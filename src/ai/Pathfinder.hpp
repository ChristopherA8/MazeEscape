//
//  Pathfinder.hpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "Graph.hpp"

class Pathfinder {
public:
   // returns the next grid position an entity should move to
   // in order to reach 'goal' from 'start' via Dijkstra
   // returns 'start' if no path exists (entity stays put)
   static sf::Vector2i nextStep(
      const Graph&   graph,
      sf::Vector2i   start,
      sf::Vector2i   goal
   );

private:
   // runs Dijkstra from start node, returns distance and previous arrays
   struct Result {
      std::vector<float> dist;  // dist[i] = shortest distance to node i
      std::vector<int>   prev;  // prev[i] = which node came before i on shortest path
   };

   static Result dijkstra(const Graph& graph, int startIndex);
   static sf::Vector2i reconstructStep(
      const Graph& graph, 
      const Result& result, 
      int startIndex, 
      int goalIndex
   );
};