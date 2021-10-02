#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkDuplicate(vector<int> grades, int num) {
    for(unsigned int i = 0; i < grades.size(); i++) {
        if(num != grades.at(i)) {
            return true;
        }
    }
    return false;
}

int main(){
    int n; //number of students
    int num;

    //cout << "Enter n \n";

    cin >> n;
    
    vector<int> grades;

    cin >> num;
    grades.push_back(num);

    for(unsigned int i = 0; i < n-1; i++) { //populate array
        cin >> num;

        if(checkDuplicate(grades, num)) {
            grades.push_back(num);
        }
    }

    sort(grades.begin(), grades.end(), greater<int>()); //sort grades

    int m = 0; //num of queries
    int grade; // ranks
    cin >> m;

    for(unsigned int i = 0; i < m; i++) {
        cin >> grade;
        vector<int>::iterator index = find(grades.begin(), grades.end(), grade);
        cout << distance(grades.begin(), index) + 1 << endl;
    }

    // for(unsigned int i = 0; i < grades.size(); i++) {
    //     cout << grades.at(i) << "\n";
    // }

    return 0;
}