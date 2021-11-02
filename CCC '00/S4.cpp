#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <climits>
#include <iterator>
using namespace std;

void solve(vector<int> set, int sum, int (&solution)[5281]) {
    for (int i = 1; i <= sum; i++) {
        if (find(set.begin(), set.end(), i) != set.end()) {solution[i] = 1; continue;}
        
        for (int j = 0; j < 5281; j++) {
            if (solution[j] != INT_MAX) {
                if (find(set.begin(), set.end(), i-j) != set.end()) {solution[i] = min(solution[j]+1, solution[i]); continue;}
            }
        }
    }
}

int main() {
    int distance;
    int nclubs;
    int sol[5281];
    fill_n(sol, 5281, INT_MAX);
    vector<int> clubs = {};
    cin >> distance >> nclubs;
    for (int i = 0; i < nclubs; i++) {
        int _;
        cin >> _;
        clubs.push_back(_);
    }
    solve(clubs, distance, sol);
    if (sol[distance] == INT_MAX) cout << "Roberta acknowledges defeat.";
    else cout << "Roberta wins in " << sol[distance] <<" strokes.";
}