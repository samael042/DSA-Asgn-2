#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char a[100];
//notice that 3rd characters of the given strings are always unique
typedef struct node
{
	struct node* next;
	int data;
}node;

node *head = NULL, *tail = NULL;

void add(int d)
{
 	node* temp = (node*)malloc(sizeof(node));
 	temp->data = d;
 	temp->next = NULL;
 	if(head == NULL){
 	 	head = temp;
 	 	tail = temp;
 	}
 	else{
 	 	tail->next = temp;
 	 	tail = temp;
 	}
}

node* insert(int j, int i)
{
	node* temp = (node*)malloc(sizeof(node));
	temp->next = NULL;
	temp->data = j;
	if(i == 1){
	 	temp->next = head;
	 	return temp;
	}
	i-=2;
	node *it = head;
	while(i--){
	 	it = it->next;
	}
	temp->next = it->next;
	it->next = temp;
	return head;
}

node* rem(int i){
 	if(i == 1){
 	 	head = head->next;
 	 	return head;
 	}
 	i-=2;
 	node *temp = head;
 	while(i--){
 	 	temp = temp->next;
 	}
 	temp->next = temp->next->next;
 	return head;
}

void lol(int val)
{
	int i = 0, first = -1, last = -1;
	struct node* temp = head;
	while(temp != NULL){
		i++;
		if(temp->data == val && first == -1){
		 	first = i;
		}
		if(temp->data == val){
		 	last = i;
		}
		temp = temp->next;	
	}	
	if(first == -1){
	 	printf("Elements not found\n");
	 	return;
	}
	head = rem(first);
	if(first != last){
	 	head = rem(last-1);
	}
}	

void reverse()
{
	if(head->next == NULL)
		return;
	node* cur = head;
	node *prev = NULL, *next = NULL;
	while(cur != NULL){
		next = cur->next;
	 	cur->next = prev;
	 	prev = cur;
	 	cur = next;
	}
	tail = head;
	head = prev;
}

void fetch(int i)
{
 	node *temp = head;
 	i--;
 	while(i--){
 	 	temp = temp->next;	
 	}
 	printf("%d\n", temp->data);
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
	int q, i, j;
	scanf("%d", &q);
	for(int x = 0; x < q; x++){
	 	scanf("%s", a);
	 	if(a[2] == 'd'){
	 		scanf("%d", &i);
			add(i);	 	 	
		}
		else if(a[2] == 's'){
			scanf("%d %d", &i, &j);
			head = insert(i, j); 	
		}
		else if(a[2] == 'm'){
		 	scanf("%d", &i);
		 	lol(i);		
		}
		else if(a[2] == 'v')
		 	reverse();
		else if(a[2] == 't'){
			scanf("%d", &i);
		    	fetch(i);
		}
		print(head);
		printf("\n");     
	}
 	return 0;
}
