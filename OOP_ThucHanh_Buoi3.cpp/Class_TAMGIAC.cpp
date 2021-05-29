#include <cmath>
#include "Class_TAMGIAC.h"
using namespace std;

typedef TAMGIAC TG; // Viết tắt TAMGIAC -> TG

TG::TAMGIAC() : A(0, 0), B(0, 0), C(0, 0)
{
    // không truyền tham số xem như 3 đỉnh trùng với gốc tọa độ
}

TG::TAMGIAC(double xA, double yA, double xB, double yB, double xC, double yC) : A(xA, yA), B(xB, yB), C(xC, yC)
{
    // 3 cặp tham số kiểu double, mỗi cặp ứng với 1 đỉnh của tam giác
}

TG::TAMGIAC(Diem a, Diem b, Diem c)
{
    // Tham số là 3 điểm -> mỗi điểm ứng với 1 đỉnh của tam giác
    A = a;
    B = b;
    C = c;
}

Diem TG::GetA() // Trả về 1 điểm chính là đỉnh A
{
    return A;
}

Diem TG::GetB() // Trả về 1 điểm chính là đỉnh B
{
    return B;
}

Diem TG::GetC() // Trả về 1 điểm chính là đỉnh C
{
    return C;
}

void TG::SetA(double xx, double yy) // Thiết lập tọa độ cho đỉnh A
{
    A.SetXY(xx, yy);
}

void TG::SetB(double xx, double yy)
{
    B.SetXY(xx, yy);
}

void TG::SetC(double xx, double yy)
{
    C.SetXY(xx, yy);
}

void TG::SetABC(Diem a, Diem b, Diem c)
{
}

void TG::Nhap()
{
    do
    {
        cout << "\t\tLan luot nhap vao 3 dinh cua tam giac o day:\n";
        cout << "\tNhap dinh A:";
        cin >> A; // Đã overload phương thức nhập cho đối tượng điểm ở thư viện Diem.cpp
        cout << "\tNhap dinh B:";
        cin >> B; // Đã overload phương thức nhập cho đối tượng điểm ở thư viện Diem.cpp
        cout << "\tNhap dinh C:";
        cin >> C; // Đã overload phương thức nhập cho đối tượng điểm ở thư viện Diem.cpp
        if (this->Kiem_Tra() == 0)
            cout << "\nTam gia ban vua nhap khong hop le!!!\n";
    } while (this->Kiem_Tra() == 0);
}

void TG::Xuat()
{
    if (this->Kiem_Tra() == 0)
    {
        cout << "Tam giac dang xet khong hop le!!!";
        return;
    }
    cout << "Tam giac co 3 dinh lan luot la:\n";
    cout << "Toa do cua dinh A la: (" << A.GetX() << ", " << A.GetY() << ")\n";
    cout << "Toa do cua dinh B la: (" << B.GetX() << ", " << B.GetY() << ")\n";
    cout << "Toa do cua dinh C la: (" << C.GetX() << ", " << C.GetY() << ")\n";
}

void TG::Di_Chuyen(double xx, double yy) //tọa độ của cả 3 đỉnh đều di chuyển một đoạn tương ứng với tham số đầu vào
{
    A.DiChuyen(xx, yy); // phương thức di chuyển Diem được cài đặt ở file thư viện Diem.cpp
    B.DiChuyen(xx, yy); // phương thức di chuyển Diem được cài đặt ở file thư viện Diem.cpp
    C.DiChuyen(xx, yy); // phương thức di chuyển Diem được cài đặt ở file thư viện Diem.cpp
}

bool TG::Kiem_Tra() //Kiem tra xem tam giác có hợp lệ không
{
    double a = A.KhoangCach(B);
    double b = B.KhoangCach(C);
    double c = C.KhoangCach(A);
    if (a + b <= c || a + c <= b || b + c <= a)
        return 0;
    return 1;
}

void TG::Phan_Loai() // Kết quả có thể bị sai khi nhập vào các điểm mà độ dài cạnh là số có chứa căn bởi vì độ chính xác, làm tròn số chưa chuẩn dẫn đến sai trong các phép so sánh
{
    double a = A.KhoangCach(B);
    double b = B.KhoangCach(C);
    double c = C.KhoangCach(A);

    if (this->Kiem_Tra() == 0)
    {
        cout << "Khong phai tam giac"; // Khong phai tam giac
        return;
    }

    if (a == b && b == c)
    {
        cout << "Tam giac deu"; // Tam giác đều
        return;
    }

    else if ((a == b && a == c) || (b == a && b == c) || (c == a && c == b)) // Điều kiện tam giác cân
    {
        // Điều kiện tam giác vuông
        if ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a))
        {
            cout << "Tam giac vuong can"; // Tam giác vuông cân
            return;
        }
        else
        {
            cout << "Tam giac can"; // Tam giác cân
            return;
        }
    }

    if ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a))
        cout << "Tam giac vuong"; // Tam giác vuông

    else
        cout << "Tam giac thuong"; // Không phái các trường hợp trên => tam giác thường;
}

double TG::Chu_Vi()
{
    if (this->Kiem_Tra() == 0) // return giá trị âm nếu như tam giác không hợp lệ
        return -1;
    return A.KhoangCach(B) + A.KhoangCach(C) + B.KhoangCach(C);
}

double TG::Dien_Tich()
{
    if (this->Kiem_Tra() == 0) // return giá trị âm nếu như tam giác không hợp lệ
        return -1;
    double ncv = Chu_Vi() / 2;                                                                      // Nửa chu vi
    return sqrt(ncv * (ncv - A.KhoangCach(B)) * (ncv - A.KhoangCach(C)) * (ncv - C.KhoangCach(B))); // Công thức Herong
}

istream &operator>>(istream &is, TG &tg) // Đè chồng toán tử nhập >> để nhập vào 1 điểm bằng lệnh cin
{
    do
    {
        cout << "\t\tLan luot nhap vao 3 dinh cua tam giac o day:\n";
        cout << "Nhap dinh A: \n";
        is >> tg.A; // Đã overload phương thức nhập cho đối tượng điểm ở thư viện Diem.cpp
        cout << "Nhap dinh B: \n";
        is >> tg.B; // Đã overload phương thức nhập cho đối tượng điểm ở thư viện Diem.cpp
        cout << "Nhap dinh C: \n";
        is >> tg.C; // Đã overload phương thức nhập cho đối tượng điểm ở thư viện Diem.cpp
        if (tg.Kiem_Tra() == 0)
            cout << "\nTAM GIAC BAN VUA NHAP KHONG HOP LE. VUI LONG NHAP LAI!!!\n";
    } while (tg.Kiem_Tra() == 0);

    return is;
}

ostream &operator<<(ostream &os, TG tg) // Đè chồng toán tử xuất << để xuất 1 điểm bằng lệnh cout
{
    if (tg.Kiem_Tra() == 0)
    {
        os << "Tam giac dang xet khong hop le!!!";
        return os;
    }
    os << "Tam giac co 3 dinh lan luot la:\n";
    os << "Toa do cua dinh A la: (" << tg.GetA().GetX() << ", " << tg.GetA().GetY() << ")\n";
    os << "Toa do cua dinh B la: (" << tg.GetB().GetX() << ", " << tg.GetB().GetY() << ")\n";
    os << "Toa do cua dinh C la: (" << tg.GetC().GetX() << ", " << tg.GetC().GetY() << ")\n";
    return os;
}