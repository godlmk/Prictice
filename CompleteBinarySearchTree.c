#include<stdio.h>
#include<stdlib.h>
int comp(const void*a,const void *b){
	return *(int*)a-*(int*)b;
}


void initArr(int* arr, int N){
	for(int i=0;i<N;i++){
		scanf("%d", &arr[i]);
	}
	qsort(arr, N, sizeof(int), comp);
}


void makeCBST(int *Tree, int* arr, int pos, int* i){
	if(pos<1||pos>Tree[0]||*i>Tree[0]) return ;
	else{
		makeCBST(Tree, arr, 2*pos, i);
		Tree[pos] = arr[(*i)++];
		makeCBST(Tree, arr, 2*pos+1,i);
	}
}


void printCBST(int* Tree){
	for(int i=1;i<=Tree[0];i++){
		if(i != 1) printf(" ");
		printf("%d", Tree[i]);
	}
}

int main(){
	int N, pos, i;
	scanf("%d", &N);
	int *arr, *Tree;
	arr=(int*)malloc(sizeof(int)*N);
	Tree=(int*)malloc(sizeof(int)*N+1);
	Tree[0]=N;
	pos = 1,i = 0;
	initArr(arr, N);
	makeCBST(Tree, arr, pos, &i);
	printCBST(Tree);
	return 0;
} 
