#include <bits/stdc++.h>
using namespace std;

int main() {
    int q; cin >> q;
    int n; cin >> n;
    vector<int> dmoj;
    vector<int> peg;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        dmoj.push_back(x);
    }
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        peg.push_back(x);
    }

    if (q == 1) {
        sort(dmoj.begin(), dmoj.end());
        sort(peg.begin(), peg.end());
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += max(dmoj[i], peg[i]);
        }
        cout << total;
    } else if (q == 2) {
        sort(dmoj.begin(), dmoj.end());
        sort(peg.rbegin(), peg.rend());
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += max(dmoj[i], peg[i]);
        }
        cout << total;
    }
}