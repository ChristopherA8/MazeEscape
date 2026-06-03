//
//  GameOverScene.cpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#include "GameOverScene.hpp"
#include "core/SceneManager.hpp"
#include "core/AssetManager.hpp"
#include <stdexcept>
#include <utility>
#include "GameScene.hpp"

GameOverScene::GameOverScene(SceneManager* sceneManager, AssetManager& assets, int winCondition)
   : Scene(sceneManager, assets)
   , m_title(m_assets.getFont("assets/fonts/BlockBlueprint.ttf"), winCondition ? "You Won!" : "You Lost :(", 48)
   , m_playOption(m_assets.getFont("assets/fonts/BlockBlueprint.ttf"), "Play Again", 32)
   , m_quitOption(m_assets.getFont("assets/fonts/BlockBlueprint.ttf"), "Quit", 32)
   , m_uiSound(m_assets.getSoundBuffer("assets/sounds/ui_sound.mp3"))
   , m_defeatSound(m_assets.getSoundBuffer("assets/sounds/hit_sound.mp3"))
   , m_victorySound(m_assets.getSoundBuffer("assets/sounds/zelda_victory.mp3")) {
   m_title.setFillColor(sf::Color::White);
   m_title.setPosition({winCondition ? 305.f : 280.f, 150.f});

   m_playOption.setFillColor(sf::Color::White);
   m_playOption.setPosition({330.f, 300.f});

   m_quitOption.setFillColor(sf::Color::White);
   m_quitOption.setPosition({370.f, 360.f});

   if (winCondition)
      m_victorySound.play();
   else
      m_defeatSound.play();
}

void GameOverScene::handleEvent(const sf::Event& event) {
   if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {
      if (keyPressed->code == sf::Keyboard::Key::Up) {
         m_selectedIndex = (m_selectedIndex - 1 + 2) % 2;
         m_uiSound.play();
      }

      if (keyPressed->code == sf::Keyboard::Key::Down) {
         m_selectedIndex = (m_selectedIndex + 1) % 2;
         m_uiSound.play();
      }

      if (keyPressed->code == sf::Keyboard::Key::Enter) {
         if (m_selectedIndex == 0)
            m_ctx->replace(std::make_unique<GameScene>(m_ctx, m_assets));
         else
            m_ctx->pop();
      }
   }
}

void GameOverScene::update(float dt) {
   // highlight selected option
   m_playOption.setFillColor(m_selectedIndex == 0 ? sf::Color::Yellow : sf::Color::White);
   m_quitOption.setFillColor(m_selectedIndex == 1 ? sf::Color::Yellow : sf::Color::White);
}

void GameOverScene::render(sf::RenderWindow& window) {
   window.draw(m_title);
   window.draw(m_playOption);
   window.draw(m_quitOption);
}