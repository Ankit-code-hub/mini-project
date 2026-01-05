



#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter any number: ";
    cin >> n;

    int *p = &n;

    int primeCount = 0;
    int notprime = 0;
    int pa=0;
    int np=0;
    int ceven=0;
    int codd=0;

    for(int num = 2; num <= *p; num++)
    {
        int count = 0;
        for(int i = 1; i <= num; i++)
        {
            if(num % i == 0)
            {
                count++;
            }
        }
        int prime = 0;  
        if(count == 2)
            prime = 1;
            if(prime == 1)
        {
            cout << num << " is Prime";
            primeCount++;
        }
        else
        {
            cout << num << " is Not Prime";
            notprime++;
        }
        cout << endl;
    }
    cout << "\nPalindrome Numbers:\n";

    for(int num = 2; num <= *p; num++)
    {
        int temp = num;
        int rev = 0;

        while(temp > 0)
        {
            int r = temp % 10;
            rev = rev * 10 + r;
            temp /= 10;
        }

        if(rev == num)
        {
            cout << num << " is Palindrome" << endl;
            pa++;
        }
        else{
        cout << num <<" is not palindrome" << endl;
         np++;
         }
    }
    cout << "\nEven/Odd Numbers:\n";

    for(int num = 2; num <= *p; num++)
    {
        if(num%2==0)
        {
            cout << num <<" is even" << endl;
            ceven++;
        }
        else
        {
            cout << num <<" is odd" << endl;
            codd;
        }
    }
    cout << "\nTotal Prime Numbers = " << primeCount;
    cout << "\nTotal Not Prime Numbers = " << notprime;
    cout << "\nTotal Palindrome Numbers = " << pa;
    cout << "\nTotal Not Palindrome Numbers = " <<np;
    cout << "\nTotal Even Numbers = " <<ceven;
    cout << "\nTotal Odd Numbers = " <<codd << endl;



    return 0;
}
