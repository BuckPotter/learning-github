#include "DIEMMAU3C.cpp"
#include "DIEM3C.cpp"
int main()
{
    DIEMMAU3C d1, d2(1.5, 2.7, 3.9), d3;
    cin >> d1;
    d3 = d1;
    cout << d1 << endl;
    cout << d2 << endl;
    cout << d3 << endl;
    if (d1.KiemTraTrungMau(d3))
        cout << "d1 va d3 co mau trung nhau\n";
    else
        cout << "d1 va d3 co mau khac nhau\n";
    return 0;
}