# Abbott Chess

A C++ chess game playable on Linux either:
- Solo vs the computer (AI mode)
- Against another human over network (server/client)
- With a graphical interface (SDL2) or terminal-based

![Screenshot: Graphical Window](https://github.com/matthewJamesAbbott/Chess/blob/master/ChessWindow.png)
![Screenshot: Terminal View](https://github.com/matthewJamesAbbott/Chess/blob/bd3f1cef25c8cccd0c85fb408daf26480bd0f984/chess%20logo.png)

---

## Features

- **Playable against AI or another player**
- **Supports terminal and GUI with SDL2**
- **Network play:** Run as server and client to play across devices
- **Regulation chess moves, including:**
  - Castling
  - En passant
  - Pawn promotion
  - Move validation
  - Board state history and move undo/recall
- **Save and load games**
- **Unicode and bitmap chess pieces**
- **Simple user input interface** in CLI or window

---

## Getting Started

### Prerequisites

- Linux 64-bit (developed & tested)
- CMake (>=3.10 recommended)
- SDL2 development libraries (`libsdl2-dev`, `libsdl2-ttf-dev`)
- Standard C++ (tested with g++)

### Building

Clone the repository and build:

```bash
git clone https://github.com/matthewJamesAbbott/Chess.git
cd Chess
mkdir build
cd build
cmake ..
make
```

Binaries should appear in `build/`.

### Running

Run the main program for GUI, or use command-line options for other modes.

**Default GUI mode:**
```bash
./Chess
```
**Play vs AI (terminal):**
```bash
./Chess -ai
```
**Start as server:**
```bash
./Chess -s
```
**Connect as client:**
```bash
./Chess -c [IP_ADDRESS]
```
For CLI-only (no SDL dependency), you may use `mainCli.cpp` to build a reduced terminal binary.

### Controls

- Follow prompts to enter moves (e.g., number/letter for from/to squares)
- In GUI: click squares to move pieces
- Save/load/undo via menu or terminal options

### File Layout (Partial)

- `Engine.cpp`/`.h` - Core AI and decision tree logic for computer move selection
- `MoveCalculator.cpp`/`.h` - Generates & evaluates possible moves, checks chess rules
- `Game.cpp`/`.h` - Game state management, player setup, networking modes, move execution
- `Print.cpp`/`.h` - Display board in terminal or SDL window
- `main.cpp`, `mainCli.cpp` - Entry points for graphical and pure CLI variants
- `Board.*` and `MoveRecorder.*` - Board representation and move history (see inline documentation)
- `images/` - Piece bitmaps, etc.

---

## Notes on AI

The AI builds a decision tree of possible moves, rates possible captures, and selects the best-ranked move, with fallback if this puts it in check. It implements legal move logic, check/checkmate detection, and basic positional awareness.

---

## Known Issues

- Only tested on Linux x86_64, CMake builds.
- External assets (images/fonts) must be in expected relative paths.

---

## Authorship & License

> This code is © Matthew James Abbott.  
> Published for educational, learning and non-commercial personal use.
>
> **Redistribution, re-use, or commercial exploitation is prohibited without explicit permission.**   
> If you wish to modify or re-use components, contact me FIRST.

Please do not claim as your own or use for competitive coding submissions.  
If you have questions, contact me via GitHub.  

---

**Enjoy Abbott Chess!**
