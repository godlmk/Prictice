/*   题目 
设计函数分别求两个一元多项式的乘积与和。
输入格式:
输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式:
输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。

输入样例:
4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1
输出样例:
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0
*/



#include <stdio.h>
#include <stdlib.h>
typedef struct Node *polyNomial;
polyNomial ReadPoly();
void Attach(int c,int e,polyNomial *pRear);
polyNomial Add(polyNomial p1,polyNomial p2);
polyNomial Mult(polyNomial p1,polyNomial p2); 
void PrintPoly(polyNomial p);
//创建一个结构体 
struct Node{
	int cofe;
	int expon;
	polyNomial Link;
};

int main() {
	polyNomial p1,p2,pa,pm;
	p1=ReadPoly();
	p2=ReadPoly();
	pm=Mult(p1,p2);
	PrintPoly(pm);
	pa=Add(p1,p2);
	PrintPoly(pa);
	return 0;
}

polyNomial ReadPoly() {
	polyNomial p,Rear,t;
	int c,e,N;
	scanf("%d",&N);
	p=(polyNomial)malloc(sizeof(struct Node));
	p->Link=NULL;
	Rear=p;
	while(N--) {
		scanf("%d %d",&c,&e);
		Attach(c,e,&Rear);
	}
	t=p;p=p->Link;free(t);
	return p;	
}

void Attach(int c,int e,polyNomial *pRear) {
	polyNomial p;
	p=(polyNomial)malloc(sizeof(struct Node));
	p->cofe=c;
	p->expon=e;
	p->Link=NULL;
	(*pRear)->Link=p;
	*pRear=p;
}

polyNomial Add(polyNomial p1,polyNomial p2) {
	polyNomial front,rear,temp;
	int sum;
	rear=(polyNomial) malloc(sizeof(struct Node));
	rear->Link=NULL;
	front=rear;
	while(p1&&p2) {
		if(p1->expon==p2->expon) {
			sum=p1->cofe+p2->cofe;
			if(sum) {
					Attach(sum,p1->expon,&rear);
				}
			p1=p1->Link;
			p2=p2->Link;
			}
		else if(p1->expon>p2->expon) {
				Attach(p1->cofe,p1->expon,&rear);
				p1=p1->Link;
			}
		else {
				Attach(p2->cofe,p2->expon,&rear);
				p2=p2->Link;
			}
		}
	while(p1) {
			Attach(p1->cofe,p1->expon,&rear);
			p1=p1->Link;
		}
	while(p2) {
			Attach(p2->cofe,p2->expon,&rear);
			p2=p2->Link;
		}
		rear->Link=NULL;
		temp=front;
		front=front->Link;
		free(temp);
		return front;
	}
	
polyNomial Mult(polyNomial p1,polyNomial p2) {
	polyNomial Rear,p,t1,t2,t;
	int c,e;
	if(!p1||!p2) return NULL;
	t1=p1;
	t2=p2;
	//创建一个空节点 
	p=(polyNomial)malloc(sizeof(struct Node));
	p->Link=NULL;
	Rear=p;
	while(t2) {//先用p1第一项乘p2的每一项用来初始化p 
		Attach(t1->cofe*t2->cofe,t1->expon+t2->expon,&Rear);
		t2=t2->Link;
	} 
	t1=t1->Link;
	while(t1) {
		t2=p2;
		Rear=p;
		while(t2) {
			c=t1->cofe*t2->cofe;
			e=t1->expon+t2->expon;
			/*
			如果当前的节点不是最后一个节点且下一项的指数大于要插入结点的指数则继续向下寻找 ，直到找到
			最后一项或者当前节点的下一项的指数小于等于要插入结点的指数。 
			*/
			while(Rear->Link&&Rear->Link->expon>e) {
				Rear=Rear->Link;
			}
			/*
			如果指数相等，且系数相加不为0，则插入系数相加后的节点。若为0则删除当前节点的下一个节点。 
			*/ 
			if(Rear->Link&&Rear->Link->expon==e) {
					if(Rear->Link->cofe+c){
						Rear->Link->cofe+=c;
					}
					else {
						t=Rear->Link;
						Rear->Link=t->Link;
						free(t); 
					}
				}
			else {
					t=(polyNomial)malloc(sizeof(struct Node));
					t->cofe=c;t->expon=e;
					t->Link=Rear->Link;
					Rear->Link=t;
					Rear=Rear->Link; 
				}
			t2=t2->Link;
		}
		t1=t1->Link;
	}
	t2=p;p=p->Link;free(t2);
	return p;
}

void PrintPoly(polyNomial p) {
	int flag=0;
	if(!p) {
	printf("0 0\n");return;
	} 
	while(p) {
	if(flag==0){
		flag=1;
	}
	else {
		printf(" ");
	}
	printf("%d %d",p->cofe,p->expon);
	p=p->Link;
  	}
  	printf("\n");
}



