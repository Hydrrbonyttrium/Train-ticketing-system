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
    user_list.GetElem(1, current_user);

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
    User user_delete_temp;
    user_list.ListDelete(1, user_delete_temp);
    user_list.ListInsert(1, current_user);

    WriteUser(user_list);

    /***************************
     * ׼���˳�����
     * 1.����������д�������ļ�
     * 2.����������ݽṹ�����ڴ�й©
     * (SqList��LinkedListʹ���ˡ���Դ��ȡ����ʼ������RAII������Ҫ����)
    ***************************/

    return 0;
}
