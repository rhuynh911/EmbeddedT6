#include <iostream>
#include <string>

using namespace std;

class DoiTuong{
    private:
        string Ten;
        int Tuoi;
        string GioiTinh;
        int ID;
        int *ptr;
    public:
        DoiTuong(string ten="Hoang", int tuoi=20, string gioitinh="Nam");
        ~DoiTuong();
        void hienThi();
        int var;
        static int static_var;
};
