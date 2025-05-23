<div align="center">

  ![so_longm](https://github.com/user-attachments/assets/a8187f5e-2390-46cb-82ab-8dd657606145)
</div>


# So_long

Welcome to **so_long**, a project developed as part of the 42 curriculum. This project is an introduction to basic graphical programming in C, using a simple 2D game as a fun learning opportunity.


## Overview

The **so_long** project is a small 2D game where the player must navigate through a map, collect all collectibles, and reach the exit. The game is built using the MiniLibX graphical library, which is provided by 42.

<div align="center">
  
| Grade                                                             | Evaluation Information           |
| :---------------------------------------------------------------- | :------------------------------- |
| <img src="https://img.shields.io/badge/124%20%2F%20100%20%E2%98%85-sucess"/>  | `3 peers` `30 mins`  |
</div>

---

## Features

- 2D grid-based movement
- Collectibles and exit points
- Basic enemy/bonus support (if implemented)
- Input handling (keyboard)
- Custom map loading and validation
- Simple graphics using MiniLibX

---

## How to Play

1. Start the game with a map file as an argument.
2. Move the player using the keyboard (default: W/A/S/D).
3. Collect all the collectibles ('C') on the map.
4. Head to the exit ('E') to finish the level.
5. Avoid enemies if the bonus is implemented.

---

## Installation

### Prerequisites

- GCC (or another C compiler)
- Make
- MiniLibX library (usually provided in the project or can be installed)
- A Unix-like system (Linux, macOS)

### Clone the Repository

```
git clone https://github.com/DanielFonsecaa/So-long-42.git
cd So-long-42
```
Build the Project

    make

To make bonus part

    make bonus

Usage

To start the game, run:

    ./so_long maps/map2.ber

Replace maps/map.ber with the path to your map file.

Map Format

Maps must be rectangular and use the following characters:

    1 - Wall
    0 - Empty space
    P - Player start position (only one)
    C - Collectible
    E - Exit
    (Optional) X - Enemy (for bonus)

Example map file (map.ber):
  
    111111
    1P0C01
    100001
    1C0E11
    111111

All maps are validated at launch. Invalid maps will display an error and exit.

Project Structure

    
    ├── src/           # Main source files
    ├── src_bonus/     # Bonus source files
    ├── maps/          # Sample map files
    ├── textures       # Images I used
    ├── Makefile
    ├── README.md
    └── ...

Bonus Features

If you implemented the bonus part, you may also have:

Animation for the player and enemies
Move counter display

Screenshots

![Screenshot from 2025-05-23 16-43-11](https://github.com/user-attachments/assets/c5f10c6d-80fb-42d6-be4f-61e9776442b6)
![Screenshot from 2025-05-23 16-43-29](https://github.com/user-attachments/assets/4170371d-1950-484b-b993-97db8f46eb82)
![Screenshot from 2025-05-23 16-43-42](https://github.com/user-attachments/assets/601c082f-bd2c-4ca7-9572-6339d155742c)
![Screenshot from 2025-05-23 16-46-51](https://github.com/user-attachments/assets/dd091a73-3e7d-4121-acde-722f099531d5)
