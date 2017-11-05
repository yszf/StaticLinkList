#include "staticlinklist.h"

//将一维数组space中各分量链成一个备用链表，
//space[0].cur位头指针，"0"表示空指针。
void InitList(StaticLinkList space)
{
	int i;
	for (i=0;i<MAXSIZE-1;++i)
	{
		space[i].cur = i+1;
	}
	space[MAXSIZE-1].cur = 0;//目前静态链表位空，最后一个元素的cur为0
}

//若备用空间链表非空，则返回分配的结点下标，
//否则返回0
int Malloc_SSL(StaticLinkList space)
{
	int i = space[0].cur;//当前数组第一个元素的cur存的值，就是要返回的第一个备用空闲的下标
	if (space[0].cur)	
	{
		space[0].cur = space[i].cur;//由于要拿一个分来使用了，所以我们就得把它的下一个分量用来做备用
	}
	return i;
}

//将下标为k的空闲结点回收到备用链表
void Free_SSL(StaticLinkList space,int k)
{
	space[k].cur = space[0].cur;//把第一个元素的cur值赋值给要删除的分量cur
	space[0].cur = k;//包药删除的分量下标赋值给第一个元素的cur
}

//初始条件：静态链表L已存在。
//操作结果：返回L中数据元素个数
int ListLength(StaticLinkList L)
{
	int j = 0;
	int i = L[MAXSIZE-1].cur;
	while (i)
	{
		i = L[i].cur;
		j++;
	}
	return j;
}

//在L中第i个元素之前插入新的数据元素e
void ListInsert(StaticLinkList L,int i,ElemType e)
{
	int j,k,l;
	k = MAXSIZE - 1;//注意k首先是最后一个元素的下标
	if (i<1 || i > ListLength(L)+1)
	{
		return;
	}
	j = Malloc_SSL(L);//获得空闲分量的下标
	if (j)
	{
		L[j].data = e;//将数据赋值给分量的data
		for (l = 1;l<=i-1;++l)//找到第i个元素之前的位置
		{
			k = L[k].cur;
		}
		L[j].cur = L[k].cur;//把第i个元素之前的cur赋值给新元素的cur
		L[k].cur = j;
	}
}

//删除在L中第i个数据元素
void ListDelete(StaticLinkList L,int i)
{
	int j,k;
	if (i<1 || i>ListLength(L))
	{
		return;
	}
	k = MAXSIZE - 1;//k是最后一个位置，该位置存放的cur是第一个数值元素的下标
	for (j=1;j<=i-1;++j)
	{
		k = L[k].cur;
	}
	//这时的k代表第i-1个元素的位置，该位置存放的cur是第i个数据元素的下标
	j = L[k].cur;
	L[k].cur = L[j].cur;//这时k位置存放的cur就是第i+1个元素的下标
	Free_SSL(L,j);//释放第i个元素
}

//遍历打印链表的数据元素
void ShowList(StaticLinkList L)
{
	int i = L[MAXSIZE-1].cur;
	while (i)
	{
		printf("%c ",L[i].data);
		i = L[i].cur;
	}
	printf("\n");
}
