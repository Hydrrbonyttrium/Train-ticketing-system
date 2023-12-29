#ifndef TICKET_H_INCLUDED
#define TICKET_H_INCLUDED

#include "Public1.h"
#include "Reality.h"
#include "LinkList.h"
Status PurchaseTicket(User &user, Ticket &ticket);
Status EnqueueWaitingList(User &user, Ticket &ticket);
Status ProcessWaitingList();
Status RefundTicket(User &user, LinkedList<Ticket>& TicketList, const std::string& trainNumber);

#endif // TICKET_H_INCLUDED
