
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Student
{
    int id;
    string name;
    string course;
    int fees;
};

struct Teacher
{
    int id;
    string name;
    string subject;
    int salary;
};
void addStudent()
{
    Student s;
    cout << "\nEnter Student ID : ";
    cin >> s.id;
    cin.ignore();

    cout << "Enter Name : ";
    getline(cin, s.name);

    cout << "Enter Course : ";
    getline(cin, s.course);

    cout << "Enter Fees : ";
    cin >> s.fees;

    ofstream write("student.txt", ios::app);
    write << s.id << "\n" << s.name << "\n"
          << s.course << "\n" << s.fees << "\n";
    write.close();
}
void viewStudents()
{
    Student s;
    ifstream read("student.txt");

    while (read >> s.id)
    {
        read.ignore();
        getline(read, s.name);
        getline(read, s.course);
        read >> s.fees;

        cout << "\n------------------";
        cout << "\nID : " << s.id;
        cout << "\nName : " << s.name;
        cout << "\nCourse : " << s.course;
        cout << "\nFees : " << s.fees;
    }
    read.close();
}
void searchStudent()
{
    int id, found = 0;
    cout << "\nEnter Student ID to search : ";
    cin >> id;

    Student s;
    ifstream read("student.txt");

    while (read >> s.id)
    {
        read.ignore();
        getline(read, s.name);
        getline(read, s.course);
        read >> s.fees;

        if (s.id == id)
        {
            cout << "\nID : " << s.id;
            cout << "\nName : " << s.name;
            cout << "\nCourse : " << s.course;
            cout << "\nFees : " << s.fees;
            found = 1;
            break;
        }
    }
    if (found == 0)
        cout << "\nStudent not found!";
    read.close();
}
void updateStudent()
{
    int id, found = 0;
    cout << "\nEnter Student ID to update : ";
    cin >> id;
    cin.ignore();

    Student s, n;
    ifstream read("student.txt");
    ofstream temp("temp.txt");

    while (read >> s.id)
    {
        read.ignore();
        getline(read, s.name);
        getline(read, s.course);
        read >> s.fees;
        cin.ignore();

        if (s.id == id)
        {
            cout << "Enter New Name : ";
            getline(cin, n.name);
            cout << "Enter New Course : ";
            getline(cin, n.course);
            cout << "Enter New Fees : ";
            cin >> n.fees;

            temp << s.id << "\n" << n.name << "\n"
                 << n.course << "\n" << n.fees << "\n";
            found = 1;
        }
        else
        {
            temp << s.id << "\n" << s.name << "\n"
                 << s.course << "\n" << s.fees << "\n";
        }
    }
    read.close();
    temp.close();

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found == 0)
        cout << "\nStudent not found!";
}
void addTeacher()
{
    Teacher t;
    cout << "\nEnter Teacher ID : ";
    cin >> t.id;
    cin.ignore();

    cout << "Enter Name : ";
    getline(cin, t.name);

    cout << "Enter Subject : ";
    getline(cin, t.subject);

    cout << "Enter Salary : ";
    cin >> t.salary;

    ofstream write("teacher.txt", ios::app);
    write << t.id << "\n" << t.name << "\n"
          << t.subject << "\n" << t.salary << "\n";
    write.close();
}
void viewTeachers()
{
    Teacher t;
    ifstream read("teacher.txt");

    while (read >> t.id)
    {
        read.ignore();
        getline(read, t.name);
        getline(read, t.subject);
        read >> t.salary;

        cout << "\n------------------";
        cout << "\nID : " << t.id;
        cout << "\nName : " << t.name;
        cout << "\nSubject : " << t.subject;
        cout << "\nSalary : " << t.salary;
    }
    read.close();
}
void searchTeacher()
{
    int id,found=0;
    cout << "\nEnter Teacher ID to search : ";
    cin >> id;

    Teacher t;
    ifstream read("teacher.txt");

    while (read >> t.id)
    {
        read.ignore();
        getline(read, t.name);
        getline(read, t.subject);
        read >> t.salary;

        if (t.id == id)
        {
            cout << "\nID : " << t.id;
            cout << "\nName : " << t.name;
            cout << "\nSubject : " << t.subject;
            cout << "\nSalary : " << t.salary;
            found = 1;
            break;
        }
    }
    if (found == 0)
        cout << "\nTeacher not found!";
    read.close();
}
void updateTeacher()
{
    int id, found = 0;
    cout << "\nEnter Teacher ID to update : ";
    cin >> id;
    cin.ignore();

    Teacher t, n;
    ifstream read("teacher.txt");
    ofstream temp("temp.txt");

    while (read >> t.id)
    {
        read.ignore();
        getline(read, t.name);
        getline(read, t.subject);
        read >> t.salary;
        cin.ignore();

        if (t.id == id)
        {
            cout << "Enter New Name : ";
            getline(cin, n.name);
            cout << "Enter New Subject : ";
            getline(cin, n.subject);
            cout << "Enter New Salary : ";
            cin >> n.salary;

            temp << t.id << "\n" << n.name << "\n"
                 << n.subject << "\n" << n.salary << "\n";
            found = 1;
        }
        else
        {
            temp << t.id << "\n" << t.name << "\n"
                 << t.subject << "\n" << t.salary << "\n";
        }
    }
    read.close();
    temp.close();

    remove("teacher.txt");
    rename("temp.txt", "teacher.txt");

    if (found == 0)
        cout << "\nTeacher not found!";
}
int main()
{
    int ch;
    while (1)
    {
        cout << "\n\n Silicon Classes Management ";
        cout << "\n1.Add Student";
        cout << "\n2.View Students";
        cout << "\n3.Search Student";
        cout << "\n4.Update Student";
        cout << "\n5.Add Teacher";
        cout << "\n6.View Teachers";
        cout << "\n7.Search Teacher";
        cout << "\n8.Update Teacher";
        cout << "\n9.Exit";
        cout << "\nEnter Choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1: addStudent();
         break;
        case 2: viewStudents();
         break;
        case 3: searchStudent();
         break;
        case 4: updateStudent();
         break;
        case 5: addTeacher();
         break;
        case 6: viewTeachers();
         break;
        case 7: searchTeacher();
         break;
        case 8: updateTeacher();
         break;
        case 9: exit(0);
        default: cout << "\nInvalid choice!";
        }
    }
}