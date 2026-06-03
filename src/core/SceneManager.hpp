//
//  SceneManager.hpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#pragma once

#include <memory>
#include <vector>

#include "scenes/Scene.hpp"

enum class Transition { None, Push, Pop, Replace };

struct PendingTransition {
    Transition type = Transition::None;
    std::unique_ptr<Scene> scene;  // null for Pop
};

class SceneManager {
public:
    void push(std::unique_ptr<Scene> scene);
    void pop();
    void replace(std::unique_ptr<Scene> scene);
    void applyPending();

    Scene* active() const;
    bool   empty()  const;

private:
    std::vector<std::unique_ptr<Scene>> m_stack;
    PendingTransition                   m_pending;
};