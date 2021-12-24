#include <bits/stdc++.h>
using namespace std;

vector<int> add1(vector<int> v, int base, int d=1) {
    if (d == v.size() +1) {v.insert(v.begin(), 1); return v;}
    else if(v[v.size()-d] == base-1) {
        v[v.size()-d] = 0;
        return add1(v,base,d+1);
    } else {
        v[v.size()-d]+=1; return v;
    }
}
bool solve(vector<string> a, vector<string> b, int m, vector<int> seq) {
    string seqa = ""; string seqb = "";
    for (auto i : seq) {
        seqa.append(a[i]);
        seqb.append(b[i]);
    }
    if (seqa == seqb) return true;
    else return false;
}
int main() {
    int m, n; cin >> m >> n;
    vector<string> a, b;
    for (int i = 0; i < n; i++){
        string bruh; cin >> bruh;
        a.push_back(bruh);
    }
    for (int i = 0; i < n; i++){
        string bruh; cin >> bruh;
        b.push_back(bruh);
    }
    for (vector<int> seq = {0}; seq.size() < m; seq = add1(seq, a.size())) {
        if (solve(a,b,m,seq)) {
            cout << seq.size();
            for (auto i : seq) cout << '\n' << i+1;
            return 0;
        }
    }
    cout << "No solution.";
}