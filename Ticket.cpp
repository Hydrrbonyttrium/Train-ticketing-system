#include "Ticket.h"

Status PurchaseTicket(User &user, Ticket &ticket) {
    // ʵ�ֹ�Ʊ�߼�
    // ���� trainNumber ���Ҳ��޸ĳ�Ʊ��Ϣ
    // ���Ʊ��Ϊ0������ RecommendTickets �� EnqueueWaitingList
    // ���ɶ��������³��ε�ʣ��Ʊ��
    int remain_ticket_num = ticket.remains;
    string this_ticket = ticket.train_number;
    if (remain_ticket_num != 0) {
        remain_ticket_num--;
        ticket.remains--;
        if (!user.tickets.empty()) {user.tickets += '/'; } // ����ķָ����д�����
        user.tickets += this_ticket;         // ���û��ṹ��������Ʊ��¼
        return OK;
    }else {
        // ������ȴ��б� Ŀǰδ�깤
        // if (EnqueueWaitingList()) {return OK; }
        // else {return ERROR; }
        return OK;
    }
}

Status EnqueueWaitingList(const std::string& trainNumber) {
    // ���˿ͼ��뵽�ȴ��б���
}

Status ProcessWaitingList() {
    // ����ȴ��б�������Ʊʱ����Ʊ���ȴ��б��еĳ˿�
}

Status RefundTicket(LinkedList<Ticket>& ticketList, const std::string& ticketID) {
    // ʵ����Ʊ�߼�
    // ���� ticketID ���Ҳ��޸ĳ�Ʊ��Ϣ
    // ������Ʊʱ�����������
    // ���³��ε�ʣ��Ʊ��
}
