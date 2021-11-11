#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c; cin >> r >> c;
    bool yard[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char obs; cin >> obs;
            if (obs == 'X') yard[i][j] = false;
            else if (obs == '.') yard[i][j] = true;
        }
    }
    int m; cin >> m;
    char moves[m+1];
    for (int i = 0; i < m; i ++) {
        cin >> moves[i];
    }
    moves[m] = 'D';

    vector<vector<int>> finalpos = {};
    for (int i = 0; i < r; i ++) {
        for (int j = 0; j < c; j++) {
            char facing[] = {'U', 'D', 'L', 'R'};
            if(!yard[i][j]) continue;
            for (char face : facing) {
                int col = j;
                int row = i;
                for (auto move : moves) {
                    cout << move << '\n';
                    if (row >= r or row < 0 or col >= c or col < 0) break;
                    if (!yard[row][col]) break;
                    if (move == 'F') {
                        if (face == 'U') row -= 1;
                        if (face == 'D') row += 1;
                        if (face == 'L') col -= 1;
                        if (face == 'R') col += 1;
                    } else if (move == 'L') {
                        if (face == 'U') face = 'L';
                        if (face == 'D') face = 'R';
                        if (face == 'L') face = 'U';
                        if (face == 'R') face = 'D';
                    } else if (move == 'R') {
                        if (face == 'U') face = 'R';
                        if (face == 'D') face = 'L';
                        if (face == 'L') face = 'D';
                        if (face == 'R') face = 'U';
                    }
                    else if (move == 'D'){
                        vector<int> bruhment = {row, col};
                        finalpos.push_back(bruhment);
                    }
                }
            }
        }
    }
    for (auto i : finalpos) cout << i[0] << i[1] << '\n';
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            vector<int> bruhment = {i, j};
            if (find(finalpos.begin(), finalpos.end(), bruhment) != finalpos.end()) {
                cout << '*';
            } else if (yard[i][j]) cout << '.';
            else cout << 'X';
        }
        cout <<'\n';
    }
}