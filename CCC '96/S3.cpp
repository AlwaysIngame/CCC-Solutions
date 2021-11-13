#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k, string str = "") {
    int count1 = count(str.begin(), str.end(), '1');
    if (str.length() == n) {
        if (count1 == k) cout << str << '\n';
        return;
    }
    if (count1 < k) {
        str.push_back('1'); solve(n,k,str);
        str.pop_back();
    }
    str.push_back('0');
    solve(n,k,str);
}

int main() {
    int _; cin >> _;
    for (int i = 0; i < _; i++) {
        int n, k; cin >> n >> k;
        cout << "The bit patterns are\n";
        solve(n,k);
        cout << '\n';
    }
}