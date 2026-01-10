#include <stdio.h>
#include <string.h>

struct studentInformation{
    char name[100];
    char phoneNumber[50];
};

struct studentInformation input01(){

    struct studentInformation tmpInput01;

    fgets(tmpInput01.name, sizeof(tmpInput01.name), stdin);
    tmpInput01.name[strcspn( tmpInput01.name, "\n")] = 0;  // loại bỏ kí tự xuống dòng

    fgets(tmpInput01.phoneNumber, sizeof(tmpInput01.phoneNumber), stdin);  
    tmpInput01.phoneNumber[strcspn( tmpInput01.phoneNumber, "\n")] = '\0';   // loại bỏ kí tự xuống dòng

    return tmpInput01;

}

void input02(struct studentInformation *tmpInput02){

    fgets(tmpInput02->name, sizeof(tmpInput02->name), stdin);
    tmpInput02->name[strcspn( tmpInput02->name, "\n")] = 0;  // loại bỏ kí tự xuống dòng

    fgets(tmpInput02->phoneNumber, sizeof(tmpInput02->phoneNumber), stdin);  
    tmpInput02->phoneNumber[strcspn( tmpInput02->phoneNumber, "\n")] = '\0';   // loại bỏ kí tự xuống dòng
}

void output(struct studentInformation tmpOutput){
    printf("Name: %s\n", tmpOutput.name);
    printf("Phone Number: %s\n", tmpOutput.phoneNumber);
}

int main(){
    //cách in thứ 1 in trực tiếp khi trả về từ hàm do trong input01 có return
    struct studentInformation S1 = input01();
    output(S1);

    //cách in thứ 2 in thông qua con trỏ
    struct studentInformation S2;
    input02(&S2);
    output(S2);

    return 0;
}