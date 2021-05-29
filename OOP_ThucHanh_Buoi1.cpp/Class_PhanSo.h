#ifndef Phan_So_H
#define Phan_So_H

class PHANSO
{
    int ts;
    int ms;

public:
    void KhoiTao();
    void KhoiTao(int);
    void KhoiTao(int, int);
    void NhapPS();
    void Nhap2PS(PHANSO &);
    int UCLN(int, int);
    PHANSO ToiGianPS();      // Trả về phân số dạng tối giản của phân số truyền vào
    bool KiemTraPSToiGian(); // Kiểm tra xem phân số đã tối giản chưa
    void XuatPS();
    double GiaTriPS();           // Trả về giá trị thực của phân số
    int KiemTraPSLonHon(PHANSO); // So sánh 2 phân số, trả về 1 nếu phân số đầu tiên lớn hơn, ngược lại trả về -1, nếu 2 phân số bằng nhau trả về 0
    PHANSO Cong2PS(PHANSO);
    PHANSO Tru2PS(PHANSO);
    PHANSO Nhan2PS(PHANSO);
    PHANSO Chia2PS(PHANSO);
    void Tinh_Toan_Phan_So(PHANSO); // In ra màn hình cấc phép toán với 2 phân số tham số truyền vào
    void format(PHANSO, int);       //Tham số kiểu int đại diện cho phương thức
    bool KiemTra();                 //Kiểm tra phân số có bằng 0 hay không
};

typedef PHANSO PS;
#endif