#include <iostream>
#include "TestCandidate.h"
using namespace std;

void TEST::Nhap()
{
    cout << "Nhap so luong thi sinh: ";
    cin >> n;
    cout << "Nhap thong tin cho " << n << " thi sinh:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\t\tThi sinh thu " << i + 1;
        cout << endl;
        ThiSinh[i].Nhap();
        cout << endl;
    }
}

void TEST::LietKe() // In ra màn hình danh sách thí sinh có tổng điểm lớn hơn 15
{
    cout << "\tDanh sach thi sinh co tong diem lon hon 15 la: \n";
    int n = 1;
    for (int i = 0; i < n; i++)
    {
        if (ThiSinh[i].TongDiem() > 15)
        {
            cout << n++ << ". ";
            ThiSinh[i].Xuat();
            cout << endl;
        }
    }
}

void TEST::Xuat()
{
    for (int i = 0; i < n; i++)
    {
        ThiSinh[i].Xuat();
        cout << endl;
    }
}

void TEST::GiaiPhongBoNho()
{
    delete[] ThiSinh;
}