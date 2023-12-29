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

Status RefundTicket(User &user, LinkedList<Ticket>& TicketList, const std::string& trainNumber) {
    // ������һ��
    int i;
    Ticket tempTicket;
    Ticket tempTicketForDel;
    for (i = 1; TicketList.GetElemPtr(i) != nullptr; ++i) {
        tempTicket = TicketList.GetElem(i);
        if (tempTicket.train_number == trainNumber) {
            break;
        }
    }
    if (i > TicketList.ListLength()) return ERROR; // δ�ҵ� ����
    tempTicket.remains++; // ʵ��Ʊ������
    TicketList.ListDelete(i, tempTicketForDel);
    TicketList.ListInsert(i, tempTicket); // ɾһ�����һ��

    size_t foundPos = user.tickets.find(trainNumber);
    if (foundPos != std::string::npos) {
        // �ҵ������ַ���
        user.tickets.erase(foundPos, trainNumber.length());
        return OK;
    } else {
        // δ�ҵ����ַ���
        return ERROR;
    }
}

Status EnqueueWaitingList(User &user, Ticket &ticket) {
    // ���˿ͼ��뵽�ȴ��б���
}

Status ProcessWaitingList() {
    // ����ȴ��б�������Ʊʱ����Ʊ���ȴ��б��еĳ˿�
}

