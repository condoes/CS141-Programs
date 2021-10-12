#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;
int candies;


void mergeVectors(vector<int>& left, vector<int>& right, vector<int>& V_sorted) {
    int l_size = left.size();
    int r_size = right.size();
    int p1 = 0; int p2 = 0; int k = 0;

    //vector<int> V_sorted;

    while(p1 < l_size && p2 < r_size) {
        if(left.at(p1) < right.at(p2)) {
            V_sorted.at(k) = left.at(p1);
            p1++;
        }
        else {
            V_sorted.at(k) = right.at(p2);
            p2++;
        }
        k++;
    }

    while(p1 < l_size) {
        V_sorted.at(k) = left.at(p1);
        p1++;
        k++;
    }    

    while(p2 < r_size) {
        V_sorted.at(k) = right.at(p2);
        p2++;
        k++;
    }

};

void mergeSort(vector<int> &V) {

    if(V.size() <= 1) { //base case, 1 pair
        return;
    }

    int n = V.size() / 2;

    vector<int> left(V.begin(), V.end() - n);
    vector<int> right(V.begin() + n, V.end());

    mergeSort(left);
    mergeSort(right);
    mergeVectors(left, right, V);
    candies += V.at(V.size()-1) - V.at(0);

};

int main() {
    int n;
    int input;
    vector<int> userInputs;

    cin >> n;

    for(unsigned i = 0; i < n; i++) {
        cin >> input;
        userInputs.push_back(input);
    }

    mergeSort(userInputs);

    cout << candies;
    //cout << mergeSort(userInputs);

    return 0;
}
