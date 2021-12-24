// Not complete

#include <bits/stdc++.h>
using namespace std;

struct Person {
    string name;
    int speed;
};

int speed(vector<Person> group) {
    int maxi = INT_MIN;
    for (auto i : group) {
        maxi = max(maxi, i.speed);
    }
    return maxi;
}
int main() {
    int m; cin >>m;
    int np; cin >> np;
    vector<Person> people;
    for (int i = 0; i < np; i ++) {
        Person temp;
        cin >> temp.name;
        cin >> temp.speed;
        people.push_back(temp);
    }

    vector<vector<Person>> groups = {};

    while (not people.empty()) {
        vector<Person> newgroup = {};
        for (int i = 0; i < min(m, static_cast<int>(people.size())); i ++) {
            if (newgroup.size() == 0) {newgroup.push_back(people[0]); people.erase(people.begin());}
            else {
                newgroup.push_back(people[0]);
                vector<Person> temp = newgroup;
                newgroup.erase(newgroup.end() -1);
                if (speed(temp) <= speed(newgroup)) {
                    newgroup.push_back(people[0]);
                    people.erase(people.begin());
                } else {
                    break;
                }
            }
        }
        groups.insert(groups.begin(), newgroup);
    }
    int total_speed = 0;
    for_each(groups.begin(), groups.end(), [&t=total_speed](vector<Person> p){t += speed(p);});
    cout << "Total Time: " << total_speed << '\n';
    for (auto group : groups) {
        for_each(group.begin(), group.end(), [](Person p){cout << p.name << ' ';});
        cout << '\n';
    }
}