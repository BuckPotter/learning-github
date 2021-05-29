#include <iostream>
#include "Candidate.h"

using namespace std;

void CDD::Nhap()
{
    cout << "MSSV: ";
    cin.ignore();
    cin >> id;
    cin.ignore();
    cout << "Ten: ";
    cin.getline(ten, 20);
    cout << "Nhap ngay sinh (lan luot ngay - thang - nam): ";
    cin >> ng >> th >> n;
    cout << "Diem Toan: ";
    cin >> toan;
    cout << "Diem Van: ";
    cin >> van;
    cout << "Diem Anh: ";
    cin >> anh;
    DTB = (toan + anh + van) / 3.0;
}

void CDD::Xuat()
{
    cout << "Sinh vien: " << ten << "\tMSSV: " << id;
    cout << "\tDiem toan: " << toan;
    cout << "\tDiem van: " << van;
    cout << "\tDiem anh: " << anh;
    cout << "\tTong diem: " << this->TongDiem();
    cout << "\tDiem trung binh: " << DTB;
    cout << " - Xep loai: ";
    this->XepLoaiSV();
}

void CDD::XepLoaiSV()
{
    switch ((int)DTB)
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

int CDD::TongDiem()
{
    return toan + van + anh;
}