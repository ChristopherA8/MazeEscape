//
//  Entity.cpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#include "Entity.hpp"
#include "world/Maze.hpp"

Entity::Entity(Maze* maze, sf::Vector2i startGridPos)
   : m_maze(maze)
   , m_gridPos(startGridPos)
   , m_sprite(sf::Vector2f(Maze::TILE_SIZE - 0.f, Maze::TILE_SIZE - 0.f)) {
   m_sprite.setPosition(m_maze->gridToWorld(startGridPos));
}