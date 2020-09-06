/*
两个有序链表的合并
*/

#include "stdio.h"

struct Link
{
	struct Link* next;
	int data;
};

class Clink
{
public:
	struct Link* sort(struct Link* p1, struct Link* p2)
	{
		struct Link* ptemp = (p1->data > p2->data) ? p2 : p1;
		struct Link* pHead = ptemp;

		struct Link* ptmp = (ptemp == p1)? p2 : p1;
		//printf("p1 =  %p p2 = %p\n", p1, p2);
		printf("ptemp =  %p ptmp = %p\n", ptemp, ptmp);
		printf("ptemp =  %p ptemp->next = %p\n", ptemp, ptemp->next);
		while(p1 != NULL || p2 != NULL)
		{
			//printf("ptemp = %p \n", ptemp);	
			if (ptemp == 0 || ptemp->next == 0)
			{
				break;
			}		
			if (ptemp->next->data < ptmp->data)
			{
				//printf("ptemp->next !!!!= %p \n", ptemp->next);
				//printf("ptemp->data = %d ptmp->data = %d \n", ptemp->next->data, ptmp->data);
				if (ptemp == p1)
				{
					p1 = p1->next;
					ptemp = p1;
				}
				else
				{
					p2 = p2->next;
					ptemp = p2;
				}
			}
			else
			{
				printf("ptemp = %p \n", ptemp);
				printf("ptemp->next = %p \n", ptemp->next);

				//ptemp->next = ptmp;
				if (ptemp == p1)
				{
					p1 = p1->next;
					ptemp->next = ptmp;
					ptmp = p1;
				}
				else
				{
					p2 = p2->next;
					ptemp->next = ptmp;
					ptmp = p2;
				}

				ptemp = ptemp->next;
			}
		}
		return pHead;

	}
};

int main(int argc, char const *argv[])
{
	/* code */
	struct Link* pHead1 = new struct Link;
	pHead1->data = 0;

	struct Link* p1 = pHead1;
	
	struct Link* pHead2 = new struct Link;
	pHead2->data = 1;

	struct Link* p2 = pHead2;

	for (int i = 1; i < 10; i++)
	{
		p1->next = new struct Link;
		p1 = p1->next;
		p1->data = i * 2;
		p1->next = NULL;

		p2->next = new struct Link;
		p2 = p2->next;
		p2->data = i * 2 + 1;
		p2->next = NULL;
	}

	p1 = pHead1;
	printf("link 1 : ");
	while (p1)
	{
		printf("%d ", p1->data);
		p1 = p1->next;
	}
	printf("\n");

	p2 = pHead2;
	printf("link 2 : ");
	while (p2)
	{
		printf("%d ", p2->data);
		p2 = p2->next;
	}
	printf("\n");
	
	Clink a;
	struct Link* p = a.sort(pHead1, pHead2);
	printf("link : ");
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return 0;
}
