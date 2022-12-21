#include<stdio.h>
#include<stdlib.h>

struct KeyValuePair
{
	int key;
	int value;
	struct KeyValuePair* next;
};
int H(int key)//Hash function H(key) = key%10;
{
	return (key%10);
}
struct KeyValuePair* InsertPair(int key,int value,struct KeyValuePair* head)
{
	struct KeyValuePair* newNode = (struct KeyValuePair*)malloc(sizeof(struct KeyValuePair));
	(*newNode).key = key;
	(*newNode).value = value;
	(*newNode).next = head;
	head = newNode;
	return head;
}
void Print(struct KeyValuePair* head)
{
	if(!head)return;
	while(head)
	{
		printf("->(%d,%d)",head->key,head->value);
		head = head->next;
	}
	printf("\n");
	return ;
}
int main()
{
	struct KeyValuePair** HashTable = calloc(10,sizeof(struct KeyValuePair*));
	int n,key,value,i;
	printf("Number of key-value pair : ");
	scanf("%d",&n);
	int* KeyTable = (int*)malloc(sizeof(int)*n);
	int* ValueTable = (int*)malloc(sizeof(int)*n);
	printf("Enter all key-value Pairs:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",KeyTable+i);
		scanf("%d",ValueTable+i);
	}
	//Hashing begins here
	for(i=0;i<n;i++)
	{
		key = *(KeyTable+i);
		value = *(ValueTable+i);
		HashTable[H(key)] = InsertPair(key,value,HashTable[H(key)]);
	}
	printf("HASH TABLE\n");
	for(i=0;i<10;i++)
	{
		if(*(HashTable+i) == NULL)continue;
		printf("H[%d]",i);
		Print(*(HashTable+i));
	}
	return 0;
}
