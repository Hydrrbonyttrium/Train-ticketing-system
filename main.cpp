#include "Public1.h"
#include "Reality.h"
#include "Search.h"
#include "Ticket.h"
#include "DataEntry.h"
#include "Login.h"
#include "Sqlist.h"

using namespace std;

int main() {
    SqList<User> User_List; // 使用模板类创建用户列表

    User_List.InitList(); // 初始化列表
    ReadUser(User_List); // 读取用户数据

    // 检查是否有至少一个用户，并输出第一个用户的所有信息
    if (User_List.GetLength() > 0) {
        cout << "第一个用户的信息:" << endl;
        User firstUser;
        if (User_List.GetElem(1, firstUser) == OK) { // 假设列表是从 1 开始索引的
            cout << "账号: " << firstUser.account << endl;
            cout << "密码: " << firstUser.password << endl;
            cout << "姓名: " << firstUser.name << endl;
            cout << "性别: " << firstUser.sex << endl;
            cout << "ID: " << firstUser.id << endl;
            cout << "车票: " << firstUser.tickets << endl;
            cout << "权限: " << firstUser.authority << endl;
        }
    } else {
        cout << "没有读取到任何用户数据。" << endl;
    }

    // 清理用户列表
    User_List.DestroyList();
    return 0;
}
