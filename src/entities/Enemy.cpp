//
//  Enemy.cpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#include "Enemy.hpp"
#include "Player.hpp"
#include "world/Maze.hpp"
#include "ai/Pathfinder.hpp"

static constexpr float MOVE_INTERVAL = 0.35f;  // seconds between steps

Enemy::Enemy(Maze* maze, AssetManager& assets, Player* player)
   : Entity(maze, assets, "assets/textures/enemy.png", {Maze::COLS - 2, Maze::ROWS - 2})
   , m_target(player) {

}

void Enemy::update(float dt) {
   m_moveTimer += dt;

   if (m_moveTimer < MOVE_INTERVAL)
      return;

   m_moveTimer = 0.f;

   // ask pathfinder for next step toward player
   sf::Vector2i nextStep = Pathfinder::nextStep(
      m_maze->getGraph(),
      m_gridPos,
      m_target->getGridPosition()
   );

   // only move if pathfinder returned a valid step
   if (nextStep != m_gridPos) {
      m_gridPos = nextStep;
      m_sprite.setPosition(m_maze->gridToWorld(m_gridPos));
   }
}

void Enemy::render(sf::RenderWindow& window) {
   window.draw(m_sprite);
}