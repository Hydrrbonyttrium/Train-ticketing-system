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

Status EnqueueWaitingList(const std::string& trainNumber) {
    // 将乘客加入到等待列表中
}

Status ProcessWaitingList() {
    // 处理等待列表，当有退票时分配票给等待列表中的乘客
}

Status RefundTicket(LinkedList<Ticket>& ticketList, const std::string& ticketID) {
    // 实现退票逻辑
    // 根据 ticketID 查找并修改车票信息
    // 根据退票时间计算手续费
    // 更新车次的剩余票数
}
