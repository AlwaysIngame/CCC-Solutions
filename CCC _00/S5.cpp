#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <utility>
#include <set>
#include <iomanip>
using namespace std;

set<pair<double, double>> found = {};
void solve(vector<pair<double, double>> sheep) {
    for (double i = 0.00; i <= 1000.00; i += 0.01) {
        pair<double, double> mins;
        double min = 999999999999999;
        for (auto s : sheep) {
            double d = (i - s.first)*(i - s.first) + (0-s.second)*(0-s.second);
            if (d < min) {
                mins = s;
                min = d;
            }
        }
        found.insert(mins);
    }
}
int main() {
    int n; cin >> n;
    vector<pair<double, double>> sheep = {};
    for (auto i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        pair<double,double> temp(x, y);
        sheep.push_back(temp);
    }
    solve(sheep);
    for (auto i : found) {
        cout << fixed  << setprecision(2) << "The sheep at (" << i.first << ", " << i.second << ") might be eaten." << "\n";
    }
}