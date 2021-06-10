#include "DIEM.h"

DIEM::DIEM(double a, double b) // Truyền vào 2 tham số, gán lần lượt cho hoành độ x và tung độ y
{
    x = a;
    y = b;
}

double DIEM::GetX() // Trả về 1 số kiểu double là hoành độ x của điểm đang xét
{
    return x;
}

double DIEM::GetY() // Trả về 1 số kiểu double là tung độ y của điểm đang xét
{
    return y;
}

DIEM DIEM::GetXY()
{
    return *this;
}

void DIEM::SetX(double a) // Thiết lập hoành độ x
{
    x = a;
}

void DIEM::SetY(double a) // Thiết lập tung độ y
{
    y = a;
}

void DIEM::SetXY(double a, double b) // Thiết lập hoành độ và tung độ
{
    x = a;
    y = b;
}

void DIEM::Nhap()
{
    cout << "\tNhap toa do diem:\n";
    cout << "Nhap hoanh do: ";
    cin >> x;
    cout << "Nhap tung do: ";
    cin >> y;
}

void DIEM::Xuat()
{
    cout << "Toa do cua diem la: (" << x << ", " << y << ")";
}

void DIEM::DiChuyen(double a, double b) // Tịnh tiến tọa độ ban đầu
{
    x += a;
    y += b;
}

bool DIEM::KiemTra(DIEM b) // Kiểm tra 2 điểm có trùng nhau hay không
{
    if (this->x == b.x && this->y == b.y)
        return 1;
    return 0;
}

double DIEM::KhoangCach(DIEM b) //Đồng thời cũng là cạnh của tam giác
{
    double hoanh_hoanh = this->x - b.x;
    double tung_tung = this->y - b.y;
    return sqrt(hoanh_hoanh * hoanh_hoanh + tung_tung * tung_tung);
}

DIEM DIEM::DiemDoiXung() // Tìm điểm đối xứng của điểm đang xét qua O
{
    DIEM Doi_Xung;
    int xx = x, yy = y;
    if (xx != 0) // Tránh trường hơpk trả về tọa độ -0
        xx = -xx;
    if (yy != 0) // Tránh trường hơpk trả về tọa độ -0
        yy = -yy;
    Doi_Xung.SetXY(xx, yy);
    return Doi_Xung;
}

bool DIEM::KiemTraTamGiac(DIEM b, DIEM c)
{
    double i = KhoangCach(b);
    double j = KhoangCach(c);
    double k = b.KhoangCach(c);
    if (i + j <= k || i + k <= j || j + k <= i)
        return 0;
    return 1;
}

double DIEM::Chu_Vi_Tam_Giac(DIEM &b, DIEM &c) // Tham chiếu để thay đổi điểm khi nhập lại trong trường hợp tam giác không hợp lệ
{
    if (KiemTraTamGiac(b, c) == 0) // Trường hợp tam giác không hợp lệ
    {
        cout << "Tam giac nay khong hop le!!!\n";
        do
        {
            cout << "Hay nhap lai toa do (x, y, z) cho 3 dinh cho tam giac\n";
            cin >> *this >> b >> c;
        } while (KiemTraTamGiac(b, c) == 0);
    }
    return this->KhoangCach(b) + this->KhoangCach(c) + b.KhoangCach(c);
}

double DIEM::Dien_Tich_Tam_Giac(DIEM &b, DIEM &c) // Tham chiếu để thay đổi điểm khi nhập lại trong trường hợp tam giác không hợp lệ
{
    if (KiemTraTamGiac(b, c) == 0) // Trường hợp tam giác không hợp lệ
    {
        cout << "Tam giac nay khong hop le!!!\n";
        do
        {
            cout << "Hay nhap lai toa do (x, y, z) cho 3 dinh cho tam giac\n";
            cin >> *this >> b >> c;
        } while (KiemTraTamGiac(b, c) == 0);
    }
    double ncv = this->Chu_Vi_Tam_Giac(b, c) / 2;                                                           // Nửa chu vi
    return sqrt(ncv * (ncv - this->KhoangCach(b)) * (ncv - this->KhoangCach(c)) * (ncv - c.KhoangCach(b))); // Công thức Herong
}

istream &operator>>(istream &is, DIEM &d)
{
    cout << "\tNhap toa do diem:\n";
    cout << "Nhap hoanh do: ";
    is >> d.x;
    cout << "Nhap tung do: ";
    is >> d.y;
    return is;
}

ostream &operator<<(ostream &os, DIEM d)
{
    os << "Toa do cua diem la: (" << d.x << ", " << d.y << ")";
    return os;
}
