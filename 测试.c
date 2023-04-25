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
	printf("1.尾插数据     2.头插数据");
	printf("3.尾删数据     4.头删数据");
	printf("5.打印数据    -1.退出程序");
	printf("**************************");
	printf("请输入数据：>");
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
			printf("请输入数据，以-1结束：>");
			while (1)
			{
				scanf("%d", &x);
				if (x == -1)
					break;
				SeqListPushBack(&s, x);//插入数据
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
			SeqListPrintf(&s);//打印数据
			break;
		default:
			break;			
		}
	} while (option != 0);
	SeqListDestory(&s);
	return 0;
}

