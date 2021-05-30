#ifndef __DIEMMAU_H__
#define __DIEMMAU_H__
#include "DIEM.h"
#include "MAU.h"
class DIEMMAU : public DIEM, public MAU
{
    MAU m;

public:
    DIEMMAU();
    DIEMMAU(DIEM, MAU);
    DIEMMAU(DIEMMAU &);
    DIEM Get_Diem();
    MAU Get_Mau();
    void Set_Diem(DIEM);
    void Set_Mau(MAU);
    void Set(DIEM, MAU);
    bool KiemTraHopLe();
    bool KiemTraTrung();
    void DiChuyen(double, double);
    friend istream &operator>>(istream &, DIEMMAU &);
    friend ostream &operator<<(ostream &, DIEMMAU);
};

#endif