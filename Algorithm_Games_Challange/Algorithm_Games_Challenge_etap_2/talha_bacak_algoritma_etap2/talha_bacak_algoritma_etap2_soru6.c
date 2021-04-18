#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void carpma(int K[10][10], int L[10][10], int N, int indexK, int indexL){
	int i;
	int j;
	int k;
	int sum;
	
	printf("\n");
	for(i=0; i<indexK; i++){
		for(j=0; j<indexL; j++){
			sum = 0;
			for(k=0; k<N; k++){
				sum += K[i][k] *L[k][j];
			}
			printf("%d ",sum);
		}
		printf("\n");
	}
}

int main(){
	int X;
	int N;
	int A;
	int vektor[10][10];
	int K[10][10];
	int L[10][10];
	int secilen[10];
	int secilmeyen[10];
	int sec;
	int i;
	int j;
	int indis = 0;
	int flag;
	int indexK;
	int indexL;
	
	srand(time(NULL));
		
	printf("X'i giriniz: ");
	scanf("%d", &X);
	printf("N'i giriniz: ");
	scanf("%d", &N);
	
	for(i=0; i<X; i++){
		secilen[i] = -1;
		secilmeyen[i] = i;
	}


	for(i=0; i<X; i++){
		for(j=0; j<N; j++){
			printf("%d. vektorun %d. elemanini giriniz: ",i+1,j+1);
			scanf("%d", &vektor[i][j]);
		}		
	}
	
	do{
		printf("A'yi giriniz: ");
		scanf("%d", &A);	
	}while(A >= X);
	
	for(i=0; i<A; i++){
		do{
			sec=rand() % X;
			j = 0;
			flag = 1;
			while(j < indis && flag == 1){
				if(secilen[j] == sec){
					flag = 0;
				}
				j++;
			}
		}while(flag == 0);
		
		secilen[indis] = sec;
		secilmeyen[sec] = -1;
		indis++;
	}
	
	indexK = 0;
	indexL = 0;
	for(i=0; i<X; i++){		
		if(secilmeyen[i] == -1){
			for(j=0; j<N; j++){		
				K[indexK][j] = vektor[secilen[indexK]][j];
			}			
			indexK++;
		}
		else{
			for(j=0; j<N; j++){		
				L[indexL][j] = vektor[secilmeyen[i]][j];
			}	
			indexL++;
		}				
	}
		
	if(N == indexL){
		carpma(K, L, N, indexK, indexL);
	}
	else{
		printf("\n?");
	}
	
	return 0;
}
