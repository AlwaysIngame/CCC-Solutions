#include <iostream>

using namespace std;

int main() {
    int player = 1;
    while (player != 100) {
        int move;
        cin >> move;
        if (move == 0) {
            cout <<"You Quit!\n";
            break;
        } else if (player+move <= 100) {
            player += move;
        }
        switch (player) {
            case 54:
                player = 19;
                break;
            case 90:
                player = 48;
                break;
            case 99:
                player = 77;
                break;
            case 9:
                player = 34;
                break;
            case 40:
                player = 64;
                break;
            case 67:
                player = 86;
                break;
            default:
                break;
        }
        cout << "You are now on square " << player << "\n";
    }
    if (player == 100) cout << "You Win!\n";
}