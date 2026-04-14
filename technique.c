MỘT SỐ KĨ THUẬT LẬP TRÌNH

1. Dùng biến cờ (flag) để kiểm tra điều kiện hoặc trạng thái của chương trình. Biến cờ thường được sử dụng để xác định xem một điều kiện đã được thỏa mãn
    hay chưa, hoặc để kiểm soát luồng thực thi của chương trình.

2. Sử dụng con trỏ để quản lý bộ nhớ động và truyền dữ liệu giữa các hàm. Con trỏ cho phép bạn làm việc với địa chỉ của biến
    và có thể giúp tối ưu hóa hiệu suất của chương trình.

3. Sử dụng biến left và right để duyệt một mảng hoặc một chuỗi. Biến left thường được sử dụng để bắt đầu từ đầu mảng, trong khi biến right được sử dụng để
    bắt đầu từ cuối mảng. Kỹ thuật này thường được sử dụng trong các thuật toán sắp xếp hoặc tìm kiếm.

4. Sử dụng biến kỉ lục (record) để so sánh và lưu trữ thông tin về phần tử hiện tại trong quá trình duyệt mảng hoặc chuỗi. Biến kỉ lục có thể giúp bạn theo
    dõi vị trí và giá trị của phần tử hiện tại, từ đó giúp bạn thực hiện các phép so sánh hoặc cập nhật dữ liệu một cách hiệu quả.

5. Sử dụng các biến max = -1e9 và min = 1e9 để khởi tạo giá trị cực đại và cực tiểu trong quá trình duyệt mảng hoặc chuỗi. Điều này giúp bạn dễ
    dàng cập nhật giá trị max và min khi duyệt qua các phần tử, mà không cần phải lo lắng về việc khởi tạo chúng với giá trị không hợp lệ.

6. Khi nhập số tước chữ sẽ xảy ra hiện tượng trôi lệnh do scanf() sẽ đọc số và bỏ qua kí tự xuống dòng, sau đó khi dùng fgets() để nhập chuỗi thì fgets() sẽ
    đọc cả kí tự xuống dòng còn thừa trong bộ đệm và coi đó là một chuỗi rỗng, để khắc phục vấn đề này thì có thể dùng getchar() để loại bỏ kí tự xuống dòng
    còn thừa trong bộ đệm sau khi dùng scanf()
    ví dụ:
        int n;
        scanf("%d", &n);
        getchar(); // loại bỏ kí tự xuống dòng còn thừa trong bộ đệm
        char str[100];
        fgets(str, sizeof(str), stdin); // nhập chuỗi có dấu cách
        printf("%s", str); // in chuỗi vừa nhập