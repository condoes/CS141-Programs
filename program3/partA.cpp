#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int MergeCandies(vector<int> numCandies) {

    sort(numCandies.begin(), numCandies.end()); //sort vector

    //int n = numCandies.size();
    int i, j, cost, added_candy;
    i = j = cost = 0;
    int v1, v2;
    //vector<int> new_pile;

    while(numCandies.size() > 1){
        added_candy = (numCandies[0] + numCandies[1]);
        cost += added_candy * 2;
        numCandies.erase(numCandies.begin()); //erase first element //O(n)
        numCandies[0] = added_candy;
        sort(numCandies.begin(), numCandies.end()); //sort vector //O(nlogn)
    }    
    return cost;
}

int main() {
    int n, a;
    vector<int> numCandies;
    cin >> n;

    for(unsigned i = 0; i < n; i++) {
        cin >> a;
        numCandies.push_back(a);
        //cout << numCandies.at(i) << endl;
    }

    cout << MergeCandies(numCandies);

    return 0;
}