#include <iostream>
#include <string.h>
#include "Sinh_Vien.h"
using namespace std;

void NhapSV(SV &a)
{
    cout << "MSSV: ";
    cin.ignore();
    cin >> a.id;
    cin.ignore();
    cout << "Ten: ";
    cin.getline(a.ten, 20);
    cout << "Diem Toan: ";
    cin >> a.toan;
    cout << "Diem Van: ";
    cin >> a.van;
    a.DTB = (a.toan + a.van) / 2.0;
    switch ((int)a.DTB)
    {
    case 8:
        a.hocbong = 1;
        break;
    case 9:
    case 10:
        a.hocbong = 2;
        break;
    default:
        a.hocbong = 0;
    }
}

void XepLoaiSV(float DTB)
{
    int dtb = DTB;
    switch (dtb)
    {
    case 10:
    case 9:
        cout << "Xuat sac";
        break;
    case 8:
        cout << "Gioi";
        break;
    case 7:
        cout << "Kha";
        break;
    case 6:
    case 5:
        cout << "Trung binh";
        break;
    default:
        cout << "Yeu";
        break;
    }
}

void XuatSV(SV a)
{
    cout << "Diem trung binh cua sinh vien " << a.ten << ", co MSSV " << a.id << " la: " << a.DTB;
    cout << " - Xep loai: ";
    XepLoaiSV(a.DTB);
    cout << ". Duoc nhan hoc bong " << a.hocbong << " trieu VND\n";
}

void NhapLop(SV arr[], int &n) // n la si so lop
{
    cout << "Nhap si so lop: ";
    cin >> n; // nhap si so lop
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin cho sinh vien thu " << i + 1 << endl;
        NhapSV(arr[i]);
        cout << endl;
    }
}

void XuatLop(SV arr[], int n)
{
    for (int i = 0; i < n; i++)
        XuatSV(arr[i]);
}

void DS_HocSinhYeu(SV arr[], int n) // in ra danh sach cac hoc sinh yeu
{
    SV *p = new SV;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].DTB < 5)
        {
            p[x++] = arr[i];
        }
    }

    cout << "Danh sach hoc sinh yeu la:\n";
    for (int i = 0; i < x; i++)
        cout << i + 1 << ". " << p[i].ten << ", MSSV: " << p[i].id << endl;

    delete p;
    p = NULL;
}

int SoLuongHSTB(SV arr[], int n) // tra ve 1 so nguyen la so luong hoc sinh trung binh trong lop
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].DTB >= 5 && arr[i].DTB < 7)
            dem++;
    }
    return dem;
}

int TongHocBong_HSXuatSac(SV arr[], int n) // Tra ve 1 so nguyen duong la so tien hoc bong da trao cho hoc sinh xuat sac
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].DTB >= 8)
            total += arr[i].hocbong;
    }
    return total;
}

float DTBChung_HSG(SV arr[], int n) // Tra ve 1 so thuc la diem trung binh chung cua cac hoc sinh gioi
{
    float dtb = 0, dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].DTB >= 8)
        {
            dtb += arr[i].DTB;
            dem++;
        }
    }
    return dtb / dem;
}

bool KiemTraHSY(SV arr[], int n) // kiem tra co hoc sinh yeu trong lop khong
{
    for (int i = 0; i < n; i++)
        if (arr[i].DTB < 5)
            return 0;
    return 1;
}

void SapXepGiamDan(SV arr[], int n) // sap xep lop theo danh sach hoc bong giam dan
{
    SV tam;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
            if (arr[j].hocbong > arr[j - 1].hocbong || (arr[j].hocbong == arr[j - 1].hocbong && strcmp(arr[j].id, arr[j - 1].id) < 0))
            { // Neu hoc sinh truoc co hoc bong nhieu hon hoc sinh sau thi doi cho
                // Hoac neu 2 hoc sinh co hoc bong bang nhau va ID hoc sinh truoc nho hon hoc sinh sau thi doi cho
                tam = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tam;
            }
    }
}

void TimSV(SV arr[], int n) // cho phep nhap thong tin cua sinh vien can tim khi goi ham
{
    int oper; // chon phuong thuc tim kiem
    cout << "\t\t\tChon phuong thuc tim kiem:\n";
    cout << "\t1. Tim kiem bang ten\n";
    cout << "\t2. Tim kiem bang MSSV\n";
    cout << "\t3. Tim kiem bang DTB\n";
    cout << "\t4. Tim kiem bang hoc bong\n";
    cout << "\t0. Thoat chuong trinh\n";
    int dem;
    do
    {
        cin >> oper;
        switch (oper)
        {
        case 1:
            cout << "Nhap ten sinh vien can tim: ";
            char name[20];
            fflush(stdin);
            cin.getline(name, 20);
            dem = 0;
            for (int i = 0; i < n; i++)
                if (strcmp(name, arr[i].ten) == 0)
                {
                    XuatSV(arr[i]);
                    dem++;
                }
            if (dem == 0)
                cout << "Khong tim thay sinh nao!!!\n\n";
            else
                cout << endl;
            break;
        case 2:
            cout << "Nhap MSSV cua sinh vien can tim: ";
            char maso[15];
            dem = 0;
            fflush(stdin);
            cin.getline(maso, 20);
            for (int i = 0; i < n; i++)
                if (strcmp(maso, arr[i].id) == 0)
                {
                    XuatSV(arr[i]); // MSSV khong trung nhau nen tim duoc thi ket thuc chuong trinh ngay lap tuc
                    dem++;
                    break;
                }
            if (dem == 0)
                cout << "Khong tim thay sinh vien nao!!!\n\n";
            else
                cout << endl;
            break;
        case 3:
            cout << "Nhap DTB cua sinh vien can tim: ";
            float diem;
            dem = 0;
            cin >> diem;
            for (int i = 0; i < n; i++)
                if (arr[i].DTB == diem)
                {
                    XuatSV(arr[i]);
                    dem++;
                }
            if (dem == 0)
                cout << "Khong tim thay sinh vien nao!!!\n\n";
            else
                cout << endl;
            break;
        case 4:
            cout << "Nhap hoc bong ma sinh vien can tim duoc nhan: ";
            short hb;
            dem = 0;
            cin >> hb;
            for (int i = 0; i < n; i++)
                if (arr[i].hocbong == hb)
                {
                    XuatSV(arr[i]);
                    dem++;
                }
            if (dem == 0)
                cout << "Khong tim thay sinh vien nao!!!\n\n";
            else
                cout << endl;
            break;
        case 0:
            cout << "\tCam on ban da su dung chuong trinh\n";
            break;
        default:
            cout << "Phuong thuc khong hop le!!!\n\n";
            break;
        }
    } while (oper != 0);
}
