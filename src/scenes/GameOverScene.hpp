//
//  GameOverScene.hpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Scene.hpp"

class GameOverScene : public Scene {
public:
   GameOverScene(SceneManager* sceneManager, AssetManager& assets, int winCondition);

   void handleEvent(const sf::Event& event) override;
   void update(float dt)                    override;
   void render(sf::RenderWindow& window)    override;

private:
   // UI elements
   sf::Text m_title;
   sf::Text m_playOption;
   sf::Text m_quitOption;

   sf::Sound m_uiSound;
   sf::Sound m_defeatSound;
   sf::Sound m_victorySound;

   int m_selectedIndex = 0; // which menu item is highlighted
};