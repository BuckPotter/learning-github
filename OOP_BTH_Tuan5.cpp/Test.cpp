#include <iostream>
#include "String.cpp"
using namespace std;

int main()
{
    /*char a[100] = "Hello buddy";
    fflush(stdin);
    String b(a);*/
    string a;
    a = "Hello";
    a = a + 'x';
    cout << a;
    return 0;
}