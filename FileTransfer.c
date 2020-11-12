#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10000
typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MaxSize];

void Initialization(SetType s, int n){
	int i;
	for( i = 0;i < n;i++) 
	s[i] = -1;
}


void Union(SetType s, SetName Root1, SetName Root2 ){
	if( s[Root2] < s[Root1] ){
		s[Root2] += s[Root1];
		s[Root1] = Root2;
	}else {
		s[Root1] += s[Root2];
		s[Root2] = Root1;
	}
}


SetName Find(SetType s, ElementType X){
	if(s[X] < 0) return X;
	else return s[X] = Find(s, s[X]);
}


void check_connection(SetType s){
	ElementType u,v;
	scanf("%d %d\n", &u, &v);
	SetName Root1 = Find(s, u-1);
	SetName Root2 = Find(s,v-1);
	if( Root1 == Root2 ) printf("yes\n");
	else printf("no\n");
}


void input_connection(SetType s){
	ElementType u,v;
	scanf("%d %d\n", &u, &v);
	SetName Root1 = Find(s, u-1);
	SetName Root2 = Find(s, v-1);
	if(Root1 != Root2) Union(s, Root1, Root2);
}


void check_network(SetType s, int n ){
	int count = 0;
	for(int i = 0;i < n;i++){
		if(s[i] < 0) count++;
	}
	if(count == 1) printf("The network is connected.\n");
	else printf("There are %d components.\n", count);
}


int main(){
	SetType S;
	int n;
	char in;
	scanf("%d\n", &n);
	Initialization(S, n);
	do{
		scanf("%c", &in);
		switch(in) {
			case 'C':check_connection(S); break;
			case 'I':input_connection(S); break;
			case 'S':check_network(S, n); break;
		}
	}while(in != 'S');
	return 0;
}
