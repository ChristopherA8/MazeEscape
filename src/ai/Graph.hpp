//
//  Graph.hpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#pragma once

#include <unordered_map>
#include <vector>

#include <SFML/Graphics.hpp>

struct Edge {
   int   toNode; // index of destination node
   float weight;
};

struct Node {
   int col;
   int row;
   std::vector<Edge> edges;
};

class Graph {
public:
   // called by Maze::buildGraph()
   void addNode(int col, int row);
   void addEdge(int fromCol, int fromRow, int toCol, int toRow, float weight);

   // called by Pathfinder (Dijkstra)
   int              nodeIndex(int col, int row)  const;
   const Node&      getNode(int index)           const;
   int              nodeCount()                  const;
   bool             hasNode(int col, int row)    const;

private:
   std::vector<Node>                        m_nodes;
   std::unordered_map<int, int>             m_indexMap;  // encoded key → index

   // encode (col, row) into a single int key for the map
   // assumes col and row fit in 16 bits — fine for any reasonable maze size
   static int encode(int col, int row) { return (row << 16) | col; }
};