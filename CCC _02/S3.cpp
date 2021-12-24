#include <bits/stdc++.h>
using namespace std;

int main () {
    int r; int c; cin >> r >> c;
    char board[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
        }
    }
    int nmoves; cin >> nmoves;
    char moves[nmoves+1];
    for (int i = 0; i < nmoves; i++) {
        cin >> moves[i];
    }
    moves[nmoves] = 'Q';
    
    for (int row = 0; row < r; row++) {
        for (int col = 0; col < c; col++) {
            if (board[row][col] == 'X') continue;
            char facing[] = {'U', 'D', 'L', 'R'};
            for (int face = 0; face < 4; face++) {
                int posX = col;
                int posY = row;
                for (auto move : moves) {
                    if (move == 'F') {
                        if (facing[face] == 'U') posY--;
                        if (facing[face] == 'D') posY++;
                        if (facing[face] == 'L') posX--;
                        if (facing[face] == 'R') posX++;
                    }
                    else if (move == 'R') {
                        if (facing[face] == 'D') facing[face] = 'L';
                        else if (facing[face] == 'L') facing[face] = 'U';
                        else if (facing[face] == 'U') facing[face] = 'R';
                        else if (facing[face] == 'R') facing[face] = 'D';
                    }
                    else if (move == 'L') {
                        if (facing[face] == 'D') facing[face] = 'R';
                        else if (facing[face] == 'L') facing[face] = 'D';
                        else if (facing[face] == 'U') facing[face] = 'L';
                        else if (facing[face] == 'R') facing[face] = 'U';
                    }
                    if (posY >= r or posX < 0 or posX >= c or posY < 0) {
                        break;
                    }
                    if (board[posY][posX] == 'X') break;
                    if (move == 'Q') {
                        if (board[posY][posX] == '.') board[posY][posX] = '*';
                    }
                }
            }
        }
    }
    for (int i = 0; i < r; i ++) {
        for (int j = 0; j < c; j++) cout << board[i][j];
        cout << '\n';
    }
}