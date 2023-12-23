#include "DataEntry.h"

void ReadUser(SqListUser *User)
{
    FILE* file =fopen("data\\User.csv","r");
     if (file == NULL) {
        fprintf(stderr, "无法打开文件\n");
        exit(OVERFLOW);
    }
   while (fscanf(file, "%s,%s,%s,%s,%s,%s,%d\n",User->elem.account,User->elem.password,User->elem.name,User->elem.sex,User->elem.id,User->elem.ticket,&User->elem.authority) == 6) 
   User++;
}