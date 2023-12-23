#include "DataEntry.h"

void ReadUser(SqList<User>& UserList) {
    std::ifstream file("data\\User.csv");
    if (!file.is_open()) {
        std::cerr << "无法打开文件" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        User tempUser;

        // 读取并分割每行的字段
        getline(iss, tempUser.account, '\t');
        getline(iss, tempUser.password, '\t');
        getline(iss, tempUser.name, '\t');
        getline(iss, tempUser.sex, '\t');
        getline(iss, tempUser.id, '\t');
        getline(iss, tempUser.tickets, '\t');
        iss >> tempUser.authority;

        // 将读取的用户添加到列表中
        UserList.ListInsert(UserList.GetLength() + 1, tempUser);
    }

    file.close();
}
