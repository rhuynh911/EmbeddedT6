#include <iostream>
#include <string>
#include "test.cpp"
#include <vector>

using namespace std;

class SinhVien{
    protected:
    //char *comment(){
    virtual char *comment(){
        return (char*)"Class Sinh vien\n";
    }
    public:
    void display(){
        printf("%s\n", comment());
    }
};

class HocSinh: public SinhVien{
    private:
    //public:
    char *comment(){                        //overload
        return (char*)"Class Hoc Sinh\n";   //override
    }
};

int main(int argc, char const *argv[])
{
    //HocSinh hs;
    //hs.display();
    //printf("test: %s\n", hs.comment());
    vector<int> array;
    array.push_back(7);
    array.push_back(3);
    array.push_back(5);
    array.push_back(1);
    array.insert(array.begin()+2,35);
    //array.pop_back();
    //array.erase(array.begin()+1);
    //array.clear();

    //for(int i = 0; i < array.size(); i++){
        //cout << array[i] << endl;
    //}

    //for(int item : array){
        //cout << item << endl;
    //}

    //auto test = 10.6;

    for(auto item : array){
        cout << item << endl;
    }

    return 0;
}
