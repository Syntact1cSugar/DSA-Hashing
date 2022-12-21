#include<stdio.h>
#include<stdlib.h>

int H(int k,int j)
{
	return ((k % 10) + j) % 10;
}
int main()
{
	int i,n,key;
	int j;//Probe number
	//Creation of Hash Table
	int* HashTable = malloc(sizeof(int)*10);
	for(i=0;i<10;i++)
		*(HashTable+i) = -1;
	printf("Number of Keys: ");
	scanf("%d",&n);
	int* KeyTable = malloc(sizeof(int)*n);
	printf("\nEnter all the keys:");
	for(i=0;i<n;i++)
		scanf("%d",KeyTable+i);
	//Hashing the keys:
	for(i=0;i<n;i++)
	{
		key = *(KeyTable+i);
		j = 0;
		while(*(HashTable+(H(key,j))) != -1)
		{
			if(j == 10)break;
			else j++;
		}
		if(*(HashTable+(H(key,j))) == -1)
			*(HashTable+(H(key,j))) = key;
	}
	printf("HASH TABLE:\n");
	for(i=0;i<10;i++)
		printf("H[index=%d] -> %d\n",i,*(HashTable+i));
	return 0;
}
