#ifndef __MAU_H__
#define __MAU_H__
#include <iostream>
#include <vector>
using namespace std;

class MAU
{
protected:
    int r;
    int gr;
    int bl;

public:
    MAU(int = 0, int = 0, int = 0);
    MAU Get();
    int Get_R();
    int Get_G();
    int Get_B();
    void Set(int, int, int);
    void Set_R(int);
    void Set_G(int);
    void Set_B(int);
    void Set(MAU);
    void Nhap();
    void Xuat();
    bool KiemTraTrung(MAU);
    bool KiemTraHopLe();
};
#endif