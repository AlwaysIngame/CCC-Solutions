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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ts = 1;
    cin >> ts;
    forrange(ts) {
        int n; cin >> n;
        vector<string> input(n);
        forrange(n) {
            cin >> input[i];
        }
        input.insert(input.begin(), input.back());
        vector<string> depthlist;
        int maxdepth = 0;
        for (auto str : input) {
            if (depthlist.size() >= 2)
                if (*(depthlist.end()-2) == str) depthlist.pop_back();
                else depthlist.pb(str); 
            else depthlist.pb(str);
            maxdepth = max(maxdepth, int(depthlist.size()));
        }
        cout << n*10 - (maxdepth-1)*20 << nl;
    }
}