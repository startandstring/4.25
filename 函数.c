#include"SeqList.h"
void SeqListInit(SEQ* pq)//˳���ĳ�ʼ��
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

void SeqListDestory(SEQ* pq)//˳���Ĵݻ�
{
	assert(pq);
	free(pq->a);
	pq->a = NULL;
	pq->capacity = pq->size = 0;
}
void SeqListPrint(SEQ* pq)//˳������Ч���ֵĴ�ӡ
{
	assert(pq);
	for (int i = 0; i < pq->size; i++)
	{
		printf("%d", pq->size);
	}
	printf("\n");
}

void SeqListCapacity(SEQ* pq)//˳�����������������
{
	if (pq->size == pq->capacity)//�ж�����������
	{
		int newcapacity = pq->capacity = 0 ? 4 : pq->capacity * 2;
		//����˳���ĳ�ʼ���ڴ�Ϊ4��������2��������������������ռ�
		SeqDataType* newA = realloc(pq->a, sizeof(SeqDataType)*newcapacity);
		//�������
		if (newA == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		pq->a = newA;//����¶�̬�ڴ�ռ�Ŀ��٣��޷�����>>>>
		pq->capacity = newcapacity;
	}

}

void SeqListPushBack(SEQ* pq, SeqDataType x)//β��
{
	 SeqListInsert(pq,pq->size,x);//����SEQ insert�ĺ���   SEQ*pq?????
}

void SeqListPushFront(SEQ* pq, SeqDataType x)//ͷ��
{
	 SeqListInsert(pq,0,x);//����SEQ insert�ĺ���
}

void SeqListPopBack(SEQ* pq)//βɾ
{
	 SeqListErase(pq,pq->size-1);
	 //ע�ⲻ��size,��Ҫ���ص���Ч���ֵ����һ��֮ǰ���Ա���˳��ɾ��>>>>>
}

void SeqListPopFront(SEQ* pq)//ͷɾ
{
	 SeqListErase(pq,0);
}

int SeqListFind(SEQ* pq, SeqDataType x)//���Ҿ������ݵ��±�
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

void SeqListInsert(SEQ* pq, int pos, SeqDataType x)//�ھ���λ�ò���Ŀ��Ԫ��
{
	assert(pq);
	assert(pos >= 0 && pos <= pq->size);
	SeqListCapacity(pq);
	int end = pq->size - 1;
	while (end >= pos)//��������ЧԪ�����ƫ��һ��
	{
		pq->a[end + 1] = pq->a[end];
		--end;
	}
	pq->a[pos] = x;//����Ԫ��
	pq->size++;//�ָ����	
}

void SeqListErase(SEQ* pq, int pos)//�ھ���λ��ɾ��Ŀ��Ԫ��
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
void SeqListModify(SEQ* pq, int pos, SeqDataType x)//�������ĳ��˳����е�ָ
{
	assert(pq);
	assert(pos >= 0 && pos < pq->size);
	pq->a[pos] = x;
}