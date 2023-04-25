#include"SeqList.h"
void SeqListInit(SEQ* pq)//顺序表的初始化
{
	assert(pq);
	pq->a = (SeqDataType*)malloc(sizeof(SeqDataType)* 4);
	if (pq->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	pq->capacity = 4;
	pq->size = 0;
}

void SeqListDestory(SEQ* pq)//顺序表的摧毁
{
	assert(pq);
	free(pq->a);
	pq->a = NULL;
	pq->capacity = pq->size = 0;
}
void SeqListPrint(SEQ* pq)//顺序表的有效数字的打印
{
	assert(pq);
	for (int i = 0; i < pq->size; i++)
	{
		printf("%d", pq->size);
	}
	printf("\n");
}

void SeqListCapacity(SEQ* pq)//顺序表容量的自行扩增
{
	if (pq->size == pq->capacity)//判定扩增的条件
	{
		int newcapacity = pq->capacity = 0 ? 4 : pq->capacity * 2;
		//定义顺序表的初始化内存为4，后续以2倍的扩增规则进行扩增空间
		SeqDataType* newA = realloc(pq->a, sizeof(SeqDataType)*newcapacity);
		//结果是让
		if (newA == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		pq->a = newA;//完成新动态内存空间的开辟，无缝连接>>>>
		pq->capacity = newcapacity;
	}

}

void SeqListPushBack(SEQ* pq, SeqDataType x)//尾插
{
	 SeqListInsert(pq,pq->size,x);//引用SEQ insert的函数   SEQ*pq?????
}

void SeqListPushFront(SEQ* pq, SeqDataType x)//头插
{
	 SeqListInsert(pq,0,x);//引用SEQ insert的函数
}

void SeqListPopBack(SEQ* pq)//尾删
{
	 SeqListErase(pq,pq->size-1);
	 //注意不是size,他要返回到有效数字的最后一个之前，以便能顺利删除>>>>>
}

void SeqListPopFront(SEQ* pq)//头删
{
	 SeqListErase(pq,0);
}

int SeqListFind(SEQ* pq, SeqDataType x)//查找具体数据的下表
{
	assert(pq);
	for (int i = 0; i < pq->size; i++)
	{
		if (pq->a[i] == x)
		{
			return i;
		}
		else
			return -1;
	}
}

void SeqListInsert(SEQ* pq, int pos, SeqDataType x)//在具体位置插入目标元素
{
	assert(pq);
	assert(pos >= 0 && pos <= pq->size);
	SeqListCapacity(pq);
	int end = pq->size - 1;
	while (end >= pos)//是所有有效元素向后偏移一格
	{
		pq->a[end + 1] = pq->a[end];
		--end;
	}
	pq->a[pos] = x;//插入元素
	pq->size++;//恢复如初	
}

void SeqListErase(SEQ* pq, int pos)//在具体位置删除目标元素
{
	assert(pq);
	assert(pos >= 0 && pos <= pq->size);
	int begin = pq->size - 1;
	while (begin <= pq->size)
	{
		pq->a[begin - 1] = pq->a[begin];
		++begin;
	}
	pq->size--;
}
void SeqListModify(SEQ* pq, int pos, SeqDataType x)//具体更改某个顺序表中的指
{
	assert(pq);
	assert(pos >= 0 && pos < pq->size);
	pq->a[pos] = x;
}