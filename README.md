# Dungeon Explorer

Dungeon Explorer is a simple text-based game written in C++, where you play as a monk exploring a randomly generated dungeon. The game features two main components: a dungeon generation system that creates rooms with different types (empty, monster, and treasure), and an exploration component that allows the player to navigate through the dungeon, pray in empty rooms, and engage in turn-based combat with monsters.

## Features

- Random dungeon generation with different types of rooms
- Player-controlled monk with customizable name and description
- Turn-based combat system with attack and defend actions
- Exploration of connected rooms
- Praying in empty rooms to restore health

## Requirements

- A C++ compiler that supports C++17 or later
- Make (for Unix-based systems)

## Building and Running

1. Clone the repository or download the source code.
2. Navigate to the project directory.
3. Build the project using Make (for Unix-based systems):

This will compile the source files and create the `dungeon-explorer` executable.

4. Run the game:

5. Follow the on-screen instructions to create your monk and start exploring the dungeon.

## File Structure

- `include/`: Contains header files for the classes used in the game.
- `src/`: Contains the implementation files for the classes.
- `main.cpp`: Entry point of the program.

## Design and Implementation

The game is designed using an object-oriented approach and follows principles such as inheritance, polymorphism, and encapsulation. It utilizes various design patterns like Factory, Composite, and Observer to ensure a flexible and extensible architecture.

The game is divided into separate modules:

- `Room`: Represents different types of rooms (empty, monster, treasure).
- `Monster`: Represents different types of monsters (currently only Goblin).
- `Dungeon`: Handles the generation and structure of the dungeon.
- `Monk`: Represents the player-controlled character.
- `Game`: Manages the game loop, user input, and exploration.

Smart pointers (`std::unique_ptr`) are used for efficient memory management, and the code follows the RAII (Resource Acquisition Is Initialization) principle.

## Contributing

Contributions to the project are welcome. If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.
