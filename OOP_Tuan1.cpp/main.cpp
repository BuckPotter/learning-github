#include <iostream>
#include "Phan_So.h"
using namespace std;

int main()
{
    cout << "\n\t\t\tMENU\n";
    cout << "\t\tNhap vao 1 trong cac phuong thuc sau de thao tac voi 2 phan so ban vua nhap: \n";
    cout << "\t1.  Nhap 1 phan so\n";
    cout << "\t2.  Rut gon 1 phan so\n";
    cout << "\t3.  Xuat 1 phan so\n";
    cout << "\t4.  Nhap 2 phan so\n";
    cout << "\t5.  Tim phan so lon hon trong 2 phan so\n";
    cout << "\t6.  Tinh tong 2 phan so\n";
    cout << "\t7.  Tinh hieu 2 phan so\n";
    cout << "\t8.  Tinh tich 2 phan so\n";
    cout << "\t9.  Tinh thuong 2 phan so\n";
    cout << "\t10. Tinh gia tri thuc cua phan so\n";
    cout << "\t0.  Thoat chuong trinh\n";

    short oper; //phuong thuc lam viec
    PS a, b;
    do
    {
        cin >> oper;
        switch (oper)
        {
        case 1:
            NhapPS(a);
            cout << "\n\n";
            break;
        case 2:
            NhapPS(a);
            cout << "Phan so sau khi rut gon la ";
            XuatPS(ToiGianPS(a));
            cout << "\n\n";
            break;
        case 3:
            NhapPS(a);
            cout << "Phan so ban vua nhap la: ";
            XuatPS(ToiGianPS(a));
            cout << "\n\n";
            break;
        case 4:
            cout << "\tNhap vao 2 phan so \n";
            cout << "Nhap phan so thu nhat:\n";
            NhapPS(a);
            cout << "Nhap phan so thu hai:\n";
            NhapPS(b);
            cout << "\n\n";
            break;
        case 5:
            cout << "Nhap phan so thu nhat:\n";
            NhapPS(a);
            cout << "Nhap phan so thu hai:\n";
            NhapPS(b);
            if (GiaTriThuc(a) == GiaTriThuc(b))
            {
                cout << "2 phan so vua nhap bang nhau ";
                XuatPS(a);
                cout << "\n\n";
                break;
            }
            cout << "Phan so lon hon la ";
            if (GiaTriThuc(a) > GiaTriThuc(b))
                XuatPS(a);
            else if (GiaTriThuc(a) < GiaTriThuc(b))
                XuatPS(b);
            cout << "\n\n";
            break;
        case 6:
            cout << "Nhap phan so thu nhat:\n";
            NhapPS(a);
            cout << "Nhap phan so thu hai:\n";
            NhapPS(b);
            cout << "Tong cua 2 phan so tren la: ";
            XuatPS(ToiGianPS(Tong2PS(a, b)));
            cout << "\n\n";
            break;
        case 7:
            cout << "Nhap phan so thu nhat:\n";
            NhapPS(a);
            cout << "Nhap phan so thu hai:\n";
            NhapPS(b);
            cout << "Hieu cua 2 phan so tren la: ";
            XuatPS(ToiGianPS(Hieu2PS(a, b)));
            cout << "\n\n";
            break;
        case 8:
            cout << "Nhap phan so thu nhat:\n";
            NhapPS(a);
            cout << "Nhap phan so thu hai:\n";
            NhapPS(b);
            cout << "Tich cua 2 phan so tren la: ";
            XuatPS(ToiGianPS(Tich2PS(a, b)));
            cout << "\n\n";
            break;
        case 9:
            cout << "Nhap phan so thu nhat:\n";
            NhapPS(a);
            cout << "Nhap phan so thu hai:\n";
            NhapPS(b);
            if (b.ts == 0) //Truong hop chia cho phan so bang 0
                cout << "Loi: khong chia duoc cho so 0\n\n";
            else
            {
                cout << "Thuong cua 2 phan so tren la: ";
                XuatPS(ToiGianPS(Thuong2PS(a, b)));
                cout << "\n\n";
            }
            break;
        case 10:
            NhapPS(a);
            cout << "Gia tri thuc cua phan so vua nhap la: " << GiaTriThuc(a);
            break;
        case 0:
            cout << "\t\t\tCam on ban da su dung chuong trinh\n";
            break;
        default: // Truong hop nhap sai phuong thuc
            cout << "Phuong thuc khong hop le, vui long nhap lai!!!\n\n";
            break;
        }

    } while (oper != 0);

    system("pause");
    return 0;
}