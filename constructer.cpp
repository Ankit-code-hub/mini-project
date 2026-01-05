


#include <iostream>
using namespace std;
class group 
{
 public:
 int mem;
 string name;
 string dept;
 
 group(int m,string d){
 mem=m;
 dept=d;
 }
 group(string n,int m,string d){
 name=n;
 mem=m;
 dept=d;
 }
 };
 int main(){
 group a1(11,"pro");
 a1.name="subham";
 group a2("rahul",23,"jio");
 group a3=a1;
 a3.name="vishal";
 cout << a1.name <<" "<<a1.mem<<" "<<a1.dept<< endl;
 cout << a2.name <<" "<<a2.mem<<" "<<a2.dept<< endl;
 cout << a3.name <<" "<<a3.mem<<" "<<a3.dept<< endl;

return 0;
}