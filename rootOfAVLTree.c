#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode* AVLTree;
struct TreeNode{
	int V;
	AVLTree Left,Right;
};

int getHeight(AVLTree T){
	if(!T) return 0;
	int lHeight,rHeight;
	lHeight=getHeight(T->Left);
	rHeight=getHeight(T->Right);
	return (lHeight>rHeight? lHeight:rHeight)+1;
}

AVLTree NewNode(int V){
	AVLTree T=(AVLTree)malloc(sizeof(struct TreeNode));
	T->V=V;
	T->Left=T->Right=NULL;
	return T;
}

AVLTree RR(AVLTree T){
	AVLTree tem=T->Right;
	T->Right=tem->Left;
	tem->Left=T;
	return tem;	
} 

AVLTree LL(AVLTree T){
	AVLTree tem=T->Left;
	T->Left=tem->Right;
	tem->Right=T;
	return tem;
}

AVLTree LR(AVLTree T){
	AVLTree ltem,lrtem;
	ltem=T->Left;
	lrtem=ltem->Right;
	ltem->Right=lrtem->Left;
	T->Left=lrtem->Right;
	lrtem->Left=ltem;
	lrtem->Right=T;
	return lrtem;
}

AVLTree RL(AVLTree T){
	AVLTree rtem,rltem;
	rtem=T->Right;
	rltem=rtem->Left;
	T->Right=rltem->Left;
	rtem->Left=rltem->Right;
	rltem->Left=T;
	rltem->Right=rtem;
	return rltem;
}

AVLTree Insert(AVLTree T,int V){
	if(!T) T=NewNode(V);
	else {
		if(V<T->V) {
			T->Left=Insert(T->Left,V);
			if(getHeight(T->Left)-getHeight(T->Right)==2){
				if(V<T->Left->V) T=LL(T);
				else T=LR(T);
			}
		}
		else {
			T->Right=Insert(T->Right,V);
			if(getHeight(T->Left)-getHeight(T->Right)==-2){
				if(V>T->Right->V) T=RR(T);
				else T=RL(T);
			} 
		}
	}
	return T;
}

AVLTree MakeTree(int N){
	int i,V;
	AVLTree R=NULL;
	for(i=0;i<N;i++){
		scanf("%d",&V);
		R=Insert(R,V);
	}
	return R;
}

int main(){
	AVLTree T;
	int i,N;
	scanf("%d",&N);
	if(N){
		T=MakeTree(N);
		printf("%d",T->V);
	}
	return 0;
}
