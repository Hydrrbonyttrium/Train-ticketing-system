#include "Public1.h"
#include "Reality.h"
#include "Search.h"
#include "Ticket.h"
#include "DataEntry.h"
#include "Login.h"
#include "Sqlist.h"

using namespace std;

int main() {
    SqList<User> User_List; // ʹ��ģ���ഴ���û��б�

    User_List.InitList(); // ��ʼ���б�
    ReadUser(User_List); // ��ȡ�û�����

    // ����Ƿ�������һ���û����������һ���û���������Ϣ
    if (User_List.GetLength() > 0) {
        cout << "��һ���û�����Ϣ:" << endl;
        User firstUser;
        if (User_List.GetElem(1, firstUser) == OK) { // �����б��Ǵ� 1 ��ʼ������
            cout << "�˺�: " << firstUser.account << endl;
            cout << "����: " << firstUser.password << endl;
            cout << "����: " << firstUser.name << endl;
            cout << "�Ա�: " << firstUser.sex << endl;
            cout << "ID: " << firstUser.id << endl;
            cout << "��Ʊ: " << firstUser.tickets << endl;
            cout << "Ȩ��: " << firstUser.authority << endl;
        }
    } else {
        cout << "û�ж�ȡ���κ��û����ݡ�" << endl;
    }

    // �����û��б�
    User_List.DestroyList();
    return 0;
}
