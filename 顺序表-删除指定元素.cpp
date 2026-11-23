#include<iostream>
using namespace std;
#include<iomanip>

#define OK 1
#define ERROR 0
const int LIST_INIT_LISTSIZE = 50;
const int LISTINCREMENT = 10;

typedef int ElemType;

typedef struct {
    ElemType* elem;
    int      length;
    int      listsize;
    int     incsize;
}*SqList;

SqList InitList_Sq(int maxlistsize, int incremelistsize)
{
    SqList L;
    if (!(L = (SqList)malloc(sizeof(*L))))    return ERROR;
    L->elem = (ElemType*)malloc(maxlistsize * sizeof(ElemType));
    if (!L->elem)    return ERROR;
    L->length = 0;
    L->listsize = maxlistsize;
    L->incsize = incremelistsize;
    return L;
}

int CreateList_Sq(SqList& L, ElemType A[], int n)
{
    if (!L)  return ERROR;
    while (n > L->listsize) {
        L->elem = (ElemType*)realloc(L->elem, (L->listsize + L->incsize) * sizeof(ElemType));
        if (!L->elem)    return ERROR;
        L->listsize += L->incsize;
    }
    for (int i = 0; i < n; i++) {
        L->elem[i] = A[i];
    }
    L->length = n;
    return OK;
}

void ListTraverse_Sq(SqList L) {
    if (!L || L->length == 0)  return;
    for (int i = 0; i < L->length; i++)
        cout << L->elem[i] << " ";
    cout << endl;
}



int Delete_Elem(SqList& L, ElemType e)
{
    if (!L) return ERROR;
    int j = 0;
    for (int i = 0; i < L->length; i++)
    {
        if (L->elem[i] != e)
        {
            L->elem[j] = L->elem[i];
            j++;
        }
    }
    L->length = j;
    return L->length;
}

int main()
{
    SqList La;
    int A[] = { 12,2,12,19,10,12,0,1 };
    int lable;
    La = InitList_Sq(LIST_INIT_LISTSIZE, LISTINCREMENT);
    lable = CreateList_Sq(La, A, sizeof(A) / sizeof(A[0]));
    if (lable) {
        cout << "顺序表La为：" << endl;
        ListTraverse_Sq(La);
    }
    cout << endl;
    Delete_Elem(La, 12);
    cout << "调整后：" << endl;
    ListTraverse_Sq(La);
    return OK;
}
