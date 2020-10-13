#include <stdio.h>
#include <stdlib.h>
#define MaxTree 10
#define Element int
#define Tree int
#define Position int
#define Null -1
struct TreeNode{
	Tree Left;
	Tree Right;
}T[MaxTree];

struct QNode{
	Element* Data;
	Position front,rear;
	int MaxSize;
}; 
typedef struct QNode* Queue;

Queue CreatQueue(int MaxSize) {
	Queue q=(Queue)malloc(sizeof(struct QNode));
	q->Data=(int*) malloc(MaxSize*sizeof(int));
	q->MaxSize=MaxSize;
	q->front=q->rear=0;
	return q;
}
int IsFull(Queue q){
	return (q->rear+1)%q->MaxSize==q->front;
}
int AddQ(Queue Q,Element x) {
	if(IsFull(Q)) return 0;
	Q->rear=(Q->rear+1)%Q->MaxSize;
	Q->Data[Q->rear]=x;
	return 1;
}
int IsEmpty(Queue q) {
	return q->front==q->rear;
}
Element DeleteQ(Queue Q){
	if(IsEmpty(Q)) return 0;
	Q->front=(Q->front+1)%Q->MaxSize;
	return Q->Data[Q->front];
}
Tree BuildTree(struct TreeNode T[]){
	Tree Root=Null;
	int i,N;
	char cl,cr;
	int check[MaxTree];
	scanf("%d\n", &N);
	for(i=0;i<N;i++) check[i]=0;
	if(N){
		for(i=0;i<N;i++)  {
			scanf("%c %c\n",&cl,&cr);
			if(cl!='-'){
				T[i].Left = cl - '0';
				check[T[i].Left] = 1;
			}
			else T[i].Left=Null;
			if(cr!='-'){
				T[i].Right = cr - '0';
				check[T[i].Right]=1;
			}
			else T[i].Right=Null;
		}
		for(i=0;i<N;i++) {
			if(!check[i]) break;
		}
		Root=i;
	}
	return Root;
}

void ListLeaves(Tree R){
	Tree tem;
	if(R==Null) return ;
	Queue q=CreatQueue(11);
	AddQ(q,R);
	int flag=0;
	while(!IsEmpty(q)){
		tem=DeleteQ(q);
		if(T[tem].Left==Null&&T[tem].Right==Null){
			if(flag) printf(" ");
			printf("%d",tem);
			flag=1;
		}
		if(T[tem].Left!=Null) AddQ(q,T[tem].Left);
		if(T[tem].Right!=Null) AddQ(q,T[tem].Right);
	}
}

int main() {
//	创建一棵树
	Tree R=BuildTree(T);
//	把树的每一节点入栈，并把他的左右节点入栈。若无左右子树则出栈
 	ListLeaves(R);
 	
	return 0;
} 
