#include <bits/stdc++.h>
using namespace std;
int main() {
    // Stupid solution
    string cards = "";
    int score = 0;
    char current = 'C';
    cout << "Cards Dealt       Points\n";
    int total = 0;
    for (int i = 0; i < 18; i++) {
        char x; 
        if (i != 17) cin >> x;
        else x = 'D';
        if (x== 'C') continue;
        if (x == 'H' or x == 'D' or x == 'S') {
            switch (current)
            {
            case ' ':
                break;
            case 'C':
                cout << "Clubs ";
                break;
            case 'H':
                cout << "Hearts ";
                break;
            case 'D':
                cout << "Diamonds ";
                break;
            case 'S':
                cout << "Spades ";
                break;
            default:
                break;
            }
            for (auto i : cards) {
                switch (i)
                {
                case 'A':
                    score += 4;
                    break;
                case 'K':
                    score += 3;
                    break;
                case 'Q':
                    score += 2;
                    break;
                case 'J':
                    score += 1;
                    break;
                default:
                    break;
                }
                cout << i << ' ';
            }
            if (cards.size() <= 2) score += 3-cards.size();
            cards = "";
            total += score;
            cout << score;
            score = 0;
            current = x;
            cout << "\n";
        } else {
            cards.push_back(x);
        }
    }
    cout << "               Total " << total; 
}