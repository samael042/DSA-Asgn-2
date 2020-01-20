#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 10005
int a[N];

typedef struct node
{
	struct node* next;
	struct node* prev;
	int data;
}node;

typedef struct ll
{
 	struct node* head;
 	struct node* tail;
}ll;

ll l1, l2, l3;

void insert(ll *l, int data)
{
 	node *temp = (node*)malloc(sizeof(node));
 	temp->data = data;
 	temp->next = NULL;
 	temp->prev = NULL;
 	if(l->head == NULL){
 	 	l->head = temp;
 	 	l->tail = temp;
 	}else{
 	 	l->tail ->next = temp;
 	 	temp->prev = l->tail;
 	 	l->tail = l->tail->next;
 	}
}

void print(node *head)
{
 	if(head == NULL)
 		return;
 	printf("%d ", head->data);
 	print(head->next);
}

int main()
{
	int i;
	char ch;
	while(1)
	{
		scanf("%d%c", &i, &ch);
		insert(&l1, i);
		if(ch == '\n')
			break;
	}
	while(1)
	{
	 	scanf("%d%c", &i, &ch);
	 	insert(&l2, i);
	 	if(ch == '\n')
	 		break;
	}
	node *h1 = l1.head;
	node *h2 = l2.head;
	while(h1 != NULL || h2 != NULL)
	{
		int val;
	  	if(h1 != NULL&& h2 != NULL && (h1->data <= h2->data))
		{
			val = h1->data;
			h1 = h1->next;
		}	
	  	else if(h1 != NULL&& h2 != NULL && h1->data > h2->data)
	  	{
	  	    val = h2->data;
	  	    h2 = h2->next;
	  	}
	  	else if(h2 != NULL && h1 != NULL &&h1->data <= h2->data)
	  	{
	  	    val = h1->data;
	  	    h1 = h1->next;
	  	}
	  	else if(h2 != NULL && h1 != NULL &&h1->data > h2->data)
	  	{
	  		val = h2->data;
	  		h2 = h2->next;
	  	}
	  	else if(h1 == NULL)
	  	{
	  		val = h2->data;
	  		h2 = h2->next;
	  	}
	  	else
	  	{
	  	 	val = h1->data;
	  	 	h1 = h1->next;
	  	}
	  	insert(&l3, val);
	}
	print(l3.head);
 	return 0;
}