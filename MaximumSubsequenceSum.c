#include<stdio.h>
int MaxSubSum(int a[],int k){
	int ThisSum,MaxSum;
	int start;
	start=0;
	int MaxStart=0,MaxEnd=k-1;
	ThisSum=MaxSum=0;
	int i;
	for(int i=0;i<k;i++){
		ThisSum+=a[i];
		if((ThisSum>MaxSum)||(ThisSum==MaxSum&&MaxSum==0)){
		MaxSum=ThisSum;
		MaxStart=start;
		MaxEnd=i;	
		}
		else if(ThisSum<0){	
		ThisSum=0;
		start=i+1;
		}
	}
	printf("%d %d %d",MaxSum,a[MaxStart],a[MaxEnd]);
	return MaxSum;
}
int main(){
	int N;
	scanf("%d",&N);
	int i,arr[10000];
	for(i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}
	MaxSubSum(arr,N);
	return 0;
} 
