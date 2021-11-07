#include <bits/stdc++.h>
using namespace std;

int main() {
    char dir = 'D';
    int left = 1;
    int l = 1;
    int arr[50][50];
    memset(arr, 0, sizeof(arr));
    int w = 25; int h = 25;

    int x, y; cin >> x >> y;
    arr[h][w] = x;
    for (int i = x+1; i <= y; i++) {
        if (dir == 'D') {
            h += 1;
            arr[h][w] = i;
            left -=1;
            if (not left) {
                dir = 'R';
                left = l;
            }
        } else if (dir == 'R') {
            w += 1;
            arr[h][w] = i;
            left -=1;
            if (not left) {
                dir = 'U';
                l += 1;
                left = l;
            }
        } else if (dir == 'U') {
            h -= 1;
            arr[h][w] = i;
            left -=1;
            if (not left) {
                dir = 'L';
                left = l;
            }
        } else if (dir == 'L') {
            w -= 1;
            arr[h][w] = i;
            left -=1;
            if (not left) {
                dir = 'D';
                l += 1;
                left = l;
            }
        }
    }
    for (auto i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        for (int j = 0; j < sizeof(arr[i])/sizeof(arr[i][0]); j++) {
            if (arr[i][j] != 0) cout << arr[i][j] << " ";
        }
        if (find_if(begin(arr[i]), end(arr[i]), [](int p) {return p!=0;})!=end(arr[i])) cout << "\n";
    }
    return 0;
}