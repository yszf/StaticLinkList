#include "staticlinklist.h"

int main()
{
	StaticLinkList L;
	InitList(L);
	printf("��ʼ��L��:L.length=%d\n",ListLength(L));
	ListInsert(L,1,'F');
	ListInsert(L,1,'E');
	ListInsert(L,1,'D');
	ListInsert(L,1,'B');
	ListInsert(L,1,'A');
	printf("\n��L�ı�ͷ���β���FEDBA��\nL.data=");
	ShowList(L);
	ListInsert(L,3,'C');
	printf("\n��L�ġ�B���롰D��֮����롰C����\nL.data=");
	ShowList(L);
	ListDelete(L,2);
	printf("\n��L��ɾ����B����\nL.data=");
	ShowList(L);

	printf("\n");
	return 0;
}