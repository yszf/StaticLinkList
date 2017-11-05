#include "staticlinklist.h"

//��һά����space�и���������һ����������
//space[0].curλͷָ�룬"0"��ʾ��ָ�롣
void InitList(StaticLinkList space)
{
	int i;
	for (i=0;i<MAXSIZE-1;++i)
	{
		space[i].cur = i+1;
	}
	space[MAXSIZE-1].cur = 0;//Ŀǰ��̬����λ�գ����һ��Ԫ�ص�curΪ0
}

//�����ÿռ�����ǿգ��򷵻ط���Ľ���±꣬
//���򷵻�0
int Malloc_SSL(StaticLinkList space)
{
	int i = space[0].cur;//��ǰ�����һ��Ԫ�ص�cur���ֵ������Ҫ���صĵ�һ�����ÿ��е��±�
	if (space[0].cur)	
	{
		space[0].cur = space[i].cur;//����Ҫ��һ������ʹ���ˣ��������Ǿ͵ð�������һ����������������
	}
	return i;
}

//���±�Ϊk�Ŀ��н����յ���������
void Free_SSL(StaticLinkList space,int k)
{
	space[k].cur = space[0].cur;//�ѵ�һ��Ԫ�ص�curֵ��ֵ��Ҫɾ���ķ���cur
	space[0].cur = k;//��ҩɾ���ķ����±긳ֵ����һ��Ԫ�ص�cur
}

//��ʼ��������̬����L�Ѵ��ڡ�
//�������������L������Ԫ�ظ���
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

//��L�е�i��Ԫ��֮ǰ�����µ�����Ԫ��e
void ListInsert(StaticLinkList L,int i,ElemType e)
{
	int j,k,l;
	k = MAXSIZE - 1;//ע��k���������һ��Ԫ�ص��±�
	if (i<1 || i > ListLength(L)+1)
	{
		return;
	}
	j = Malloc_SSL(L);//��ÿ��з������±�
	if (j)
	{
		L[j].data = e;//�����ݸ�ֵ��������data
		for (l = 1;l<=i-1;++l)//�ҵ���i��Ԫ��֮ǰ��λ��
		{
			k = L[k].cur;
		}
		L[j].cur = L[k].cur;//�ѵ�i��Ԫ��֮ǰ��cur��ֵ����Ԫ�ص�cur
		L[k].cur = j;
	}
}

//ɾ����L�е�i������Ԫ��
void ListDelete(StaticLinkList L,int i)
{
	int j,k;
	if (i<1 || i>ListLength(L))
	{
		return;
	}
	k = MAXSIZE - 1;//k�����һ��λ�ã���λ�ô�ŵ�cur�ǵ�һ����ֵԪ�ص��±�
	for (j=1;j<=i-1;++j)
	{
		k = L[k].cur;
	}
	//��ʱ��k�����i-1��Ԫ�ص�λ�ã���λ�ô�ŵ�cur�ǵ�i������Ԫ�ص��±�
	j = L[k].cur;
	L[k].cur = L[j].cur;//��ʱkλ�ô�ŵ�cur���ǵ�i+1��Ԫ�ص��±�
	Free_SSL(L,j);//�ͷŵ�i��Ԫ��
}

//������ӡ���������Ԫ��
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
