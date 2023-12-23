#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

#include "Public1.h"
#include "Reality.h"
#include "SqList.h"

Status UserCompare(const User &userFirst, const User &userSecond);
Status Register(SqList<User>& userList, const User& newUser);
Status Login(SqList<User>& userList, const std::string& account, const std::string& password, User& currentUser);

#endif // LOGIN_H_INCLUDED
