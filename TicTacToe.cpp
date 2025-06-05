#include <iostream>
#include <vector>
#include <limits>

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;
    bool gameActive;
    int scoreX;
    int scoreO;
    int scoreTie;

    // Clear the input buffer
    void clearInputBuffer() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

public:
    // Constructor
    TicTacToe() {
        initGame();
        scoreX = 0;
        scoreO = 0;
        scoreTie = 0;
    }

    // Initialize the game board
    void initGame() {
        // Initialize the board with empty spaces
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
        currentPlayer = 'X';  // X starts the game
        gameActive = true;
    }

    // Display the current game board
    void displayBoard() {
        std::cout << "\n";
        std::cout << "  1   2   3 " << std::endl;
        std::cout << "-------------" << std::endl;
        
        for (int i = 0; i < 3; i++) {
            std::cout << i + 1 << "| ";
            for (int j = 0; j < 3; j++) {
                std::cout << board[i][j] << " | ";
            }
            std::cout << std::endl;
            std::cout << "-------------" << std::endl;
        }
        std::cout << std::endl;
    }

    // Display the current scores
    void displayScores() {
        std::cout << "\n===== SCORES =====\n";
        std::cout << "Player X: " << scoreX << std::endl;
        std::cout << "Player O: " << scoreO << std::endl;
        std::cout << "Ties    : " << scoreTie << std::endl;
        std::cout << "=================\n\n";
    }

    // Check if a player has won
    bool checkWin() {
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                return true;
            }
        }
        
        // Check columns
        for (int j = 0; j < 3; j++) {
            if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
                return true;
            }
        }
        
        // Check diagonals
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return true;
        }
        
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return true;
        }
        
        return false;
    }

    // Check if the game is a draw
    bool checkDraw() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    return false;  // Still empty cells, not a draw
                }
            }
        }
        return true;  // All cells filled, it's a draw
    }

    // Switch to the next player
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Make a move on the board
    bool makeMove(int row, int col) {
        // Adjust for 0-based indexing
        row--;
        col--;
        
        // Check if the move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            return false;
        }
        
        // Make the move
        board[row][col] = currentPlayer;
        return true;
    }

    // Play a single round of the game
    void playRound() {
        int row, col;
        bool validMove = false;
        
        std::cout << "Player " << currentPlayer << "'s turn." << std::endl;
        
        // Keep asking until we get a valid move
        while (!validMove) {
            std::cout << "Enter row (1-3): ";
            if (!(std::cin >> row)) {
                std::cout << "Invalid input. Please enter a number between 1 and 3." << std::endl;
                clearInputBuffer();
                continue;
            }
            
            std::cout << "Enter column (1-3): ";
            if (!(std::cin >> col)) {
                std::cout << "Invalid input. Please enter a number between 1 and 3." << std::endl;
                clearInputBuffer();
                continue;
            }
            
            validMove = makeMove(row, col);
            
            if (!validMove) {
                std::cout << "Invalid move! The cell is either occupied or out of bounds. Try again." << std::endl;
            }
        }
        
        displayBoard();
        
        // Check if the game is over
        if (checkWin()) {
            std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            
            // Update scores
            if (currentPlayer == 'X') {
                scoreX++;
            } else {
                scoreO++;
            }
            
            gameActive = false;
        } else if (checkDraw()) {
            std::cout << "Game ended in a draw!" << std::endl;
            scoreTie++;
            gameActive = false;
        } else {
            switchPlayer();
        }
    }

    // Play the game
    void playGame() {
        char playAgain = 'y';
        
        while (playAgain == 'y' || playAgain == 'Y') {
            initGame();
            displayBoard();
            
            // Game loop
            while (gameActive) {
                playRound();
            }
            
            displayScores();
            
            std::cout << "Do you want to play again? (y/n): ";
            std::cin >> playAgain;
            
            // Clear input buffer
            clearInputBuffer();
        }
        
        std::cout << "Thanks for playing!" << std::endl;
    }

    // Reset all scores
    void resetScores() {
        scoreX = 0;
        scoreO = 0;
        scoreTie = 0;
        std::cout << "All scores have been reset." << std::endl;
    }

    // Main menu
    void showMenu() {
        int choice;
        bool exit = false;
        
        while (!exit) {
            std::cout << "\n===== TIC TAC TOE =====\n";
            std::cout << "1. Play Game\n";
            std::cout << "2. View Scores\n";
            std::cout << "3. Reset Scores\n";
            std::cout << "4. Exit\n";
            std::cout << "Enter your choice (1-4): ";
            
            if (!(std::cin >> choice)) {
                std::cout << "Invalid input. Please enter a number between 1 and 4." << std::endl;
                clearInputBuffer();
                continue;
            }
            
            switch (choice) {
                case 1:
                    playGame();
                    break;
                case 2:
                    displayScores();
                    break;
                case 3:
                    resetScores();
                    break;
                case 4:
                    exit = true;
                    std::cout << "Goodbye!" << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }
    }
};

int main() {
    TicTacToe game;
    std::cout << "Welcome to Tic Tac Toe!" << std::endl;
    game.showMenu();
    
    return 0;
}
