#ifndef STATICLINKLIST_H
#define STATICLINKLIST_H

#include <stdio.h>

#define MAXSIZE 1000 //存储空间初始分配量

typedef char ElemType;//元素类型

typedef struct  
{
	ElemType data;
	int cur;//游标(Cursor)，为0时表示无指向
}Component,StaticLinkList[MAXSIZE];

//将一维数组space中各分量链成一个备用链表，
//space[0].cur位头指针，"0"表示空指针。
void InitList(StaticLinkList space);

//若备用空间链表非空，则返回分配的结点下标，
//否则返回0
int Malloc_SSL(StaticLinkList space);

//将下标为k的空闲结点回收到备用链表
void Free_SSL(StaticLinkList space,int k);

//初始条件：静态链表L已存在。
//操作结果：返回L中数据元素个数
int ListLength(StaticLinkList L);

//在L中第i个元素之前插入新的数据元素e
void ListInsert(StaticLinkList L,int i,ElemType e);

//删除在L中第i个数据元素
void ListDelete(StaticLinkList L,int i);

//遍历打印链表的数据元素
void ShowList(StaticLinkList);

#endif