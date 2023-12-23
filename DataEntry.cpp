#include "DataEntry.h"

void ReadUser(SqListUser &UserList) {
    std::ifstream file("data\\User.csv");
    if (!file.is_open()) {
        std::cerr << "�޷����ļ�" << std::endl;
        exit(EXIT_FAILURE);
    }

    // ��ʼ�� SqListUser
    UserList.length = 0;
    UserList.listsize = 10; // ��ʼ��С
    UserList.elem = new User[UserList.listsize];

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        if (UserList.length == UserList.listsize) {
            // ��չ�����С
            UserList.listsize *= 2;
            User *newElem = new User[UserList.listsize];
            for (int i = 0; i < UserList.length; i++) {
                newElem[i] = UserList.elem[i];
            }
            delete[] UserList.elem;
            UserList.elem = newElem;
        }

        // ��ȡ���ָ�ÿ�е��ֶ�
        getline(iss, UserList.elem[UserList.length].account, '\t');
        getline(iss, UserList.elem[UserList.length].password, '\t');
        getline(iss, UserList.elem[UserList.length].name, '\t');
        getline(iss, UserList.elem[UserList.length].sex, '\t');
        getline(iss, UserList.elem[UserList.length].id, '\t');
        getline(iss, UserList.elem[UserList.length].tickets, '\t');
        iss >> UserList.elem[UserList.length].authority;
        UserList.length++;
    }

    file.close();
}
