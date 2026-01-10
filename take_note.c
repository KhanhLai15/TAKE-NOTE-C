Một số trang web kiến thức C: Programiz, W3Schools

Kiểu dữ liệu:
    
    * Số nguyên:
        int: %d, %i, 4 byte, lưu được dãy dữ liệu từ -2^31 -> 2^31 - 1 
        long long int: %lld, %lli, 8 byte, lưu được dãy dữ liệu từ -2^63 -> 2^61 - 1
        các kiểu dữ liệu int và long long int nếu dùng để lưu số âm sẽ lấy 1 bit để biểu diễn dấu âm
        có thể dùng unsigned int (4 byte) và unsigned long long int (8 byte) để lưu số dương => dãy dữ liệu lưu được từ 0 -> 2^32 - 1 với int, 0 -> 2^64 - 1 với long long int
        
        cách nhập: scanf("%d", &tên_biến) hoặc scanf("%lld", &tên_biến) kí hiệu & trước mỗi tên biến được gọi là toán tử địa chỉ dùng để truy tìm đến vị trí lưu của biến và thay đổi giá trị của biến
        cách in: printf("%d", tên_biến) hoặc printf("%lld", tên_biến)
                           
    * Số thực:
        float: %f, 4 byte, mặc định in ra 6 số sau dấu phẩy
        double: %lf, 8 byte, mặt định in ra 14 số sau dấu phẩy
        
        cách nhập: scanf("%f", &tên_biến) hoặc scanf("%lf", &tên_biến)
        cách in: printf("%f", tên_biến) hoặc printf("%lf", tên_biến)
            -> in ra toàn bộ 6 hoặc 14 số sau dấu phẩy
            -> dùng %.xf hoặc %.xlf để in ra x số sau dấu phẩy
            -> ví dụ: printf("%.2f", tên_biến) in ra 2 số sau dấu phẩy

    * Kí tự: 
        char: %c, 1 byte, đùng để lưu 1 kí tự
        cách nhập: scanf("%c", &tên biến)
        cách khai báo: char tên_biến = 'kí tự gì đó'
        cách in: printf("%c", tên_biến)
    
    * Chuỗi kí tự:
        char tên_biến[kích thước mảng]: dùng để lưu một chuỗi kí tự
        cách nhập: scanf("%s", tên_biến) -> không cần dấu &
        cách in: printf("%s", tên_biến)
        => cách này có nhược điểm là không thể nhập được chuỗi có dấu cách
        
        có thể dùng fgets() để nhập chuỗi có dấu cách
        cách dùng:
            char str[100];
            fgets(str, sizeof(str), stdin); // nhập chuỗi có dấu cách
            printf("%s", str); // in chuỗi vừa nhập

        => fgets() sẽ đọc cả dấu cách và kí tự xuống dòng khi nhấn Enter
        => để loại bỏ kí tự xuống dòng thì dùng:
        
            str[strcspn(str, "\n")] = 0; // loại bỏ kí tự xuống dòng
            hoặc str[strcspn(str, "\n")] = '\0'; // loại bỏ kí tự xuống dòng
            -> lệnh strcspn() trả về vị trí của kí tự cần tìm trong chuỗi
            
        => cần thêm thư viện #include <string.h> để dùng hàm strcspn
        
        getchar() có thể dùng để loại bỏ kí tự xuống dòng còn thừa trong bộ đệm sau khi dùng scanf
        ví dụ:
            int n;
            scanf("%d", &n);
            getchar(); // loại bỏ kí tự xuống dòng còn thừa trong bộ đệm

Toán tử:
    
    * Cách ép kiểu:
        2 số int nhân bị tràn: (long long int)a*b hoặc 1ll*a*b
        phép chia có số thập phân: (float)a/b hoặc 1.0*a/b
    
    * Tăng giảm:
        tên_biến++ -> tính toán rồi tăng -> b = a++ thì b vẫn giữ nguyên, a + 1
        ++tên_biến -> tăng rồi tính toán -> b = ++a thì a và b đều +1
        -> có thể thay bằng các toán tử khác: +, -, *, /, %

    * Một số toán tử khác:
        += có thể thay bằng: +, -, *, /, %
        ví dụ: a += b tương đương a = a + b


Làm việc với kiểu dữ liệu char:

    khi khai báo char tên_biến thì biến sẽ được lưu theo số thứ tự của bảng mã ASCII
    A - Z: 65 - 90
    a - z: 97 - 122
    0 - 9: 48 - 57

    các kí tự thường lớn hơn kí tự hoa 32 đơn vị -> có thể thay đổi hoa thường bằng cách + hoặc - 32
    có thể dùng 'A' hoặc 'a' thay cho số thứ tự của nó trong bảng mã ASCII

    có những hàm hay dùng với kiểu char:
        islower(kí_tự): kiểm tra kí tự có phải là chữ thường không
        isupper(kí_tự): kiểm tra kí tự có phải là chữ hoa không
        tolower(kí_tự): chuyển kí tự thành chữ thường
        toupper(kí_tự): chuyển kí tự thành chữ hoa
        isdigit(kí_tự): kiểm tra kí tự có phải là số không

    cách in giá trị của biến char:
        printf("%c", tên_biến); // in ra kí tự
        printf("%d", tên_biến); // in ra số thứ tự của kí tự trong bảng mã ASCII


Câu lệnh goto:
    
    cú pháp:
        goto nhãn;
        ...
        nhãn: câu lệnh;

    ví dụ:
        #include <stdio.h>
        int main() {
            int i = 0;
            start: // nhãn
            if (i < 5) {
                printf("%d\n", i);
                i++;
                goto start; // quay lại nhãn
            }
            return 0;
        }
    
    hoặc có thể dùng goto để bỏ qua một số dòng lệnh
    ví dụ:
        printf("Hello");
        goto skip;
        printf("World");
        skip: printf("!");
        -> sẽ in ra Hello!


Vòng lặp for:
    
    lệnh break trong vòng lặp for: khi gặp lệnh break sẽ thoát khỏi vòng lặp
    lệnh continue trong vòng lặp for: khi gặp lệnh continue sẽ bỏ qua các lệnh phía sau trong vòng lặp và quay lại vòng lặp tiếp theo
    có thể kết hợp lệnh if else trong vòng lặp for để thực hiện các hành động khác nhau tùy vào điều kiện
        ví dụ:
            for( int i = 1; i <= 10; i++ ) {
                if( i == 5 ) {
                    break; // thoát vòng lặp khi i = 5
                }
            }

            for( int i = 1; i <= 10; i++ ) {
                if( i % 2 == 0 ) {
                    continue; // bỏ qua các lệnh phía sau khi i là số chẵn
                }
                printf("%d ", i); // in ra các số lẻ
            }


Vòng lặp while:
        
    lệnh break trong vòng lặp while: khi gặp lệnh break sẽ thoát khỏi vòng lặp
    lệnh continue trong vòng lặp while: khi gặp lệnh continue sẽ bỏ qua các lệnh phía sau trong vòng lặp và quay lại vòng lặp tiếp theo
    có thể kết hợp lệnh if else trong vòng lặp while để thực hiện các hành động khác nhau tùy vào điều kiện
        ví dụ:
            int i = 1;
            while( i <= 10 ) {
                if( i == 5 ) {
                    break; // thoát vòng lặp khi i = 5
                }
                i++;
            }

            int i = 1;
            while( i <= 10 ) {
                if( i % 2 == 0 ) {
                    i++;
                    continue; // bỏ qua các lệnh phía sau khi i là số chẵn
                }
                printf("%d ", i); // in ra các số lẻ
                i++;
            }


Vòng lặp do while:
    
    cú pháp:
        do {
            // khối lệnh
        } while (điều kiện);
    
    lệnh do while sẽ thực hiện khối lệnh ít nhất một lần trước khi kiểm tra điều kiện
    thường dùng khi yêu cầu người dùng nhập một dữ liệu hợp lệ nếu không sẽ nhập lại


Hàm:
    
    cú pháp:
        kiểu_dữ_liệu tên_hàm(kiểu_dữ liệu của tham số){
            // khối lệnh
            return giá_trị_trả_về; // nếu kiểu_dữ_liệu khác void
        }
    các hàm có thể gọi lẫn nhau, nếu muốn gọi xây dựng nhiều hàm mà không quan tâm đến thứ tự thì cần khai báo nguyên mẫu hàm
    cách khai báo nguyên mẫu hàm:
        kiểu_dữ_liệu tên_hàm(kiểu dữ liệu tham số); // hàm 1
        kiểu_dữ_liệu tên_hàm(kiểu dữ liệu tham số); // hàm 2

    ví dụ khác:
        #include <stdio.h>

        int change(int n){
            n += 10;
            return n;
        }

        int main(){
            int m = 100;
            change(m);
            printf("%d", m);
        }
        -> sẽ in ra 100 vì hàm change chỉ thay đổi giá trị của biến n trong hàm chứ không thay đổi giá trị của biến m trong hàm main
        nếu muốn thay đổi giá trị của biến m thì cần thay đổi int change(int &n)


Mảng một chiều:
    
    khi dùng mảng một chiều làm tham số trong hàm (giống ví dụ về Hàm) thì các giá trị trong mảng sẽ bị thay đổi
    ví dụ:
        #include <stdio.h>

        void change(int arr[], int n){
            for(int i = 0; i < n; i++){
                arr[i] += 10; // thay đổi giá trị của mảng arr
            }
        }

        int main(){
            int arr[] = {1, 2, 3, 4, 5};
            int n = sizeof(arr) / sizeof(arr[0]);
            change(arr, n); // truyền mảng arr và kích thước n cho hàm change
            for(int i = 0; i < n; i++){
                printf("%d ", arr[i]); // in ra các giá trị trong mảng arr -> sẽ in ra 11 12 13 14 15
            }
        }

    khi khai báo mảng thì kích thước mảng có thể để trống nếu khởi tạo mảng ngay lập tức
    ví dụ:
        int arr[] = {1, 2, 3, 4, 5}; // kích thước mảng sẽ là 5
        int arr[5] = {1, 2, 3}; // các phần tử còn lại sẽ được khởi tạo là 0
    
    khi xây dựng một hàm về mảng ở ngoài hàm main nhưng ta thay đổi các giá trị hoặc địa chỉ trong đó thì
    các giá trị hoặc địa chỉ trong mảng ở hàm main cũng sẽ bị thay đổi theo
    

Con trỏ:
    
    biến con trỏ là biến lưu địa chỉ của một biến khác
    ví dụ:
        int a = 10;
        int *p; // khai báo biến con trỏ p
        p = &a; // gán địa chỉ của biến a cho biến con trỏ p
        printf("%d", p); // in ra địa chỉ (tọa độ) của biến a
        printf("%d", *p); // in ra giá trị của biến a thông qua biến con trỏ p
        *p = 20; // thay đổi giá trị của biến a thông qua biến con trỏ p -> lúc này a = 20
    
    cách xây dựng hàm với biến con trỏ
        
        #include <stdio.h>

        void change(int *n){
            *n += 10; // thay đổi giá trị của biến n thông qua con trỏ
        }

        int main(){
            int m = 100;
            change(&m); // truyền địa chỉ của biến m cho hàm change
            printf("%d", m); // in ra giá trị của biến m -> sẽ in ra 110
        }

    - nếu là biến giá trị thì dấu "&" dùng để truy cập tọa độ (địa chỉ)
    - nếu là biến tọa độ (địa chỉ, con trỏ) thì dấu "*" dùng để truy cập giá trị

    mảng cũng được coi là con trỏ
        
        ví dụ:
            int mang[5] = {1, 2, 3, 4, 5};
            printf("%d", mang); // in ra địa chỉ của mảng
            printf("%d", &mang[0]); // in ra địa chỉ của phần tử đầu tiên trong mảng
            lưu ý: 2 câu lệnh trên đều trả về cùng một giá trị -> địa chỉ của mảng chính là địa chỉ của phần tử đầu tiên trong mảng
            printf("%d", &mang[1]); // in ra địa chỉ của phần tử thứ 2 trong mảng

    con trỏ và mảng có thể tương tác với nhau:
        
        ví dụ:
            int a[5] = {6, 7, 8, 9, 10};
            int *p = a; // khai báo con trỏ p và gán địa chỉ của mảng a cho con trỏ p -> con trỏ p sẽ quản lí mảng a
            printf("%d", p[3]);
            printf("%d", *(p + 3));
            -> 2 câu lệnh trên là như nhau, đều in ra số 9
            để dễ hiểu hơn: 
                &a[3] = a + 3 = p + 3 // đều là biến tọa độ (địa chỉ)
                a[3] = *(a + 3) = *(p + 3) // đều là biến giá trị


Cấp phát động:
    
    khi sử dụng cấp phát động thì cần dùng thư viện stdlib.h
    cấp phát động là cấp phát bộ nhớ
    ví dụ: khi khai báo một mảng có 1 triệu phần tử a[1000000] thì sẽ bị tràn bộ nhớ nên ta cần cấp phát động để tránh bị tràn bộ nhớ
    
    cú pháp:
        
        int *p = (int*)malloc(1000000 * sizeof(int)); // cấp phát động cho mảng 1 triệu phần tử
        kiểu_dữ_liệu *tên_biến = (kiểu dữ liệu muốn trả về*)malloc(số lượng phần tử * kích thước của kiểu dữ liệu của phần tử đó);
        
        -> vì malloc sẽ trả về kiểu void* nên cần ép kiểu về kiểu dữ liệu muốn trả về

        free(p); // giải phóng bộ nhớ đã cấp phát động cho biến con trỏ p


Cấu trúc:

    CÓ THỂ XEM LẠI PHẦN NÀY Ở struct.c
    
    cú pháp:
        struct tên_cấu_trúc {
            kiểu_dữ_liệu tên_biến1;
            kiểu_dữ_liệu tên_biến2;
            ...
        };

    ví dụ:

        #include <stdio.h>

        struct SinhVien {
            char ten[50];
            int tuoi;
            float diemTB;
        };

        int main() {
            struct SinhVien sv1;
        }

        để trong hàm main không cần khai báo struct SinhVien mỗi khi cần khai báo một sinh viên mới thì dùng
        typedef struct SinhVien SV ở ngoài hàm main khi đó trong hàm main chỉ cần khai báo SV sv1;

        để truy cập các thành phần trong cấu trúc thì dùng dấu chấm "."
        ví dụ: sv1.ten, sv1.tuoi, sv1.diemTB

    ví dụ về struct:
    #include <stdio.h>
    #include <string.h>

    struct studentInformation{
	    char name[100];
	    char id[50];
	    float gpa;
    };

    int main(){
	
	    struct studentInformation S1;
	
	    fgets(S1.name, sizeof(S1.name), stdin);
	    S1.name[strcspn(S1.name, "\n")] = 0;  // loại bỏ kí tự xuống dòng
	
	    fgets(S1.id, sizeof(S1.id), stdin);  
	    S1.id[strcspn(S1.id, "\n")] = 0;   // loại bỏ kí tự xuống dòng
	
	    scanf("%f", &S1.gpa);
	    getchar();   // để loại bỏ kí tự xuống dòng còn thừa trong bộ đệm sau khi dùng scanf
	
	    printf("\n\n");
	    printf("%s\n", S1.name);
	    printf("%s\n", S1.id);
	    printf("%.2f\n", S1.gpa);
	
	    return 0;
    }