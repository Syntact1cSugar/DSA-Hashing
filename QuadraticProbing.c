#include<stdio.h>
#include<stdlib.h>
int H(int key,int j)
{
	return (((key%10) + j*j) % 10);
}
int main()
{
	int i,n,key,j;
	//Creating Hash Table
	int* HashTable = malloc(sizeof(int)*10);
	for(i=0;i<10;i++)
		*(HashTable+i) = -1;
	printf("Number of keys: ");
	scanf("%d",&n);
	//Creating Key Table
	int* KeyTable = malloc(sizeof(int)*n);
	printf("\nEnter all the keys:");
	for(i=0;i<n;i++)
		scanf("%d",KeyTable+i);
	//Hashing the Keys
	for(i=0;i<n;i++)
	{
		key = *(KeyTable+i);
		j = 0;
		while(*(HashTable+H(key,j)) != -1 && j<=5)
			j++;
		if(*(HashTable+H(key,j)) == -1)
			*(HashTable+H(key,j)) = key;
	}
	printf("\nHASH TABLE:\n");
	for(i=0;i<10;i++)
		printf("H[index=%d] -> %d\n",i,*(HashTable+i));
	return 0;
}
