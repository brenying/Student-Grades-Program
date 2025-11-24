#include <iostream>
#include <string>
using namespace std;

struct studentType
{
    string studentFname;
    string studentLname;
    int testScore;
    char grade;
};
void highestScore(studentType students[], int size);
void printStudents (studentType students[], int size);
void gradeAssign(studentType students[], int size);
void inputStudents(studentType students[], int size);


void gradeAssign(studentType students[], int size)
{
    for (int i=0; i<=size; i++)
    {
        if (students[i].testScore >= 90 && students[i].testScore <= 100)
        {
            students[i].grade = 'A';
        }
        else if (students[i].testScore >= 80 && students[i].testScore <= 89)
        {
            students[i].grade = 'B';
        }
        else if (students[i].testScore >= 70 && students[i].testScore <= 79)
        {
            students[i].grade = 'C';
        }
        else if (students[i].testScore >= 60 && students[i].testScore <= 69)
        {
            students[i].grade = 'D';
        }
        else
        {
            students[i].grade = 'F';
        }
    }
}

void inputStudents (studentType students[], int size)
{
    for (int i=0; i < size; i++)
    {
        cout << "What is the student's first name: ";
        cin >> students[i].studentFname;

        cout << "What is the student's last name: ";
        cin >> students[i].studentLname;

        cout << "Enter test score: ";
        cin >> students[i].testScore;
        
        gradeAssign(students, size);
    }
}

void highestScore(studentType students[], int size) 
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (students[j].testScore < students[j + 1].testScore) {
                studentType temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    cout << endl;
    cout << "Highest Score: " << students[0].testScore << " - " << students[0].grade << " Name: " << students[0].studentLname << ", "
    << students[0].studentFname <<endl;
}

void printStudents (studentType students[], int size)
{
    cout << endl;
        cout << "---------- Student Grades ---------" << endl;
    for(int i=0; i<size; i++)
    {
        cout << "Name: " << students[i].studentLname << ", " << students[i].studentFname 
        << " Score: " << students[i].testScore << " - " << students[i].grade << endl;
        
    }
}


int main()
{
    int size = 3;
    studentType *students = new studentType[size];
    
    inputStudents(students, size);
    printStudents(students, size);
    highestScore(students, size);
    
    delete [] students;
    


    return 0;
}
