#ifndef _So_Phuc
#define _So_Phuc

class SOPHUC
{
    double thuc, ao;

public:
    void Nhap();
    void Xuat();
    void GiaTri();
    SOPHUC Cong2SP(SOPHUC);
    SOPHUC Tru2SP(SOPHUC);
    SOPHUC Nhan2SP(SOPHUC);
    SOPHUC Chia2SP(SOPHUC);
    void Tinh_Toan_So_Phuc(SOPHUC);
};

typedef SOPHUC SP;

#endif
