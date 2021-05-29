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
    cout << "2 phan so ban vua nhap lan luot la ";
    XuatPS(ToiGianPS(a));
    cout << " va ";
    XuatPS(ToiGianPS(b));

    // Xu ly va xuat ket qua
    cout
        << "\n\t\t\tMENU\n";
    cout << " \tNhap vao 1 trong cac phuong thuc sau de thao tac voi 2 phan so ban vua nhap: \n";
    cout << " \t'+' Cong 2 phan so \n";
    cout << " \t'-' Tru 2 phan so \n";
    cout << " \t'*' Nhan 2 phan so \n";
    cout << " \t'/' Chia 2 phan so \n";
    cout << " \tNhap '0' de ket thuc\n";
    char oper; // Bien the hien phuong thuc lam viec
    do
    {
        cin >> oper;
        switch (oper)
        {
        case '+':
            cout << "Tong cua 2 phan so tren la: ";
            XuatPS(ToiGianPS(Tong2PS(a, b)));
            cout << "\n\n";
            break;
        case '-':
            cout << "Hieu cua 2 phan so tren la: ";
            XuatPS(ToiGianPS(Hieu2PS(a, b)));
            cout << "\n\n";
            break;
        case '*':
            cout << "Tich cua 2 phan so tren la: ";
            XuatPS(ToiGianPS(Tich2PS(a, b)));
            cout << "\n\n";
            break;
        case '/':
            if (b.ts == 0) //Truong hop chia cho phan so bang 0
                cout << "Loi: khong chia duoc cho so 0\n\n";
            else
            {
                cout << "Thuong cua 2 phan so tren la: ";
                XuatPS(ToiGianPS(Thuong2PS(a, b)));
                cout << "\n\n";
            }
            break;
        case '0':
            cout << "\t\t\tCam on ban da su dung chuong trinh\n";
            break;
        default: // Truong hop nhap sai phuong thuc
            cout << "Phuong thuc khong hop le, vui long nhap lai!!!\n\n";
        }
    } while (oper != '0');

    system("pause");
    return 0;
}