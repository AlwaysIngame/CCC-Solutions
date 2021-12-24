#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include<math.h>
using namespace std;

vector<string> substrs(string str) {
	vector<string> bruh = {};
	for (int i = 0; i < str.size() + 1; i++) {
		string temp = str.substr(0,i);
		for (int j = 0; j < temp.size(); j++) {
			string secondtemp = temp.substr(j, temp.size() - j);
			bruh.push_back(secondtemp);
		}
	}
	return bruh;
}

int main()
{
	string str;
    cin >> str;
	vector<string> subs = substrs(str);
	int maxi = -1;
	for (int i = 0; i < subs.size(); i++) {
		string lol = subs[i];
		reverse(lol.begin(), lol.end());
		int a = static_cast<int>(lol.length());
		if (subs[i] == lol && a > maxi) {
			maxi = a;
		}
	}
	cout << maxi;
}
