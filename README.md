# Ludo-Game

# Overview
Welcome to the Ludo Game Project! This project is an implementation of the classic board game Ludo using *Object-Oriented Programming (OOP)* principles and the *Simple and Fast Multimedia Library (SFML)* for graphical rendering. The project is designed to provide an engaging and interactive experience, making use of advanced C++ programming techniques. This project aims to replicate the fun and excitement of Ludo in a digital format. It uses OOP concepts to model the game entities and SFML to handle graphics and user interaction.

# Features
- **Multiplayer Support**: Play with upto 4 players.
- **Graphical User Interface**: Visually appealing game board and pieces rendered using SFML.
- **Dice Rolling Simulation**: Realistic dice rolling with random number generation.
- **Piece Movement**: Intuitive piece movement based on dice rolls and game rules.
- **Collision Detection**: Handles interactions between pieces, including sending opponent pieces back to start.
- **Winning Condition**: Detects and announces when a player wins the game.
- **Modular Codebase**: Easily extendable and maintainable code using OOP principles.
- **Event Handling**: User interactions such as dice rolls and piece movement handled smoothly.

# Project Structure
The project consists of several C++ source and header files, each encapsulating different aspects of the game:
- Blue.cpp, Blue.h
- Board.cpp, Board.h
- Dice.cpp, Dice.h
- Green.cpp, Green.h
- Ludo_game.cpp, Ludo_game.h
- Ludo_Project.cpp
- Piece.cpp, Piece.h
- Player.h, Player.cpp
- Red.cpp, Red.h
- Team.cpp, Team.h
- Utility.cpp, Utility.h
- Yellow.cpp, Yellow.h

# Class Descriptions
## Blue, Green, Red, Yellow
Represents the respective colour team in the game, managing the specific behavior and properties of their pieces.

## Dice
Simulates the rolling of a dice, generating random numbers between 1 and 6.

## Piece
Represents a game piece, encapsulating its position, movement, and interaction with other pieces.

## Board
Handles the game board's layout, including the positions of the paths, home, and finish areas.

## Player
An abstract class that represents a player in the game. Specific player behaviors are implemented in derived classes. Manages multiple players, handling turn-taking and interactions between players.

## Team
Encapsulates a team of pieces, managing their collective behavior and interactions on the board.

## Utility
Contains helper functions and utilities used throughout the project.

## Ludo_game
The core class that manages the overall game logic, including player turns, game state, and win conditions.

# Usage of OOP
This project leverages Object-Oriented Programming to create a modular and maintainable codebase. Key OOP principles used include:

- **Encapsulation**: Each class encapsulates its data and methods, providing a clear interface and reducing dependencies between classes.
- **Inheritance**: Common behaviors are abstracted into base classes (Player), with specific behaviors implemented in derived classes (Blue, Red, Green, Yellow).
- **Polymorphism**: Through the use of virtual functions, the project allows for dynamic method binding, enabling different player types to interact seamlessly.
- **Abstraction**: Complex game logic is broken down into simpler, manageable components, each responsible for a specific part of the game.

# Integration with SFML
The project uses SFML (Simple and Fast Multimedia Library) to handle graphical rendering and user interaction. SFML provides the tools to create a visually appealing and responsive user interface, including:
- **Graphics**: Rendering the game board, pieces, and other visual elements.
- **Events**: Handling user input such as mouse clicks and keyboard presses.
- **Audio**: (Optional) Adding sound effects to enhance the gaming experience.
By integrating SFML, the project achieves a smooth and interactive gameplay experience, bringing the classic board game to life on the screen.

# How to Run
1. **Install SFML**: Make sure SFML is installed on your system. You can download it from SFML's official website.
2. **Compile the Project**: Use a C++ compiler to compile the source files. Ensure you link against the SFML libraries during compilation.
3. **Run the Executable**: Execute the compiled program to start the game.

Enjoy playing Ludo on your computer!
This project showcases the power of C++ and SFML in creating a complex yet enjoyable game. By adhering to OOP principles, it ensures a clean and maintainable codebase, making it easy to extend and modify in the future.

# Author
- **Kainat Umar** - *Developer of this LUDO game using SFML and OOP principles.*
