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

vvi tensorproduct(vvi a, vvi b) {
    int tensorrows = a.size()*b.size(), tensorcols = a[0].size()*b[0].size();
    vvi tensor(tensorrows, vi(tensorcols));
    for (int i = 0; i < tensorrows; i++) {
        for (int j = 0; j < tensorcols; j++) {
            tensor[i][j] = a[i/b.size()][j/b[0].size()] * b[i%b.size()][j%b[0].size()];
        }
    }
    return tensor;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vvi tensorprod = {{1}};
    forrange(n) {
        int r, c; cin >> r >> c;
        vvi matrix = {};
        forrange(r) {
            vi row = {};
            forrange(c) {
                int x; cin >> x;
                row.pb(x);
            }
            matrix.pb(row);
        }
        tensorprod = tensorproduct(tensorprod, matrix);
    }
    int maxele = INT_MIN;
    int minele = INT_MAX;
    int maxrow = INT_MIN, minrow = INT_MAX;
    int maxcol = INT_MIN, mincol = INT_MAX;

    for (auto row : tensorprod) {
        for (auto item : row) {
            maxele = max(maxele, item); minele = min(minele, item);
        }
        int rowsum = accumulate(row.begin(), row.end(), 0);
        maxrow = max(maxrow, rowsum);
        minrow = min(minrow, rowsum);
    }
    forrange(tensorprod[0].size()) {
        int rowsum = 0;
        for_each(tensorprod.begin(), tensorprod.end(), [&rowsum, i](vi r){rowsum += r[i];});
        maxcol = max(maxcol, rowsum);
        mincol = min(mincol, rowsum);
    }
    cout << maxele << nl << minele << nl << maxrow << nl << minrow << nl << maxcol << nl << mincol;
}