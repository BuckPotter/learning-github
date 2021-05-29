#include <iostream>
#include "Phan_So.h"
using namespace std;

void NhapPS(PS &a) //Nhap PS
{
    cout << "Nhap tu so: ";
    cin >> a.ts;
    cout << "Nhap mau so: ";
    do
    {
        cin >> a.ms;
        if (a.ms == 0)
            cout << "Vui long nhap mau so khac 0!!!\n";
    } while (a.ms == 0);
}

void XuatPS(PS a) //Xuat PS
{
    if (a.ms < 0)
    {
        a.ts = -a.ts;
        a.ms = -a.ms;
    }
    if (a.ts == 0)
    {
        cout << 0;
        return;
    }
    if (a.ms == 1)
    {
        cout << a.ts;
        return;
    }
    cout << a.ts << "/" << a.ms;
}

int UCLN(int a, int b)
{
    a = abs(a);
    b = abs(b);
    if (a == 0 || b == 0)
        return a + b;
    if (a == 1 || b == 1)
        return 1;
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

PS Tong2PS(PS a, PS b) // Tinh tong 2 phan so va tra ve phan so tong
{
    PS tong;
    tong.ts = a.ts * b.ms + a.ms * b.ts;
    tong.ms = a.ms * b.ms;
    return tong;
}

PS Hieu2PS(PS a, PS b) // Tinh hieu 2 phan so va tra ve phan so hieu
{
    PS hieu;
    hieu.ts = a.ts * b.ms - a.ms * b.ts;
    hieu.ms = a.ms * b.ms;
    return hieu;
}

PS Tich2PS(PS a, PS b) // Tinh tich 2 phan so va tra ve phan so tich
{
    PS tich;
    tich.ts = a.ts * b.ts;
    tich.ms = a.ms * b.ms;
    return tich;
}

PS Thuong2PS(PS a, PS b) // Tinh thuong 2 phan so va tra ve phan so thuong
{
    PS thuong;
    thuong.ts = a.ts * b.ms;
    thuong.ms = a.ms * b.ts;
    return thuong;
}

PS ToiGianPS(PS a) //Toi gian PS va tra ve phan so toi gian
{
    int ucln = UCLN(a.ts, a.ms);
    a.ts = a.ts / ucln;
    a.ms = a.ms / ucln;
    return a;
}

float GiaTriThuc(PS a)
{
    return (float)a.ts / a.ms;
}