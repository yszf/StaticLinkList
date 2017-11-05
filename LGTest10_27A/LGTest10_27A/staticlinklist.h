#ifndef STATICLINKLIST_H
#define STATICLINKLIST_H

#include <stdio.h>

#define MAXSIZE 1000 //�洢�ռ��ʼ������

typedef char ElemType;//Ԫ������

typedef struct  
{
	ElemType data;
	int cur;//�α�(Cursor)��Ϊ0ʱ��ʾ��ָ��
}Component,StaticLinkList[MAXSIZE];

//��һά����space�и���������һ����������
//space[0].curλͷָ�룬"0"��ʾ��ָ�롣
void InitList(StaticLinkList space);

//�����ÿռ�����ǿգ��򷵻ط���Ľ���±꣬
//���򷵻�0
int Malloc_SSL(StaticLinkList space);

//���±�Ϊk�Ŀ��н����յ���������
void Free_SSL(StaticLinkList space,int k);

//��ʼ��������̬����L�Ѵ��ڡ�
//�������������L������Ԫ�ظ���
int ListLength(StaticLinkList L);

//��L�е�i��Ԫ��֮ǰ�����µ�����Ԫ��e
void ListInsert(StaticLinkList L,int i,ElemType e);

//ɾ����L�е�i������Ԫ��
void ListDelete(StaticLinkList L,int i);

//������ӡ���������Ԫ��
void ShowList(StaticLinkList);

#endif