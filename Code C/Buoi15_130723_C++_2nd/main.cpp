#include <iostream>
#include <string>

using namespace std;

class DoiTuong{
    protected:
        string TEN;
        int NAM_SINH;
        string DIA_CHI;
        int tinhTuoi(int namSinh);
    public:
        void themThongTin(string ten, int tuoi, string diachi);
        void hienThi();
};

int DoiTuong::tinhTuoi(int namSinh){
    return 2023 - namSinh;
}

void DoiTuong::themThongTin(string ten, int namSinh, string diachi){
    TEN = ten;
    NAM_SINH = namSinh;
    DIA_CHI = diachi;
}

void DoiTuong::hienThi(){
    cout << "Ten: " << TEN << endl;
    cout << "Nam sinh: " << NAM_SINH << endl;
    cout << "Dia chi: " << DIA_CHI << endl;
    cout << "Tuoi: " << tinhTuoi(NAM_SINH) << endl;
}

class SinhVien : public DoiTuong{
    private:
        int MSSV;
    public:
        SinhVien();
        int getMSSV();
        void themThongTin(string ten, int namSinh, string diachi, int mssv);
        void hienThi(); //override
};

SinhVien::SinhVien(){
    static int mssv = 1000;
    MSSV = mssv;
    mssv++;
}

int SinhVien::getMSSV(){
    return MSSV;
}

void SinhVien::hienThi(){
    cout << "Ten: " << TEN << endl;
    cout << "Nam sinh: " << NAM_SINH << endl;
    cout << "Dia chi: " << DIA_CHI << endl;
    cout << "Ma so SV: " << MSSV << endl;
}

void SinhVien::themThongTin(string ten, int namSinh, string diachi, int mssv){
    TEN = ten;
    NAM_SINH = namSinh;
    DIA_CHI = diachi;
    MSSV = mssv;
}

int main(int argc, char const *argv[])
{
    DoiTuong dt;
    dt.themThongTin("Hoang", 1997, "Go Vap");
    //t.TEN = "Hoang";
    //dt.TUOI = 20;
    //dt.DIA_CHI = "Go Vap";
    dt.hienThi();

    /* SinhVien sv;
    sv.TEN = "Tien";
    sv.TUOI = 20;
    sv.DIA_CHI = "Tan Binh";
    sv.MSSV = 1001;
    sv.hienThi(); */

    SinhVien sv;
    sv.themThongTin("Oanh", 2001, "Tan Binh", 1001);
    sv.hienThi();

    return 0;
}
