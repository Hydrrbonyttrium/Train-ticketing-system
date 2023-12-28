#include "Public1.h"
#include "Reality.h"
#include "Search.h"
#include "Ticket.h"
#include "DataEntry.h"
#include "Login.h"
#include "Sqlist.h"
#include "LinkList.h"

using namespace std;

//数据实体定义
SqList<User> UserList;
SqList<Train> TrainList;
SqList<TrainNumber> TrainNumberList;
User currentUser;

// 函数声明
void loginMenu();
void userMenu();
void adminMenu();
void loginUser();
void registerUser();
void loginAdmin();
void queryTimetable();
void queryTicketPrice();
void purchaseTicket();
void viewOrders();
void refundOrChangeTicket();
void manageUserDetails();
void manageTrainDetails();
void enterModifyCityInfo();
void optimalStationQuery();

// 主函数
int main() 
{
    UserList.InitList();
    TrainList.InitList();
    TrainNumberList.InitList();
    ReadUser(UserList);
    loginMenu();
    ReadTrain(TrainList);
    ReadTrainNumber(TrainNumberList);
    
    return 0;
}

// 登录菜单
void loginMenu() {
    system("cls");
    int choice;
    while (true) {
        printf("\t\t|=============================================|\n");
        printf("\t\t|===            铁路票务管理系统           ===|\n");
        printf("\t\t|=============================================|\n");
        printf("\t\t|\t1.普通用户登录                        |\n");
        printf("\t\t|\t2.管理员登录                          |\n");
        printf("\t\t|\t3.用户注册                            |\n");
        printf("\t\t|\t4.退出程序                            |\n");
        printf("\t\t|=============================================|\n");
        printf("\t\t请输入要进行的操作(1 - 4)");
        std::cin >> choice;

        switch (choice) {
            case 1:
                loginUser();
                break;
            case 2:
                loginAdmin();
                break;
            case 3:
                registerUser();
                break;
            case 4:
                std::cout << "退出系统.\n";
                exit(0);
            default:
                std::cout << "无效选择，请重试。\n";
                break;
        }
    }
}

//***********普通用户功能***********//

//普通用户登录菜单
 void loginUser() {
    system("cls");
    std::string username, password;
    std::cout << "输入用户名: ";
    std::cin >> username;
    std::cout << "输入密码: ";
    std::cin >> password;
    // 验证登录逻辑
    if(Login(UserList,username,password,currentUser))
        userMenu();
    else
        std::cout << "用户名或密码错误" << endl;
}

// 普通用户主菜单函数
void userMenu() {
    system("cls");
    int choice;
    while (true) {
        std::cout << "\n用户菜单:\n";
        std::cout << "1. 查询时刻表\n";
        std::cout << "2. 查询票价和余票\n";
        std::cout << "3. 购买车票\n";
        std::cout << "4. 查询个人订单\n";
        std::cout << "5. 退票/改签\n";
        std::cout << "6. 退出系统\n";
        std::cout << "选择操作 (1-6): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                queryTimetable();
                break;
            case 2:
                queryTicketPrice();
                break;
            case 3:
                purchaseTicket();
                break;
            case 4:
                viewOrders();
                break;
            case 5:
                refundOrChangeTicket();
                break;
            case 6:
                std::cout << "退出用户菜单.\n";
                return; // 返回到登录界面
            default:
                std::cout << "无效选择，请重试。\n";
                break;
        }
    }
}

// 普通用户注册菜单
void registerUser() {
    int outcome;
    std::string username, password, name, confirmPassword ,sex, id;
    do{
        system("cls");
        std::cout << "输入用户名: ";
        std::cin >> username;
        std::cout << "设置密码: ";
        std::cin >> password;
        std::cout << "确认密码: ";
        std::cin >> confirmPassword;
        std::cout <<"输入姓名:";
        std::cin >> name;
        std::cout << "请输入性别:";
        std::cin >> sex;
        std::cout << "输入身份证:";
        std::cin >> id;
        outcome= password==confirmPassword?0:1;
        if(outcome)
        {
            std::cout << "两次密码不同,请重新输入" <<endl;
            system("pause");
        }
    }while(outcome);
    // TODO: 注册逻辑
    User tempUser;
    tempUser={username,password,name,sex,id,"0",0};
    Register(UserList,tempUser);
    std::cout << "注册成功" << endl;
    system("pause");
    loginUser();
}

// 查询时刻表
void queryTimetable() {
    std::string trainNumberOrStation;
    std::cout << "\n输入车次或站点: ";
    std::cin >> trainNumberOrStation;
    // TODO: 根据输入的车次或站点显示相关时刻表
}

// 查询票价和余票
void queryTicketPrice() {
    std::string trainNumber;
    std::cout << "\n输入车次: ";
    std::cin >> trainNumber;
    // TODO: 根据输入的车次显示票价和余票信息
}

// 查看个人订单
void viewOrders() {
    // 实现查看个人订单逻辑...
}

// 购买车票
void purchaseTicket() {
    std::string trainNumber;
    std::string seatType;
    // TODO: 实现购买车票的逻辑
    // 输入车次、选择座位类型等
}

// 预售车票
void purchaseAdvanceTicket() {
    // 实现预售车票购买逻辑...
}

// 退票/改签
void refundOrChangeTicket() {
    // TODO: 实现退票或改签的逻辑
    // 显示用户订单，选择进行退票或改签的订单
}

//**********************************//





//***********管理员用户功能**********//
//管理员用户登录菜单
void loginAdmin() {
    std::string adminUsername, adminPassword;
    std::cout << "输入管理员用户名: ";
    std::cin >> adminUsername;
    std::cout << "输入密码: ";
    std::cin >> adminPassword;
    // TODO: 验证管理员登录逻辑
    if(Login(UserList,adminUsername,adminPassword,currentUser)&&currentUser.authority)
        adminMenu();
    else
        std::cout << "非管理员用户或用户名或密码错误" << endl;
}

// 管理员主菜单函数
void adminMenu() {
    system("cls");
    int choice;
    while (true) {
        std::cout << "\n管理员菜单:\n";
        std::cout << "1. 用户资料管理\n";
        std::cout << "2. 车次信息管理\n";
        std::cout << "3. 录入/修改城市信息\n";
        std::cout << "4. 录入/修改车辆类别信息\n";
        std::cout << "5. 站间最优查询管理\n";
        std::cout << "6. 退出系统\n";
        std::cout << "选择操作 (1-6): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                manageUserDetails();
                break;
            case 2:
                manageTrainDetails();
                break;
            case 3:
                optimalStationQuery();
                break;
            case 4:
                // TODO: 实现录入/修改车辆类别信息的函数
                break;
            case 5:
                optimalStationQuery();
                break;
            case 6:
                std::cout << "退出管理员菜单.\n";
                return; // 返回到登录界面
            default:
                std::cout << "无效选择，请重试。\n";
                break;
        }
    }
}

//用户资料管理
void manageUserDetails() {
    int choice;
    while (true) {
        std::cout << "\n管理用户资料:\n";
        std::cout << "1. 查看用户列表\n";
        std::cout << "2. 选择用户进行编辑\n";
        std::cout << "3. 返回上一级\n";
        std::cout << "选择操作 (1-3): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                // TODO: 实现查看用户列表的逻辑
                break;
            case 2:
                // TODO: 实现选择并编辑用户的逻辑
                break;
            case 3:
                return; // 返回管理员菜单
            default:
                std::cout << "无效选择，请重试。\n";
                break;
        }
    }
}

//管理车次信息
void manageTrainDetails() {
    int choice;
    while (true) {
        std::cout << "\n管理车次信息:\n";
        std::cout << "1. 查看车次列表\n";
        std::cout << "2. 选择车次进行编辑\n";
        std::cout << "3. 返回上一级\n";
        std::cout << "选择操作 (1-3): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                // TODO: 实现查看车次列表的逻辑
                break;
            case 2:
                // TODO: 实现选择并编辑车次的逻辑
                break;
            case 3:
                return; // 返回管理员菜单
            default:
                std::cout << "无效选择，请重试。\n";
                break;
        }
    }
}

//修改城市信息
void enterModifyCityInfo(){

}

//最优站点查询
void optimalStationQuery(){

}
//**********************************//
