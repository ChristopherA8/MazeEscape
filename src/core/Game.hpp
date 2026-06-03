//
//  Game.hpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "core/SceneManager.hpp"
#include "core/AssetManager.hpp"

class Game {
private:
   sf::RenderWindow  m_window;
   SceneManager      m_sceneManager;
   AssetManager      m_assetManager;
   sf::Clock         m_clock;

public:
   Game();
   void run();
};