//
//  AssetManager.cpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#include "AssetManager.hpp"
#include "utils/Logger.hpp"

sf::Font& AssetManager::getFont(const std::string& path) {
   auto it = m_fonts.find(path);
   if (it != m_fonts.end())
      return it->second;

   sf::Font font;
   if (!font.openFromFile(path))
      throw std::runtime_error("AssetManager: failed to load font: " + path);

   Logger::info("AssetManager", "Loaded font: " + path);
   m_fonts[path] = std::move(font);
   return m_fonts[path];
}

sf::Texture& AssetManager::getTexture(const std::string& path) {
   auto it = m_textures.find(path);
   if (it != m_textures.end())
      return it->second;

   sf::Texture texture;
   if (!texture.loadFromFile(path))
      throw std::runtime_error("AssetManager: failed to load texture: " + path);

   Logger::info("AssetManager", "Loaded texture: " + path);
   m_textures[path] = std::move(texture);
   return m_textures[path];
}

sf::SoundBuffer& AssetManager::getSoundBuffer(const std::string& path) {
   auto it = m_soundBuffers.find(path);
   if (it != m_soundBuffers.end())
      return it->second;

   sf::SoundBuffer buffer;
   if (!buffer.loadFromFile(path))
      throw std::runtime_error("AssetManager: failed to load sound: " + path);

   Logger::info("AssetManager", "Loaded sound: " + path);
   m_soundBuffers[path] = std::move(buffer);
   return m_soundBuffers[path];
}

void AssetManager::playMusic(const std::string& path, bool loop) {
   if (!m_music.openFromFile(path)) {
      Logger::warn("AssetManager", "Failed to load music: " + path);
      return;
   }

   m_music.setLooping(loop);
   m_music.play();
   Logger::info("AssetManager", "Playing music: " + path);
}

void AssetManager::stopMusic() {
   m_music.stop();
}

void AssetManager::setMusicVolume(float volume) {
   m_music.setVolume(volume);
}