#include <stdio.h>
#include <math.h>

int isprime(int n){
	if (n==2){return 1;}
	if (n%2 == 0){return 0;}
	for(int i = 3; i<=(int)ceil(sqrt(n)); i++){
		if(n%i == 0){return 0;}
	}
	return 1;
}

int main(){
	int limit, N=0, start;
	FILE * fp = fopen("primelist.txt","a");
	printf("Enter the number of prime numbers you need: ");
	scanf("%d",&limit);
	printf("Enter the start value to check: ");
	scanf("%d",&start);
	while(limit>N){
		if (isprime(start)){
			//printf("%d\n",start);
			fprintf(fp,"%d\n",start);
			N++;
		}
		start++;
	}
	return 0;
}
