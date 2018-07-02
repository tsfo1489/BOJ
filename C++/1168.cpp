#include<stdio.h>
#include<stdlib.h>
struct L
{
	int data;
	struct L *prev;
	struct L *next;
};
int main()
{
	int i, n, m, chk = 0;
	struct L *prev_ptr, *start_ptr, *now_ptr, *new_ptr;
	scanf("%d%d", &n, &m);
	start_ptr = (L*)malloc(sizeof(L));
	start_ptr->data = 1;
	start_ptr->prev = NULL;
	prev_ptr = start_ptr;
	for (i = 2; i <= n; i++)
	{
		new_ptr = (L*)malloc(sizeof(L));
		new_ptr->data = i;
		new_ptr->prev = prev_ptr;
		prev_ptr->next = new_ptr;
		prev_ptr = new_ptr;
	}
	prev_ptr->next = start_ptr;
	start_ptr->prev = prev_ptr;

	printf("<");
	now_ptr = start_ptr;
	i = 1;
	while (1)
	{
		if (i%m == 0)
		{
			chk++;
			printf("%d", now_ptr->data);
			if (chk == n) break;
			printf(", ");
			(now_ptr->prev)->next = now_ptr->next;
			(now_ptr->next)->prev = now_ptr->prev;
		}
		now_ptr = now_ptr->next;
		i++;
	}
	printf(">");
}