#ifndef __PHANSO_H__
#define __PHANSO_H__

class PHANSO
{
private:
    int ts, ms;

public:
    PHANSO(int = 1, int = 1);
    void Nhap();
    void Nhap2PS(PHANSO &);
    void Xuat();
    int UCLN(int, int);
    PHANSO RutGon();
    float GiaTriThuc();
    PHANSO PSLonHon(PHANSO);
    void format(PHANSO, int);
    PHANSO Cong2PS(PHANSO);
    PHANSO Tru2PS(PHANSO);
    PHANSO Nhan2PS(PHANSO);
    PHANSO Chia2PS(PHANSO);
    bool KiemTra(); // kiểm tra xem tử số = 0 ?
};

#endif