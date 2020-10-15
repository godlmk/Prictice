#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode* Tree;
struct TreeNode{
	int v;
	Tree Left;
	Tree Right;
	int flag;
};

Tree NewNode(int V){
	Tree T=(Tree) malloc(sizeof(struct TreeNode));
	T->v=V;
	T->Left=T->Right=NULL;
	T->flag=0;
	return T;
}


Tree Insert(Tree T,int v){
	if(!T) T=NewNode(v);
	else {
		if(v>T->v) T->Right=Insert(T->Right,v);
		else T->Left=Insert(T->Left,v);
	}
	return T;
}

int check(Tree T,int V){
	if(T->flag) {
		if(V<T->v) return check(T->Left,V);
		else if(V>T->v) return check(T->Right,V);
		else return 0;
	}
	else {
		if(V==T->v){
			T->flag=1;
			return 1;
		}
		else return 0;
	}
}

int Judge(Tree T,int N){
	int i,V,flag=0;
	scanf("%d",&V);
	if(V!=T->v) flag=1;
	else T->flag=1;
	for(i=1;i<N;i++){
		scanf("%d",&V);
		if((!flag)&&(!check(T,V))) flag=1;
		
	}
	if(flag) return 0;
	else return 1;
}
Tree makeTree(int N){
	int i,v;
	Tree T;
	scanf("%d",&v);
	T=NewNode(v);
	for(i=1;i<N;i++){
		scanf("%d",&v);
		Insert(T,v);
	}
	return T;
}

void Reset(Tree T){
	if(T->Left) Reset(T->Left);
	if(T->Right) Reset(T->Right);
	T->flag=0;
}

void freeTree(Tree T){
	if(T->Left) freeTree(T->Left);
	if(T->Right) freeTree(T->Right);
	free(T);
}

int main(){
	int N,L,i;
	scanf("%d",&N);
	while(N){
		scanf("%d",&L);
		Tree T=makeTree(N);
		for(i=0;i<L;i++) {
			if(Judge(T,N)) printf("Yes\n");
			else printf("No\n"); 
			Reset(T);
		}
		freeTree(T);
		scanf("%d",&N);
	}
	return 0;
} 
