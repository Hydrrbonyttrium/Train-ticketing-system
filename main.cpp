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

    // ����Ƿ�������һ���û����������һ���û���������Ϣ
    if (User_List.length > 0) {
        cout << "��һ���û�����Ϣ:" << endl;
        cout << "�˺�: " << User_List.elem[0].account << endl;
        cout << "����: " << User_List.elem[0].password << endl;
        cout << "����: " << User_List.elem[0].name << endl;
        cout << "�Ա�: " << User_List.elem[0].sex << endl;
        cout << "ID: " << User_List.elem[0].id << endl;
        cout << "��Ʊ: " << User_List.elem[0].tickets << endl;
        cout << "Ȩ��: " << User_List.elem[0].authority << endl;
    } else {
        cout << "û�ж�ȡ���κ��û����ݡ�" << endl;
    }

    // �����û��б�
    DestroyList(User_List);
    return 0;
}
