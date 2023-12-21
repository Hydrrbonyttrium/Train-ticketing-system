#include"Public1.h"
#include"SqList.h"

using namespace std;

Status InitList(SqList &L)
{
    //����һ���յ�˳���
    L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem)
        exit(OVERFLOW);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;
}

Status DestroyList(SqList &L)
{
    //����˳�����Ա�L
    if (L.elem)
    {
        free(L.elem);
        L.elem = NULL;
        L.length = 0;
        L.listsize = 0;
    }
    return OK;
}

Status comp(ElemType c1, ElemType c2)
{
    if(c1==c2)
        return TRUE;
    else
        return FALSE;
}

int LocateElem(SqList L, ElemType e,Status (* compare)(ElemType, ElemType))
{
    //��������Ԫ�ص�ֵ�������������Ա�L�е�λ��
    int i=0;
    while ((i<=L.length)&&(!compare(*(L.elem+i-1),e)))
        i++;
    if (i<=L.length)
        return i;
    else
    return(0);
}

Status GetElem(SqList L,int i,ElemType &e)
{
    //��������Ԫ�������Ա�L�е�λ�ã���������ֵ
    if (i < 1 || i > L.length)
    {
        return ERROR;
    }
    e = L.elem[i - 1];
    return OK;
}

Status ListInsert(SqList &L,int i,ElemType e)
{
    // ��L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1
    if (i < 1 || i > L.length + 1)
    {
        return ERROR;
    }

    if (L.length >= L.listsize) //�������Բ����������
    {
        //���·���ռ�
        ElemType * newbase = (ElemType *) realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase)
        {
            return OVERFLOW;
        }
        L.elem = newbase;
        L.listsize = L.listsize + LISTINCREMENT;
    }

    //���Բ���
    ElemType * insert_index = L.elem + i - 1;

   // �Ӻ���ǰ�ƶ�Ԫ���Կճ�λ��
    for (ElemType *p = &(L.elem[L.length - 1]); p >= insert_index; p--)
    {
        *(p + 1) = *p;
    }

    *insert_index = e;
    L.length++;

    return OK;
}

Status ListDelete(SqList &L,int i,ElemType &e)
{
    //ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
    //����Ƿ�Խ��
    if (i < 1 || i > L.length)
    {
        return ERROR;
    }

    for (ElemType * p = &L.elem[i - 1]; p <= &L.elem[L.length - 2]; p++)
    {
        *p = *(p + 1);
    }

    L.length--; //������

    return OK;
}

void print(ElemType c)
{
    printf("%d ",c);
}

Status ListTraverse(SqList L,void(* visit)(ElemType))
{
    //�������˳���ĸ���Ԫ��ֵ
    int i;
    for(i=1;i<=L.length;i++)
        visit(*(L.elem+i-1));
    cout<<endl;
    printf("L.elem=%u L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);
    return OK;
}

Status PriorElem(SqList L,ElemType cur_e,ElemType &pre_e)
 {
     // ��cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ��
     // �����ʧ��
     if (cur_e == L.elem[0]) //ȷ�����ǵ�һ��
     {
         return ERROR;
     }

     for (int i = 1; i < L.length; i++)
     {
         if (L.elem[i] == cur_e)
         {
             pre_e = L.elem[i - 1]; //�������Ѿ�ȷ������Խ��
             return OK;
         }
     }
     return ERROR; //δ�ҵ�
 }

 Status DeleteAllX(SqList &L, ElemType x)
 {
     int valid_index = 0;
     for (int i = 0; i < L.length; i++)
     {
         if (L.elem[i] != x)
         {
             L.elem[valid_index] = L.elem[i];
             valid_index++;
         }
     }
     L.length = valid_index;
     return OK;
 }
