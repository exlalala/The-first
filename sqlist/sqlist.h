#pragma once
#include<iostream>
using namespace std;
#include<iomanip>

#define OK 1
#define ERROR 0

typedef int ElemType;

typedef struct {
    ElemType* elem; //存储空间基地址
    int      length; //当前长度 
    int      listsize; //当前分配的存储容量
    int     incsize;//每次存储空间扩容的增量
}*SqList;


SqList InitList_Sq(int maxlistsize, int incremelistsize)
{ //构造一个最大容量为maxlistsize的顺序表L
    SqList L; // L被声明为顺序表指针变量，须调用初始化操作才能使用
    if (!(L = (SqList)malloc(sizeof(*L))))    return ERROR;
    L->elem = (ElemType*)malloc(maxlistsize * sizeof(ElemType));
    if (!L->elem)    return ERROR;
    L->length = 0;
    L->listsize = maxlistsize;
    L->incsize = incremelistsize;
    return L;
}

/* 根据数组a构造顺序表L */

int CreateList_Sq(SqList& L, ElemType A[], int n)
{ //顺序表L空间已有，由数组A赋值
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


int LocateElem_Sq(SqList L, ElemType e)
{  //返回L中第一个与e满足相等关系的元素位序，如不存在返回0
    int i = 1;
    ElemType* p = L->elem;
    while (i <= L->length && *p != e) {
        i++;
        p++;
    }
    if (i <= L->length)return i;
    else return 0;

}
//LocateElem_Sq


//在顺序表的第i个位置插入一个元素e
int ListInsert_Sq(SqList& L, int i, ElemType e)
{
    if (!L || i<1 || i>L->length + 1) //L不存在或位序越界
        return ERROR;
    if (L->length >= L->listsize) {
        L->elem = (ElemType*)realloc(L->elem, (L->listsize + L->incsize) * sizeof(ElemType));
        if (!L->elem)    return ERROR;
        L->listsize += L->incsize;
    }
    ElemType* p = &L->elem[L->length];
    ElemType* q = &L->elem[i];
    for (p--;p >= q; p--) {
        *(p + 1) = *p;
    }
    *q = e;
    L->length++;
    return OK;
}

//在有序顺序表中插入一个元素e
int ListInsert_Sq(SqList& L, ElemType e)
{
    if (!L) //L不存在
        return ERROR;
    if (L->length >= L->listsize) {
        L->elem = (ElemType*)realloc(L->elem, (L->listsize + L->incsize) * sizeof(ElemType));
        if (!L->elem)    return ERROR;
        L->listsize += L->incsize;
    }
    ElemType* p = &(L->elem[L->length - 1]);
    for (; *p >= e; p--)     *(p + 1) = *p;
    *(p + 1) = e;
    L->length++;
    return OK;
}

int ListDelete_Sq(SqList& L, int i, ElemType& e)
{ //删除L的第i个数据元素，并用e返回其值
    if (!L || i<1 || i>L->length)    return ERROR;
    ElemType* p = &(L->elem[i - 1]);
    e = *p;
    ElemType* q = &(L->elem[L->length - 1]);
    for (p++;p <= q;p++) {
        *(p - 1) = *p;
    }
    L->length--;
    return OK;
} //ListDelete_Sq


void ListTraverse_Sq(SqList L) {  //依次对每个数据元素输出
    if (!L || L->length == 0)  return;
    for (int i = 0; i < L->length; i++)
        cout << L->elem[i] << " ";
    cout << endl;
}

int DestroyList_Sq(SqList L)
{  //释放线性表L所占存储空间
    delete[]L->elem;
    L->length = 0;
    L->listsize = 0;
    L->incsize = 0;
    delete L;
    L = NULL;
    return OK;
} //DestroyList_Sq

SqList MergeList_Sq(SqList La, SqList Lb) { // 归并升序顺序表La和Lb
    SqList Lc;
    ElemType* pa, * pb, * pc, * pa_end, * pb_end;
    if (!La && !Lb) return NULL;
    pa = La->elem;  pb = Lb->elem;
    Lc = InitList_Sq(La->length + Lb->length, La->incsize);
    Lc->length = Lc->listsize;
    pc = Lc->elem;
    pa_end = La->elem + La->length - 1;
    pb_end = Lb->elem + Lb->length - 1;

    while (pa <= pa_end && pb <= pb_end) {
        if (*pa < *pb) *pc++ = *pa++;
        else if (*pa > *pb)*pc++ = *pb++;
        else { *pc++ = *pb++; pa++; Lc->length--; }
    }
    while (pa <= pa_end) *pc++ = *pa++;
    while (pb <= pb_end) *pc++ = *pb++;
    return Lc;
}