#include "DIEM3C.cpp"

int main()
{
    DIEM3C d1, d2(1, 2, 3), d3;
    cin >> d1;
    d3 = d1;
    cout << d1 << endl;
    cout << d2 << endl;
    cout << d3 << endl;
    cout << "Diem doi xung cua d1 qua O: " << d1.DiemDoiXung() << endl;
    if (d1.KiemTraTamGiac(d2, d3))
        cout << "3 diem d1, d2, d3 tao thanh 1 tam giac hop le\n";
    else
        cout << "3 diem d1, d2, d3 khong the tao thanh tam giac\n";
    cout << d1.ChuVi(d2, d3) << endl; // Sẽ yêu cầu nhập lại 3 điểm d1, d2, d3 nếu 3 điểm này không thể tạo thành tam giác
    cout << d1.DienTich(d2, d3) << endl;
    system("pause");
    return 0;
}
