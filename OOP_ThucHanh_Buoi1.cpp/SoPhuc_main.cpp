#include <iostream>
#include "So_Phuc.h"
using namespace std;

int main()
{
    SP a, b;
    cout << "Nhap so phuc thu nhat:\n";
    a.Nhap();
    cout << "Nhap so phuc thu hai: \n";
    b.Nhap();
    a.Tinh_Toan_So_Phuc(b);

    system("pause");
    return 0;
}