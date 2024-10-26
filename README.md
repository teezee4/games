# Games
- Hokeemon Game
- Monopoly Simulaton
- Rock-Paper-Scissors Game
  
# Hokeemon Game

Welcome to **Hokeemon Game**, created by **Taha Zeeshan**. This project is a C++ console-based game where players can create and manage virtual creatures called Hokeemon. Each Hokeemon has unique attributes, such as species, element, and technique, and requires regular care to prevent it from starving or becoming overly bored.

## Table of Contents
- [Features](#features)
- [Game Rules](#game-rules)
- [Getting Started](#getting-started)
- [Class Structure](#class-structure)
- [Gameplay Functions](#gameplay-functions)
- [Credits](#credits)

## Features
- Create and manage up to 10 unique Hokeemon creatures.
- Hokeemons have specific stats, including `hunger` and `boredom`.
- Choose unique elements, techniques, and species for each Hokeemon.
- Play with and feed Hokeemon to maintain their stats.
- Combine two Hokeemon to create a new, unique Hokeemon with blended attributes.

## Game Rules
1. **Care for Hokeemon:** Each Hokeemon has `hunger` and `boredom` levels that need management.
2. **Playing and Feeding:** Decrease boredom and increase hunger by choosing appropriate actions.
3. **Survival Requirements:** Boredom should be under 20, and hunger should not fall below 0 to keep Hokeemon alive.
4. **Turn Mechanics:** Each turn, boredom increases by 1, and hunger decreases by 1.

## Getting Started
1. **Compile and Run**: Compile `hokeemon.cpp` using a C++ compiler (e.g., g++) and run the executable.
    ```bash
    g++ hokeemon.cpp -o hokeemon
    ./hokeemon
    ```
2. **Gameplay Menu**:
    - Choose to create, view, play with, or merge Hokeemons.
    - Follow prompts to interact with Hokeemon and manage their stats.

## Class Structure

- **creature** (abstract base class): Defines the core Hokeemon properties and pure virtual functions for `returnHunger` and `returnBore`.
- **mon** (child class of creature): Implements creature attributes, including stats management and interaction methods (`feed`, `play`, `listen`, etc.).
- **mon2** (second child class): Provides an example of subclassing, with a copy constructor for potential extensions.

## Gameplay Functions
- **greeting**: Displays the game introduction.
- **start**: Main menu for creating, viewing, playing with, or merging Hokeemons.
- **menu**: Interaction menu for feeding, playing, or quitting with a Hokeemon.
- **validInput**: Ensures correct user input for menu options.
- **passTime, play, feed**: Adjust Hokeemon's `hunger` and `boredom` stats.
- **displayTypes, displayAll**: Show Hokeemon types and full details.
- **testMethod**: Runs internal tests for checking functionality of class methods.

## Credits
Created by **Taha Zeeshan**. This project is an interactive game designed to showcase class structures, inheritance, operator overloading, and input validation in C++.

# Monopoly Simulation

Welcome to the **Monopoly Simulation**, crafted by **Taha Zeeshan**. This program is a lively, randomized simulation of the classic game, tracking how often each board position is landed on over an impressive 10,000 turns. With vibrant randomness and an intricate setup, this simulation provides insight into the frequency of different positions—like "Go" and "Jail"—creating a wonderfully rich picture of the game’s mechanics.

## Features
- **Randomized Rolls and Cards**: Every turn, a virtual dice roll and card draw replicate the core random elements of Monopoly.
- **Position Tracking**: The program tracks how often each space on the Monopoly board is landed on, providing fascinating insights into game statistics.
- **Special Action Handling**: Certain spaces like Chance, Community Chest, and Jail are uniquely handled to mimic real game mechanics.

## Simulation Rules
1. **Board Setup**: The simulation board has 40 spaces, with key spots like "Go," "Chance," "Community Chest," and "Jail" identified.
2. **Movement and Landing**: Every turn rolls the dice and advances the position, looping around once it surpasses the board limit.
3. **Special Spaces**: Chance and Community Chest cards can move the player forward, backward, or to specific spaces.
4. **Jail Rules**: The Jail spot adds a twist—some cards send the player here, while others offer an “out of jail free” effect.

## Getting Started
To dive right into this energetic simulation:
1. **Compile and Run**: Compile `monopolySimulation.cpp` with your favorite C++ compiler and run the executable.
    ```bash
    g++ monopolySimulation.cpp -o monopolySimulation
    ./monopolySimulation
    ```
2. **Observe the Results**: Watch as the program tracks each landing, then displays how often each spot was landed on, showing the frequency of positions that were reached during the simulation.

## Code Structure
The code is simple yet effective, using core structures and functions to manage the board and simulate player movement:
- **`struct spots`**: Defines each board space with a number and name.
- **Arrays and Counters**: Arrays like `board` and `landCount` help track board positions and landing frequencies.

## Core Functions
- **`roll`**: Rolls the dice, generating a random number between 1 and 6.
- **`cards`**: Randomly selects a card, potentially causing special movement effects.
- **Main Loop**: This lively loop simulates 10,000 rounds of gameplay, updating positions and counting landings for each space.

## Credits
By **Taha Zeeshan**. This project captures the charm of Monopoly while beautifully demonstrating the power of randomization, struct arrays, and functions in C++.

# Rock-Paper-Scissors Game

Welcome to the **Rock-Paper-Scissors Game**, brought to you by **Taha Zeeshan**! This classic game, implemented in C++, allows you to play multiple rounds against the computer, tracking wins, losses, and draws until you decide to quit. Enjoy competing with the computer and see if you can outwit its random choices!

## Features
- **User Choice Menu**: Select between Rock, Paper, Scissors, or Quit to end the game.
- **Randomized Computer Opponent**: The computer's choice is randomized for every round.
- **Score Tracking**: The game keeps count of your wins, the computer’s wins, and draws.
- **User-Friendly Error Handling**: Prompts the player for valid inputs if needed.

## How to Play
1. Choose one of the options:
   - **1** for Rock
   - **2** for Paper
   - **3** for Scissors
   - **4** to Quit and display the game statistics.
2. The computer will randomly select its choice, and the result of the round will be displayed.
3. The game keeps going until you choose to quit. At that point, your win count, the computer's win count, and the total number of draws will be displayed.

## Getting Started
To play this game:
1. **Compile and Run**: Compile the code using a C++ compiler and run the executable.
   ```bash
   g++ RockPaperScissors.cpp -o RockPaperScissors
   ./RockPaperScissors



