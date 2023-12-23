#ifndef TICKET_H_INCLUDED
#define TICKET_H_INCLUDED

#include "Public1.h"
#include "Reality.h"
#include "LinkList.h"
Status PurchaseTicket(User &user, Ticket &ticket);
Status EnqueueWaitingList(const std::string& trainNumber);
Status ProcessWaitingList();
Status RefundTicket(LinkedList<Ticket>& ticketList, const std::string& ticketID);

#endif // TICKET_H_INCLUDED
