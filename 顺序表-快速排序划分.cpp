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



int Adjust(SqList& L)
{
    if (!L || L->length == 0)
        return ERROR;
    ElemType pivot = L->elem[0];
    int i = 0, j = L->length - 1;

    while (i < j)
    {
        while (i < j && L->elem[j] >= pivot)
            j--;
        L->elem[i] = L->elem[j];

        while (i < j && L->elem[i] < pivot)
            i++;
        L->elem[j] = L->elem[i];
    }
    L->elem[i] = pivot;
    return OK;
}

int main()
{
    SqList La;
    int A[] = { 12,2,33,19,10,0 };
    int lable;
    La = InitList_Sq(LIST_INIT_LISTSIZE, LISTINCREMENT);
    lable = CreateList_Sq(La, A, sizeof(A) / sizeof(A[0]));
    if (lable) {
        cout << "顺序表La为：" << endl;
        ListTraverse_Sq(La);
    }
    cout << endl;
    Adjust(La);
    cout << "调整后：" << endl;
    ListTraverse_Sq(La);
    return OK;
}
