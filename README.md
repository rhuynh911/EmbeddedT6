# EmbeddedT6
https://hala.edu.vn/embedded-interview/

COMPILER
Quy trình dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao sang ngôn ngữ đích (ngôn ngữ máy) để máy tính có thể hiểu và thực thi. Ngôn ngữ lập trình C++ là một ngôn ngữ dạng biên dịch. Chương trình được viết bằng C++ muốn chạy được trên máy tính phải trải qua một quá trình biên dịch để chuyển đổi từ dạng mã nguồn sang chương trình dạng mã thực thi. Quá trình được chia ra làm 4 giai đoạn chính:

![image](https://github.com/rhuynh911/EmbeddedT6/assets/13808386/c67bee80-892f-49e5-8684-ba6ffe3e59c9)


HOẠT ĐỘNG

Giai đoạn tiền xử lý – Preprocessor Bộ tiền xử lý có nhiệm vụ thực hiện:
* Nhận mã nguồn
* Xóa bỏ tất cả chú thích, comments của chương trình
* Chỉ thị tiền xử lý (bắt đầu bằng #) cũng được xử lý Chúng ta có thể bắt lỗi ngay ở giai đoạn này với việc sử dụng một cách hợp lý các chỉ thị #if và #error. Bằng cách sử dụng option -E của trình biên dịch như bên dưới, chúng ta có thể dừng quá trình biên dịch ngay ở giai đoạn tiền xử lý nếu có lỗi ở giai đoạn này.
Ví dụ: chỉ thị #include cho phép ghép thêm mã chương trình của một tệp tiêu để vào mã nguồn cần dịch. Các hằng số được định nghĩa bằng #define sẽ được thay thế bằng giá trị cụ thể tại mỗi nơi sử dụng trong chương trình. 

![image](https://github.com/rhuynh911/EmbeddedT6/assets/13808386/1fdb07fb-2d47-406b-8924-58ec5e9f1716)

Sau khi thực hiện tiền xử lý

![image](https://github.com/rhuynh911/EmbeddedT6/assets/13808386/10e240ea-c06f-4b45-aaf5-cb6ef4aef3d4)

Compilation (biên dịch)
* Phân tích cú pháp (syntax) của mã nguồn NNBC.
* Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp (hợp ngữ) gần với tập lệnh của bộ vi xử lý.

![image](https://github.com/rhuynh911/EmbeddedT6/assets/13808386/52ae28e7-f9ba-4cb4-8caf-94e95aad7ad0)

Công đoạn dịch Assembly
* Dịch chương trình => Sang mã máy 0 và 1
* Một tệp mã máy (.obj) sinh ra trong hệ thống sau đó.

Giai đoạn Linker
Trong giai đoạn này mã máy của một chương trình dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình đích duy nhất Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này. Chính vì vậy mà các lỗi liên quan đến việc gọi hàm hay sử dụng biến tổng thể mà không tồn tại sẽ bị phát hiện. Kể cả lỗi viết chương trình chính không có hàm main() cũng được phát hiện trong liên kết.
