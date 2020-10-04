#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100000
typedef int Position;
typedef int Eletment;

typedef struct Node* PtrToNode;
struct Node{
	Position Address;
	Eletment Data;
	Position Next;
	 PtrToNode Nextptr;
}; 
typedef PtrToNode List;
struct Node Arr[MaxSize];
List ReadList(Position firstAddr,int N){
	List p=(List)malloc(sizeof(struct Node));
	p->Nextptr=NULL;
	List L=p;
	int i;
	int Addr;
	for(i=0;i<N;i++){
		scanf("%d",&Addr);
		Arr[Addr].Address=Addr;
		scanf("%d%d",&Arr[Addr].Data,&Arr[Addr].Next);
	}
	int pos=firstAddr;
	while(p->Next!=-1){
		p->Nextptr=&Arr[pos];
		p=p->Nextptr;
		if(p->Next==-1) break;
		pos=p->Next;
	}
	List temp=L;L=L->Nextptr;free(temp);
	return L;
}
List ReverseList(List L,int k){
	List temp;
	List head=(List)malloc(sizeof(struct Node));
	head->Nextptr=L;
	List newNode=head->Nextptr;
	List oldNode=newNode->Nextptr;
	int cnt=1;
	while(cnt<k){
		temp=oldNode->Nextptr;
		oldNode->Nextptr=newNode;
		newNode=oldNode;
		oldNode=temp;
		cnt++;
	}
	head->Nextptr->Nextptr=oldNode;
	return newNode;
}
void PrintList(List L){
	List p=L;
	while(p){
		if(!p->Nextptr) printf("%05d %d %d\n",p->Address,p->Data,-1);
		else printf("%05d %d %05d\n",p->Address,p->Data,p->Nextptr->Address);
		p=p->Nextptr;
	}
}
int main(){
	int N,k;
	Position firstAddr;
	scanf("%d%d%d",&firstAddr,&N,&k);
	List L=ReadList(firstAddr,N);
	L=ReverseList(L,k);	
	PrintList(L);
	return 0;
} 
