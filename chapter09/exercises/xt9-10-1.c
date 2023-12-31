#include <stdio.h>
#include <malloc.h>
#define LEN sizeof(struct student)

struct student
{
	long num;
	int score;
	struct student *next;
};

struct student list_a, list_b;
int n, sum = 0;

int main()
{
	struct student *creat(void);
	struct student *insert(struct student *, struct student *);
	void print(struct student *);
	struct student *a_head, *b_head, *ab_h;
	printf("input list a:\n");
	a_head = creat();
	sum = sum + n;
	printf("input list b:\n");
	b_head = creat();
	sum = sum + n;
	ab_h = insert(a_head, b_head);
	print(ab_h);
	return 0;
}

struct student *creat(void) // 建立链表函数
{
	struct student *p1, *p2, *head;
	n = 0;
	p1 = p2 = (struct student *)malloc(LEN);
	printf("input number & scores of student:\n");
	printf("if number is 0,stop inputting.\n");
	scanf("%ld,%d", &p1->num, &p1->score);
	head = NULL;
	while (p1->num != 0)
	{
		n = n + 1;
		if (n == 1)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (struct student *)malloc(LEN);
		scanf("%ld,%d", &p1->num, &p1->score);
	}
	p2->next = NULL;
	return (head);
}

struct student *insert(struct student *ah, struct student *bh) // 插入函数
{
	struct student *pa1, *pa2, *pb1, *pb2;
	pa2 = pa1 = ah;
	pb2 = pb1 = bh;
	do
	{
		while ((pb1->num > pa1->num) && (pa1->next != NULL))
		{
			pa2 = pa1;
			pa1 = pa1->next;
		}
		if (pb1->num <= pa1->num)
		{
			if (ah == pa1)
				ah = pb1;
			else
				pa2->next = pb1;
			pb1 = pb1->next;
			pb2->next = pa1;
			pa2 = pb2;
			pb2 = pb1;
		}
	} while ((pa1->next != NULL) || (pa1 == NULL && pb1 != NULL));
	if ((pb1 != NULL) && (pb1->num > pa1->num) && (pa1->next == NULL))
		pa1->next = pb1;
	return (ah);
}

void print(struct student *head) // 输出函数
{
	struct student *p;
	printf("There are %d records:  \n", sum);
	p = head;
	if (p != NULL)
		do
		{
			printf("%ld %d\n", p->num, p->score);
			p = p->next;
		} while (p != NULL);
}