# Snake and Ladder Game

This repository contains a C++ implementation of the classic Snake and Ladder game. The game simulates a board with snakes and ladders, and allows multiple players to roll dice and move across the board. The goal is to reach exactly position 100 to win the game.

## Problem Statement

The game board has 100 cells numbered from 1 to 100. Players take turns to roll a six-sided dice and move forward by the rolled number of cells. The board also contains snakes and ladders that change the player's position when landed upon.

- **Snakes**: Moves the player down to a lower position.
- **Ladders**: Moves the player up to a higher position.

### Input

- Number of snakes, followed by head and tail positions of each snake.
- Number of ladders, followed by start and end positions of each ladder.
- Number of players, followed by the names of the players.

### Example Input
9 62 5 33 6 49 9 88 16 41 20 56 53 98 64 93 73 95 75 8 2 37 27 46 10 32 51 68 61 79 65 84 71 91 81 100 2 Gaurav Sagar

### sample Output
Gaurav rolled a 6 and moved from 0 to 6 Sagar rolled a 1 and moved from 0 to 1 ... Sagar wins the game!


## Game Rules

- Each player starts at position 0 (outside the board).
- Players take turns to roll a dice and move their piece forward.
- If a player lands on the head of a snake, they are moved down to the tail of the snake.
- If a player lands on the start of a ladder, they are moved up to the end of the ladder.
- The first player to reach exactly position 100 wins the game.
- If a player rolls a number that would move them beyond position 100, they do not move.

## Code Structure

- `Board`: Handles the board setup, including snakes and ladders.
- `Player`: Represents each player and manages their current position.
- `Game`: Manages the entire gameplay, including player turns and dice rolls.

## How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/ankitrajlogin/snake-and-ladder-game.git

## Future Enhancements
Support for two dice instead of one.
Handling additional game rules like consecutive 6s.
