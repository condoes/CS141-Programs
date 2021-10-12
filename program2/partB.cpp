#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n; //num departments
    int members;
    vector<int> V_members;
    cin >> n;

    for(unsigned i = 0; i < n; i++) {
        cin >> members;
        V_members.push_back(members);
    }

    sort(V_members.begin(), V_members.end());

    // for(unsigned i = 0; i < V_members.size(); i++) {
    //     cout << V_members.at(i) << " ";
    // }
    // cout << endl;

    int halfSize = (V_members.size() / 2) + 1;
    int total = 0;

    for(unsigned i = 0; i < halfSize; i++) {
        total += (V_members.at(i) / 2) + 1;
    }

    cout << total << endl;

    return 0;
}