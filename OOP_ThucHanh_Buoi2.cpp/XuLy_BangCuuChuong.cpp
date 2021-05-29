#include <iostream>
#include <iomanip>
#include "BangCuuChuong.h"
using namespace std;

BANGCUUCHUONG::BANGCUUCHUONG()
{
    m = n = 2;
}

BANGCUUCHUONG::BANGCUUCHUONG(int a)
{
    n = 2;
    m = a;
}

BANGCUUCHUONG::BANGCUUCHUONG(int a, int b)
{
    n = a;
    m = b;
}

void BCC::Nhap() // Nhập vào giá trị m va n
{
    do
    {
        cout << "Nhap m: ";
        cin >> m;
        if (m < 2 || m > 9)
            cout << "Vui long nhap m trong khoang [2;9] !!!\n";
    } while (m < 2 || m > 9);
    do
    {
        cout << "Nhap n: ";
        cin >> n;
        if (n < 2 || n > 9)
            cout << "Vui long nhap n trong khoang [2;9] !!!\n";
    } while (n < 2 || n > 9);
}

void BCC::In_BCC() // In ra màn hình bảng cửu chương m
{
    for (int i = 1; i <= 10; i++)
        cout << m << "  x " << setw(2) << i << " = " << setw(2) << m * i << endl;
}

void BCC::In_BCC_MN() // In ra màn hình bảng cửu chương từ m đến n
{
    if (m <= n)
    {
        for (int i = 1; i <= 10; i++)
        {
            for (int j = m; j <= n; j++)
            {
                cout << j << "  x " << setw(2) << i << " = " << setw(2) << i * j << "\t";
            }
            cout << endl;
        }
    }
    else
    {
        for (int i = 1; i <= 10; i++)
        {
            for (int j = m; j >= n; j--)
            {
                cout << j << "  x " << setw(2) << i << " = " << setw(2) << i * j << "\t";
            }
            cout << endl;
        }
    }
}

void BCC::In_BCC_TH() // In ra màn hình bảng cửu chương tổng hợp từ 2 đến 9
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cout << setw(4) << i * j;
        }
        cout << endl;
    }
}