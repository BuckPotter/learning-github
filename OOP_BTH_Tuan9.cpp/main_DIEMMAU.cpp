#include "DIEMMAU.cpp"
#include "MAU.cpp"

int main()
{
    DIEMMAU d1, d2(1.5, 2.7, 5, 6, 7), d3;
    cin >> d1;
    d3.Set(d1, 10, 20, 30);
    cout << d1 << endl;
    cout << d2 << endl;
    cout << d3 << endl;
    if (d1.KiemTraTamGiac(d2, d3))
        cout << "3 diem d1, d2, d3 tao thanh tam giac hop le\n";
    else
        cout << "3 diem d1, d2, d3 khong the tao thanh tam giac\n";
    cout << d1.Dien_Tich_Tam_Giac(d2, d3);
    system("pause");
    return 0;
}