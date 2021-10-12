#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkDuplicate(vector<int> grades, int num) {
    for(unsigned int i = 0; i < grades.size(); i++) {

        if(num == grades.at(i)) {
            //cout << num << " matches " << grades.at(i) << endl;
            return false;
        }
    }
    return true;
}

int main(){
    int n; //number of students
    int num; // number to add into vector

    //cout << "Enter size of vector: \n";

    cin >> n;
    
    vector<int> grades;

    cin >> num;
    grades.push_back(num);

    for(unsigned int i = 0; i < n-1; i++) { //populate array

        cin >> num;
        //cout << "Checking if " << num << " is in the vector" << endl;

        if(checkDuplicate(grades, num)) {
            grades.push_back(num);
        }
    }
    

    sort(grades.begin(), grades.end(), greater<int>()); //sort grades

    int m = 0; //num of queries
    int rank; // ranks
    cin >> m;

    for(unsigned int i = 0; i < m; i++){
        cin >> rank;
        cout << grades.at(rank-1) << endl;
    }

    

    return 0;
}