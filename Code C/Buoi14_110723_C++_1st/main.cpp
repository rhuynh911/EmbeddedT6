#include "main.hpp"

DoiTuong::DoiTuong(string ten, int tuoi, string gioitinh){
    static int id = 100;
    ptr = &id;
    ID = id;
    id++;
    Ten = ten;
    Tuoi = tuoi;
    GioiTinh = gioitinh;
}
DoiTuong::~DoiTuong(){
    *ptr = 100;
    cout<<"Ten: "<<Ten<<endl;
}

int DoiTuong::static_var;

/* DoiTuong(string ten="Vu", int tuoi=16, string gioitinh="Nam"){
    Ten = ten;
    Tuoi = tuoi;
    GioiTinh = gioitinh;
} */

/* void nhapThongTin(string ten, int tuoi, string gioitinh){
    Ten = ten;
    Tuoi = tuoi;
    GioiTinh = gioitinh;
} */

void DoiTuong::hienThi(){
    cout<<"ID: "<<ID<<endl;
    cout<<"Ten: "<<Ten<<endl;
    cout<<"Tuoi: "<<(int)Tuoi<<endl;
    cout<<"Gioi Tinh: "<<GioiTinh<<endl;
}

void test1(){
    DoiTuong dt("Hang", 18, "Nu");
    dt.hienThi();

    DoiTuong dt1("Ngoc", 18, "Nu");
    dt1.hienThi();

    DoiTuong dt2("Tuyet", 18, "Nu");
    dt2.hienThi();
}

void test2(){
    DoiTuong dt("Vy", 19, "Nu");
    dt.hienThi();

    DoiTuong dt1("Oanh", 19, "Nu");
    dt1.hienThi();

    DoiTuong dt2("Nga", 19, "Nu");
    dt2.hienThi();
}

int main(int argc, char const *argv[])
{
    //cout << "this is test" << endl;
    /*int i;
    cout << "Nhap vao i: ...";
    cin >> i;
    cout << "\ni = " << i << endl;*/

    //DoiTuong dt;
    //dt.Ten = "Hoang";
    //dt.Tuoi = 20;
    //dt.GioiTinh = "Nam";

    //dt.hienThi();

    //DoiTuong dt("Hang", 18, "Nu"), dt2("Vy", 19, "Nu");
    //DoiTuong dt;
    //dt.nhapThongTin("Hoang", 17, "Nam");
    //dt.hienThi();
    //dt2.hienThi();

    //test1();
    //test2();

    DoiTuong dt, dt1, dt2;

    printf("Dia chi dt.var = %p\n", &dt.var);
    printf("Dia chi dt1.var = %p\n", &dt1.var);
    printf("Dia chi dt2.var = %p\n", &dt2.var);

    printf("Dia chi dt.static_var = %p\n", &dt.static_var);
    printf("Dia chi dt1.static_var = %p\n", &dt1.static_var);
    printf("Dia chi dt2.static_var = %p\n", &dt2.static_var);

    return 0;
}
