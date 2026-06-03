//
//  Graph.cpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#include "Graph.hpp"

#include <stdexcept>

#include "core/utils/Logger.hpp"

void Graph::addNode(int col, int row) {
   int key = encode(col, row);

   if (m_indexMap.count(key))
      return;  // already added, skip

   int index = static_cast<int>(m_nodes.size());
   m_indexMap[key] = index;
   m_nodes.push_back({ col, row, {} });
}

void Graph::addEdge(int fromCol, int fromRow, int toCol, int toRow, float weight) {
   int fromIndex = nodeIndex(fromCol, fromRow);
   int toIndex   = nodeIndex(toCol, toRow);

   if (fromIndex == -1 || toIndex == -1) {
      Logger::warn("Graph", "addEdge called with non-existent node");
      return;
   }

   m_nodes[fromIndex].edges.push_back({ toIndex, weight });
}

int Graph::nodeIndex(int col, int row) const {
   auto it = m_indexMap.find(encode(col, row));
   if (it == m_indexMap.end())
      return -1;  // sentinel for "not found"
   return it->second;
}

const Node& Graph::getNode(int index) const {
   return m_nodes.at(index);  // .at() does bounds checking
}

int Graph::nodeCount() const {
   return static_cast<int>(m_nodes.size());
}

bool Graph::hasNode(int col, int row) const {
   return m_indexMap.count(encode(col, row)) > 0;
}