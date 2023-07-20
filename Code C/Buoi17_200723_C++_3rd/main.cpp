#include <iostream>
#include <string>
#include "test.cpp"

using namespace std;

namespace ConOngA{
    int Teo = 10;

    class ToanHoc{
    public:
        void tong(int a, int b){
            cout << "Tong a va b: " << a + b << endl;
        }
        void tong(float a, float b){
            cout << "Tong a va b: " << a + b << endl;
        }
        void tong(int a, int b, int c){
            cout << "Tong a,b va c: " << a + b + c << endl;
        }
    };

}

namespace ConOngB{
    int Teo = 20;
}

using namespace ConOngA;

template <typename bien, typename bien2>

bien tong(bien a, bien2 b){
    return (bien)(a + b);
}

int main(int argc, char const *argv[])
{
    /* code */
    //ToanHoc th;
    //th.tong(8,9);
    //th.tong((float)8.2, (float)6.7);
    //th.tong(6, 3, 6);
    //cout << "Tong a va b: " << tong(6, 7) << endl;
    //cout << "Tong a va b: " << tong(6.3, 7.2) << endl;
    //cout << "Tong a va b: " << tong(6.3, 6) << endl;
    
    cout << "Teo Con Ong A: " << ConOngA::Teo << endl;
    cout << "Teo Con Ong B: " << ConOngB::Teo << endl;

    ConOngA::ToanHoc th;
    th.tong(10, 20);

    //ConOngB::test

    cout << Teo << endl;

    return 0;
}
