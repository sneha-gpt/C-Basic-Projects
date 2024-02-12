#include <iostream>
#include <vector>

using namespace std;

void display_board(const vector<vector<char>>& board) {
    cout << "|---|---|---|" << endl;
    cout << "| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " |" << endl;
    cout << "|---|---|---|" << endl;
    cout << "| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " |" << endl;
    cout << "|---|---|---|" << endl;
    cout << "| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " |" << endl;
    cout << "|---|---|---|" << endl;
}

bool check_win(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

bool check_draw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void reset_board(vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
    }
}

int main() {
    char play_again;
    cout << "--------TIC-TAC-TOE---------" << endl;
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char player1 = 'X';

 do{
    do {
        display_board(board);

        cout << "Player " << player1 << " Enter your move (row and column) : ";
        int row, col;
        cin >> row >> col;

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid Move!!! Try Again....." << endl;
            continue;
        }

        board[row - 1][col - 1] = player1;

        if (check_win(board, player1)) {
            display_board(board);
            cout << "Player " << player1 << " wins!!!" << endl;
            break;
        } 
        else if (check_draw(board)) {
            display_board(board);
            cout << "It's a Draw!!!" << endl;
            break;
        }

        player1 = (player1 == 'X') ? 'O' : 'X';
     }while (true);
    
     cout << "Do you want to play again ? (y/n) : ";
     cin >> play_again;
     reset_board(board);
   }while(play_again == 'y' || play_again =='Y');
      return 0;
}
