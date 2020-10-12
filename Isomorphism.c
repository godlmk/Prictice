#include<stdio.h>
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode{
	ElementType Data;
	Tree Left;
	Tree Right;
}T1[MaxTree],T2[MaxTree];

Tree BuildTree(struct TreeNode T[]){
	char cl,cr;
	Tree Root=Null;
	int N,i;
	int check[MaxTree];
	scanf("%d\n",&N);
	if(N){
		for(i=0;i<N;i++) check[i]=0;
		for(i=0;i<N;i++) {
			scanf("%c %c %c\n",&T[i].Data,&cl,&cr);
			if(cl!='-'){
				T[i].Left=cl-'0';
				check[T[i].Left]=1;
			}
			else {
				T[i].Left=Null;
			}
			if(cr!='-'){
				T[i].Right=cr-'0';
				check[T[i].Right]=1;
			}
			else T[i].Right=Null;
		}
		for(i=0;i<N;++i)
			if(!check[i]) break;
		Root=i;
		
	}
	return Root;
}

int Isomorphic(Tree R1,Tree R2){
	if( (R1==Null) && (R2==Null) ) 
		return 1;
		
	if(( (R1!=Null) && (R2==Null) ) || ( (R1==Null) && (R2!=Null) )) 
		return 0;
		
	if(T1[R1].Data!=T2[R2].Data) 
		return 0;
		
	if((T1[R1].Left==Null)&&T2[R2].Left==Null) 
		return Isomorphic(T1[R1].Right,T2[R2].Right);
		
	if(((T1[R1].Left!=Null)&&(T2[R2].Left!=Null))&&
	((T1[T1[R1].Left].Data))==T2[T2[R2].Left].Data)
		return ( Isomorphic(T1[R1].Left,T2[R2].Left) && Isomorphic(T1[R1].Right,T2[R2].Right));
	else 
		return ( Isomorphic(T1[R1].Left,T2[R2].Right) && Isomorphic(T1[R1].Right,T2[R2].Left));
}

int main(){
	Tree R1,R2;
//	输入树R1
	R1=BuildTree(T1);
//	输入树R2
	R2=BuildTree(T2);
//	判断两棵树是否同构并输出结果
	if(Isomorphic(R1,R2)) printf("Yes\n");
	else printf("No\n");
	return 0;
} 
