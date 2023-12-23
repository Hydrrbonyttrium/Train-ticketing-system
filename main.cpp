#include "Public1.h"
#include "Reality.h"
#include "Search.h"
#include "Ticket.h"
#include "DataEntry.h"
#include "Login.h"
#include "Sqlist.h"
SqListUser User_List[500];

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    ReadUser(User_List);
    printf("%s",User_List[0].elem.account);
    return 0;
}
