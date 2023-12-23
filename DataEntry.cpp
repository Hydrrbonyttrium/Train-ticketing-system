#include "DataEntry.h"

void ReadUser(SqList<User>& UserList) {
    std::ifstream file("data\\User.csv");
    if (!file.is_open()) {
        std::cerr << "�޷����ļ�" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        User tempUser;

        // ��ȡ���ָ�ÿ�е��ֶ�
        getline(iss, tempUser.account, '\t');
        getline(iss, tempUser.password, '\t');
        getline(iss, tempUser.name, '\t');
        getline(iss, tempUser.sex, '\t');
        getline(iss, tempUser.id, '\t');
        getline(iss, tempUser.tickets, '\t');
        iss >> tempUser.authority;

        // ����ȡ���û���ӵ��б���
        UserList.ListInsert(UserList.GetLength() + 1, tempUser);
    }

    file.close();
}
