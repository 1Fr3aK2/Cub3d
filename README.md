# 🎮 Cub3D

> A first-person 3D engine in C inspired by Wolfenstein 3D — built from scratch as part of the **42 School** curriculum.

![Language](https://img.shields.io/badge/language-C-blue?style=flat-square)
![School](https://img.shields.io/badge/school-42-black?style=flat-square)
![Graphics](https://img.shields.io/badge/graphics-MiniLibX-orange?style=flat-square)
![Norm](https://img.shields.io/badge/norminette-compliant-brightgreen?style=flat-square)

---

## 📖 About

**Cub3D** is a first-person 3D raycasting engine written in C, inspired by the iconic *Wolfenstein 3D*. The engine renders a navigable 3D world from a 2D map using the raycasting technique — casting rays from the player's point of view and calculating wall distances to simulate depth.

The project covers low-level graphics rendering, mathematical 3D projection, strict input validation, and robust memory management — all built without any game engine or high-level graphics library, using only MiniLibX.

---

## ✨ Features

### 🖥️ Rendering
- **Raycasting engine** — DDA (Digital Differential Analysis) algorithm for efficient wall detection
- **Textured walls** — each cardinal direction (N/S/E/W) rendered with its own texture
- **Floor and ceiling colours** — configurable RGB values per scene
- **Real-time rendering** — smooth frame-by-frame scene updates via MiniLibX

### 🗺️ Map Parsing & Validation
- **`.cub` file parser** — reads and validates scene description files
- **Map integrity checks** — detects unclosed maps, invalid characters, and missing player spawn
- **Boundary error detection** — prevents undefined behaviour from malformed map inputs
- **Strict input validation** — all file and map data validated before any rendering begins

### 🕹️ Player & Controls
- **Player movement** — move forward, backward, strafe left and right
- **Camera rotation** — look left and right
- **Keyboard hooks** — responsive real-time input handling via MiniLibX events

### 🧠 Memory Management
- Full cleanup on exit — no memory leaks
- Safe handling of all allocated resources across parsing, rendering, and shutdown

---

## 🗂️ Project Structure

```
Cub3D/
├── includes/
│   └── cub3d.h             # Main header — structs and prototypes
├── libraries/
│   ├── libft/              # Custom C library + get_next_line
│   └── minilibx-linux/     # MiniLibX graphics library
├── maps/                   # Sample .cub scene files
├── src/
│   ├── main.c              # Entry point
│   ├── errors/             # Error handling and messages
│   ├── init/               # Engine and struct initialisation
│   ├── hooks/              # Keyboard input and event hooks
│   ├── math/               # Raycasting math and DDA algorithm
│   ├── mlx/                # MiniLibX window and image setup
│   ├── parsing/
│   │   ├── file/           # .cub file validation
│   │   ├── map/            # Map parsing, validation, and initialisation
│   │   └── player/         # Player spawn detection and initialisation
│   ├── player/             # Player movement and rendering position
│   ├── render/             # Frame painting, colours, and render loop
│   ├── textures/           # Texture loading and assignment
│   └── utils/              # General utilities and memory cleanup
└── Makefile
```

---

## 🗺️ Map Format

Maps are defined in `.cub` scene description files. Example:

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

111111
100101
1000N1
1100011
```

| Element | Description |
|---------|-------------|
| `NO` `SO` `WE` `EA` | Paths to wall textures for each direction |
| `F` | Floor colour in RGB format |
| `C` | Ceiling colour in RGB format |
| `1` | Wall |
| `0` | Empty floor |
| `N` `S` `E` `W` | Player spawn position and facing direction |

> The map must be fully enclosed by walls (`1`). Any open boundary will be rejected at parse time.

---

## 🚀 Getting Started

### Prerequisites

**Ubuntu / Debian**

```bash
sudo apt update
sudo apt install -y gcc make libx11-dev libxext-dev
```

**macOS**

```bash
xcode-select --install
```

### Build

```bash
git clone https://github.com/1Fr3aK2/Cub3d.git
cd Cub3d
make
```

### Run

```bash
./cub3D maps/<map_file>.cub
```

Example:
```bash
./cub3D maps/map1.cub
```

---

## 🧹 Makefile Targets

| Target        | Description                              |
|---------------|------------------------------------------|
| `make`        | Build the project and all dependencies   |
| `make clean`  | Remove object files                      |
| `make fclean` | Remove object files and the executable   |
| `make re`     | Full rebuild (`fclean` + `all`)          |

---

## 🕹️ Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` | Rotate camera left |
| `→` | Rotate camera right |
| `ESC` | Exit the program |

---

## 🧠 Key Concepts

**Raycasting** — a rendering technique that simulates 3D perspective by casting rays from the player's viewpoint and calculating the distance to the nearest wall for each vertical column of pixels.

**DDA (Digital Differential Analysis)** — an efficient grid traversal algorithm used to determine which map cell a ray hits, avoiding costly floating-point operations per step.

**MiniLibX** — a minimal X11 graphics library provided by 42 School for pixel-level rendering, window management, and event handling.

---

## 👥 Authors

- **[1Fr3aK2](https://github.com/1Fr3aK2)**
- **[htrindad](https://github.com/htrindad)**
- Contributors visible in the [repository graph](https://github.com/1Fr3aK2/Cub3d/graphs/contributors)

---

## 📄 License

This project was developed for educational purposes at **42 School**. No explicit license has been applied — please refer to the school's academic integrity policy before reusing any code.

---

> *"Every wall is just a ray's end."*
