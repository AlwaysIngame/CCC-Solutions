#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> tides(n);
    for (auto & i : tides) {
        cin >> i;
    }
    sort(tides.begin(), tides.end());
    int half_size = (tides.size()-1) / 2;
    
    for (auto i = 0; i < tides.size(); i++) {
        if (i % 2) cout << tides[half_size+i/2+1] << " ";
        else cout << tides[half_size-i/2] << " "; 
    }
}