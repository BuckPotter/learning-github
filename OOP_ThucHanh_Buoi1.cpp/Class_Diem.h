#ifndef DIEM_H
#define DIEM_H

class Diem
{
private:
    double x;
    double y;

public:
    void KhoiTao();
    void KhoiTao(double);
    void KhoiTao(double, double);
    void Nhap();
    void Xuat();
    void DiChuyen(double, double);
    bool KiemTra2DiemTrungNhau(Diem);
    double KhoangCach(Diem);
    Diem Doi_Xung_Qua_O();
    double Chu_Vi_Tam_Giac(Diem, Diem, Diem);
    double Do_Dai_Canh();
    double Dien_Tich_Tam_Giac(Diem, Diem, Diem);
};

#endif
