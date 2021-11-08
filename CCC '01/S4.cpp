#include <bits/stdc++.h>
using namespace std;

// Not my solution:
// If you need a hint for your own solution, try the circumradius formula.
long double dis(pair<long double,long double> x, pair<long double, long double> y) {
    return sqrt(pow(x.first-y.first,2) - pow(x.second-y.second,2));
}
int main () {
    int n; cin >> n;
    double x[n];
    double y[n];
    double a,b,c,semiP = 0, diameter, output = 0;
    double tri1, tri2, tri3;
    for (int i = 0; i < n; i ++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j <n; j++)
            for (int k=0; k<n;k++) {
                a = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
                b = sqrt(pow(x[j] - x[k], 2) + pow(y[j] - y[k], 2));
                c = sqrt(pow(x[k] - x[i], 2) + pow(y[k] - y[i], 2));
                semiP = (a+b+c)/2;
                diameter = 0;
                tri1 = (a * a) + (b * b) - (c * c);
                tri2 = (b * b) + (c * c) - (a * a);
                tri3 = (a * a) + (c * c) - (b * b);

                if (tri1 < 0 || tri2 < 0 || tri3 < 0 || semiP == 0) {
                    if (a > diameter) diameter = a;
                    if (b > diameter) diameter = b;
                    if (c > diameter) diameter = c;
                }
                else {
                    diameter = (a * b * c);
                    diameter /= (4 * sqrt (semiP * (semiP - a) * (semiP - b) * (semiP - c)));
                    diameter *= 2;
                }
                if (diameter > output) output = diameter;
    }
    cout << output;
}