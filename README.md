# Embedded-Interview
<details>

<summary>COMPILER</summary>
Quy trình dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao sang ngôn ngữ đích (ngôn ngữ máy) để máy tính có thể hiểu và thực thi. Ngôn ngữ lập trình C++ là một ngôn ngữ dạng biên dịch. Chương trình được viết bằng C++ muốn chạy được trên máy tính phải trải qua một quá trình biên dịch để chuyển đổi từ dạng mã nguồn sang chương trình dạng mã thực thi. Quá trình được chia ra làm 4 giai đoạn chính:
    
![image](https://codelearn.io/Media/Default/Users/Darksider/ssj/maxresdefault.jpg)
	
	
HOẠT ĐỘNG

1. Giai đoạn tiền xử lý – Preprocessor
Bộ tiền xử lý có nhiệm vụ thực hiện:

- Nhận mã nguồn
- Xóa bỏ tất cả chú thích, comments của chương trình
- Chỉ thị tiền xử lý (bắt đầu bằng #) cũng được xử lý
Chúng ta có thể bắt lỗi ngay ở giai đoạn này với việc sử dụng một cách hợp lý các chỉ thị #if và #error. Bằng cách sử dụng option -E của trình biên dịch như bên dưới, chúng ta có thể dừng quá trình biên dịch ngay ở giai đoạn tiền xử lý nếu có lỗi ở giai đoạn này.

Ví dụ: chỉ thị #include cho phép ghép thêm mã chương trình của một tệp tiêu để vào mã nguồn cần dịch. Các hằng số được định nghĩa bằng #define sẽ được thay thế bằng giá trị cụ thể tại mỗi nơi sử dụng trong chương trình.
![image](https://codelearn.io/Media/Default/Users/Darksider/ssj/Screenshot%202020-09-22%20092248.png)
	
Sau khi thực hiện tiền xử lý
	
![image](https://codelearn.io/Media/Default/Users/Darksider/ssj/Screenshot%202020-09-22%20092317.png)
	

2. Compilation (biên dịch)

- Phân tích cú pháp (syntax) của mã nguồn NNBC.
- Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp (hợp ngữ) gần với tập lệnh của bộ vi xử lý.

![image](https://codelearn.io/Media/Default/Users/Darksider/ssj/Screenshot%202020-09-22%20094157.png)
	
3. Công đoạn dịch Assembly

- Dich chương trình => Sang mã máy 0 và 1
- Một tệp mã máy (.obj) sinh ra trong hệ thống sau đó.
	
4. Giai đoạn Linker

Trong giai đoạn này mã máy của một chương trình dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình đích duy nhất
Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này.
Chính vì vậy mà các lỗi liên quan đến việc gọi hàm hay sử dụng biến tổng thể mà không tồn tại sẽ bị phát hiện. Kể cả lỗi viết chương trình chính không có hàm main() cũng được phát hiện trong liên kết.

</details>

<details>
<summary>PRAGMA</summary>

The `pragma pack` directive can be used to improve the efficiency of C code by reducing the amount of memory that is used to store structure objects. However, it is important to note that using the `pragma pack` directive can also make the code less portable, as not all compilers support it.

![no-pragma](https://github.com/rhuynh911/EmbeddedT6/assets/13808386/fe897c02-0693-4a02-b7c9-84896c1dfc9b)

![has-pragama](https://github.com/rhuynh911/EmbeddedT6/assets/13808386/0d6ae515-79a2-4b5b-a3b7-0c9806c4486b)
	
</details>

<details>
<summary>POINTER</summary>
 
## Null Pointer
- Con trỏ null là con trỏ có giá trị và địa chỉ bằng 0.
- Khi khai báo 1 con trỏ:
    + Phải khai báo địa chỉ cho nó.
    + Nếu mà chưa sử dụng thì gán cho nó con trỏ null. 
    + Hoặc khi khai báo con trỏ và đã sử dụng nó rồi, khi không muốn sử dụng nó nữa thì phải gán nó lại là con trỏ null.
```
    int *ptr = NULL;
```
## Function Pointer
- Sau khi khai báo thì hàm cũng được lưu trữ tại một địa chỉ trong bộ nhớ, và do đó, chúng ta cũng có thể sử dụng con trỏ để lưu trữ địa chỉ và qua đó thao tác với chúng.
- Chúng ta gọi con trỏ lưu trữ địa chỉ của một hàm là con trỏ hàm trong c, và sử dụng nó để truy cập vào địa chỉ của hàm, cũng như thực thi các xử lý bên trong hàm đó.
 ```
    Cách khai báo:
        type (*fp) ( para_type_1, para_type_2, para_type_3,...);
    fp: tên con trỏ hàm.
    type: kiểu của con trỏ.
    para_type_1,.. : các kiểu của các đối số parameter.
 ```
 ```
 VD:
#include <stdio.h>

void tong(int a,int b){
    printf("tong %d va %d = %d\n", a, b, a + b);
}

void hieu(int a,int b){
    printf("hieu %d va %d = %d\n", a, b, a - b);
}

void tich(int a,int b){
    printf("tich %d va %d = %d\n", a, b, a * b);
}

void thuong(int a,int b){
    printf("thuong %d va %d = %f\n", a, b, (float)a/b);
}

void tinhtoan(int a, int b, void (*ptr)(int, int))
{   // thông qua con trỏ hàm để hàm làm input parameter
    printf("Chuong trin tinh toan\n");
    ptr(a,b);
}
int main()
{

    // void (*pheptoan)(int, int) = NULL;
    // pheptoan = thuong;
    // pheptoan(5,1);

    tinhtoan(8,6,thuong);
    return 0;
}
    
 ```
 ## Void Pointer
 - `Con trỏ void có thể trỏ đến các vùng nhớ có các kiểu dữ liệu khác nhau`.
 - Tuy nhiên, con trỏ void không xác định được kiểu dữ liệu của vùng nhớ mà nó trỏ tới, vì vậy không thể truy cập xuất trực tiếp nội dung thông qua toán tử derefernce () được. Mà `con trỏ kiểu void` cần `phải được ép kiểu` một cách rõ ràng `sang con trỏ có kiểu dữ liệu khác trước khi sử dụng toán tử derefernce` ().
 ```
 #include <stdio.h>

void tong(int a,int b){
    printf("tong %d va %d = %d\n", a, b, a + b);
}

int main()
{

    int i = 3;
    double d =12.4;
    char c ='B';

    // con trỏ void có thể trỏ đến bất kỳ địa chỉ nào 
    void *ptr = &i;

    // để lấy giá trị từ con trỏ void ta cần ép kiểu nó
    printf("i = %d\n",*(int *)ptr);

    ptr = &d;
    printf("d = %f\n",*(double *)ptr);

    ptr = &c;
    printf("c = %c\n",*(char *)ptr);

    ptr = &tong;
    ((void (*)(int, int))ptr)(9,1);
    return 0;
}
    
 ```
 ## Pointer to Pointer
 Con trỏ trỏ đến con trỏ (Pointers to pointers) là một con trỏ chứa địa chỉ của một con trỏ khác.
    
 ```
  cách khai báo: 
   data_type_of_pointer **name_of_variable = & normal_pointer_variable;
 ```
 
 ```
int val = 5; 
int *ptr = &val; // lưu địa chỉ của val vào con trỏ ptr. 
int **d_ptr = &ptr; // con trỏ tới một con trỏ được khai báo 
                    // đang trỏ tới một số nguyên.
    
 ```
 ```
 VD :
 #include <stdio.h>
 
int main()
{
    int var = 123;
 
    int* ptr2;
 
    int** ptr1;
 
    ptr2 = &var;
 
    ptr1 = &ptr2;
 
    printf("Gia tri var = %d\n", var);
    printf("Gia tri *pointer = %d\n", *ptr2);
    printf("Gia tri **pointer = %d\n", **ptr1);
 
    return 0;
    
    /*
     Result : 
        Gia tri var = 123
        Gia tri *pointer = 123
        Gia tri **pointer = 123
    */
}
 ```
</details>

<details>
<summary>STRUCT_UNION</summary>

### 1. Struct
- Sizeof của Struct bằng tổng các member cộng lại (+ padding nếu có).
- Địa chỉ của Struct sẽ bằng địa chỉ của member đầu tiên và các member còn lại sẽ có địa chỉ riêng của chúng nên chúng có thể lưu giá trị độc lập với nhau.
- Khi nào dùng Struct: Struct cùng một thời điểm ta có thể chọn cùng lúc nhiều member.
- Tùy cách sắp xếp các member trong Struct ta sẽ có sizeof khác nhau, chúng ta nên sắp xếp 1 cách thông minh để không tốn tài nguyên:

* Đây tiết kiệm tài nguyên.
<p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/77714d49-3cae-4862-bf51-9597a67abfdb">
</p> 

* Đây là lãng phí tài nguyên
<p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/271d4a47-36fa-443b-b69f-c42e563a9e5d">
</p> 

### 2. Union
- Sizeof của Union là kích thước của member lớn nhất.

<p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/866bfa76-1864-4724-888e-2d149704a005">
</p> 

<p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/9b2fc738-255b-4339-8a7c-1c7168855723">
</p> 

- Địa chỉ của Union và các member là dùng chung nên nếu gán giá trị vào thì các member sẽ có giá trị giống nhau.

<p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/0d274e6d-1281-4f41-86f6-b1ddcddb9363">
</p>

- Khi nào dùng Union: Union có rất nhiều member và tại 1 thời điểm mình chỉ sử dụng 1 member trong đó thôi thì ta sẽ dùng Union (ví dụ: Khi mua lap, ta sẽ có nhiều hãng để lựa chọn, nhưng ta chỉ có thể chọn 1 hãng để mua).

</details>

<details>
<summary>PHÂN VÙNG NHỚ</summary>
	
<img width="400" alt="image" src="https://i0.wp.com/media.geeksforgeeks.org/wp-content/uploads/memoryLayoutC.jpg?resize=449%2C343&ssl=1">

## Phân vùng Text:
- Quyền truy cập chỉ Read và nó chứa lệnh để thực thi nên tránh sửa đổi instruction.

- Chứa khai báo hằng số trong chương trình (.rodata)
```
// Ví dụ : chỉ đọc data
const int a = 9;
char *arr = "Hello";
```
## Phân vùng Data:
- Quyền truy cập là read-write.

- Chứa biến toàn cục or biến static với giá trị khởi tạo khác không.

- Được giải phóng khi kết thúc chương trình.
```
#include <stdio.h>

int x = 10; // biến toàn cục
static int a = 15; // biến static toàn cục

void test(){
 static int b = 10; // biến static cục bộ
 a = a + 20;
 prinf("test: %d\n", a);
}
int main (){

 test();
 a = a +15;
 prinf("main: %d\n", a);
 return 0;
 // Result: test = 35, main = 50
```
## Phân vùng BSS:
- Quyền truy cập là read-write.

- Chứa biến toàn cục or biến static với giá trị khởi tạo bằng không or không khởi tạo.

- Được giải phóng khi kết thúc chương trình.
```
static int a ; // biến static toàn cục phân vùng bss
/* khi giá trị được khởi tạo vd: a = 10 thì nó vẫn ở phân vùng bss */ 
void test(){
 static int b ; // biến static cục bộ
}
int main (){
}
```
## Phân vùng Stack:
- Quyền truy cập là read-write.

- Được sử dụng cấp phát cho biến local, input parameter của hàm,…

- Sẽ được giải phóng khi ra khỏi block code/hàm.
```
// int a, int b là input parameter
int sum(int a, int b){
  int c; // biến cục bộ ở phân vùng stack
  c = a + b;
  return c;
}
```
## Phân vùng Heap:
- Quyền truy cập là read-write.

- Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc,…

- Sẽ được giải phóng khi gọi hàm free,…
```
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void test1(){
  char arr[3]; // biến toàn cục
  printf("Dia chi arr: %p\n", arr);
}

void test2(){
/*
 Khi khai báo kiểu malloc, các ô nhớ sẽ được giữ nguyên bộ nhớ ban đầu (draf data hay dữ liệu rác).
 Kiểu trả về là con trỏ void (không có giá trị), tham số truyền vào là  size tính bằng byte.
 Vì hàm malloc trả về dạng void, vậy ta cần ép kiểu cho nó trở về đúng kiểu con trỏ mà ta sử dụng.
 Vì char có 1 byte nên khai báo sẽ được cấp 3 byte tương ứng 3 phần tử.
*/
  char *arr = (char*)malloc(sizeof(char)*3);
  // arr = (char*)realloc(arr,(sizeof(char)*5) // thay đổi kích thước mảng 5 byte tương ứng 5 phần tử
  printf("Dia chi arr: %p\n", arr);
  free(arr);
}

int main(){
  test1();
  test1();
  test2();
  test2();
}
/*
Result: khi chưa sử dụng lệnh free cho hàm malloc
Dia chi arr: 0061FF0D : khi gọi test1 lần 1 sau khởi tạo xong nó sẽ thoát ra và thu hồi vùng nhớ 
Dia chi arr: 0061FF0D : khi gọi test1 lần 2 nó khởi tạo địa chỉ trước đó vì địa chỉ đó vẫn còn trống.
Dia chi arr: 00BA2F20 : do malloc được lưu ở phân vùng Heap nên nó không thể tự thu hồi 
Dia chi arr: 00BA2F30

Result: khi sử dụng lệnh free cho hàm malloc
Dia chi arr: 0061FF0D
Dia chi arr: 0061FF0D
Dia chi arr: 00AD2F20
Dia chi arr: 00AD2F20
*/
```
## Sự khác nhau giữa bộ nhớ Heap và bộ nhớ Stack :
- Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra và lưu trữ trong RAM khi chương trình được thực thi.
- Bộ nhớ Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch
- Vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động hủy khi hàm thực hiện xong công việc của mình.
- Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C).
- Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow).
</details>
