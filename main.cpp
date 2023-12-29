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

Graph CityGraph;
WeightMap weightmap;
std::unordered_map<std::string, Vertex> stationMap;

User currentUser;
LinkedList<Ticket> TicketList;

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
void queryInterCityPath();
void SetConsoleSize(int cols, int lines);
void viewUserList(SqList<User>& UserList);
void modifyUser(SqList<User>& UserList);
void viewTrainNumberList(SqList<TrainNumber>& TrainNumberList);
void modifyTrainNumberList(SqList<TrainNumber>& TrainNumberList);
std::string getCityName(const Vertex& v);
int getEdgeWeight(const Vertex& v1, const Vertex& v2, WeightMap& weightmap);
// 主函数
int main()
{
    SetConsoleSize(80, 20);
    // 全套数据读取
    UserList.InitList();
    TrainList.InitList();
    TrainNumberList.InitList();
    ReadUser(UserList);
    ReadTicket(TicketList);
    weightmap = get(boost::edge_weight, CityGraph);
    ReadCity(CityGraph, weightmap, stationMap);
    loginMenu();
    // ReadTrain(TrainList);
    // ReadTrainNumber(TrainNumberList);

    // 退出程序
    // 注意这里要删除一个插入一个
    // 注意这里要删除一个插入一个
    int user_delete_index;
    User user_delete_temp;
    user_delete_index = UserList.LocateElem(currentUser, UserCompare);
    UserList.ListDelete(user_delete_index, user_delete_temp);
    UserList.ListInsert(user_delete_index, currentUser);

    WriteUser(UserList);
    WriteTicket(TicketList);
    return 0;
}

// 登录菜单
void loginMenu() {
    
    SetConsoleSize(80, 20); // 控制窗口大小
    int choice;
    while (true) {
        system("cls");
        printf("\n\n\n\n\n\n");
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
                return; // 返回 开始退出程序
            default:
                std::cout << "无效选择，请重试。\n";
                break;
        }
    }
}

//***********普通用户功能***********//

// 普通用户登录菜单
void loginUser() {
    SetConsoleSize(80, 20);
    system("cls");
    std::string username, password;

    std::cout << "\n\n";
    std::cout << "\t\t╔══════════════════════════════════════╗\n";
    std::cout << "\t\t║      欢迎使用铁路票务管理系统        ║\n";
    std::cout << "\t\t╠══════════════════════════════════════╣\n";
    std::cout << "\t\t║            用户登录菜单              ║\n";
    std::cout << "\t\t╚══════════════════════════════════════╝\n";

    std::cout << "输入用户名: ";
    std::cin >> username;
    std::cout << "输入密码: ";
    std::cin >> password;

    // 验证登录逻辑
    if (Login(UserList, username, password, currentUser)) {
        userMenu();
    } else {
        std::cout << "用户名或密码错误。\n";
    }
}


// 用户主菜单函数
void userMenu() {
    SetConsoleSize(80, 20);
    system("cls");
    int choice;
    while (true) {
        std::cout << "\n\n";
        std::cout << "\t\t╔══════════════════════════════════════╗\n";
        std::cout << "\t\t║      欢迎使用铁路票务管理系统        ║\n";
        std::cout << "\t\t╠══════════════════════════════════════╣\n";
        std::cout << "\t\t║               用户菜单               ║\n";
        std::cout << "\t\t╠══════════════════════════════════════╣\n";
        std::cout << "\t\t║ 1. 查询时刻表                        ║\n";
        std::cout << "\t\t║ 2. 查询票价和余票                    ║\n";
        std::cout << "\t\t║ 3. 查询城际路径                      ║\n";
        std::cout << "\t\t║ 4. 购买车票                          ║\n";
        std::cout << "\t\t║ 5. 查询个人订单                      ║\n";
        std::cout << "\t\t║ 6. 退票/改签                         ║\n";
        std::cout << "\t\t║ 7. 退出系统                          ║\n";
        std::cout << "\t\t╚══════════════════════════════════════╝\n";
        std::cout << "选择操作 (1-7): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                queryTimetable();
                break;
            case 2:
                queryTicketPrice();
                break;
            case 3:
                queryInterCityPath();
                break;
            case 4:
                purchaseTicket();
                break;
            case 5:
                viewOrders();
                break;
            case 6:
                refundOrChangeTicket();
                break;
            case 7:
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
    SetConsoleSize(80, 20);
    system("cls");
    int outcome;
    std::string username, password, name, confirmPassword, sex, id;

    do {
        system("cls");
        std::cout << "\n\n";
        std::cout << "╔══════════════════════════════════════╗\n";
        std::cout << "║      欢迎使用铁路票务管理系统        ║\n";
        std::cout << "╠══════════════════════════════════════╣\n";
        std::cout << "║            用户注册菜单             ║\n";
        std::cout << "╚══════════════════════════════════════╝\n";

        std::cout << "输入用户名: ";
        std::cin >> username;
        std::cout << "设置密码: ";
        std::cin >> password;
        std::cout << "确认密码: ";
        std::cin >> confirmPassword;
        std::cout << "输入姓名: ";
        std::cin >> name;
        std::cout << "请输入性别: ";
        std::cin >> sex;
        std::cout << "输入身份证: ";
        std::cin >> id;

        outcome = (password == confirmPassword) ? 0 : 1;

        if (outcome) {
            std::cout << "两次密码不同，请重新输入。\n";
            system("pause");
        }
    } while (outcome);

    User tempUser;
    tempUser = {username, password, name, sex, id, "0", 0};
    if(Register(UserList, tempUser))
        std::cout << "注册成功。\n";
    system("pause");
    loginUser();
}


// 查询时刻表
void queryTimetable() {
    SetConsoleSize(100, 60);
    system("cls");
    std::string start_stop;
    std::string end_stop;

    std::cout << "输入出发站点: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略之前的输入
    std::getline(std::cin, start_stop); // 使用 getline 读取包含空格的字符串

    std::cout << "输入到达站点: ";
    std::getline(std::cin, end_stop); // 同样使用 getline

    if (Timetable(TicketList, start_stop, end_stop)) {
        std::cout << "查询结束" << std::endl;
    } else {
        std::cout << "查询失败: 未找到匹配的车次" << std::endl;
    }
    while (TRUE) {
        char result;
        std::cout << "按q结束查询：";
        std::cin >> result;
        if (result == 'q'){
            SetConsoleSize(80, 20);
            system("cls");
            break;
        }
    }
}

// 查询票价和余票
void queryTicketPrice() {
    SetConsoleSize(80, 20);
    system("cls");
    std::string trainNumber;
    std::cout << "输入车次号: ";
    std::cin >> trainNumber;

    Ticket foundTicket = FindTicketByTrainNumber(TicketList, trainNumber);
    if (!foundTicket.train_number.empty()) { // 检查是否找到了票
        std::cout << "车次: " << foundTicket.train_number
                  << ", 票价: " << foundTicket.price
                  << ", 剩余票数: " << foundTicket.remains << std::endl;
    } else {
        std::cout << "未找到车次为 " << trainNumber << " 的票信息" << std::endl;
    }
}

// 查看个人订单
void viewOrders() {
    SetConsoleSize(80, 20);
    system("cls");
    User tempUser = currentUser;
    string tempCurrentUserTicket = tempUser.tickets;
    cout << "该用户拥有票：" << endl;
    // 遍历用户拥有的票，并在遇到'/'字符时换行打印
    for (char ch : tempUser.tickets) {
        if (ch == '/') {
            std::cout << std::endl;
        } else {
            std::cout << ch;
        }
    }
    std::cout << std::endl;
}

// 购买车票
void purchaseTicket() {
    SetConsoleSize(80, 20);
    system("cls");
    std::string trainNumber;
    std::string seatType;

    cout << "请输入车次：";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略之前的输入
    std::getline(std::cin, trainNumber); // 使用 getline 读取包含空格的字符串
    cout << "请输入座位类型（First Class/Second Class）：";
    std::getline(std::cin, seatType); // 同样使用 getline
    Ticket tempfoundTicket = FindTicketByTrainNumberAndSeat(TicketList, trainNumber, seatType);
    if (!tempfoundTicket.train_number.empty()) { // 检查是否找到了票
        std::cout << "找到车票 正在购买" << std::endl;
        PurchaseTicket(currentUser, tempfoundTicket);
    } else {
        std::cout << "未找到车次为 " << trainNumber << " 的票信息" << std::endl;
    }
}

void queryInterCityPath() {
    SetConsoleSize(100, 60);
    system("cls");
    std::cout << "\t\t╔══════════════════════════════════════╗\n";
    std::cout << "\t\t║      欢迎使用铁路票务管理系统        ║\n";
    std::cout << "\t\t╠══════════════════════════════════════╣\n";
    std::cout << "\t\t║            城际查询菜单              ║\n";
    std::cout << "\t\t╚══════════════════════════════════════╝\n";

    std::cout << "请输入出发城市: ";
    std::string sourceCity;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, sourceCity);

    std::cout << "请输入目的城市: ";
    std::string destinationCity;
    std::getline(std::cin, destinationCity);

    if (stationMap.find(sourceCity) != stationMap.end() && stationMap.find(destinationCity) != stationMap.end()) {
        Vertex startVertex = stationMap[sourceCity];
        Vertex endVertex = stationMap[destinationCity];
        std::vector<Vertex> path = dijkstraShortestPath(CityGraph, startVertex, endVertex);

        // 获取权重映射
        WeightMap weightmap = get(boost::edge_weight, CityGraph);

        // 输出表头
        std::cout << std::left << std::setw(40) << "起始城市" << "|" << std::setw(40) << "目的城市" << "|" << std::setw(10) << "距离" << std::endl;
        std::cout << std::string(52, '-') << std::endl; // 打印分隔线

        for (size_t i = 0; i < path.size() - 1; ++i) {
            std::string fromCity = getCityName(path[i]);
            std::string toCity = getCityName(path[i + 1]);

            // 假设已有函数可以获取两个顶点之间的边权重
            int distance = getEdgeWeight(path[i], path[i + 1], weightmap);

            std::cout << std::left << std::setw(40) << fromCity << "|" << std::setw(40) << toCity << "|" << std::setw(10) << distance << std::endl;
        }
    }

    while (TRUE) {
        char result;
        std::cout << "按q结束查询：";
        std::cin >> result;
        if (result == 'q') {
            SetConsoleSize(80, 20);
            system("cls");
            break;
        }
    }
}

// 预售车票
void purchaseAdvanceTicket() {
    // 实现预售车票购买逻辑...
    // 先进入时刻表查询
    queryTimetable();

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
    system("cls");
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
    system("cls");
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
                viewUserList(UserList);
                break;
            case 2:
                // TODO: 实现选择并编辑用户的逻辑
                modifyUser(UserList);
                break;
            case 3:
                return; // 返回管理员菜单
            default:
                std::cout << "无效选择，请重试。\n";
                break;
        }
    }
}

//查看用户信息
void viewUserList(SqList<User>& UserList){
    system("cls");
    int i = 0;
    std::cout << std::left
            << std::setw(14) << "用户名" << " | "
            << std::setw(14) << "密码" << " | "
            << std::setw(4) << "姓名" << " | "
            << std::setw(2) << "性别" << " | "
            << std::setw(18) << "身份证号" << " | "
            << std::setw(20) << "购买的票" << " | "
            << std::setw(14) << "权限" << endl;
    for(int i = 0;i <= UserList.GetLength();i++)
    {
        User currentUser;
        UserList.GetElem(i,currentUser);
        std::cout << std::left
                << std::setw(14) << currentUser.account <<" | "
                << std::setw(14) << currentUser.password <<" | "
                << std::setw(4) << currentUser.name << " | "
                << std::setw(2) << currentUser.sex << " | "
                << std::setw(18) << currentUser.id << " | "
                << std::setw(20) << currentUser.tickets << " | "
                << std::setw(14) << currentUser.authority <<endl;
    }
    system("pause");
}

void modifyUser(SqList<User>& UserLsit){
    string account;
    system("cls");
    std::cout << "请输入你想找的用户名:";
    std::cin >> account;
    std::cout << "输入修改后的用户资料"<<endl;
    for(int i = 0 ;i <= UserList.GetLength(); i++ ){
        User currentUser;
        UserList.GetElem(i,currentUser);
        if(currentUser.account == account)
        {
            UserList.ListDelete(i,currentUser);
            std::cout << "用户名:";
            std::cin >> currentUser.account;
            std::cout << "密码:";
            std::cin >> currentUser.password;
            std::cout << "姓名:";
            std::cin >> currentUser.name;
            std::cout <<"性别:";
            std::cin >>currentUser.sex;
            std::cout <<"身份证:";
            std::cin >> currentUser.id;
            std::cout <<"订单:";
            std::cin >> currentUser.tickets;
            std::cout <<"权限:";
            std::cin >> currentUser.authority;
            UserList.ListInsert(i,currentUser);
        }
    }
    system("pause");
}

//管理车次信息
void manageTrainDetails() {
    int choice;
    system("cls");
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
                viewTrainNumberList(TrainNumberList);
                break;
            case 2:
                // TODO: 实现选择并编辑车次的逻辑
                modifyTrainNumberList(TrainNumberList);
                break;
            case 3:
                return; // 返回管理员菜单
            default:
                std::cout << "无效选择，请重试。\n";
                break;
        }
    }
}

void viewTrainNumberList(SqList<TrainNumber>& TrainNumberList){
    system("cls");
    int i = 0;
    std::cout << std::left
            << std::setw(14) << "车次" << " | "
            << std::setw(14) << "始发站" << " | "
            << std::setw(4) << "终点站" << " | "
            << std::setw(2) << "票价" << " | "
            << std::setw(18) << "余票" << " | "
            << std::setw(20) << "总路程" << " | "
            << std::setw(14) << "总车程" << endl;
    for(int i = 0;i <= UserList.GetLength();i++)
    {
        TrainNumber currentTrainNumber;
        TrainNumberList.GetElem(i,currentTrainNumber);
        std::cout << std::left
                << std::setw(14) << currentTrainNumber.number <<" | "
                << std::setw(14) << currentTrainNumber.begin <<" | "
                << std::setw(4) << currentTrainNumber.end << " | "
                << std::setw(2) << currentTrainNumber.price << " | "
                << std::setw(18) << currentTrainNumber.remains << " | "
                << std::setw(20) << currentTrainNumber.distance << " | "
                << std::setw(14) << currentTrainNumber.train_distance <<endl;
    }
    system("pause");
}

void modifyTrainNumberList(SqList<TrainNumber>&TrainNumberList){
    string number;
    system("cls");
    std::cout << "请输入你想找的车次:";
    std::cin >> number;
    std::cout << "输入修改后的车次信息"<<endl;
    for(int i = 0 ;i <= TrainNumberList.GetLength(); i++ ){
        TrainNumber currentTrainNumber;
        TrainNumberList.GetElem(i,currentTrainNumber);
        if(currentTrainNumber.number == number)
        {
            TrainNumberList.ListDelete(i,currentTrainNumber);
            std::cout << "车次:";
            std::cin >> currentTrainNumber.number;
            std::cout << "始发站:";
            std::cin >> currentTrainNumber.begin;
            std::cout << "终点站:";
            std::cin >> currentTrainNumber.end;
            std::cout <<"票价:";
            std::cin >>currentTrainNumber.price;
            std::cout <<"余票:";
            std::cin >> currentTrainNumber.remains;
            std::cout <<"总路程:";
            std::cin >> currentTrainNumber.distance;
            std::cout <<"总车程:";
            std::cin >> currentTrainNumber.train_distance;
            TrainNumberList.ListInsert(i,currentTrainNumber);
        }
    }
    system("pause");
}
//修改城市信息
void enterModifyCityInfo(){
    
}

//最优站点查询
void optimalStationQuery(){

}
//**********************************//

std::string getCityName(const Vertex& v) {
    for (const auto& pair : stationMap) {
        if (pair.second == v) {
            return pair.first; // 找到与 Vertex 对应的城市名称
        }
    }
    return ""; // 如果没有找到对应的城市，返回空字符串
}

int getEdgeWeight(const Vertex& v1, const Vertex& v2, WeightMap& weightmap) {
    boost::graph_traits<Graph>::edge_descriptor e;
    bool exists;
    boost::tie(e, exists) = edge(v1, v2, CityGraph);

    if (exists) {
        return weightmap[e]; // 返回边的权重
    } else {
        return -1; // 表示边不存在
    }
}

// 设置控制台窗口大小的函数
void SetConsoleSize(int cols, int lines) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // 设置控制台窗口缓冲区大小
    COORD coord;
    coord.X = cols;
    coord.Y = lines;
    SetConsoleScreenBufferSize(hOut, coord);

    // 设置控制台窗口大小
    SMALL_RECT rect;
    rect.Left = 0;
    rect.Top = 0;
    rect.Right = cols - 1;
    rect.Bottom = lines - 1;
    SetConsoleWindowInfo(hOut, TRUE, &rect);
}
