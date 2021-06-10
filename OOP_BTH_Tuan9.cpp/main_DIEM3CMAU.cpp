#include "DIEM3CMAU.cpp"
#include "MAU.cpp"
#include "DIEM3C.cpp"

int main()
{
    DIEM3CMAU d1, d2(1.5, 2.7, 3.9), d3;
    cin >> d1;
    d3 = d1;
    cout << d1 << endl;
    cout << d2 << endl;
    cout << d3 << endl;
    if (d1.KiemTraMau(d3))
        cout << "d1 va d3 co mau trung nhau\n";
    else
        cout << "d1 va d3 co mau khac nhau\n";
    return 0;
}