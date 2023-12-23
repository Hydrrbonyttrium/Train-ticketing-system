#include "Login.h"
#include <iostream>

Status UserCompare(const User &userFirst, const User &userSecond) {
    if (userFirst.account == userSecond.account) {
        return TRUE;
    }else {
        return FALSE;
    }
}

Status Register(SqList<User>& userList, const User& newUser) {
    // ����û����Ƿ��Ѵ���
    for (int i = 1; i <= userList.GetLength(); ++i) {
        User existingUser;
        if (userList.GetElem(i, existingUser) == OK) {
            if (existingUser.account == newUser.account) {
                std::cout << "�û��Ѵ��ڣ�" << std::endl;
                return ERROR;
            }
        }
    }
    // ������û�
    userList.ListInsert(userList.GetLength() + 1, newUser);
    return OK;
}

Status Login(SqList<User>& userList, const std::string& account, const std::string& password, User& currentUser) {
    for (int i = 1; i <= userList.GetLength(); ++i) {
        User existingUser;
        if (userList.GetElem(i, existingUser) == OK) {
            if (existingUser.account == account && existingUser.password == password) {
                currentUser = existingUser;
                return true;
            }
        }
    }
    return false;
}
