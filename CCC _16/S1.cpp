#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, int> freq;
    string s; cin >> s;
    for (char i : s) {
        if (freq[i] == NULL) freq[i]=1;
        else freq[i] += 1;
    }
    string s2; cin >> s2;
    int starcount = 0;
    for (auto i : s2) {
        if (i == '*') starcount += 1;
        else if (freq[i] == NULL) {cout << "N"; return 0;}
        else freq[i]--;
    }
    for (char i = 'a'; i <= 'z'; i ++) {
        if (freq[i] != NULL) starcount -= freq[i];
    }
    if (starcount == 0) cout << "A"; else cout << "N";
}