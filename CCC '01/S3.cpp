#include <bits/stdc++.h>
using namespace std;

bool path(map<char, vector<char>> roadmap, char a, char b, vector<char> visited = {}) {
    //DFS
    if (a == b) return true;
    if (find(visited.begin(), visited.end(), a) != visited.end()) return false;
    visited.push_back(a);
    for (auto i : roadmap[a]) {
        if (path(roadmap, i, b, visited)) return true;
    }
    return false;
}
int main() {
    map<char, vector<char>> lis;
    vector<pair<char, char>> roads;
    while (true) {
        char x; char y; cin >> x >> y;
        if (x == y) break;
        lis[x].push_back(y);
        lis[y].push_back(x);
        roads.push_back(pair<char, char>(x, y));
    }
    vector<pair<char, char>> breaks = {};
    for (auto i : roads) {
        lis[i.first].erase(find(lis[i.first].begin(), lis[i.first].end(), i.second));
        lis[i.second].erase(find(lis[i.second].begin(), lis[i.second].end(), i.first));
        if (not path(lis, 'A', 'B')) breaks.push_back(pair<char,char>(i.first, i.second));
        lis[i.first].push_back(i.second);
        lis[i.second].push_back(i.first);
    }
    for (auto i : breaks) {
        cout << i.first << i.second << '\n';
    }
    cout << "There are " << breaks.size() << " disconnecting roads.\n";
}