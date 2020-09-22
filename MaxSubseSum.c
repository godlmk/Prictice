#include<stdio.h>
int MaxSubseqSum1(int A[],int N){
	int ThisSum,MaxSum;
	int i,j,k;
	for(i=0;i<N;i++){
		for(j=i;j<N;j++){
			ThisSum=0;
			for(k=i;k<j;k++){
				ThisSum+=A[k];
			}
			if(ThisSum>MaxSum)
			MaxSum=ThisSum;
		}
	}
	return MaxSum;
}
int MaxSubseqSum2(int A[],int N){
	int ThisSum,MaxSum;
	int i,j;
	for(i=0;i<N;i++){
		ThisSum=0;
		for(j=i;j<N;j++){
			ThisSum+=A[j];
			if(ThisSum>MaxSum)
			MaxSum=ThisSum;
		}
	}
	return MaxSum;
}
int main(){
	int N;
	scanf("%d",&N);
	int a[100000];
	int i;
	for(i=0;i<N;i++)
	scanf("%d",&a[i]);
	int out=MaxSubseqSum1(a,N);
	printf("%d\n",out);
	return 0;
} 
