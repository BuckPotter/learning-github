#include "Class_HCN.h"
#include <cmath>

HCN::HCN() // Constructor
{
    A.SetXY(0, 0);
}

HCN::HCN(double xA, double yA, double xB, double yB) : A(xA, yA), B(xB, yB)
{
    // Constructor
}

HCN::HCN(Diem a, Diem b) // Constructor
{
    A = a;
    B = b;
}

Diem HCN::GetA() // phương thức truy xuất, trả về điểm chéo trên
{
    return A;
}

Diem HCN::GetB() // phương thức truy xuất, trả về điểm chéo dưới
{
    return B;
}

void HCN::SetA(double xx, double yy) // phương thức thiết lập tọa độ cho điểm chéo trên với 1 cặp tham số double
{
    A.SetX(xx);
    A.SetY(yy);
}

void HCN::SetB(double xx, double yy) // phương thức thiết lập tọa độ cho điểm chéo dưới với 1 cặp tham số double
{
    B.SetX(xx);
    B.SetY(yy);
}

void HCN::SetA(Diem a) // phương thức thiết lập tọa độ cho điểm chéo trên với tham số Diem
{
    A = a;
}

void HCN::SetB(Diem b) // phương thức thiết lập tọa độ cho điểm chéo dưới với tham số Diem
{
    A = b;
}

void HCN::SetAB(double xA, double yA, double xB, double yB) // thiết lập tọa độ cho điểm chéo trên và dưới với 2 cặp tham số double tương ứng
{

    A.SetXY(xA, yA);
    B.SetXY(xB, yB);
}

void HCN::SetAB(Diem a, Diem b) // thiết lập tọa độ cho điểm chéo trên và dưới với tham số Diem tương ứng
{
    A = a;
    B = b;
}

bool HCN::Kiem_Tra() // Kiểm tra HCN có hợp lệ không
{
    // 2 điểm A(xA, yA) và B(xB, yB) không thể tạo thành HCN nếu xA = xA hoặc yA = yB
    if (A.GetX() == B.GetX() || A.GetY() == B.GetY())
        return 0;
    return 1;
}

void HCN::Nhap()
{
    do
    {
        cout << "Nhap vao diem cheo tren A:\n";
        cin >> A; // Đã overload phương thức nhập cho đối tượng điểm ở thư viện Diem.cpp
        cout << "Nhap vao diem cheo duoi B:\n";
        cin >> B; // Đã overload phương thức nhập cho đối tượng điểm ở thư viện Diem.cpp
        if (this->Kiem_Tra() == 0)
            cout << "2 diem ban vua nhap khong the tao thanh HCN duoc !!!";
    } while (this->Kiem_Tra() == 0); // Nếu người dùng nhập vào 1 HCN không hợp lệ thì yêu cầu nhập lại
}

void HCN::Xuat()
{
    if (this->Kiem_Tra() == 0)
    {
        cout << "HCN dang xet khong hop le\n";
        return;
    }
    cout << "Diem cheo tren va diem cheo duoi cua hinh chu nhat lan luot la:\n";
    cout << "\tToa do cua diem cheo tren A(" << A.GetX() << ", " << A.GetY() << ")" << endl;
    cout << "\tToa do cua diem cheo duoi B(" << B.GetX() << ", " << B.GetY() << ")" << endl;
}

void HCN::Di_Chuyen(double xx, double yy) // tịnh tiến điểm chéo trên và điểm chéo dưới 1 khoảng tương ứng với tham số đầu vào
{
    A.DiChuyen(xx, yy); // phương thức di chuyển Diem được cài đặt ở file thư viện Diem.cpp
    B.DiChuyen(xx, yy); // phương thức di chuyển Diem được cài đặt ở file thư viện Diem.cpp
}

double HCN::Chu_Vi()
{
    if (this->Kiem_Tra() == 0)
        return -1;               // Trả về số âm nếu HCN không hợp lệ
    Diem C;                      // Tạo 1 điểm phụ C sao cho ACB là 1 tam giác vuông (C chính là 1 đỉnh của hình chữ nhật)
    C.SetXY(A.GetX(), B.GetY()); //C(xA, yB) hay C(xB, yA) vẫn đúng
    double a = A.KhoangCach(C);
    double b = B.KhoangCach(C);
    // a và b chính là độ dài của 2 cạnh kề nhau của hình chữ nhật đang xét (1 cạnh là chiều dài, 1 cạnh là chiều rộng)
    return 2 * a + 2 * b;
}

double HCN::Dien_Tich()
{
    if (this->Kiem_Tra() == 0)
        return -1;               // Trả về số âm nếu HCN không hợp lệ
    Diem C;                      // Tạo 1 điểm phụ C sao cho ACB là 1 tam giác vuông (C chính là 1 cạnh của hình chữ nhật)
    C.SetXY(A.GetX(), B.GetY()); //Hoành độ của C = xA, tung độ của C = yB. Hoành độ của C = xB, tung độ của C = yA vẫn đúng
    double a = A.KhoangCach(C);
    double b = B.KhoangCach(C);
    // a và b chính là độ dài của 2 cạnh kề nhau của hình chữ nhật đang xét (1 cạnh là chiều dài, 1 cạnh là chiều rộng)
    return a * b;
}

istream &operator>>(istream &is, HCN &hcn)
{
    do
    {
        cout << "Nhap vao diem cheo tren A:\n";
        is >> hcn.A; // Đã overload phương thức nhập cho đối tượng điểm ở thư viện Diem.cpp
        cout << "Nhap vao diem cheo duoi B:\n";
        is >> hcn.B; // Đã overload phương thức nhập cho đối tượng điểm ở thư viện Diem.cpp
        if (hcn.Kiem_Tra() == 0)
            cout << "2 DIEM BAN VUA NHAP KHONG THE TAO THANH HCN DUOC. VUI LONG NHAP LAI!!!\n\n";
    } while (hcn.Kiem_Tra() == 0); // Nếu người dùng nhập vào 1 HCN không hợp lệ thì yêu cầu nhập lại
    return is;
}

ostream &operator<<(ostream &os, HCN hcn)
{
    os << "Diem cheo tren va diem cheo duoi cua hinh chu nhat lan luot la:\n";
    os << "\tToa do cua diem cheo tren A(" << hcn.A.GetX() << ", " << hcn.A.GetY() << ")" << endl;
    os << "\tToa do cua diem cheo duoi B(" << hcn.B.GetX() << ", " << hcn.B.GetY() << ")" << endl;
    return os;
}