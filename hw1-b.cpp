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
    int grade;
    cin >> m;

    for(unsigned int i = 0; i < m; i++){
        cin >> grade;
        vector<int>::iterator index = find(grades.begin(), grades.end(), grade);
        cout << distance(grades.begin(), index) + 1 << endl;
    }

    return 0;
}