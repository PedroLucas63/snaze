# Snaze 🐍

[![Download](https://img.shields.io/badge/Download-Latest%20Release-brightgreen)](https://github.com/PedroLucas63/snaze/releases)

Snaze is an automatic Snake game where you watch the snake navigate through various scenes without controlling its movements.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Game Controls](#game-controls)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Introduction 🚀

Snaze is a unique twist on the classic Snake game. Instead of playing the game manually, you can sit back and watch as the snake maneuvers through different scenes automatically. The game is driven by an intelligent player algorithm, making decisions on the snake's movements.

## Features 🌟

- **Automatic Gameplay:** The snake moves autonomously through the game scenes.
- **Multiple Scenes:** Explore different game scenes with varying challenges.
- **Player Types:** Choose between a random player or a greedy player for different gameplay styles.
- **Game State Monitoring:** Track the game state, including wins, losses, and current scenes.

## Getting Started 🛠️

To get started with Snaze, follow these steps:

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/PedroLucas63/snaze.git
   cd snaze
   ```

2. **Build the Project:**
   ```bash
   cmake -S . -B build
   cmake --build build
   ```

3. **Run the Game:**
   ```bash
   ./snaze -f 10 -l 3 -F 5 -p random levels/level1.txt
   ```

## Usage 🎮

Snaze accepts various command-line arguments for customization. Here's an example of running the game:

```bash
./snaze -f 10 -l 3 -F 5 -p greedy levels/level1.txt
```

- `-f`: Set the frames per second (FPS).
- `-l`: Set the number of lives.
- `-F`: Set the number of food items.
- `-p`: Choose the player type (`random` or `greedy`).
- `levels/level1.txt`: Specify the level file.

## Game Controls 🎮

As Snaze is an automatic game, there are no manual controls during gameplay. Simply run the game with your chosen settings, sit back, and enjoy watching the snake's automatic movements.

## Contributing 🤝

Contributions are welcome! If you have ideas for improvements or new features, feel free to open an issue or submit a pull request.

## License 📄

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact 📧

Made by ❤️ Pedro Lucas

Contact me at pedrolucas.jsrn@gmail.com.