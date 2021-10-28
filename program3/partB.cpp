#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(vector<int> weights, vector<int> val, int n, int cap) {
    vector<vector<int> > ans(n+1, vector<int>(cap + 1));
    //int ans[n+1][cap+1];

    for(unsigned i = 0; i <= n; i ++) {
        for(unsigned j = 0; j <= cap; j++) {
            if(i == 0 | j == 0) {
                ans[i][j] = 0;
            }
            else if (weights[i-1] <= j) {
                ans[i][j] = max(val[i-1] + ans[i-1][j - weights[i-1]], ans[i-1][j]);
            }
            else {
                ans[i][j] = ans[i-1][j];
            }
        }
    }
    return ans[n][cap];
}

int main() {
    int w, n; //w = weight budget, n = num items
    w = n = 0;

    cin >> w >> n; //getting input for w and n

    int wi, v;
    wi = v = 0;

    vector<int> weights, value;

    for(unsigned i = 0; i < n; i ++) {
        cin >> wi;
        weights.push_back(wi);
        cin >> v;
        value.push_back(v);
    }

    cout << knapsack(weights, value, weights.size(), w);

    return 0;
}