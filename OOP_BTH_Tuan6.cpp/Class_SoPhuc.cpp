#include "Class_SoPhuc.h"
#include <cmath>
using namespace std;

SP::SOPHUC() // constructor không truyền tham số
{
    this->SetThucAo(0, 0);
}

SP::SOPHUC(double t) // constructor truyền 1 tham số
{
    this->SetThucAo(t, 0);
}

double SP::GetThuc() // truy xuất phần thực
{
    return thuc;
}

double SP::GetAo() // truy xuất phần ảo
{
    return ao;
}

void SP::SetThuc(double t) // thiết lập phần thực
{
    thuc = t;
}

void SP::SetAo(double a) // thiết lập phần ảo
{
    ao = a;
}

void SP::SetThucAo(double t, double a)
{
    thuc = t;
    ao = a;
}

void SP::Nhap()
{
    cout << "Nhap phan thuc: ";
    cin >> thuc;
    cout << "Nhap phan ao: ";
    cin >> ao;
}

void SP::Xuat()
{
    if (ao == 0)
    {
        cout << "So phuc dang xet la so phuc dac biet (so thuc) co gia tri = " << thuc;
        return;
    }
    cout << "So phuc dang xet la (" << thuc << ", " << ao << ")";
}

istream &operator>>(istream &is, SP &sp)
{
    double t, a;
    cout << "Nhap phan thuc: ";
    is >> t;
    cout << "Nhap phan ao: ";
    is >> a;
    sp.SetThucAo(t, a);
    return is;
}

ostream &operator<<(ostream &os, SP sp)
{
    if (sp.ao == 0)
    {
        os << "So phuc dang xet la so phuc dac biet (so thuc) co gia tri = " << sp.thuc;
        return os;
    }
    os << "So phuc dang xet la (" << sp.GetThuc() << ", " << sp.GetAo() << ")";
    return os;
}

bool SP::operator==(SP a) // đè chồng toán tử ==
{
    if (this->GetThuc() != a.GetThuc() || this->GetAo() != a.GetAo())
        return 0;
    return 1;
}

bool SP::operator!=(SP a) // đè chồng toán tử !=
{
    return !(a == *this);
}

bool SP::operator>(SP sp) // Chỉ sử dụng cho số thực (số phức đặc biệt có phần ảo = 0)
{
    if (thuc > sp.thuc)
        return 1;
    return 0;
}

bool SP::operator<(SP sp) // Chỉ sử dụng cho số thực (số phức đặc biệt có phần ảo = 0)
{
    if (thuc < sp.thuc)
        return 1;
    return 0;
}

bool SP::operator>=(SP sp) // Chỉ sử dụng cho số thực (số phức đặc biệt có phần ảo = 0)
{
    return !(*this < sp);
}

bool SP::operator<=(SP sp) // Chỉ sử dụng cho số thực (số phức đặc biệt có phần ảo = 0)
{
    return !(*this > sp);
}

SP SP::operator+(SP sp) // Đè chồng toán tử +
{
    SP tong;
    tong.thuc = thuc + sp.thuc;
    tong.ao = ao + sp.ao;
    return tong;
}

SP SP::operator-(SP sp) // Đè chồng toán tử -
{
    SP hieu;
    hieu.thuc = thuc - sp.thuc;
    hieu.ao = ao - sp.ao;
    return hieu;
}

SP SP::operator*(SP sp) // Đè chồng toán tử *
{
    SP tich;
    tich.thuc = thuc * sp.thuc - ao * sp.ao;
    tich.ao = thuc * sp.ao + ao * sp.thuc;
    return tich;
}

SP SP::operator/(SP sp) // Đè chồng toán tử /
{
    SP thuong;
    thuong.thuc = (thuc + sp.thuc + ao * sp.ao) / (sp.thuc * sp.thuc + sp.ao * sp.ao);
    thuong.ao = (ao * sp.thuc - thuc * sp.ao) / (sp.thuc * sp.thuc + sp.ao * sp.ao);
    return thuong;
}