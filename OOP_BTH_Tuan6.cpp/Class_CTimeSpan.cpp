#include "Class_CTimeSpan.h"

using namespace std;

CTP::CTimeSpan()
{
    h = m = s = 0;
}

CTP::CTimeSpan(int hh)
{
    h = hh;
    m = s = 0;
}

CTP::CTimeSpan(int hh, int mm)
{
    h = hh;
    m = mm;
    s = 0;
}

CTP::CTimeSpan(int hh, int mm, int ss)
{
    h = hh;
    m = mm;
    s = ss;
}

int CTP::Get_h()
{
    return h;
}

int CTP::Get_m()
{
    return m;
}

int CTP::Get_s()
{
    return s;
}

CTP CTP::Get_CTIMESPAN()
{
    return *this;
}

void CTP::Set_h(int hh)
{
    h = hh;
}

void CTP::Set_m(int mm)
{
    m = mm;
}

void CTP::Set_s(int ss)
{
    s = ss;
}

void CTP::Set(int hh, int mm, int ss)
{
    h = hh;
    m = mm;
    s = ss;
}

void CTP::Nhap()
{
    cout << "Nhap vao mot khoang thoi gian:\n";
    cout << "\tNhap gio: ";
    cin >> h;
    cout << "\tNhap phut: ";
    cin >> m;
    cout << "\tNhap giay: ";
    cin >> s;
}
void CTP::Chuan_Hoa() // chuẩn hóa khoảng thời gian, giả sử 1 khoảng thời gian 1h 80m 90s sẽ cần chuẩn hóa
{
    while (s >= 60) // Đổi giây sang phút nếu số giây >= 60
    {
        s -= 60;
        m++;
    }
    while (m >= 60) // Đổi phút sang giờ nếu số phút >= 60
    {
        m -= 60;
        h++;
    }
}

void CTP::Xuat()
{
    this->Chuan_Hoa();
    cout << "Khoang thoi gian dang xet la: " << h << " gio, " << m << " phut, " << s << " giay";
}

istream &operator>>(istream &is, CTP &time)
{
    int h, m, s;
    cout << "Nhap vao mot khoang thoi gian:\n";
    cout << "\tNhap gio: ";
    is >> h;
    cout << "\tNhap phut: ";
    is >> m;
    cout << "\tNhap giay: ";
    is >> s;
    time.Set(h, m, s);
    return is;
}

CTP CTP::operator+(CTP time)
{
    CTP tong;
    tong.s = s + time.s;
    tong.m = m + time.m;
    tong.h = h + time.h;
    tong.Chuan_Hoa();
    return tong;
}

CTP CTP::operator-(CTP time) // Trả về 1 khoảng thời gian biểu diễn độ chênh lệch của 2 khoảng thời gian
{
    int a = h * 60 * 60 + m * 60 + s;                // quy đổi ra giây
    int b = time.h * 60 * 60 + time.m * 60 + time.s; // quy đổi ra giây
    CTP hieu;
    if (a >= b)
        hieu.Set_s(a - b);
    else
        hieu.Set_s(b - a);
    hieu.Chuan_Hoa();
    return hieu;
}

ostream &operator<<(ostream &os, CTP time)
{
    time.Chuan_Hoa();
    os << "Khoang thoi gian dang xet la: " << time.Get_h() << " gio, " << time.Get_m() << " phut, " << time.Get_s() << " giay";
}

bool CTP::operator==(CTP time)
{
    if (h != time.h || m != time.m || s != time.s)
        return 0;
    return 1;
}

bool CTP::operator!=(CTP time)
{
    return !(*this == time);
}

bool CTP::operator>(CTP time)
{
    // Quy đổi ra cùng đơn vị giây để so sánh
    int n1 = h * 60 * 60 + m * 60 + s;
    int n2 = time.h * 60 * 60 + time.m * 60 + time.s;
    if (n1 > n2)
        return 1;
    return 0;
}

bool CTP::operator<(CTP time)
{
    // Quy đổi ra cùng đơn vị giây để so sánh
    int n1 = h * 60 * 60 + m * 60 + s;
    int n2 = time.h * 60 * 60 + time.m * 60 + time.s;
    if (n1 < n2)
        return 1;
    return 0;
}

bool CTP::operator>=(CTP time)
{
    return !(*this < time);
}

bool CTP::operator<=(CTP time)
{
    return !(*this > time);
}