#include <stdio.h>

int carpma(int **m1, int **m2, int indexm1, int indexm2){
	int i;
	int j;
	int k;
	int sum;
	int **matris;
	
	matris = (int**)calloc(2, sizeof(int*));
	for(i=0; i<2; i++){
		matris[i] = (int*)calloc(2, sizeof(int));	
	}
	
	for(i=0; i<indexm1; i++){
		for(j=0; j<indexm2; j++){
			sum = 0;
			for(k=0; k<2; k++){
				sum += m1[i][k] *m2[k][j];
			}
			matris[i][j] = sum;
		}
	}
	
	return matris;
}

int us(int **sbt, int n){
	if(n <= 1){
		return sbt;
	}
	
	if(n % 2 == 0){
		return carpma(us(sbt,n/2),us(sbt,n/2),2,2);
	}
	
	return carpma(carpma(sbt,us(sbt,(n-1)/2),2,2),us(sbt,(n-1)/2),2,2) ;
}

int main(){
	int n;
	int **matris;
	int **sbt;
	int i;
	int j;
	
	matris = (int**)calloc(1, sizeof(int*));
	for(i=0; i<2; i++){
		matris[i] = (int*)calloc(2, sizeof(int));	
	}

	sbt = (int**)calloc(2, sizeof(int*));
	for(i=0; i<2; i++){
		sbt[i] = (int*)calloc(2, sizeof(int));	
	}

	matris[0][0] = 1;
	matris[1][0] = 0;
	
	sbt[0][0] = 1;
	sbt[0][1] = 1;
	sbt[1][0] = 1;
	sbt[1][1] = 0;
	
	printf("n'i giriniz: ");
	scanf("%d", &n);
	while(n < 0){
		printf("n negatif olamaz, n'i tekrar giriniz: ");
		scanf("%d", &n);
	}
	
	if(n > 0){
		sbt = us(sbt, n-1);	
		matris = carpma(sbt,matris,2,1);
	}

	for (i = 0; i < 2; i++){
		printf("%d\n",matris[i][0]);
    }	
    
	for (i = 0; i < 2; i++){
    	int* currentIntPtr = matris[i];
    	free(currentIntPtr);
	}
	for (i = 0; i < 2; i++){
    	int* currentIntPtr = sbt[i];
    	free(currentIntPtr);
	}
	
	return 0;
}
