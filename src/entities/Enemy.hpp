//
//  Enemy.hpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#pragma once

#include "Entity.hpp"

class Player;

class Enemy : public Entity {
public:
    Enemy(Maze* maze, AssetManager& assets, Player* player);

    void update(float dt)                 override;
    void render(sf::RenderWindow& window) override;

private:
    Player* m_target;           // non-owning observer pointer
    float   m_moveTimer = 0.f;  // throttle how often enemy steps
};