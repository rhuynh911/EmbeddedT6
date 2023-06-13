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
