# Maze Escape

Maze survival game

<img width="600" alt="ezgif com-video-to-gif-converter" src="https://github.com/user-attachments/assets/44950a28-84ad-494e-9730-b958eb934831" />

```bash
project/
├── maze_level_builder.html          # Claude-generated level builder ui
├── dist/
├── SFML/
├── assets/
│   ├── fonts/
│   ├── textures/
│   └── sounds/
├── src/
│   ├── main.cpp
│   ├── core/
│   │   ├── Game.hpp / .cpp          # owns the window, main loop, scene stack
│   │   ├── SceneManager.hpp / .cpp  # pushes/pops scenes
│   │   └── AssetManager.hpp / .cpp  # texture/font/sound cache
│   ├── scenes/
│   │   ├── Scene.hpp                # abstract base
│   │   ├── MenuScene.hpp / .cpp
│   │   ├── GameScene.hpp / .cpp
│   │   └── GameOverScene.hpp / .cpp
│   ├── entities/
│   │   ├── Entity.hpp               # abstract base
│   │   ├── Player.hpp / .cpp
│   │   └── Enemy.hpp / .cpp
│   ├── world/
│   │   ├── Maze.hpp / .cpp          # grid, tile types, collision queries
│   │   └── Tile.hpp                 # simple struct/enum
│   └── ai/
│       ├── Pathfinder.hpp / .cpp    # your Dijkstra implementation
│       └── Graph.hpp / .cpp         # adjacency representation of the maze
```

## Credits:

- Project structure/architecture - [claude](https://claude.ai)
- Colored terminal output - [agauniyal/rang](https://github.com/agauniyal/rang)
- 2D Graphics Library - [SFML 3.0.2](https://www.sfml-dev.org/)
- "Fix your timestep" by Glenn Fiedler - [article](https://gafferongames.com/post/fix_your_timestep/#:~:text=a%20temporary%20spike.-,Free%20the%20physics,-Now%20let%E2%80%99s%20take)
- BlockBlueprint font by HipFonts - [1001fonts.com](https://www.1001fonts.com/blockblueprint-font.html)
