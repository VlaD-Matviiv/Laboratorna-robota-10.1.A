// Lab 10.1.A

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

enum Specialization {Mathematics, Physics, Engineering };

struct Student 
{
    string surname;
    int course;
    Specialization specialization;
    int physicsGrade;
    int mathGrade;
    int informaticsGrade;
};

string specializationToString(Specialization spec) 
{
    switch (spec) 
    {
    case Mathematics: return "Математика";
    case Physics: return "Фізика";
    case Engineering: return "Інженерфя";
    default: return "Невідомо";
    }
}

void inputStudents(vector<Student>& students, int count) 
{
    for (int i = 0; i < count; ++i) 
    {
        Student student;
        cout << "Ввести прізвище студента " << i + 1 << ": ";
        cin >> student.surname;
        cout << "Ввести курс (1-5): ";
        cin >> student.course;

        int spec;
        cout << "Ввести спеціальність (1 - Математика, 2 - Фізика, 3 - Інженерія): ";
        cin >> spec;
        student.specialization = static_cast<Specialization>(spec);

        cout << "Ввести оцінку з Фізики: ";
        cin >> student.physicsGrade;
        cout << "Ввести оцінку з Математики: ";
        cin >> student.mathGrade;
        cout << "Ввести оцінку з Інформатики: ";
        cin >> student.informaticsGrade;

        students.push_back(student);
    }
}

void displayStudents(const vector<Student>& students) 
{
    cout << left << setw(5) << "№"
        << setw(15) << "Прізвище"
        << setw(10) << "Курс"
        << setw(20) << "Спеціальність"
        << setw(15) << "Фізика"
        << setw(15) << "Математика"
        << setw(15) << "Інформатика" << endl;

    for (size_t i = 0; i < students.size(); ++i) 
    {
        cout << left << setw(5) << i + 1
            << setw(15) << students[i].surname
            << setw(10) << students[i].course
            << setw(20) << specializationToString(students[i].specialization)
            << setw(15) << students[i].physicsGrade
            << setw(15) << students[i].mathGrade
            << setw(15) << students[i].informaticsGrade << endl;
    }
}

void calculateAverageGrades(const vector<Student>& students, double& physicsAvg, double& mathAvg, double& informaticsAvg) 
{
    int totalPhysics = 0, totalMath = 0, totalInformatics = 0;
    for (const auto& student : students) 
    {
        totalPhysics += student.physicsGrade;
        totalMath += student.mathGrade;
        totalInformatics += student.informaticsGrade;
    }
    physicsAvg = static_cast<double>(totalPhysics) / students.size();
    mathAvg = static_cast<double>(totalMath) / students.size();
    informaticsAvg = static_cast<double>(totalInformatics) / students.size();
}

int countHighPhysicsGrades(const vector<Student>& students) 
{
    int count = 0;
    for (const auto& student : students) 
    {
        if (student.physicsGrade == 5 || student.physicsGrade == 4) 
        {
            count++;
        }
    }
    return count;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int studentCount;
    cout << "Ввести кількість студентів: ";
    cin >> studentCount;

    vector<Student> students;
    inputStudents(students, studentCount);

    cout << "\nStudent Information:\n";
    displayStudents(students);

    double physicsAvg, mathAvg, informaticsAvg;
    calculateAverageGrades(students, physicsAvg, mathAvg, informaticsAvg);

    cout << fixed << setprecision(2);
    cout << "\nAverage Grades:\n";
    cout << "Фізика: " << physicsAvg << "\n";
    cout << "Математика: " << mathAvg << "\n";
    cout << "Інформатика: " << informaticsAvg << "\n";

    int highPhysicsGradeCount = countHighPhysicsGrades(students);
    cout << "\nNumber of students with a physics grade of '5' or '4': " << highPhysicsGradeCount << "\n";

    return 0;
}
