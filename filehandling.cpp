
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Student
{
    int id;
    string name;
    int age;
    string degree;
    int sem_no;
};

void addstudent()
{
    Student stu;

    cout << "Enter your id :- ";
    cin >> stu.id;

    cin.ignore();

    cout << "Enter name :- ";
    getline(cin, stu.name);

    cout << "Enter age :- ";
    cin >> stu.age;

    cin.ignore();

    cout << "Enter degree :- ";
    getline(cin, stu.degree);

    cout << "Enter semester number :- ";
    cin >> stu.sem_no;

    ofstream Write;
    Write.open("raaj.txt",ios::app);

    Write << stu.id << "\n";
    Write << stu.name << "\n";
    Write << stu.age << "\n";
    Write << stu.degree << "\n";
    Write << stu.sem_no << "\n";
    Write.close();
}
void stuprint(Student s)
{
    cout <<"\n\t---Stuent Data---";
    cout <<"\n\tID is : " <<s.id;
    cout <<"\n\tName is :" <<s.name;
    cout <<"\n\tAge is: " <<s.age;
    cout <<"\n\tDegree is : " <<s.degree;
    cout << "\n\tSmester Number is :" << s.sem_no<<"\n\n";
}
void readData()
{
    Student student;
    ifstream read;

    read.open("raaj.txt");
    if(!read)
    {
        cout<<"File is not found!";
    }

    do
    {
        read >> student.id;
        read.ignore();
        getline(read, student.name);

        read >> student.age;
        read.ignore();
        getline(read, student.degree);

        read >> student.sem_no;

        stuprint(student);
    } while (!read.eof());
    read.close();
}
int searchdata()
{
    int id;
    cout<<"enter ID which you want to search :- ";
    cin>>id;
    Student stu;
    ifstream read;
    read.open("raaj.txt");
    while(!read.eof())
    {
        if(stu.id==id)
        {
            stuprint(stu);
            return id;
        }
        read >> stu.id;
        read.ignore();
        getline(read, stu.name);

        read >> stu.age;
        read.ignore();
        getline(read, stu.degree);

        read >> stu.sem_no;

    }
}
void deleteData() {
    int id = searchdata();
    cout << "\n\tYou want to delete record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        Student student;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("raaj.txt");
        read >> student.id;
        read.ignore();
        getline(read, student.name);
        read >> student.age;
        read >> student.degree;
        read >> student.sem_no;
        while (!read.eof()) {
            if (student.id != id) {
                tempFile << student.id << "\n";
                tempFile << student.name << "\n";
                tempFile << student.age << "\n";
                tempFile << student.degree << "\n";
                tempFile << student.sem_no << "\n";
            }
            read >> student.id;
            read.ignore();
            getline(read, student.name);
            read >> student.age;
            read >> student.degree;
            read >> student.sem_no;
        }
        read.close();
        tempFile.close();
        remove("raaj.txt");
        rename("temp.txt", "raaj.txt");
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}
void updatedata()
{
int id =searchdata();
cout<<"\n\tyou want to update record (y/n) : ";
char choice;
cin>>choice ;
if(choice=='y')
{
Student newdata;
cout << "Enter name :- ";
    getline(cin, newdata.name);

    cout << "Enter age :- ";
    cin >> newdata.age;

    cin.ignore();

    cout << "Enter degree :- ";
    getline(cin, newdata.degree);

    cout << "Enter semester number :- ";
    cin >> newdata.sem_no;
    Student student;
    ofstream tempfile;
    tempfile.open("temp.txt");
    ifstream read;
    read.open("raaj.txt");
    read>>student.id;
    read.ignore();
    getline(read,student.name);
    read>>student.age;
    read>>student.degree;
    read>>student.sem_no;
    while(!read.eof())
    {
    if(student.id!=id)
    {
    tempfile<<student.id<<"\n";
    tempfile<<student.name<<"\n";
    tempfile<<student.age<<"\n";
    tempfile<<student.degree<<"\n";
    tempfile<<student.sem_no<<"\n";
    }
    else
    {
    tempfile<<student.id<<"\n";
    tempfile<<newdata.name<<"\n";
    tempfile<<newdata.age<<"\n";
    tempfile<<newdata.degree<<"\n";
    tempfile<<newdata.sem_no<<"\n";
    }
     read>>student.id;
    read.ignore();
    getline(read,student.name);
    read>>student.age;
    read>>student.degree;
    read>>student.sem_no;
    }
    read.close();
    tempfile.close();
    remove("raaj.txt");
    rename("temp.txt","raaj.txt");
}
}
int main()
{
    while (true)
    {
        cout << "\n1.Add student data";
        cout << "\n2.See student data";
        cout<<"\n3.search student details ";
        cout<<"\n4.delete student data ";
        cout<<"\n5.update data ";
        int choice;
        cout << "\n\tEnter choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            addstudent();
            break;
        case 2:
            readData();
            break;
        case 3:
            searchdata();
            break;
        case 4 :
            deleteData();
            break;
            case 5:
            updatedata();
            break;
                    }
    }
    return 0;
}