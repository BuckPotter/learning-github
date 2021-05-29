#include "Class_HTRON.h"
#include <cmath>

HTRON::HTRON()
{
    O.SetXY(0, 0); // Mặc định tâm đường tròn sẽ là gốc tọa độ
    R = 1;         // Mặc định R = 1
    // constructor
}
HTRON::HTRON(Diem o) // constructor
{
    O = o;
    R = 1; // Mặc định R = 1 nếu như không có tham số kiểu double nào được truyền vào
}
HTRON::HTRON(double r) // constructor
{
    O.SetXY(0, 0); // Mặc định tâm đường tròn sẽ là gốc tọa độ
    R = r;
}
HTRON::HTRON(Diem o, double r) // constructor
{
    O = o;
    R = r;
}
Diem HTRON::GetO() // phương thức truy xuất. Trả về 1 điểm chính là tâm của hình tròn
{
    return O;
}
double HTRON::GetR() // phương thức truy xuất. Trả về 1 số kiểu double là bán kính của hình tròn
{
    return R;
}
void HTRON::SetO(double xO, double yO) // thiết lập tọa độ tâm cho hình tròn với 2 tham số double là hoành và tung độ
{
    O.SetXY(xO, yO);
}
void HTRON::SetO(Diem o) // thiết lập tọa độ tâm cho hình tròn với tham số Diem
{
    O = o;
}
void HTRON::SetR(double r) // thiết lập độ dài bán kính
{
    R = r;
}
void HTRON::SetOR(double xO, double yO, double r) // thiết lập tọa độ tâm và độ dài bán kính. 2 tham số đầu tiên là tọa dộ tâm, 1 tham số còn lại là bán kính
{
    O.SetXY(xO, yO);
    R = r;
}
void HTRON::SetOR(Diem o, double r) // thiết lập tọa độ tâm và độ dài bán kính. Tham số Diem là tâm, tham số double là bán kính
{
    O = o;
    R = r;
}

bool HTRON::Kiem_Tra() // Kiểm tra HTRON có hợp lệ không
{
    // Hình tròn có bán kính <= 0 là hình tròn không hợp lệ
    if (R <= 0)
        return 0;
    return 1;
}

void HTRON::Nhap()
{
    do
    {
        cout << "Nhap vao toa do tam O cua hinh tron:\n";
        cin >> O; // Đã overload toán tử nhập cho Diem ở Diem.cpp
        cout << "Nhap ban kinh R cua hinh tron: ";
        cin >> R;
        if (this->Kiem_Tra() == 0)
            cout << "HINH TRON BAN VUA NHAP KHONG HOP LE. VUI LONG NHAP LAI!!!\n\n";
    } while (this->Kiem_Tra() == 0);
}

void HTRON::Xuat()
{
    if (this->Kiem_Tra() == 0)
    {
        cout << "Hinh tron khong hop le\n";
        return;
    }
    cout << "Hinh tron co toa do tam O(" << O.GetX() << ", " << O.GetY() << "), ban kinh R = " << R;
}

void HTRON::Di_Chuyen(double xx, double yy) // tịnh tiến tọa độ tâm một khoảng tương ứng với tham số đầu vào
{
    O.DiChuyen(xx, yy); // phương thức di chuyển Diem được cài đặt ở file thư viện Diem.cpp
}

double HTRON::Chu_Vi()
{
    if (this->Kiem_Tra() == 0)
        return -1; // trả về số âm nếu hình tròng không hợp lệ;
    return 2 * R * M_PI;
}

double HTRON::Dien_Tich()
{
    if (this->Kiem_Tra() == 0)
        return -1; // trả về số âm nếu hình tròng không hợp lệ;
    return M_PI * R * R;
}

istream &operator>>(istream &is, HTRON &htron)
{
    do
    {
        cout << "Nhap vao toa do tam O cua hinh tron:\n";
        is >> htron.O; // Đã overload toán tử nhập cho Diem ở Diem.cpp
        cout << "Nhap ban kinh R cua hinh tron: ";
        is >> htron.R;
        if (htron.Kiem_Tra() == 0)
            cout << "HINH TRON BAN VUA NHAP KHONG HOP LE. VUI LONG NHAP LAI!!!\n\n";
    } while (htron.Kiem_Tra() == 0);
    return is;
}

ostream &operator<<(ostream &os, HTRON htron)
{
    cout << "Hinh tron co toa do tam O(" << htron.O.GetX() << ", " << htron.O.GetY() << "), ban kinh R = " << htron.R;
    return os;
}
