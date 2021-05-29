#include <iostream>
#include "Phan_So.h"
using namespace std;

int main() // Nhap vao 1 phan so va rut gon
{
    // Khai bao va nhap lieu
    PS a;
    NhapPS(a);

    // Xu ly va xuat ket qua
    cout << "\nPhan so ban vua nhap la: ";
    XuatPS(ToiGianPS(a));

    cout << endl;
    system("pause");
    return 0;
}