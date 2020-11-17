#include<stdio.h>


int IsPrime(int num){
	int flag = 1;
	for( int i = 2; i < num / 2 + 1; i++){
		if(num % i == 0) {
			flag = 0;
			break;
		}
	}
	return flag;
}


void Primefactor(int n){
	if(  IsPrime(n) ) {
		printf("%d", n);
		return ;
	}
	for(int i = 2; i <= n / 2 + 1; i++){
		if(n % i ==0 && IsPrime(i)){
			printf("%d*", i);
			Primefactor( n/i );
			break;
		}
	}
}


int main(){
	int x;
	scanf("%d", &x);
	printf("%d=", x);
	Primefactor(x);
	return 0;
}
