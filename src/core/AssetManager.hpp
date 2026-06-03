//
//  AssetManager.hpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#pragma once

#include <unordered_map>
#include <string>
#include <stdexcept>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class AssetManager {
public:
   sf::Font&        getFont(const std::string& path);
   sf::Texture&     getTexture(const std::string& path);
   sf::SoundBuffer& getSoundBuffer(const std::string& path);

   // music streams from disk — call playMusic to swap tracks
   void playMusic(const std::string& path, bool loop = true);
   void stopMusic();
   void setMusicVolume(float volume);  // 0-100

private:
   std::unordered_map<std::string, sf::Font>        m_fonts;
   std::unordered_map<std::string, sf::Texture>     m_textures;
   std::unordered_map<std::string, sf::SoundBuffer> m_soundBuffers;

   sf::Music m_music;  // one music stream — only one track plays at a time
};