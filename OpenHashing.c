#include<stdio.h>
#include<stdlib.h>

struct KeyNode
{
	int key;
	struct KeyNode* link;
};
struct KeyNode** HashTable = NULL;
void Init()//Create and Initialize the hash table
{
	HashTable = (struct KeyNode**)calloc(10,sizeof(struct KeyNode*));
}
void Traverse(struct KeyNode* first)
{
	if(first == NULL)return;
	while(first)
	{
		printf("->%d",first->key);
		first = first->link;
	}
	printf("\n");
	return;
}
int H(int key)//Hash function h(key) = (key)%10
{
	return (key%10);
}
void InsertKey(int key)
{
	struct KeyNode* keyNode = (struct KeyNode*)malloc(sizeof(struct KeyNode));
	keyNode->key = key;
	keyNode->link = *(HashTable+H(key));
	*(HashTable+H(key)) = keyNode;
	return;
}
void ShowHashTable()
{
	int i;
	printf("HASH TABLE : \n");
	for(i=0;i<10;i++)
	{
		if(!*(HashTable+i))continue;
		printf("H[%d]",i);
		Traverse(*(HashTable+i));
	}
	return;
}
int main()
{
	int i;
	Init();
	int n,key;
	printf("Number of keys : ");
	scanf("%d",&n);
	printf("\nEnter all the keys : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&key);
		InsertKey(key);
	}
	ShowHashTable();
	return 0;
}
