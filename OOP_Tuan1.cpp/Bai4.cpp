#include <iostream>
#include "NTN.h"
using namespace std;

int main()
{
    // Khai bao va nhap lieu
    NTN day;
    cout << "Nhap vao mot ngay theo thu tu ngay, thang, nam:\n";
    NhapNTN(day);

    // Xu ly va xuat ket qua
    cout << "\nNgay ke tiep la: ";
    FindTheNextDay(day);
    cout << day.ng << "/" << day.th << "/" << day.n << endl;

    system("pause");
    return 0;
}