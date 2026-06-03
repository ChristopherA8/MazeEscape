//
//  MenuScene.hpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Scene.hpp"

class MenuScene : public Scene {
public:
   MenuScene(SceneManager* sceneManager, AssetManager& assets);

   void handleEvent(const sf::Event& event) override;
   void update(float dt)                    override;
   void render(sf::RenderWindow& window)    override;

private:
   // UI elements
   sf::Text m_title;
   sf::Text m_playOption;
   sf::Text m_quitOption;

   sf::RectangleShape m_overlay;
   sf::Sprite m_background;

   sf::Sound m_uiSound;

   int m_selectedIndex = 0; // which menu item is highlighted
};