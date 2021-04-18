#include <stdio.h>
#include <stdlib.h>

void f(double* dizi, int a, int b, int k, char islem){
	int i;
	double temp;

	if(islem != 's'){
		for(i=a; i<=b; i++){
			if(islem == '+'){
				dizi[i] += k;
			}
			if(islem == '-'){
				dizi[i] -= k;
			}
			if(islem == '*'){
				dizi[i] *= k;
			}
			if(islem == '/'){
				dizi[i] /= k;
			}
		}
	}
	else{
		for(i=0; i<=k; i++){
			temp = dizi[a+i];
			dizi[a+i] = dizi[b-i];
			dizi[b-i] = temp;
		}
	}
}

int main(){
	int N;
	int M;
	int a;
	int b;
	int k;
	double *dizi;
	int i;
	char islem;
	
	printf("Sirayla N ve M'i bir boslukla giriniz: ");
	scanf("%d %d", &N, &M);
	while(N < 3 || N > 1000){
		printf("N'i tekrar giriniz: ");
		scanf("%d", &N);		
	}
	while(M > 100 || M < 1){
		printf("M'i tekrar giriniz: ");
		scanf("%d", &M);		
	}
	
	dizi = (double*)calloc(N,sizeof(double));
	
	for(i=0; i<M; i++){
		printf("Sirasiyla a, b, k, islem'i bir boslukla giriniz: ");
		scanf("%d %d %d %c", &a, &b, &k, &islem);
		while(a >= N || a < 1){
			printf("a'yi tekrar giriniz: ");
			scanf("%d", &a);		
		}
		while(b > N || b < a){
			printf("b'yi tekrar giriniz: ");
			scanf("%d", &b);		
		}
		while(k < 0 || k > 1000){
			printf("k'yi tekrar giriniz: ");
			scanf("%d", &k);		
		}
		while(islem != '+' && islem != '-' && islem != '/' && islem != '*' && islem != 's'){
			printf("islem'i tekrar giriniz: ");
			scanf("%c", &islem);		
		}
		
		f(dizi,a-1,b-1,k,islem);
	}
	
	for(i=0; i<N; i++){
		printf("%lf  ",dizi[i]);
	}		
		
	free(dizi);
	
	return 0;
}
