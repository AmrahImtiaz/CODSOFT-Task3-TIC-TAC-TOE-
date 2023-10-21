#include <iostream>
#include <windows.h>
using namespace std;

char board[3][3] = { { '1', '2', '3' }, { '4', '5', '6' }, { '7', '8', '9' } };
char currentPlayer = 'X';



void Loadingscreen(){
	
	for(int i=1;i<=10;i++){
		cout<<"Loading"<<endl;
		cout<<"...";
		Sleep(10);
	}

}

void printBoard() {
    system("cls"); // Use "cls" on Windows
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------\n";
    }
    cout << endl;
}

bool placeMarker(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move. That place is already occupied. Try again." << endl;
        return false;
    }

    board[row][col] = currentPlayer;
    return true;
}

void changePlayer() {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}

int main() {
    int position;
    int moves = 0;
    
    system ("Color 65 ");
    
    printBoard();

    while (moves < 9) {
        cout << "Player " << currentPlayer << ", enter a position (1-9): ";
        cin >> position;

        if (position < 1 || position > 9) {
            cout << "Invalid input. Please enter a number between 1 and 9." << endl;
            continue;
        }

        if (placeMarker(position)) {
            moves++;
            printBoard();
            // Check for a win or a draw here
            // You can implement these checks to end the game
            changePlayer();
        }
    }

    cout << "It's a draw!" << endl;
    return 0;
}
