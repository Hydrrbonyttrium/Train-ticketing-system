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
    LinkedList<Ticket> ticket_list;
    ReadTicket(ticket_list);
    return 0;
}
