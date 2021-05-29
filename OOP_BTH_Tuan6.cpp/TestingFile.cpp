#include "CMatrix.cpp"

int main()
{
    /*    CV a, b;
    cin >> a >> b;
    cout << a << endl;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * 2 << endl;
    cout << b / 2;
    */
    CM a, b;
    cin >> a >> b;
    CM c = a * b;
    cout << c;

    return 0;
}