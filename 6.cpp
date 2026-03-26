// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

/**
6. Viết chương trình cho phép người dùng nhập vào danh sách học sinh (thông tin
mỗi học sinh giống bài 5). Tìm và xuất thông tin học sinh có điểm trung bình cao
nhất, thấp nhất ra màn hình.
*/

#include <iostream>
#include "6.h"

using namespace std;

#define MAX_STUDENTS 100

// Helper function to input a student from the user.
Student inputStudent()
{
    string sName;
    float fScoreMath, fScoreLiterature;
    cin.ignore(); // there's a "\n" left in the buffer
    cout << "\tNhap ho ten: ";
    getline(cin, sName);
    cout << "\tNhap diem toan: ";
    cin >> fScoreMath;
    cout << "\tNhap diem van: ";
    cin >> fScoreLiterature;
    return Student(sName, fScoreMath, fScoreLiterature);
}

int main()
{
    int n;
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;
    if (n <= 0)
    {
        cout << "So luong hoc sinh phai lon hon 0." << endl;
        return 1;
    }

    // Get all the students
    Student students[MAX_STUDENTS];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin hoc sinh thu " << (i + 1) << ":" << endl;
        students[i] = inputStudent();
    }

    // Find the student with the highest score
    int iBestStudentIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (students[i].AverageScore() > students[iBestStudentIndex].AverageScore())
        {
            iBestStudentIndex = i;
        }
    }
    cout << "Hoc sinh co diem trung binh cao nhat: " << endl;
    students[iBestStudentIndex].Print();

    // Find the student with the lowest score
    int iWorstStudentIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (students[i].AverageScore() < students[iWorstStudentIndex].AverageScore())
        {
            iWorstStudentIndex = i;
        }
    }
    cout << "Hoc sinh co diem trung binh thap nhat: " << endl;
    students[iWorstStudentIndex].Print();

    return 0;
}

// Default constructor: initializes to empty name and 0 scores.
Student::Student()
{
    this->sName = "";
    this->fScoreMath = 0;
    this->fScoreLiterature = 0;
}

// Initialize a new Student with the given name and scores.
Student::Student(string sName, float fScoreMath, float fScoreLiterature)
{
    this->sName = sName;
    this->fScoreMath = fScoreMath;
    this->fScoreLiterature = fScoreLiterature;
}

// Print the student's information to the console.
void Student::Print()
{
    cout << "Ho ten: " << sName << endl;
    cout << "Diem toan: " << fScoreMath << endl;
    cout << "Diem van: " << fScoreLiterature << endl;
    cout << "Diem trung binh: " << AverageScore() << endl;
}

// Return the average score of the student.
float Student::AverageScore()
{
    return (fScoreMath + fScoreLiterature) / 2;
}
