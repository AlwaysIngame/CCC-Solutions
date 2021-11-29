#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define pb push_back
#define mp make_pair
#define forrange(x) for (long long i = 0; i < x; i++)
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
ull MOD = pow(10,9)+7;

template<typename T> void printList(std::initializer_list<T> text) {
    for_each(text.begin(), text.end(), [](auto x){cout << x << ' ';});
    cout << nl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c,r; cin >> c >> r;
    int x = 0, y = 0;
    while (true) {
        int a, b; cin >> a >> b;
        if (a == 0 and b == 0) break;
        x += a; y += b;
        x = min(c, x); y = min(r,y);
        x = max(0,x); y = max(0,y);
        cout << x << ' ' << y << nl;
    }
}