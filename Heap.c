#include<stdio.h>
#define ElementType int
#define Min -10001
typedef struct HeapNode* MinHeap;
struct HeapNode{
	ElementType* Data;
	int size;
	int cipacity;
};


MinHeap Creat(int MaxSize){
	MinHeap H = malloc(sizeof(struct HeapNode));
	H->Data = malloc(sizeof(ElementType)*(MaxSize+1));
	H->Data[0] = Min;
	H->cipacity = MaxSize;
	H->size = 0;
	return H;
}

void Insert(MinHeap H, ElementType item){
	int i;
	if(H->size == H->cipacity) return;
	i = ++H->size;
	for(; H->Data[i/2] > item; i /= 2){
		H->Data[i] = H->Data[i/2];
	}
	H->Data[i] = item;
}


int main(){
	int size,lines;
	int j;
	int temp;
	scanf("%d %d", &size, &lines);
	MinHeap H = Creat(size);
	for(int i = 0;i < size;i++){
		scanf("%d", &temp);
		Insert(H, temp);
	}
	for(int i = 0;i < lines;i++){
		scanf("%d", &j);
		printf("%d", H->Data[j]);
		while(j > 1){
			j /= 2;
			printf(" %d", H->Data[j]);
		}
		printf("\n");
	}
	
	return 0;
}
