#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string get_syllable(string l) {
    for (int i = l.length() - 1; i >= 0; i--) {
        if (l[i] == *"a" or l[i] == *"e" or l[i] == *"i" or l[i] == *"o" or l[i] == *"u" or l[i] == *" ") return l.substr(i, l.length()-i);
    }
    return l;
};
int main() {
    int n;
    cin >> n;
    cin >> ws;
    for (int i = 0; i < n; i++) {
        string syllables[4] = {"", "", "", ""};
        for (int j = 0; j < 4; j++) {
            string line;
            getline(cin, line);
            transform(line.begin(), line.end(), line.begin(), ::tolower);
            syllables[j] = get_syllable(line);
        }
        if (syllables[0] == syllables[1] and syllables[2] == syllables[3] and syllables[0] == syllables[3]) {
            cout << "perfect" << endl;
            continue;
        } else if (syllables[0] == syllables[1] and syllables[2] == syllables[3]) {
            cout << "even" <<endl;
        } else if (syllables[0] == syllables[2] and syllables[1] == syllables[3]) {
            cout << "cross" << endl;
            continue;
        } else if (syllables[0] == syllables[3] and syllables[1] == syllables[2]) {
            cout << "shell" << endl;
        } else {
            cout << "free" << endl;
        }
    }
}