//
//  Maze.hpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#pragma once

#include <vector>
#include <array>

#include <SFML/Graphics.hpp>
#include "Tile.hpp"

class Graph;

class Maze {
public:
   static constexpr int COLS = 21;
   static constexpr int ROWS = 21;
   static constexpr int TILE_SIZE = 32;

   Maze();

   // grid queries — used by Player, Enemy, collision
   TileType        getTile(int col, int row)          const;
   bool            isWalkable(int col, int row)       const;
   bool            isExitTile(sf::Vector2i gridPos)   const;
   sf::Vector2f    gridToWorld(sf::Vector2i gridPos)  const;
   sf::Vector2i    worldToGrid(sf::Vector2f worldPos) const;

   // graph access — used by Pathfinder
   const Graph&    getGraph() const;
   
   void render(sf::RenderWindow& window);

   ~Maze();
   
private:
   void buildGrid();   // fills m_grid with wall/floor/exit
   void buildGraph();  // derives m_graph from m_grid

   std::array<std::array<TileType, COLS>, ROWS> m_grid;
   std::unique_ptr<Graph>                       m_graph;

   // visual tiles
   sf::RectangleShape m_tileShape;  // reused for rendering, avoid alloc per tile
};