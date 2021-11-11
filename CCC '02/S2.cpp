#include <bits/stdc++.h>
using namespace std;

int vectorproduct(vector<int> v) {
    int total = 1;
    for (auto i : v) {
        total *= i;
    }
    return total;
}
vector<int> primefactors(int n){
    vector<int> lis = {};
    if (n > 1){
        for (int i = 2; i <=n; i++) {
            if (n%i == 0) {
                lis.push_back(i);
                vector<int> temp = primefactors(n / i);
                lis.insert(lis.end(), temp.begin(), temp.end());
                break;
            }
        }
    }
    return lis ;
}

int main() {
    int n, d; cin >> n >> d;
    int w = 0;
    if (n >= d) {
        w = n/d;
        n = n%d;
    }
    if (n == 0) {
        cout << w << '\n';
        return 0;
    }
    auto a = primefactors(n);
    auto b = primefactors(d);

    for (auto & i : a) {
        auto bruh = find(b.begin(), b.end(), i);
        if (bruh != b.end()) {
            i = 1;
            b.erase(bruh);
        }
    }
    n = vectorproduct(a);
    d = vectorproduct(b);
    if (w != 0) cout << w << ' ';
    cout << n << '/' << d << '\n';
}