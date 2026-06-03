//
//  GameScene.cpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#include "GameScene.hpp"
#include "core/SceneManager.hpp"
#include "world/Maze.hpp"
#include "entities/Player.hpp"
#include "entities/Enemy.hpp"
#include "core/utils/Logger.hpp"
#include "MenuScene.hpp"
// #include "PauseScene.hpp"   ← uncomment when ready
#include "GameOverScene.hpp"

GameScene::GameScene(SceneManager* sceneManager, AssetManager& assets)
   : Scene(sceneManager, assets) {
   // build the maze first — enemies and player need it to know
   // where they can spawn and move
   m_maze   = std::make_unique<Maze>();
   m_player = std::make_unique<Player>(m_maze.get());

   // spawn a few enemies at fixed positions for now
   m_enemies.emplace_back(std::make_unique<Enemy>(m_maze.get(), m_player.get()));
}

void GameScene::handleEvent(const sf::Event& event) {
   if (const auto* key = event.getIf<sf::Event::KeyPressed>()) {
      if (key->code == sf::Keyboard::Key::Escape) {
         // m_ctx->push(std::make_unique<PauseScene>(m_ctx, m_assets));
      }
   }

   m_player->handleEvent(event);
}

void GameScene::update(float dt) {
   m_player->update(dt);

   for (auto& enemy : m_enemies)
      enemy->update(dt);
   
   checkWinCondition();
   checkLoseCondition();
}

void GameScene::render(sf::RenderWindow& window) {
   m_maze->render(window);
   m_player->render(window);

   for (auto& enemy : m_enemies)
      enemy->render(window);
}

void GameScene::onResume() {
   // coming back from PauseScene — nothing needed yet
   // good place to restart music or reset input state later
}

void GameScene::checkWinCondition() {
   // player reaches the exit tile
   if (m_maze->isExitTile(m_player->getGridPosition())) {
      m_ctx->replace(std::make_unique<GameOverScene>(m_ctx, m_assets, true));
   }
}

void GameScene::checkLoseCondition() {
   for (auto& enemy : m_enemies) {
      if (enemy->getGridPosition() == m_player->getGridPosition()) {
         m_ctx->replace(std::make_unique<GameOverScene>(m_ctx, m_assets, false));
         return;
      }
   }
}

GameScene::~GameScene() = default;