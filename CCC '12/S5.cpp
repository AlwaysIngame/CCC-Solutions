#include <bits/stdc++.h>
using namespace std;

class Square {
    public:
        bool cat;
        int paths;
        Square() {
            cat = false;
            paths = 0;
        }
};
int main () {
    int r, c; cin >> r >> c;
    int k;  cin >> k;
    Square cages[r][c];
    for (int i = 0; i <r; i ++) {
        for (int j = 0; j < c; j++) {
            cages[i][j] = Square();
        }
    }
    for (int i = 0; i < k; i++) {
        int kr, kc; cin >> kr >> kc;
        cages[kr-1][kc-1].cat = true;
    }

    for (int j = c-1; j >= 0; j--) {
        for (int i = r-1; i >= 0; i--) {
            if (j == c-1 and i == r-1) cages[i][j].paths = 1;
            else if (cages[i][j].cat == false) {
                if (i+1 != r) cages[i][j].paths += cages[i+1][j].paths;
                if (j+1 != c) cages[i][j].paths += cages[i][j+1].paths;
            }
        }
    }

    cout << cages[0][0].paths;
}