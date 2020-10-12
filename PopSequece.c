#include<stdio.h>
#include<stdlib.h>
#define ERROR -1
typedef int Position;
typedef int Element;
struct SNode{
	Element* Data;
	Position Top;
	int Maxsize;
};
typedef struct SNode *Stack;

void makeEmpty(Stack s) {
	s->Top=-1;
}


Stack CreatStack(int Maxsize){
	Stack s=(Stack)malloc(sizeof(struct SNode));
	s->Data=(int*)malloc(Maxsize*sizeof(int));
	s->Top=-1;
	s->Maxsize=Maxsize;
	return s;
}

void Push(Stack s,Element k){
	if(s->Top==s->Maxsize-1) return;
	else {
		s->Data[++(s->Top)]=k;
	}
}

Element Pop(Stack s){
	if(s->Top==-1) 
		return NULL;
	return s->Data[(s->Top)--];
	
}

Element GetTopEle(Stack s){
	if(s->Top==-1) 
		return NULL;
	return s->Data[s->Top];
}
int check(int* squ,Stack stack,int N){
	int i;
	int item=1;
	int flag=1;
	for(i=0;i<N;i++){
		while(item<=N&&GetTopEle(stack)!=squ[i]){
			Push(stack,item++);
		}
		if(GetTopEle(stack) == squ[i]) 
			Pop(stack);
		else {
			flag=0;
			break;	
		}
	}
	return flag;
}

int main(){
	//	读入初始数据：M:堆栈的容量 N:每个序列的长度 K:序列的个数 
	int M,N,K;
	scanf("%d %d %d",&M,&N,&K); 
	//构造一个堆栈
	Stack s=CreatStack(M);
	//	存储需要判断的序列：
	int * squ=(int*)malloc(N*sizeof(int));
	int i,j,result;
	for(i=0;i<K;i++){
		for(j=0;j<N;j++){
			scanf("%d",&squ[j]);
		}
	//	判断是否能输出这个结果
	//	需先初始化堆栈，不然结果可能不对 
	makeEmpty(s);
	result=check(squ,s,N);
	if(result) 
		printf("YES\n");
	else 
		printf("NO\n"); 
	} 
 
	return 0;
}
