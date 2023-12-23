#include "Public1.h"
#include "Reality.h"
#include "Search.h"
#include "Ticket.h"
#include "DataEntry.h"
#include "Login.h"
#include "Sqlist.h"
SqListUser User_List;

using namespace std;

int main() {
    InitList(User_List);
    ReadUser(User_List);

    // 检查是否有至少一个用户，并输出第一个用户的所有信息
    if (User_List.length > 0) {
        cout << "第一个用户的信息:" << endl;
        cout << "账号: " << User_List.elem[0].account << endl;
        cout << "密码: " << User_List.elem[0].password << endl;
        cout << "姓名: " << User_List.elem[0].name << endl;
        cout << "性别: " << User_List.elem[0].sex << endl;
        cout << "ID: " << User_List.elem[0].id << endl;
        cout << "车票: " << User_List.elem[0].tickets << endl;
        cout << "权限: " << User_List.elem[0].authority << endl;
    } else {
        cout << "没有读取到任何用户数据。" << endl;
    }

    // 清理用户列表
    DestroyList(User_List);
    return 0;
}
