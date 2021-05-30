#ifndef __MAU_H__
#define __MAU_H__
#include <iostream>
#include <vector>
using namespace std;

class MAU
{
    int r;
    int gr;
    int bl;

public:
    MAU(int = 0, int = 0, int = 0);
    MAU(MAU &);
    MAU Get();
    void Set(int, int, int);
    void Set(MAU);
    void Nhap();
    void Xuat();
    bool KiemTraTrung(MAU);
    bool KiemTraHopLe();
};
#endif