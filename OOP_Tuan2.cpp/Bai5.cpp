#include <iostream>
#include <string>
#include "Sinh_Vien.h"
using namespace std;

int main()
{
    // Khai bao va nhap lieu
    SV a;
    cout << "Nhap thong tin sinh vien\n";
    NhapSV(a);

    // Xu ly va xuat ket qua
    XuatSV(a);

    cout << endl;
    system("pause");
    return 0;
}