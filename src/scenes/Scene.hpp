//
//  Scene.hpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#pragma once

#include <SFML/Graphics.hpp>

class SceneManager;
class AssetManager;

class Scene {
public:
   Scene(SceneManager* sceneManager, AssetManager& assets)
      : m_ctx(sceneManager)
      , m_assets(assets)
   {}

   virtual ~Scene() = default;

   Scene(const Scene&)            = delete;
   Scene& operator=(const Scene&) = delete;

   virtual void handleEvent(const sf::Event& event) = 0;
   virtual void update(float dt)                    = 0;
   virtual void render(sf::RenderWindow& window)    = 0;

   // optional — called when this scene becomes active again after a pop
   virtual void onResume() {}

protected:
   SceneManager* m_ctx;
   AssetManager& m_assets;
};