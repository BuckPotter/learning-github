#include <iostream>
#include "Class_PhanSo.h"
using namespace std;

int main()
{
    int oper; //phuong thuc lam viec
    PS a, b, c, bienphu;
    bool KiemTraNhap2PS = 0, KiemTraNhap1PS = 0;
    do
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
        cout << "\t11. Kiem tra phan so da toi gian chua\n";
        cout << "\t0.  Thoat chuong trinh\n";

        cin >> oper;
        switch (oper)
        {
        case 1:
            c.NhapPS();
            KiemTraNhap1PS = 1;
            cout << "\n\n";
            break;
        case 2:
            if (KiemTraNhap1PS == 0)
            {
                cout << "Vui long thuc hien buoc 1 truoc de nhap vao 1 phan so!!!\n\n";
                break;
            }
            cout << "Phan so sau khi rut gon la ";
            (c.ToiGianPS()).XuatPS();
            cout << "\n\n";
            break;
        case 3:
            if (KiemTraNhap1PS == 0)
            {
                cout << "Vui long thuc hien buoc 1 truoc de nhap vao 1 phan so!!!\n\n";
                break;
            }
            cout << "Phan so ban vua nhap la: ";
            c.XuatPS();
            cout << "\n\n";
            break;
        case 4:
            a.Nhap2PS(b);
            KiemTraNhap2PS = 1;
            break;
        case 5:
            if (KiemTraNhap2PS == 0)
            {
                cout << "Vui long thuc hien buoc 4 truoc de nhap vao 2 phan so!!!\n\n";
                break;
            }
            if (a.KiemTraPSLonHon(b) == 1)
            {
                cout << "Phan so lon hon la: ";
                a.XuatPS();
            }
            else if (a.KiemTraPSLonHon(b) == -1)
            {
                cout << "Phan so lon hon la: ";
                b.XuatPS();
            }
            else
            {
                cout << "2 phan so bang nhau: ";
                a.XuatPS();
            }
            cout << "\n\n";
            break;
        case 6:
            if (KiemTraNhap2PS == 0)
            {
                cout << "Vui long thuc hien buoc 4 truoc de nhap vao 2 phan so!!!\n\n";
                break;
            }
            a.format(b, oper);
            bienphu = a.Cong2PS(b);
            bienphu = bienphu.ToiGianPS();
            bienphu.XuatPS();
            cout << "\n\n";
            break;
        case 7:
            if (KiemTraNhap2PS == 0)
            {
                cout << "Vui long thuc hien buoc 4 truoc de nhap vao 2 phan so!!!\n\n";
                break;
            }

            a.format(b, oper);
            bienphu = a.Tru2PS(b);
            bienphu = bienphu.ToiGianPS();
            bienphu.XuatPS();
            cout << "\n\n";
            break;
        case 8:
            if (KiemTraNhap2PS == 0)
            {
                cout << "Vui long thuc hien buoc 4 truoc de nhap vao 2 phan so!!!\n\n";
                break;
            }
            a.format(b, oper);
            bienphu = a.Nhan2PS(b);
            bienphu = bienphu.ToiGianPS();
            bienphu.XuatPS();
            cout << "\n\n";
            break;
        case 9:
            if (KiemTraNhap2PS == 0)
            {
                cout << "Vui long thuc hien buoc 4 truoc de nhap vao 2 phan so!!!\n\n";
                break;
            }
            if (b.KiemTra()) //Truong hop chia cho phan so bang 0
                cout << "Loi: khong chia duoc cho so 0\n\n";
            else
            {
                a.format(b, oper);
                bienphu = a.Chia2PS(b);
                bienphu = bienphu.ToiGianPS();
                bienphu.XuatPS();
                cout << "\n\n";
            }
            break;
        case 10:
            if (KiemTraNhap1PS == 0)
            {
                cout << "Vui long thuc hien buoc 1 truoc de nhap vao 1 phan so!!!\n\n";
                break;
            }
            cout << "Gia tri thuc cua phan so da nhap o buoc 1 la: " << a.GiaTriPS();
            cout << "\n\n";
            break;
        case 11:
            if (KiemTraNhap1PS == 0)
            {
                cout << "Vui long thuc hien buoc 1 truoc de nhap vao 1 phan so!!!\n\n";
                break;
            }
            if (c.KiemTraPSToiGian())
            {
                cout << "Phan so vua nhap o buoc 1 la: ";
                c.XuatPS();
                cout << ". Phan so nay da toi gian\n\n";
            }
            else
            {
                cout << "Phan so vua nhap o buoc 1 la: ";
                c.XuatPS();
                cout << ". Phan so nay chua toi gian\n\n";
            }
            break;
        case 0:
            cout << "\t\t\tCam on ban da su dung chuong trinh\n\n";
            break;
        default: // Truong hop nhap sai phuong thuc
            cout << "Phuong thuc khong hop le, vui long nhap lai!!!\n\n";
            break;
        }
        cout << "---------------------------------------------------------------";
    } while (oper != 0);

    system("pause");
    return 0;
}