#include "DataEntry.h"

void ReadUser(SqListUser &User)
{
    FILE* file =fopen("data\\User.csv","r");
     if (file == NULL) {
        fprintf(stderr, "�޷����ļ�\n");
        exit(OVERFLOW);
    }
   while (fscanf(file, "%99[^,],%99[^,],%99[^,],%99[^,],%99[^,],%d\n",
                  User.elem->account, User.elem->password, User.elem->name, User.elem->sex, User.elem->id, &User.elem->authority) == 6) {   
    }
   
   fclose(file);
}
