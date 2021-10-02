#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n; //number of students
    int num;

    cin >> n;
    vector<int> grades;

    for(unsigned int i = 0; i < n; i++) { //populate array
        cin >> num;
        grades.push_back(num);
        //cout << grades.at(i) << " ";
    }

    //int end = sizeof(grades) / sizeof(grades[0]);

    sort(grades.begin(), grades.end(), greater<int>());

    int m; //number of queries
    //vector<int> k; //rank
    int rank;
    cin >> m;

    for(unsigned int i = 0; i < m; i++){
        cin >> rank;
        cout << grades.at(rank-1) << endl;
    }

    return 0;
}