#include <iostream>
#include <string.h>
#include "Sinh_Vien.cpp"
using namespace std;

int main()
{
    SV arr[50];
    int n;
    NhapLop(arr, n);
    XuatLop(arr, n);
    cout << endl;
    TimSV(arr, n);

    system("pause");
    return 0;
}
