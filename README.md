# 🎮 Tic-Tac-Toe Game (C++)

A simple console-based Tic-Tac-Toe game developed using C++. This is a two-player game that runs in the terminal and checks for win/draw conditions in real time.

## 🔧 Technologies Used

- C++
- Object-Oriented Programming
- Console I/O

## 📌 Features

- Two-player turn-based gameplay
- Real-time win, draw, and invalid move detection
- Clear console UI with board updates after every move
- Structured using classes for better modularity

## 🧠 How It Works

- The game uses a 3x3 grid, represented as a character array.
- Players take turns entering their move (position 1–9).
- The game checks after every turn if a player has won or if the match is a draw.
- Invalid moves (already occupied cells or out-of-range inputs) are handled gracefully.

## 🖥️ How to Run

1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/tic-tac-toe-cpp.git
   cd tic-tac-toe-cpp

Example
Player 1 (X)  -  Player 2 (O)

     |     |
  X  |  O  |  X
_____|_____|_____
     |     |
  O  |  X  |  O
_____|_____|_____
     |     |
  X  |     |  
     |     |

📚 Future Enhancements
    Add AI opponent (single-player mode)
    Score tracking system
