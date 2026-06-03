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

static sf::Font loadFont(const std::string& path) {
   sf::Font font;
   if (!font.openFromFile(path))
      throw std::runtime_error("Failed to load font: " + path);
   return font;
}

MenuScene::MenuScene(SceneManager* sceneManager, AssetManager& assets)
   : Scene(sceneManager, assets)
   , m_font(loadFont("assets/fonts/BlockBlueprint.ttf"))
   , m_title(m_font, "Maze Escape", 48)
   , m_playOption(m_font, "Play", 32)
   , m_quitOption(m_font, "Quit", 32) {

   m_title.setFillColor(sf::Color::White);
   m_title.setPosition({275.f, 150.f});

   m_playOption.setFillColor(sf::Color::White);
   m_playOption.setPosition({370.f, 300.f});

   m_quitOption.setFillColor(sf::Color::White);
   m_quitOption.setPosition({370.f, 360.f});
}

void MenuScene::handleEvent(const sf::Event& event) {
   if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {
      if (keyPressed->code == sf::Keyboard::Key::Up)
         m_selectedIndex = (m_selectedIndex - 1 + 2) % 2;

      if (keyPressed->code == sf::Keyboard::Key::Down)
         m_selectedIndex = (m_selectedIndex + 1) % 2;

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
   window.draw(m_title);
   window.draw(m_playOption);
   window.draw(m_quitOption);
}