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
List ReadList(Position firstAddr,int *length){
	List p=(List)malloc(sizeof(struct Node));
	p->Nextptr=NULL;
	List L=p;
	int i;
	int Addr;
	for(i=0;i<(*length);i++){
		scanf("%d",&Addr);
		Arr[Addr].Address=Addr;
		scanf("%d%d",&Arr[Addr].Data,&Arr[Addr].Next);
	}
	int size=0;
	int pos=firstAddr;
	while(Arr[pos].Address!=-1){
		p->Nextptr=&Arr[pos];
		p=p->Nextptr;
		++size;
		if(Arr[pos].Next==-1) break;
		pos=p->Next;
	}
	*length=size;
	List temp=L;L=L->Nextptr;free(temp);
	return L;
}
List ReverseList(List L,int k){
	List temp;
	List newNode=L->Nextptr;
	List oldNode=newNode->Nextptr;
	int cnt=1;
	while(cnt<k){
		temp=oldNode->Nextptr;
		oldNode->Nextptr=newNode;
		newNode=oldNode;
		oldNode=temp;
		cnt++;
	}
	List rear=L->Nextptr;
	rear->Nextptr=oldNode;
	L->Nextptr=newNode;
	return rear;
}
List Reverse(List L,int N,int k){
	if(k==1) return L; 
	List head=(List)malloc(sizeof(struct Node));
	head->Nextptr=L;
	List p=head;
	int times=N/k;
	while(times--){
		p=ReverseList(p,k);
	}
	if(N%k==0) p->Nextptr=NULL;
	List tem=head;
	head=head->Nextptr;
	free(tem);
	return head;
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
	scanf("%d%d%d",&firstAddr, &N, &k);
	List L=ReadList(firstAddr, &N);
	L=Reverse(L, N, k);
	PrintList(L);
	return 0;
} 
