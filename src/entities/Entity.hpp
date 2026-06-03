//
//  Entity.hpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#pragma once

#include <SFML/Graphics.hpp>

class Maze;

class Entity {
public:
   Entity(Maze* maze, sf::Vector2i startGridPos);
   virtual ~Entity() = default;

   virtual void handleEvent(const sf::Event& event) {}
   virtual void update(float dt)                    = 0;
   virtual void render(sf::RenderWindow& window)    = 0;

   sf::Vector2i getGridPosition()  const { return m_gridPos; }
   sf::Vector2f getWorldPosition() const { return m_sprite.getPosition(); }

protected:
   Maze*              m_maze;
   sf::Vector2i       m_gridPos;    // logical position in grid space
   sf::RectangleShape m_sprite;     // simple colored rect until you have textures
};