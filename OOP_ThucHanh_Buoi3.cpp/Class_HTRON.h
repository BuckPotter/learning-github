#ifndef _HTRON
#define _HTRON
#include "Diem.h"
class HTRON
{
private:
    Diem O;   // Tâm của hình tròn
    double R; // Bán kính của hình tròn
public:
    HTRON();                            // constructor
    HTRON(Diem);                        // constructor
    HTRON(double);                      // constructor
    HTRON(Diem, double);                // constructor
    Diem GetO();                        // phương thức truy xuất. Trả về 1 điểm chính là tâm của hình tròn
    double GetR();                      // phương thức truy xuất. Trả về 1 số kiểu double là bán kính của hình tròn
    void SetO(double, double);          // thiết lập tọa độ tâm cho hình tròn với 2 tham số double là hoành và tung độ
    void SetO(Diem);                    // thiết lập tọa độ tâm cho hình tròn với tham số Diem
    void SetR(double);                  // thiết lập độ dài bán kính
    void SetOR(double, double, double); // thiết lập tọa độ tâm và độ dài bán kính. 2 tham số đầu tiên là tọa dộ tâm, 1 tham số còn lại là bán kính
    void SetOR(Diem, double);           // thiết lập tọa độ tâm và độ dài bán kính. Tham số Diem là tâm, tham số double là bán kính
    void Nhap();
    void Xuat();
    void Di_Chuyen(double, double); // tịnh tiến tọa độ tâm một khoảng tương ứng với tham số đầu vào
    double Chu_Vi();
    double Dien_Tich();
    bool Kiem_Tra(); // Kiểm tra HTRON có hợp lệ không
    friend istream &operator>>(istream &, HTRON &);
    friend ostream &operator<<(ostream &, HTRON);
};
#endif