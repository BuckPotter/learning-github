#include "DIEM3C.h"

DIEM3C::DIEM3C(double xx, double yy, double zz)
{
    SetXY(xx, yy);
    z = zz;
}

DIEM3C::~DIEM3C() // Đặt lại điểm về gốc tọa độ
{
    x = y = z = 0;
}

DIEM3C DIEM3C::Get() // Trả về điểm có tọa độ của điểm đang xét
{
    return *this;
}

double DIEM3C::GetZ() // Bổ sung thêm GetZ so với lớp cha DIEM
{
    return z;
}

void DIEM3C::SetZ(double zz) // Bổ sung thêm GetZ so với lớp cha DIEM
{
    z = zz;
}

void DIEM3C::SetXYZ(double xx, double yy, double zz) // Thiết lập tọa độ x y và z
{
    SetXY(xx, yy); // Gọi lại hàm thiết lập SetXY đã xây dựng ở lớp cha
    z = zz;
}

void DIEM3C::SetXYZ(DIEM d, double zz)
{
    SetXY(d.GetX(), d.GetY());
    z = zz;
}

bool DIEM3C::KiemTra(DIEM3C d) // Kiểm tra 2 điểm ba chiều có trùng nhau không
{
    return this->DIEM::KiemTra(d) && z == d.z;
}

void DIEM3C::DiChuyen(double xx, double yy, double zz)
{
    DIEM::DiChuyen(xx, yy); // Gọi lại hàm di chuyển đã xây dựng ở lớp cha DIEM
    z += zz;
}

double DIEM3C::KhoangCach(DIEM3C d)
{
    return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2) + pow((z - d.z), 2));
}

DIEM3C DIEM3C::DiemDoiXung()
{
    int zz = 0;
    DIEM temp = DIEM::DiemDoiXung(); // Gọi lại hàm lấy tọa độ đối xứng cho x và y ở lớp DIEM
    if (z != 0)                      // Tránh trường hợp trả về -0
        zz = -z;
    DIEM3C temp2;           // biến phụ temp2 thuộc lớp temp2 để trả về
    temp2.SetXYZ(temp, zz); // Thiết lập tọa độ cho biên trả về
    return temp2;
}

void DIEM3C::Nhap()
{
    DIEM::Nhap(); // Gọi lại hàm nhập đã xây dựng ở lớp điểm
    cout << "Nhap cao do: ";
    cin >> z;
}

void DIEM3C::Xuat()
{
    cout << "Toa do cua diem la: (" << x << ", " << y << ", " << z << ")";
}

bool DIEM3C::KiemTraTamGiac(DIEM3C b, DIEM3C c)
{
    double i = KhoangCach(b);
    double j = KhoangCach(c);
    double k = b.KhoangCach(c);
    if (i + j <= k || i + k <= j || j + k <= i)
        return 0;
    return 1;
}

double DIEM3C::ChuVi(DIEM3C &b, DIEM3C &c) // Tham chiếu để thay đổi điểm khi nhập lại trong trường hợp tam giác không hợp lệ
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
    return KhoangCach(b) + KhoangCach(c) + b.KhoangCach(c);
}

double DIEM3C::DienTich(DIEM3C &b, DIEM3C &c) // Tham chiếu để thay đổi điểm khi nhập lại trong trường hợp tam giác không hợp lệ
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
    double i = KhoangCach(b);
    double j = KhoangCach(c);
    double k = b.KhoangCach(c);
    double p = this->ChuVi(b, c) / 2;
    return sqrt(p * (p - i) * (p - j) * (p - k));
}

istream &operator>>(istream &is, DIEM3C &d)
{
    cout << "\tNhap toa do diem:\n";
    cout << "Nhap hoanh do: ";
    is >> d.x;
    cout << "Nhap tung do: ";
    is >> d.y;
    cout << "Nhap cao do: ";
    is >> d.z;
    return is;
}

ostream &operator<<(ostream &os, DIEM3C d)
{
    os << "Toa do cua diem la: (" << d.x << ", " << d.y << ", " << d.z << ")";
    return os;
}