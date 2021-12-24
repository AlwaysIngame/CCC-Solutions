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
    int n; cin >> n;
    vi sw(n);
    vi sem(n);
    forrange(n) cin >> sw[i];
    forrange(n) cin >> sem[i];
    int a = accumulate(sw.begin(), sw.end(), 0), b = accumulate(sem.begin(), sem.end(), 0);
    if (a == b) {cout << n; return 0;}
    for (auto i = n-1; i >= 0; i--) {
        a-= sw[i]; b -= sem[i];
        if (a==b) {cout << i; return 0;}
    }
    cout << 0;
}