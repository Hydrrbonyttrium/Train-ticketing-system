#include "Ticket.h"

Status PurchaseTicket(User &user, Ticket &ticket) {
    // 实现购票逻辑
    // 根据 trainNumber 查找并修改车票信息
    // 如果票数为0，调用 RecommendTickets 或 EnqueueWaitingList
    // 生成订单，更新车次的剩余票数
    int remain_ticket_num = ticket.remains;
    string this_ticket = ticket.train_number;
    if (remain_ticket_num != 0) {
        remain_ticket_num--;
        ticket.remains--;
        if (!user.tickets.empty()) {user.tickets += '/'; } // 这里的分隔符有待商议
        user.tickets += this_ticket;         // 在用户结构体下增加票记录
        return OK;
    }else {
        // 添加至等待列表 目前未完工
        // if (EnqueueWaitingList()) {return OK; }
        // else {return ERROR; }
        return OK;
    }
}

Status RefundTicket(User &user, LinkedList<Ticket>& TicketList, const std::string& trainNumber) {
    // 先搜索一下
    int i;
    Ticket tempTicket;
    Ticket tempTicketForDel;
    for (i = 1; TicketList.GetElemPtr(i) != nullptr; ++i) {
        tempTicket = TicketList.GetElem(i);
        if (tempTicket.train_number == trainNumber) {
            break;
        }
    }
    if (i > TicketList.ListLength()) return ERROR; // 未找到 返回
    tempTicket.remains++; // 实现票数增加
    TicketList.ListDelete(i, tempTicketForDel);
    TicketList.ListInsert(i, tempTicket); // 删一个添加一个

    size_t foundPos = user.tickets.find(trainNumber);
    if (foundPos != std::string::npos) {
        // 找到了子字符串
        user.tickets.erase(foundPos, trainNumber.length());
        return OK;
    } else {
        // 未找到子字符串
        return ERROR;
    }
}

Status EnqueueWaitingList(User &user, Ticket &ticket) {
    // 将乘客加入到等待列表中
}

Status ProcessWaitingList() {
    // 处理等待列表，当有退票时分配票给等待列表中的乘客
}

