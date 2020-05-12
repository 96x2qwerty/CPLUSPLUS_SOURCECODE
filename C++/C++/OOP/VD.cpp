#include <iostream>
using namespace std;
class PS
{
    private:
        int tu;
        int mau;
    public:
        PS()
        {
            tu = 0;
            mau = 1;
        }
        PS(int tu, int mau)
        {
            tu = tu;
            mau = mau;
        }
        PS cong(PS a, PS b)
        {
   
            this -> tu = a.tu * b.tu;
            this -> mau = a.mau * b.mau;
            return *this;
        }
        void print()
        {
            cout << tu << " / " << mau << endl;
        }      
};
main()
{
    PS p1(1, 2);
    PS p2(3, 4);
    PS p3;
    p3.cong(p1, p2);
    p3.print();
    system("pause");
}
