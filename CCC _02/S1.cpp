#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> p, int t, int &minn, vector<vector<int>> &combos, vector<int> nums = {0,0,0,0}) {
    if (t == 0) {
        
        if (minn > nums[0] + nums[1] + nums[2] + nums[3]) minn = nums[0] + nums[1] + nums[2] + nums[3];
        if (find(combos.begin(), combos.end(), nums) == combos.end()) {
            cout << "# of PINK is " << nums[0] << " # of GREEN is " << nums[1] << " # of RED is " << nums[2] << " # of ORANGE is " << nums[3] << '\n';
            combos.push_back(nums);}
    }
    for (int i = 0; i < 4; i++) {
        if (t-p[i] >= 0) {
            nums[i] += 1;
            solve(p,t-p[i], minn, combos, nums);
            nums[i] -= 1;
        }
    }
}
int main() {
    int total;
    vector<int> prices(4);
    cin >> prices[0] >> prices[1] >> prices[2] >> prices[3] >> total;
    int m = INT_MAX;
    vector<vector<int>> combo;
    solve(prices, total, m, combo);
    cout << "Total combinations is " << combo.size() << ".\nMinimum number of tickets to print is " << m << '.';
}