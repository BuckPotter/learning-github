#include <iostream>
#include "NTN.h"
using namespace std;

bool KiemTraNTN(NTN a) // Kiem tra dieu kien nhap
{
    if (a.th > 12 || a.th < 1)
        return 0;
    switch (a.th)
    {
        // Truong hop cac thang 31 ngay
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (a.ng > 31 || a.ng < 1)
            return 0;
        break;

        // Truong hop cac thang 30 ngay
    case 4:
    case 6:
    case 9:
    case 11:
        if (a.ng < 1 || a.ng > 30)
            return 0;
        break;

        // Truong hop thang 2
    case 2:
        if (a.n % 400 == 0 || (a.n % 4 == 0 && a.n % 100 != 0)) // Kiem tra nam nhuan
            if (a.ng < 1 || a.ng > 29)
                return 0;
            else
                return 1;
        else if (a.ng < 1 || a.ng > 28)
            return 0;
        break;
    }

    // Neu vuot qua tat ca cac dieu kien ben tren thi dieu kien nhap chac chac dung
    return 1;
}

void NhapNTN(NTN &a)
{
    do
    {
        cin >> a.ng >> a.th >> a.n;
        if (KiemTraNTN(a) == 0)
            cout << "Ngay ban vua nhap khong hop le, vui long kiem tra lai!!!\n\n";
    } while (KiemTraNTN(a) == 0);
}

void FindTheNextDay(NTN &a) // Tim ngay ke tiep va in ra man hinh
{
    if (a.ng == 31, a.th == 12)
    {
        a.ng = 1;
        a.th = 1;
        a.n++;
        return;
    }

    switch (a.th)
    {
    // Truong hop cac thang co 31 ngay
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (a.ng < 31)
            a.ng++;
        else //ngay 31 thi tang thang va dat lai ngay
        {
            a.th++;
            a.ng = 1;
        }
        break;

    // Truong hop thang 2
    case 2:
        if (a.n % 400 == 0 || (a.n % 4 == 0 && a.n % 100 != 0)) //Neu nam nhuan;
            if (a.ng < 29)
                a.ng++;
            else
            {
                a.th++;
                a.ng = 1;
            }
        else
        {
            if (a.ng < 28)
                a.ng++;
            else
            {
                a.th++;
                a.ng = 1;
            }
        }
        break;

    //Truong hop cac thang co 30 ngay
    case 4:
    case 6:
    case 9:
    case 11:
        if (a.ng < 30)
            a.ng++;
        else
        {
            a.th++;
            a.ng = 1;
        }
        break;
    }
}

int SoNgayTrongThang(int a) // tra ve so ngay cua thang a
{
    switch (a)
    {
        // Truong hop cac thang 31 ngay
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;

        // Truong hop cac thang 30 ngay
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;

        // Truong hop thang 2
    case 2:
        if (a % 400 == 0 || (a % 4 == 0 && a % 100 != 0)) // Kiem tra nam nhuan
            return 29;
        else
            return 28;
        break;
    }
}