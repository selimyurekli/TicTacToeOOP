// TicTacToe.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#define SIZE 3;
using namespace std;

class Game {
    
private: 
    char grid[3][3];
    
    void printGame() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                cout << char(this->grid[i][j]) << " ";
            cout << endl;
        }        
    }
    bool isSameRow(int row, int col) {
        if (row == 1) {

            if (grid[row][col] != '_' && grid[row][col] == grid[row + 1][col] && grid[row][col] == grid[row - 1][col]) {
                return true;
            }
        }
        else if (row == 0) {

            if (grid[row][col] != '_' && grid[row][col] == grid[row + 1][col] && grid[row][col] == grid[row + 2][col]) {
                return true;
            }
        }
        else {

            if (grid[row][col] != '_' && grid[row][col] == grid[row - 1][col] && grid[row][col] == grid[row - 2][col]) {
                return true;
            }
        }

        return false;
    }
    bool isSameCol(int row, int col) {

        if (col == 1) {

            if (grid[row][col] != '_' && grid[row][col] == grid[row][col + 1] && grid[row][col] == grid[row][col - 1]) {
                return true;
            }
        }
        else if (col == 0) {

            if (grid[row][col] != '_' && grid[row][col] == grid[row][col + 1] && grid[row][col] == grid[row][col + 2]) {
                return true;
            }
        }
        else {

            if (grid[row][col] != '_' && grid[row][col] == grid[row][col - 1] && grid[row][col] == grid[row][col - 2]) {
                return true;
            }
        }

        return false;
    }

    bool isSameDiag( int row, int col) {
        
            if (col == 1) {

                if (grid[row][col] != '_' && grid[row][col] == grid[row + 1][col + 1] && grid[row][col] == grid[row - 1][col - 1]) {
                    return true;
                }
                else if (grid[row][col] != '_' && grid[row][col] == grid[row + 1][col - 1] && grid[row][col] == grid[row - 1][col + 1]) {
                    return true;
                }
            }
            else if (col == 0) {

                if (this->grid[row][col] != '_' && this->grid[row][col] == this->grid[row + 1][col + 1] && this->grid[row][col] == this->grid[row + 2][col + 2]) {
                    return true;
                }
                else if (this->grid[row][col] != '_' && this->grid[row][col] == this->grid[row - 1][col + 1] && this->grid[row][col] == this->grid[row - 2][col + 2]) {
                    return true;
                }
               
            }
            else {

                if (this->grid[row][col] != '_' && this->grid[row][col] == this->grid[row - 1][col - 1] && this->grid[row][col] == this->grid[row - 2][col - 2]) {
                    return true;
                }
                else if (this->grid[row][col] != '_' && this->grid[row][col] == this->grid[row + 1][col - 1] && this->grid[row][col] == this->grid[row + 2][col - 2]) {
                    return true;
                }
            }
        


        return false;
    }

    bool isGameEnded() {

        bool isDraw = true;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (isSameRow( i, j) || isSameCol(i, j) || isSameDiag(i, j)) {
                    if (this->grid[i][j] == 'X') cout << "X is winner" << endl;
                    else if (this->grid[i][j] == 'O') cout << "O is winner" << endl;
                    return true;
                }
                else if(this->grid[i][j] == '_') isDraw = false;

            }

        }
        if (isDraw) {
            cout << "The game is ended in a draw!" << endl;
            return true;
        }
        return false;
    }
    bool isCharSuitable(char ch) {
        if (!(ch == 'O' || ch == 'X')) {
            cout << "Please enter only O or X" << endl;

            return false;
        }
        return true;
    }
    void changeGrid( bool& isX, int x, int y) {
        if (this->grid[y - 1][x - 1] == '_') {
            if (isX) this->grid[y - 1][x - 1] = 'X';
            else this->grid[y - 1][x - 1] = 'O';
            isX = !isX;
        }
        else {
            cout << "The gap is already filled" << endl;
        }
    }
    void printTurn(bool& isX) {
        if (isX) {
            cout << "Turn for X";

        }
        else {
            cout << "Turn for O";

        }
    }
    
    
 public:
    Game(int size) {
         for (int i = 0; i < 3; i++)
             for (int j = 0; j < 3; j++)
                 grid[i][j] = '_';


    };
    void startGame()
    {
        this->printGame();
        char ch;
        bool isX = true;
        int x, y;
        bool isDraw = false;
        while (!isGameEnded()) {
            cout << "--------------------" << endl;
            printGame();
            cout << endl;
            printTurn(isX);

            cout << endl << "X-Y ->";
            cin >> x >> y;
            if (x > 3 || y > 3) continue;
            changeGrid(isX, x, y);
            if (isDraw) break;
            cout << "--------------------" << endl << endl;

        }
        printGame();
        
        //getchar();
    }



};




int main()
{
    Game game(3);
    game.startGame();

    return 0;
}

