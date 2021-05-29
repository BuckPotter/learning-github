#include <iostream>
#include "Class_PhanSo.h"
using namespace std;

void PS::KhoiTao()
{
    ts = 1;
    ms = 1;
}

void PS::KhoiTao(int a)
{
    ts = a;
}

void PS::KhoiTao(int a, int b)
{
    ts = a;
    ms = b;
}

void PS::NhapPS() //Nhap PS
{
    cout << "Nhap tu so: ";
    cin >> ts;
    cout << "Nhap mau so: ";
    do
    {
        cin >> ms;
        if (ms == 0)
            cout << "Vui long nhap mau so khac 0!!!\n";
    } while (ms == 0);
}

void PS::Nhap2PS(PS &b)
{
    cout << "\tNhap vao 2 phan so \n";
    cout << "Nhap phan so thu nhat:\n";
    this->NhapPS();
    cout << "Nhap phan so thu hai:\n";
    b.NhapPS();
    cout << "\n\n";
}

void PS::XuatPS() //Xuat PS
{
    if (ms < 0)
    {
        ts = -ts;
        ms = -ms;
    }
    if (ts == 0)
    {
        cout << 0;
        return;
    }
    if (ms == 1)
    {
        cout << ts;
        return;
    }
    cout << ts << "/" << ms;
}

int PS::UCLN(int a, int b)
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

PS PS::Cong2PS(PHANSO b)
{
    PHANSO tong;
    tong.ts = this->ts * b.ms + this->ms * b.ts;
    tong.ms = this->ms * b.ms;
    return tong;
}

PS PS::Tru2PS(PHANSO b)
{
    PHANSO hieu;
    hieu.ts = this->ts * b.ms - this->ms * b.ts;
    hieu.ms = this->ms * b.ms;
    return hieu;
}

PS PS::Nhan2PS(PHANSO b)
{
    PHANSO tich;
    tich.ts = this->ts * b.ts;
    tich.ms = this->ms * b.ms;
    return tich;
}

PS PS::Chia2PS(PHANSO b)
{
    PHANSO thuong;
    thuong.ts = this->ts * b.ms;
    thuong.ms = this->ms * b.ts;
    return thuong;
}

PS PS::ToiGianPS() // Trả về phân số tối giản của phân số truyền vào
{
    int ucln = UCLN(ts, ms);
    ts = ts / ucln;
    ms = ms / ucln;
    return *this;
}

bool PS::KiemTraPSToiGian() // Trả về 1 nếu phân số đã tối giản, ngược lại trả về 0
{
    if (UCLN(ts, ms) == 1)
        return 1;
    return 0;
}
void PS::Tinh_Toan_Phan_So(PS b) // In ra màn hình cấc phép toán với 2 phân số tham số truyền vào
{
    PS bienphu;
    this->XuatPS();
    cout << " + ";
    b.XuatPS();
    cout << " = ";
    bienphu = this->Cong2PS(b);
    (bienphu.ToiGianPS()).XuatPS();
    cout << endl;

    this->XuatPS();
    cout << " - ";
    b.XuatPS();
    cout << " = ";
    bienphu = this->Tru2PS(b);
    (bienphu.ToiGianPS()).XuatPS();
    cout << endl;

    this->XuatPS();
    cout << " * ";
    b.XuatPS();
    cout << " = ";
    bienphu = this->Nhan2PS(b);
    (bienphu.ToiGianPS()).XuatPS();
    cout << endl;

    this->XuatPS();
    cout << " / ";
    b.XuatPS();
    cout << " = ";
    bienphu = this->Chia2PS(b);
    (bienphu.ToiGianPS()).XuatPS();
    cout << endl;
}

double PS::GiaTriPS() // Trả về giá trị thực của phân số
{
    return (double)ts / ms;
}

int PS::KiemTraPSLonHon(PS b) // So sánh 2 phân số, trả về 1 nếu phân số đầu tiên lớn hơn, ngược lại trả về -1, nếu 2 phân số bằng nhau trả về 0
{
    if (this->GiaTriPS() > b.GiaTriPS())
        return 1;
    else if (this->GiaTriPS() < b.GiaTriPS())
        return -1;
    else
        return 0;
}

void PHANSO::format(PS b, int oper) //Định dạng xuất phép toán VD: 1/2 + 1/2
{
    this->XuatPS();
    switch (oper)
    {
    case 6:
        if (b.ts < 0)
        {
            b.ts = -b.ts;
            cout << " - ";
            break;
        }
        cout << " + ";
        break;
    case 7:
        if (b.ts < 0)
        {
            b.ts = -b.ts;
            cout << " + ";
            break;
        }
        cout << " - ";
        break;
    case 8:
        cout << " * ";
        break;
    case 9:
        cout << " : ";
        break;
    }
    b.XuatPS();
    cout << " = ";
}

bool PS::KiemTra() //Kiểm tra phân số có bằng 0 hay không
{
    if (this->ts == 0)
        return 1;
    return 0;
}