#include<stdio.h>
#include<stdlib.h>

struct HNode
{
	int key;
	struct HNode* next;
};

struct HNode* Insert(int key,struct HNode* head)
{
	struct HNode* newNode = (struct HNode*)malloc(sizeof(struct HNode));
	(*newNode).key = key;
	(*newNode).next = NULL;
	if(!head || key < (*head).key)//Insert Front
	{
		(*newNode).next = head;
		head = newNode;
		return head;
	}
	//Sorting
	struct HNode* temp = head;
	while(temp->next && key > (*temp).next->key)
		temp = temp->next;
	(*newNode).next = (*temp).next;
	(*temp).next = newNode;
	return head;
}
void Print(struct HNode* head)
{
	if(!head)
	{
		printf("->NILL\n");
		return;
	}
	while(head)
	{
		printf("->%d",(*head).key);
		head = (*head).next;
	}
	printf("\n");
	return;
}
int H(int k)
{
	return (k%10);
}
struct HNode** HashKeys(int* KeyTable,int n)
{
	//Creation of HashTable 
	struct HNode** HashTable = calloc(sizeof(struct HNode*),10);
	int i;
	int key;
	for(i=0;i<n;i++)
	{
		int key = *(KeyTable+i);
		*(HashTable+H(key)) = Insert(key,*(HashTable+H(key)));
	}
	return HashTable;

}
int main()
{
	int n;
	printf("Number of Keys : ");
	scanf("%d",&n);
	int i;
	int* KeyTable = (int*)malloc(sizeof(int)*n);
	printf("\nEnter all keys : ");
	for(i=0;i<n;i++)
		scanf("%d",KeyTable+i);
	struct HNode** HashTable = HashKeys(KeyTable,n);
	printf("HASH TABLE:\n");
	for(i=0;i<10;i++)
	{
		if(*(HashTable+i) == NULL)continue;
		printf("H[%d]",i);
		Print(*(HashTable+i));
	}
	
	return 0;
}
