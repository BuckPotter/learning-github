#include <iostream>
#include "Phan_So.h"
using namespace std;

int main()
{
    // Khai bao va nhap lieu
    PS a, b;
    cout << "Nhap phan so dau tien: \n";
    NhapPS(a);
    cout << "Nhap phan so thu hai: \n";
    NhapPS(b);

    // Xu ly va xuat ket qua
    double kq1 = (float)a.ts / a.ms; // gia tri thuc phan so 1
    double kq2 = (float)b.ts / b.ms; // gia tri thuc phan so 2

    if (kq1 > kq2)
    {
        cout << "\nPhan so lon hon la: ";
        XuatPS(ToiGianPS(a));
    }
    else if (kq1 < kq2)
    {
        cout << "\nPhan so lon hon la: ";
        XuatPS(ToiGianPS(b));
    }
    else
    {
        cout << "\n2 phan so bang nhau: ";
        XuatPS(ToiGianPS(a));
    }

    cout << endl;
    system("pause");
    return 0;
}