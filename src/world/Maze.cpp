//
//  Maze.cpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#include "Maze.hpp"
#include "ai/Graph.hpp"

Maze::Maze()
   : m_tileShape({TILE_SIZE, TILE_SIZE}) {
   buildGrid();
   buildGraph();
}

// void Maze::buildGrid() {
//    // hardcode a simple maze for now — replace with generation later
//    // 0 = floor, 1 = wall, E = exit
//    for (int row = 0; row < ROWS; ++row)
//       for (int col = 0; col < COLS; ++col)
//          m_grid[row][col] = (row == 0 || row == ROWS-1 ||
//                               col == 0 || col == COLS-1)
//                               ? TileType::Wall : TileType::Floor;

//    // place exit
//    m_grid[1][COLS-2] = TileType::Exit;
// }

void Maze::buildGrid() {
    for (int row = 0; row < ROWS; ++row)
        for (int col = 0; col < COLS; ++col)
            m_grid[row][col] = TileType::Wall;

    // floor tiles
    m_grid[1][1] = TileType::Floor;
    m_grid[1][2] = TileType::Floor;
    m_grid[1][3] = TileType::Floor;
    m_grid[1][4] = TileType::Floor;
    m_grid[1][5] = TileType::Floor;
    m_grid[1][6] = TileType::Floor;
    m_grid[1][7] = TileType::Floor;
    m_grid[1][8] = TileType::Floor;
    m_grid[1][9] = TileType::Floor;
    m_grid[1][10] = TileType::Floor;
    m_grid[1][11] = TileType::Floor;
    m_grid[1][16] = TileType::Floor;
    m_grid[1][17] = TileType::Floor;
    m_grid[1][18] = TileType::Floor;
    m_grid[2][1] = TileType::Floor;
    m_grid[2][7] = TileType::Floor;
    m_grid[2][9] = TileType::Floor;
    m_grid[2][14] = TileType::Floor;
    m_grid[2][15] = TileType::Floor;
    m_grid[2][16] = TileType::Floor;
    m_grid[3][1] = TileType::Floor;
    m_grid[3][3] = TileType::Floor;
    m_grid[3][4] = TileType::Floor;
    m_grid[3][5] = TileType::Floor;
    m_grid[3][6] = TileType::Floor;
    m_grid[3][7] = TileType::Floor;
    m_grid[3][9] = TileType::Floor;
    m_grid[3][10] = TileType::Floor;
    m_grid[3][11] = TileType::Floor;
    m_grid[3][12] = TileType::Floor;
    m_grid[3][13] = TileType::Floor;
    m_grid[3][14] = TileType::Floor;
    m_grid[4][1] = TileType::Floor;
    m_grid[4][3] = TileType::Floor;
    m_grid[4][5] = TileType::Floor;
    m_grid[4][7] = TileType::Floor;
    m_grid[4][14] = TileType::Floor;
    m_grid[4][16] = TileType::Floor;
    m_grid[4][17] = TileType::Floor;
    m_grid[4][18] = TileType::Floor;
    m_grid[5][1] = TileType::Floor;
    m_grid[5][3] = TileType::Floor;
    m_grid[5][5] = TileType::Floor;
    m_grid[5][7] = TileType::Floor;
    m_grid[5][8] = TileType::Floor;
    m_grid[5][9] = TileType::Floor;
    m_grid[5][10] = TileType::Floor;
    m_grid[5][11] = TileType::Floor;
    m_grid[5][14] = TileType::Floor;
    m_grid[5][16] = TileType::Floor;
    m_grid[5][18] = TileType::Floor;
    m_grid[6][1] = TileType::Floor;
    m_grid[6][2] = TileType::Floor;
    m_grid[6][3] = TileType::Floor;
    m_grid[6][5] = TileType::Floor;
    m_grid[6][11] = TileType::Floor;
    m_grid[6][12] = TileType::Floor;
    m_grid[6][13] = TileType::Floor;
    m_grid[6][14] = TileType::Floor;
    m_grid[6][15] = TileType::Floor;
    m_grid[6][16] = TileType::Floor;
    m_grid[6][18] = TileType::Floor;
    m_grid[7][1] = TileType::Floor;
    m_grid[7][3] = TileType::Floor;
    m_grid[7][5] = TileType::Floor;
    m_grid[7][6] = TileType::Floor;
    m_grid[7][7] = TileType::Floor;
    m_grid[7][8] = TileType::Floor;
    m_grid[7][9] = TileType::Floor;
    m_grid[7][14] = TileType::Floor;
    m_grid[7][16] = TileType::Floor;
    m_grid[7][18] = TileType::Floor;
    m_grid[8][1] = TileType::Floor;
    m_grid[8][3] = TileType::Floor;
    m_grid[8][8] = TileType::Floor;
    m_grid[8][9] = TileType::Floor;
    m_grid[8][10] = TileType::Floor;
    m_grid[8][11] = TileType::Floor;
    m_grid[8][12] = TileType::Floor;
    m_grid[8][14] = TileType::Floor;
    m_grid[8][16] = TileType::Floor;
    m_grid[8][18] = TileType::Floor;
    m_grid[9][1] = TileType::Floor;
    m_grid[9][3] = TileType::Floor;
    m_grid[9][4] = TileType::Floor;
    m_grid[9][5] = TileType::Floor;
    m_grid[9][6] = TileType::Floor;
    m_grid[9][12] = TileType::Floor;
    m_grid[9][14] = TileType::Floor;
    m_grid[9][16] = TileType::Floor;
    m_grid[9][18] = TileType::Floor;
    m_grid[10][1] = TileType::Floor;
    m_grid[10][3] = TileType::Floor;
    m_grid[10][6] = TileType::Floor;
    m_grid[10][7] = TileType::Floor;
    m_grid[10][8] = TileType::Floor;
    m_grid[10][9] = TileType::Floor;
    m_grid[10][10] = TileType::Floor;
    m_grid[10][12] = TileType::Floor;
    m_grid[10][14] = TileType::Floor;
    m_grid[10][16] = TileType::Floor;
    m_grid[10][18] = TileType::Floor;
    m_grid[11][1] = TileType::Floor;
    m_grid[11][2] = TileType::Floor;
    m_grid[11][3] = TileType::Floor;
    m_grid[11][12] = TileType::Floor;
    m_grid[11][14] = TileType::Floor;
    m_grid[11][16] = TileType::Floor;
    m_grid[11][18] = TileType::Floor;
    m_grid[12][1] = TileType::Floor;
    m_grid[12][6] = TileType::Floor;
    m_grid[12][7] = TileType::Floor;
    m_grid[12][9] = TileType::Floor;
    m_grid[12][12] = TileType::Floor;
    m_grid[12][14] = TileType::Floor;
    m_grid[12][16] = TileType::Floor;
    m_grid[13][1] = TileType::Floor;
    m_grid[13][2] = TileType::Floor;
    m_grid[13][6] = TileType::Floor;
    m_grid[13][9] = TileType::Floor;
    m_grid[13][11] = TileType::Floor;
    m_grid[13][12] = TileType::Floor;
    m_grid[13][14] = TileType::Floor;
    m_grid[13][16] = TileType::Floor;
    m_grid[13][17] = TileType::Floor;
    m_grid[14][2] = TileType::Floor;
    m_grid[14][3] = TileType::Floor;
    m_grid[14][6] = TileType::Floor;
    m_grid[14][8] = TileType::Floor;
    m_grid[14][9] = TileType::Floor;
    m_grid[14][11] = TileType::Floor;
    m_grid[14][14] = TileType::Floor;
    m_grid[14][17] = TileType::Floor;
    m_grid[14][18] = TileType::Floor;
    m_grid[14][19] = TileType::Floor;
    m_grid[15][2] = TileType::Floor;
    m_grid[15][6] = TileType::Floor;
    m_grid[15][8] = TileType::Floor;
    m_grid[15][11] = TileType::Floor;
    m_grid[15][13] = TileType::Floor;
    m_grid[15][14] = TileType::Floor;
    m_grid[15][15] = TileType::Floor;
    m_grid[15][19] = TileType::Floor;
    m_grid[16][2] = TileType::Floor;
    m_grid[16][6] = TileType::Floor;
    m_grid[16][8] = TileType::Floor;
    m_grid[16][10] = TileType::Floor;
    m_grid[16][11] = TileType::Floor;
    m_grid[16][13] = TileType::Floor;
    m_grid[16][19] = TileType::Floor;
    m_grid[17][2] = TileType::Floor;
    m_grid[17][4] = TileType::Floor;
    m_grid[17][5] = TileType::Floor;
    m_grid[17][6] = TileType::Floor;
    m_grid[17][8] = TileType::Floor;
    m_grid[17][9] = TileType::Floor;
    m_grid[17][10] = TileType::Floor;
    m_grid[17][11] = TileType::Floor;
    m_grid[17][12] = TileType::Floor;
    m_grid[17][13] = TileType::Floor;
    m_grid[17][14] = TileType::Floor;
    m_grid[17][15] = TileType::Floor;
    m_grid[17][19] = TileType::Floor;
    m_grid[18][2] = TileType::Floor;
    m_grid[18][6] = TileType::Floor;
    m_grid[18][15] = TileType::Floor;
    m_grid[18][16] = TileType::Floor;
    m_grid[18][19] = TileType::Floor;
    m_grid[19][1] = TileType::Floor;
    m_grid[19][2] = TileType::Floor;
    m_grid[19][3] = TileType::Floor;
    m_grid[19][4] = TileType::Floor;
    m_grid[19][5] = TileType::Floor;
    m_grid[19][6] = TileType::Floor;
    m_grid[19][7] = TileType::Floor;
    m_grid[19][8] = TileType::Floor;
    m_grid[19][9] = TileType::Floor;
    m_grid[19][10] = TileType::Floor;
    m_grid[19][11] = TileType::Floor;
    m_grid[19][12] = TileType::Floor;
    m_grid[19][13] = TileType::Floor;
    m_grid[19][16] = TileType::Floor;
    m_grid[19][17] = TileType::Floor;
    m_grid[19][18] = TileType::Floor;
    m_grid[19][19] = TileType::Floor;

    // exit tile(s)
    m_grid[1][19] = TileType::Exit;

}

void Maze::buildGraph() {
   m_graph = std::make_unique<Graph>();

   // add a node for every walkable tile
   for (int row = 0; row < ROWS; ++row)
      for (int col = 0; col < COLS; ++col)
         if (isWalkable(col, row))
            m_graph->addNode(col, row);

   // add edges between adjacent walkable tiles
   // only 4-directional — no diagonal movement in a maze
   const std::array<sf::Vector2i, 4> dirs = {{
      {0, -1}, {0, 1}, {-1, 0}, {1, 0}
   }};

   for (int row = 0; row < ROWS; ++row)
      for (int col = 0; col < COLS; ++col)
         if (isWalkable(col, row))
            for (const auto& dir : dirs) {
               int nx = col + dir.x;
               int ny = row + dir.y;
               if (nx >= 0 && nx < COLS && ny >= 0 && ny < ROWS && isWalkable(nx, ny))
                  m_graph->addEdge(col, row, nx, ny, 1.f);
               }
}

TileType Maze::getTile(int col, int row) const {
   return m_grid[row][col];
}

bool Maze::isWalkable(int col, int row) const {
   return m_grid[row][col] != TileType::Wall;
}

bool Maze::isExitTile(sf::Vector2i gridPos) const {
   return m_grid[gridPos.y][gridPos.x] == TileType::Exit;
}

sf::Vector2f Maze::gridToWorld(sf::Vector2i gridPos) const {
   return sf::Vector2f(
      static_cast<float>(gridPos.x * TILE_SIZE),
      static_cast<float>(gridPos.y * TILE_SIZE)
   );
}

sf::Vector2i Maze::worldToGrid(sf::Vector2f worldPos) const {
   return sf::Vector2i(
      static_cast<int>(worldPos.x / TILE_SIZE),
      static_cast<int>(worldPos.y / TILE_SIZE)
   );
}

const Graph& Maze::getGraph() const {
   return *m_graph;
}

void Maze::render(sf::RenderWindow& window) {
   for (int row = 0; row < ROWS; ++row)
      for (int col = 0; col < COLS; ++col) {
         switch (m_grid[row][col]) {
            case TileType::Wall:  m_tileShape.setFillColor(sf::Color(40, 40, 80));    break;
            case TileType::Floor: m_tileShape.setFillColor(sf::Color(180, 160, 120)); break;
            case TileType::Exit:  m_tileShape.setFillColor(sf::Color(80, 200, 120));  break;
         }

         m_tileShape.setPosition(gridToWorld({col, row}));
         window.draw(m_tileShape);
      }
}

Maze::~Maze() = default;