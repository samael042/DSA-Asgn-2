#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	struct node* next;
	struct node* prev;
	int data;
}node;

node *head = NULL, *tail = NULL;

void insert(int data)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if(head == NULL){
     	head = temp;
     	tail = temp;	
    }
    else{
     	tail->next = temp;
     	temp->prev = tail;
     	tail = temp;
    }
}
	
node* ahead(int k)
{
 	node *temp = head;
 	while(k--)
 	{
 	 	temp = temp->next;
 	}
 	return temp;
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
	int i = 0, n = 0;
	char ch = ' ';
	while(1)
	{
	    scanf("%d%c", &i, &ch);
	    insert(i);
	    n++;
	    if(ch == 10)
	    	break;
	}
	int k;
	scanf("%d %c", &k, &ch);
	k %= n;
	if(ch == 'R')
		k = n-k;
	if(k == n)
		return print(head), 0;
	node *temp = ahead(k);
	print(temp);
	temp = temp->prev;
	if(temp == NULL)
		return 0;
	temp->next = NULL;
	print(head); 	
 	return 0;
}               	