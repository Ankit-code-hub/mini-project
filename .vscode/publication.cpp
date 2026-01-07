
#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    void getData() {
        cout << "Enter Publication title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        
    }

    void putData() const {
        cout << "Publication Title is: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class Book : public Publication {
private:
    int pages;

public:
    void getData() {
        Publication::getData();
        cout << "Enter number of pages: ";
        cin >> pages;
    }

    void putData() const {
        Publication::putData();
        cout << "Pages: " << pages << endl;
    }
};

class Tape : public Publication {
private:
    float playt;

public:
    void getData() {
        cout << "Enter playing time : ";
        cin >> playt;
    }

    void putData() const {
        cout << "Playing Time: " << playt <<  endl;
    }
};

class Disk : public Publication {
private:
    enum DiskType { CD, DVD } type;
    string ch;
public:
    void getData() {
     cout<<"enter disk type :";
     cin>> ch;
    }

    void putData() const {
       cout << "Disk Type: " << ch << endl;
    }
};
int main() {
    Book b;
    Tape t;
    Disk d;
    b.getData();
    t.getData();
    d.getData();
    b.putData();
    t.putData();
    d.putData();
    return 0;
}