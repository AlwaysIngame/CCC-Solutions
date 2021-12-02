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
    string mom, dad; cin >> mom >> dad;
    int n; cin >> n;
    forrange(n) {
        string baby; cin >> baby;
        bool ok = true;
        for (auto x : baby) {
            if (islower(x)) {
                if (find(mom.begin(), mom.end(), x) != mom.end() and find(dad.begin(), dad.end(), x) != dad.end()); else ok = false;
            }
            else if (isupper(x)) {
                if (find(mom.begin(), mom.end(), x) != mom.end() or find(dad.begin(), dad.end(), x) != dad.end()); else ok = false;
            }
            if (not ok) break;
        }
        if (!ok) cout << "Not their baby!";
        else cout << "Possible baby.";
        cout << nl;
    }
}