//
//  Pathfinder.cpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#include "Pathfinder.hpp"

sf::Vector2i Pathfinder::nextStep(const Graph& graph, sf::Vector2i start, sf::Vector2i goal) {
   int startIndex = graph.nodeIndex(start.x, start.y);
   int goalIndex = graph.nodeIndex(goal.x, goal.y);

   Result d_res = dijkstra(graph, startIndex);
   sf::Vector2i r_vector = reconstructStep(graph, d_res, startIndex, goalIndex);

   return r_vector;
}

using PQEntry = std::pair<float, int>;
using MinHeap = std::priority_queue<PQEntry, std::vector<PQEntry>, std::greater<PQEntry>>;

Pathfinder::Result Pathfinder::dijkstra(const Graph& graph, int startIndex) {
   const int n = graph.nodeCount();

   Result r;
   r.dist.assign(n, std::numeric_limits<float>::infinity());
   r.prev.assign(n, -1);

   r.dist[startIndex] = 0.0f;

   MinHeap pq;
   pq.push({0.0f, startIndex});

   while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();

      // lazy deletion — stale entry, already found a shorter path
      if (d > r.dist[u])
         continue;

      // for each neighbor of u
      for (const Edge& edge : graph.getNode(u).edges) {
         int v = edge.toNode;
         float newDist = r.dist[u] + edge.weight;

         if (newDist < r.dist[v]) {
            r.dist[v] = newDist;
            r.prev[v] = u;
            pq.push({newDist, v});
         }
      }
   }

   return r;
}

sf::Vector2i Pathfinder::reconstructStep(const Graph& graph, const Result& result, int startIndex, int goalIndex) {
   // no path exists
   if (result.prev[goalIndex] == -1 && goalIndex != startIndex)
      return {graph.getNode(startIndex).col, graph.getNode(startIndex).row}; // stay put

   // walk prev[] backward from goal until we find
   // the node whose parent is the start
   int current = goalIndex;

   while (result.prev[current] != startIndex) {
      current = result.prev[current];

      // safety guard — should never happen on a valid graph
      if (current == -1) {
         const Node& s = graph.getNode(startIndex);
         return {s.col, s.row};
      }
   }

   // current is now the first step on the path
   const Node& next = graph.getNode(current);
   return {next.col, next.row};
}