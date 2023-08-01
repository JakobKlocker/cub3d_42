# Cub3D

Cub3D is a 42-school project inspired by the famous game Wolfenstein 3D, developed using the C programming language and the [MinilibX](https://github.com/42Paris/minilibx-linux) library. The goal of this project is to create a simple 3D game engine capable of rendering a maze-like world and implementing basic raycasting techniques to simulate 3D visuals.

## Table of Contents

- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [Features](#features)

## Getting Started

### Prerequisites

Before running Cub3D, you need to ensure that you have the following installed on your system:

- C Compiler (gcc, clang, etc.)
- Make

### Installation

1. Clone the repository:

```bash
git clone https://github.com/jklocker/cub3d_42.git
cd cub3d_42
```
compile the project with 
```bash
make
```

## Usage

After successfully compiling the project, you can run Cub3D using the following command:


./cub3D path_to_map.cub

The path_to_map.cub argument is the configuration file for the game, specifying the layout of the world and various options. The map file should adhere to the defined format.

## Controls

- **W**/**A**/**S**/**D**: Move the player forward, left, backward, or right, respectively.
- **←**/**→**: Rotate the camera left or right.
- **ESC**: Exit the game.

## Features

- [x] 3D Raycasting
- [x] Textured walls
- [x] Sprite rendering
- [x] Map parsing from file
- [x] Player movement and rotation
- [x] Configurable settings via `.cub` files
