//
//  Player.cpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#include "Player.hpp"
#include "world/Maze.hpp"

Player::Player(Maze* maze)
   : Entity(maze, {1, 1}) {  // spawn at grid position (1,1) — first open tile
   m_sprite.setFillColor(sf::Color(100, 180, 255));  // blueish
}

void Player::handleEvent(const sf::Event& event) {
   if (const auto* key = event.getIf<sf::Event::KeyPressed>()) {
      if (key->code == sf::Keyboard::Key::Up)
         m_pendingMove = {0, -1};
      else if (key->code == sf::Keyboard::Key::Down)
         m_pendingMove = {0,  1};
      else if (key->code == sf::Keyboard::Key::Left)
         m_pendingMove = {-1, 0};
      else if (key->code == sf::Keyboard::Key::Right)
         m_pendingMove = { 1, 0};
   }
}

void Player::update(float dt) {
   if (m_pendingMove == sf::Vector2i{0, 0})
      return;

   sf::Vector2i target = m_gridPos + m_pendingMove;

   if (m_maze->isWalkable(target.x, target.y)) {
      m_gridPos = target;
      m_sprite.setPosition(m_maze->gridToWorld(m_gridPos));
   }

   m_pendingMove = {0, 0};  // consume the input regardless of success
}

void Player::render(sf::RenderWindow& window) {
   window.draw(m_sprite);
}