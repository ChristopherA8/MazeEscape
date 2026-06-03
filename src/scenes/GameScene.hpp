//
//  GameScene.hpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#pragma once

#include <vector>

#include <SFML/Graphics.hpp>
#include "Scene.hpp"

class Maze;
class Player;
class Enemy;

class GameScene : public Scene {
public:
   GameScene(SceneManager* sceneManager, AssetManager& assets);

   void handleEvent(const sf::Event& event) override;
   void update(float dt)                    override;
   void render(sf::RenderWindow& window)    override;

   void onResume()                          override;  // called when PauseScene pops

   ~GameScene();
private:
   void checkWinCondition();
   void checkLoseCondition();

   std::unique_ptr<Maze>               m_maze;
   std::unique_ptr<Player>             m_player;
   std::vector<std::unique_ptr<Enemy>> m_enemies;

   bool m_paused = false;
};