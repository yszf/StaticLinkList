#include "staticlinklist.h"

int main()
{
	StaticLinkList L;
	InitList(L);
	printf("初始化L后:L.length=%d\n",ListLength(L));
	ListInsert(L,1,'F');
	ListInsert(L,1,'E');
	ListInsert(L,1,'D');
	ListInsert(L,1,'B');
	ListInsert(L,1,'A');
	printf("\n在L的表头依次插入FEDBA：\nL.data=");
	ShowList(L);
	ListInsert(L,3,'C');
	printf("\n在L的“B”与“D”之间插入“C”后：\nL.data=");
	ShowList(L);
	ListDelete(L,2);
	printf("\n在L的删除“B”后：\nL.data=");
	ShowList(L);

	printf("\n");
	return 0;
}