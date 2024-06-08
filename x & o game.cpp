#include <iostream>
#include <string>
using namespace std;

// Function to check if a player has won
bool checkWin(char array[3][3], char player) 
{
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (array[i][0] == player && array[i][1] == player && array[i][2] == player) 
        {
            return true;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (array[0][i] == player && array[1][i] == player && array[2][i] == player) 
        {
            return true;
        }
    }
    // Check diagonals
    if (array[0][0] == player && array[1][1] == player && array[2][2] == player)
     {
        return true;
    }
    if (array[0][2] == player && array[1][1] == player && array[2][0] == player) 
    {
        return true;
    }
    return false;
}

int main() {
    int row, col;
    char array[3][3] = 
    {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int turn = 0; // 0 for 'X', 1 for 'O'

    cout << "Initial 3x3 grid:" << endl;
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << "[" << array[i][j] << "]";
        }
        cout << endl;
    }

    for (int i = 0; i < 9; ++i) 
    {
        if (turn == 0) 
        {
            cout << "Enter the row (0-2) and column (0-2) to place an 'X': ";
        } else 
        {
            cout << "Enter the row (0-2) and column (0-2) to place an 'O': ";
        }

        cin >> row >> col;

        // Validate input
        if (row < 0 || row >= 3 || col < 0 || col >= 3) 
        {
            cout << "Invalid input. Please enter row and column values between 0 and 2." << endl;
            i--; // Retry the current turn
            continue;
        }

        if (array[row][col] != ' ') 
        {
            cout << "Cell already taken. Please choose another cell." << endl;
            i--; // Retry the current turn
            continue;
        }

        if (turn == 0) 
        {
            array[row][col] = 'X';
        } else
        {
            array[row][col] = 'O';
        }


        for (int i = 0; i < 3; ++i) 
        {
            for (int j = 0; j < 3; ++j) 
            {
                cout << "[" << array[i][j] << "]";
            }
            cout << endl;
        }

        // Check for win
        if (checkWin(array, 'X')) 
        {
            cout << "Player X wins!" << endl;
            break;
        }
        if (checkWin(array, 'O')) 
        {
            cout << "Player O wins!" << endl;
            break;
        }


        turn = 1 - turn; // Alternate turn between 0 and 1
    }

    if (!checkWin(array, 'X') && !checkWin(array, 'O')) 
    {
        cout << "It's a draw!" << endl;
    }

    return 0;
}
