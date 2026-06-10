#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    char choice;

    do
    {
        // Variables to store student details
        string studentName, semester;

        // Variables for CGPA calculation
        int totalCourses;
        float totalGradePoints = 0;
        float totalCredits = 0;

        cout << "\n=================================\n";
        cout << "      STUDENT CGPA CALCULATOR\n";
        cout << "=================================\n";

        // Removes the leftover newline character from previous input
        // so that getline() works correctly
        cin.ignore();

        // Taking student details
        cout << "Enter Student Name : ";
        getline(cin, studentName);

        cout << "Enter Semester : ";
        getline(cin, semester);

        // Taking total number of courses
        cout << "Enter Total Number of Courses : ";
        cin >> totalCourses;

        // Table heading
        cout << "\n---------------------------------------------------------------\n";
        cout << left << setw(20) << "Course"
             << setw(15) << "Grade Point"
             << setw(15) << "Credits"
             << setw(15) << "Grade Score" << endl;
        cout << "---------------------------------------------------------------\n";

        // Loop for each course
        for (int i = 1; i <= totalCourses; i++)
        {
            string courseName;
            float gradePoint, credits;

            // Clears newline before getline()
            cin.ignore();

            cout << "\nEnter Course " << i << " Name : ";
            getline(cin, courseName);

            // Input validation for grade point
            do
            {
                cout << "Enter Grade Point (0 - 10) : ";
                cin >> gradePoint;

                if (gradePoint < 0 || gradePoint > 10)
                {
                    cout << "Invalid Grade Point! Please try again.\n";
                }

            } while (gradePoint < 0 || gradePoint > 10);

            // Input validation for credit hours
            do
            {
                cout << "Enter Credit Hours : ";
                cin >> credits;

                if (credits <= 0)
                {
                    cout << "Invalid Credit Hours! Please try again.\n";
                }

            } while (credits <= 0);

            // Calculate grade score for current course
            float gradeScore = gradePoint * credits;

            // Updating total credits and grade points
            totalCredits += credits;
            totalGradePoints += gradeScore;

            // Display entered course details
            cout << left << setw(20) << courseName
                 << setw(15) << gradePoint
                 << setw(15) << credits
                 << setw(15) << gradeScore << endl;
        }

        // Calculate final CGPA
        float cgpa = totalGradePoints / totalCredits;

        cout << fixed << setprecision(2);

        // Display final result
        cout << "\n=========================================\n";
        cout << "Student Name       : " << studentName << endl;
        cout << "Semester           : " << semester << endl;
        cout << "Total Credits      : " << totalCredits << endl;
        cout << "Total Grade Points : " << totalGradePoints << endl;
        cout << "Final CGPA         : " << cgpa << endl;
        cout << "=========================================\n";

        // Ask user if they want to calculate again
        cout << "\nDo you want to calculate another CGPA? (Y/N) : ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    cout << "\nThank you for using the CGPA Calculator. Goodbye!\n";

    return 0;
}