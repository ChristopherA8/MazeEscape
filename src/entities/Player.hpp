//
//  Player.hpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#pragma once

#include "Entity.hpp"

class Player : public Entity {
public:
    Player(Maze* maze, AssetManager& assets);

    void handleEvent(const sf::Event& event) override;
    void update(float dt)                    override;
    void render(sf::RenderWindow& window)    override;

private:
    sf::Vector2i m_pendingMove;  // direction input buffered from handleEvent
};