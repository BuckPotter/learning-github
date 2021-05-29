#include "Diem.cpp"
#include "Class_TAMGIAC.cpp"

using namespace std;
int main()
{
    TG a(0, 0, 0, 0, 0, 0);
    cin >> a;
    cout << a << endl;
    cout << a.Chu_Vi() << endl;
    cout << a.Dien_Tich() << endl;
    cout << a.GetA().KhoangCach(a.GetB()) << " " << a.GetB().KhoangCach(a.GetC()) << " " << a.GetC().KhoangCach(a.GetA()) << endl;
    a.Phan_Loai();
    return 0;
}
