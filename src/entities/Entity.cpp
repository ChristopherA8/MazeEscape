//
//  Entity.cpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#include "Entity.hpp"
#include "world/Maze.hpp"

Entity::Entity(Maze* maze, AssetManager& assets, const std::string& texturePath, sf::Vector2i startGridPos)
   : m_maze(maze)
   , m_gridPos(startGridPos)
   , m_sprite(assets.getTexture(texturePath)) {
   // scale sprite to fit tile size
   sf::Vector2u texSize = m_sprite.getTexture().getSize();
   m_sprite.setScale({
      static_cast<float>(Maze::TILE_SIZE) / texSize.x,
      static_cast<float>(Maze::TILE_SIZE) / texSize.y
   });

   m_sprite.setPosition(m_maze->gridToWorld(startGridPos));
}