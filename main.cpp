#include "Public1.h"
#include "Reality.h"
#include "Search.h"
#include "Ticket.h"
#include "DataEntry.h"
#include "Login.h"
#include "Sqlist.h"
SqListUser User_List;

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    InitList(User_List);
    ReadUser(User_List);
    printf("%s", User_List.elem[0].account);
    DestroyList(User_List);
    return 0;
}
