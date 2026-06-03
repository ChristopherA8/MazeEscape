//
//  MenuScene.cpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#include "MenuScene.hpp"
#include "core/SceneManager.hpp"
#include <stdexcept>
#include <utility>
#include "GameScene.hpp"
#include "core/AssetManager.hpp"

MenuScene::MenuScene(SceneManager* sceneManager, AssetManager& assets)
   : Scene(sceneManager, assets)
   , m_title(m_assets.getFont("assets/fonts/BlockBlueprint.ttf"), "Maze Escape", 48)
   , m_playOption(m_assets.getFont("assets/fonts/BlockBlueprint.ttf"), "Play", 32)
   , m_quitOption(m_assets.getFont("assets/fonts/BlockBlueprint.ttf"), "Quit", 32)
   , m_uiSound(m_assets.getSoundBuffer("assets/sounds/ui_sound.mp3"))
   , m_background(m_assets.getTexture("assets/textures/menu_bg.jpeg"))
   , m_overlay({800.f, 672.f}) {

   m_title.setFillColor(sf::Color::White);
   m_title.setPosition({275.f, 150.f});

   m_playOption.setFillColor(sf::Color::White);
   m_playOption.setPosition({370.f, 300.f});

   m_quitOption.setFillColor(sf::Color::White);
   m_quitOption.setPosition({370.f, 360.f});

   // loop menu music
   m_assets.playMusic("assets/music/deku_trees_theme.mp3", true);
   m_assets.setMusicVolume(10);

   sf::Vector2u texSize = m_background.getTexture().getSize();
   m_background.setScale({
      800.f / static_cast<float>(texSize.x),
      672.f / static_cast<float>(texSize.y)
   });

   // Add a dark overlay over the background for contrast
   m_overlay.setFillColor(sf::Color(0, 0, 0, 180));
   m_overlay.setPosition({0, 0});
}

void MenuScene::handleEvent(const sf::Event& event) {
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

void MenuScene::update(float dt) {
   // highlight selected option
   m_playOption.setFillColor(m_selectedIndex == 0 ? sf::Color::Yellow : sf::Color::White);
   m_quitOption.setFillColor(m_selectedIndex == 1 ? sf::Color::Yellow : sf::Color::White);
}

void MenuScene::render(sf::RenderWindow& window) {
   window.draw(m_background);
   window.draw(m_overlay);
   window.draw(m_title);
   window.draw(m_playOption);
   window.draw(m_quitOption);
}