/*
idea -- 
i want to create a CGPA calcuator
in this - 1.CGPA of all the sem user wants will be calculated
2.GPA of each sem will be calculated

approach for 2 - user will enter an array of grade points obtained and credit points for each subject 
total = for all i sum (credit[i]+point[i])
now GPA = total/total credit point

approach for 1 - if in 1st yr and 2nd yr == gpa*1
if in 3rd or 4th yr == gpa*1.5
now add all and divide by total no. of sems.
*/


#include <iostream>
using namespace std;

// Function to calculate GPA for a semester
float gpaCalculator() {
    int numSub;
    cout << "Enter the number of subjects: ";
    cin >> numSub;

    float *credits = new float[numSub];
    float *points = new float[numSub];

    for(int i = 0; i < numSub; i++) {
        cout << "Enter the grade points obtained for subject " << i + 1 << ": ";
        cin >> points[i];
        cout << "Enter the credit for subject " << i + 1 << ": ";
        cin >> credits[i];
    }

    float total = 0, totalCredit = 0;
    for(int i = 0; i < numSub; i++) {
        total += credits[i] * points[i];
        totalCredit += credits[i];
    }

    delete[] credits;
    delete[] points;

    float gpa = total / totalCredit;
    cout << "Your GPA for this semester is: " << gpa << endl;
    return gpa;
}

// Function to calculate CGPA across semesters
void CGPACalculator() {
    int numSems;
    cout << "Enter the number of semesters: ";
    cin >> numSems;

    float *gpas = new float[numSems];
    float totalWeighted = 0;
    float totalWeight = 0;

    for(int i = 0; i < numSems; i++) {
        cout << "Enter the GPA for semester " << i + 1 << ": ";
        cin >> gpas[i];

        // Weighting logic as per your approach
        float weight = (i < 2) ? 1.0 : 1.5; // 1st and 2nd year: 1, 3rd and 4th: 1.5
        totalWeighted += gpas[i] * weight;
        totalWeight += weight;
    }

    delete[] gpas;

    float cgpa = totalWeighted / totalWeight;
    cout << "Your CGPA is: " << cgpa << endl;
}

int main() {
    int choice;
    do {
        cout << "\n===== CGPA Calculator Menu =====\n";
        cout << "1. Calculate GPA for a semester\n";
        cout << "2. Calculate CGPA across semesters\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                gpaCalculator();
                break;
            case 2:
                CGPACalculator();
                break;
            case 3:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please select 1, 2, or 3.\n";
        }
    } while(choice != 3);

    return 0;
}
