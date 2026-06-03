//
//  Game.cpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#include "Game.hpp"

#include <optional>
#include <algorithm>

#include "scenes/MenuScene.hpp"

Game::Game() : m_window(sf::VideoMode({800u, 672u}), "Maze Escape") {
   m_window.setFramerateLimit(120);
   // push your first scene here once MenuScene exists
   m_sceneManager.push(std::make_unique<MenuScene>(&m_sceneManager, m_assetManager));
}

void Game::run() {
   constexpr float FIXED_DT = 1.f/60.f; // Fixed delta-time
   float accumulator = 0.f;

   while (m_window.isOpen()) {

      m_sceneManager.applyPending();

      if (m_sceneManager.empty()) {
         m_window.close();
         continue;
      }
 
      // Event handling
      while (const std::optional event = m_window.pollEvent()) {
         if (event->is<sf::Event::Closed>())
            m_window.close();

         m_sceneManager.active()->handleEvent(*event);
      }
   
      // Update time
      // Claude + Glenn Fiedler
      // Elegant solution to constant physics simulations given variable frame and compute rates
      // https://gafferongames.com/post/fix_your_timestep/#:~:text=a%20temporary%20spike.-,Free%20the%20physics,-Now%20let%E2%80%99s%20take
      float frameTime = m_clock.restart().asSeconds();
      frameTime = std::min(frameTime, 0.1f);
      accumulator += frameTime;

      while (accumulator >= FIXED_DT) {
         m_sceneManager.active()->update(FIXED_DT);
         accumulator -= FIXED_DT;
      }

      // Rendering
      m_window.clear(sf::Color::Black);
      m_sceneManager.active()->render(m_window);
      m_window.display();

   }

}