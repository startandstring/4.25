#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
//void TestSeqList1()
//{
//	SeqList s;
//	SeqLisInit(&s);
//	SeqListPushBack(&s, 1);
//	SeqListPushBack(&s, 2);
//	SeqListPushBack(&s, 3);
//	SeqListPushBack(&s, 4);
//	SeqListPushBack(&s, 5);
//	SeqListPushBack(&s, 6);
//	SeqListPushFront(&s, 0);
//	SeqListPushFront(&s, 0);
//	SeqListPushFront(&s, 0);
//	SeqListPushFront(&s, 0);
//	SeqListPrintf(&s);
//	SeqListPopBack(&s);
//	SeqListPrintf(&s);
//	SeqListPopBack(&s);
//	SeqListPrintf(&s);
//	SeqListPopBack(&s);
//	SeqListPrintf(&s);
//	SeqListDestory(&s);
//}
//
void menu()
{
	printf("*************************");
	printf("1.β������     2.ͷ������");
	printf("3.βɾ����     4.ͷɾ����");
	printf("5.��ӡ����    -1.�˳�����");
	printf("**************************");
	printf("���������ݣ�>");
}

int main()
{
	SeqList s;
	SeqListInit(&s);
	int option = 0;
	do
	{
		menu();
		scanf("&d", &option);
		int x = 0;
		switch (option)
		{
		case 1:
			printf("���������ݣ���-1������>");
			while (1)
			{
				scanf("%d", &x);
				if (x == -1)
					break;
				SeqListPushBack(&s, x);//��������
			}
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			SeqListPrintf(&s);//��ӡ����
			break;
		default:
			break;			
		}
	} while (option != 0);
	SeqListDestory(&s);
	return 0;
}

