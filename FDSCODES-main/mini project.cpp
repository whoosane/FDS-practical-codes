/*Name: Husain Siamwala
Class : SE2
Roll number : 76
PRN : F24122001*/

#include <iostream>
#include <vector>

using namespace std;

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int checkwin();
void board();

int main() {
    int player = 1, i, choice;
    char mark;

    do {
        board();
        player = (player % 2) ? 1 : 2;

        cout << "Player " << player << ", enter a number: ";
        cin >> choice;

        mark = (player == 1) ? 'X' : 'O';

        if (choice >= 1 && choice <= 9 && square[choice] == '0' + choice) {
            square[choice] = mark;
        } else {
            cout << "Invalid move" << endl;
            player--;  // Decrement player to repeat turn
            cin.ignore(); // Pause for user input
            cin.get();
        }

        i = checkwin();
        player++;
    } while (i == -1);

    board();

    if (i == 1) {
        cout << "==> Player " << --player << " wins!" << endl;
    } else {
        cout << "==> Game draw!" << endl;
    }

    cin.ignore(); // Wait for user input before exiting
    cin.get();
    return 0;
}

int checkwin() {
    // Check winning conditions
    if (square[1] == square[2] && square[2] == square[3]) return 1;
    if (square[4] == square[5] && square[5] == square[6]) return 1;
    if (square[7] == square[8] && square[8] == square[9]) return 1;
    if (square[1] == square[4] && square[4] == square[7]) return 1;
    if (square[2] == square[5] && square[5] == square[8]) return 1;
    if (square[3] == square[6] && square[6] == square[9]) return 1;
    if (square[1] == square[5] && square[5] == square[9]) return 1;
    if (square[3] == square[5] && square[5] == square[7]) return 1;

    // Check for draw
    if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' &&
        square[7] != '7' && square[8] != '8' && square[9] != '9') {
        return 0;
    }

    return -1;
}

void board() {
    cout << "\n\n\tTic Tac Toe\n\n";
    cout << "Player 1 (X)  -  Player 2 (O)\n\n\n";

    cout << "     |     |     \n";
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << " \n";
    cout << "||_\n";
    cout << "     |     |     \n";
    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << " \n";
    cout << "||_\n";
    cout << "     |     |     \n";
    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << " \n";
    cout << "     |     |     \n\n";
}