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
