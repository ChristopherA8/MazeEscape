//
//  SceneManager.cpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#include "SceneManager.hpp"
#include "utils/Logger.hpp"

void SceneManager::push(std::unique_ptr<Scene> scene) {
   m_pending = { Transition::Push, std::move(scene) };
}

void SceneManager::pop() {
   m_pending = { Transition::Pop, nullptr };
}

void SceneManager::replace(std::unique_ptr<Scene> scene) {
   m_pending = { Transition::Replace, std::move(scene) };
}

void SceneManager::applyPending() {
   switch (m_pending.type) {
      case Transition::Push:
         m_stack.push_back(std::move(m_pending.scene));
         Logger::info("SceneManager", "Scene pushed");
         break;

      case Transition::Pop:
         if (!m_stack.empty())
               m_stack.pop_back();  // unique_ptr destructs old scene
         Logger::info("SceneManager", "Scene popped");
         break;

      case Transition::Replace:
         if (!m_stack.empty())
               m_stack.pop_back();
         m_stack.push_back(std::move(m_pending.scene));
         Logger::info("SceneManager", "Scene replaced");
         break;

      case Transition::None:
         break;
   }

   m_pending = { Transition::None, nullptr };  // always reset
}

Scene* SceneManager::active() const {
   if (m_stack.empty()) return nullptr;
   return m_stack.back().get();
}

bool SceneManager::empty() const {
   return m_stack.empty();
}