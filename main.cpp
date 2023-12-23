#include "Public1.h"
#include "Reality.h"
#include "Search.h"
#include "Ticket.h"
#include "DataEntry.h"
#include "Login.h"
#include "Sqlist.h"
#include "LinkList.h"
using namespace std;

int main() {
    // ��ʼ���û���
    SqList<User> user_list;
    user_list.InitList();
    ReadUser(user_list);

    User current_user;
    /*****************************
     * ����ʵ�ֵ�¼
     * ����½��ɵ�User��ֵ��current_user
     * ������ʹ��
    *****************************/
    // ����ʹ��һ��ʾ��
    // ע�����û�
    User newUser = {"zhangsan", "password123", "New User"};
    if (Register(user_list, newUser)) {
        std::cout << "ע��ɹ���" << std::endl;
    }

    // �û���¼
    std::string account, password;
    std::cout << "�������˺�: ";
    std::cin >> account;
    std::cout << "����������: ";
    std::cin >> password;

    if (Login(user_list, account, password, current_user)) {
        std::cout << "��¼�ɹ�����ӭ " << current_user.name << std::endl;
    } else {
        std::cout << "��¼ʧ�ܣ�" << std::endl;
    }

    //��ʼ��Ʊ������
    LinkedList<Ticket> ticket_list;
    ReadTicket(ticket_list);

    Ticket ticket_to_purchase;
    /*****************************
     * ����ʵ��Ʊ������
     * ��������ѡ�е�Ʊ��ֵ��ticket_to_purchase
    *****************************/
    // ����ʹ��һ��ʾ��
    ticket_to_purchase = ticket_list.GetElem(1);

    // ����һ�¹�Ʊ
    if (PurchaseTicket(current_user, ticket_to_purchase)) {
        cout << "��Ʊ�ɹ�" << endl;
    } else {
        cout << "�Ѽ���Ⱥ��б���" << endl;
    }

    // ������ɽ����д��
    // ע������Ҫɾ��һ������һ��
    int user_delete_index;
    User user_delete_temp;
    user_delete_index = user_list.LocateElem(current_user, UserCompare);
    user_list.ListDelete(user_delete_index, user_delete_temp);
    user_list.ListInsert(user_delete_index, current_user);

    WriteUser(user_list);

    /***************************
     * ׼���˳�����
     * 1.����������д�������ļ�
     * 2.����������ݽṹ�����ڴ�й©
     * (SqList��LinkedListʹ���ˡ���Դ��ȡ����ʼ������RAII������Ҫ����)
    ***************************/

    return 0;
}
