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
    vvi boxes;
    forrange(n) {
        vi box(3);
        cin >> box[0] >> box[1] >> box[2];
        boxes.pb(box);
    }
    int m; cin >> m;
    forrange(m) {
        vi item(3);
        cin >> item[0] >> item[1] >> item[2];
        int minvol = INT_MAX;
        for (auto box : boxes){
            if (item[0] <= box[0] and item[1] <= box[1] and item[2] <= box[2]) minvol = min(minvol, box[0]*box[1]*box[2]);
            else if (item[0] <= box[0] and item[1] <= box[2] and item[2] <= box[1])minvol = min(minvol, box[0]*box[1]*box[2]);
            else if (item[0] <= box[1] and item[1] <= box[0] and item[2] <= box[2])minvol = min(minvol, box[0]*box[1]*box[2]);
            else if (item[0] <= box[1] and item[1] <= box[2] and item[2] <= box[0])minvol = min(minvol, box[0]*box[1]*box[2]);
            else if (item[0] <= box[2] and item[1] <= box[1] and item[2] <= box[0])minvol = min(minvol, box[0]*box[1]*box[2]);
            else if (item[0] <= box[2] and item[1] <= box[0] and item[2] <= box[1])minvol = min(minvol, box[0]*box[1]*box[2]);
        }
        if (minvol == INT_MAX) cout << "Item does not fit."; else cout << minvol;
        cout << nl;
    }
}