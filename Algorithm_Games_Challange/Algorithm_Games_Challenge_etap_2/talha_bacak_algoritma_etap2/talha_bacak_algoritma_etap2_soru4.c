#include <stdio.h>

int main(){
	int N;
	int matris[100][100];
	int x;
	int y;
	int i;
	int j;
	int cikti;
	
	printf("N'i giriniz: ");
	scanf("%d",&N);	
	
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("Matrisin %d. satir %d. sutununu giriniz: ",i+1,j+1);
			scanf("%d",&matris[i][j]);
		}
	}
	
	printf("x'i giriniz: ");
	scanf("%d",&x);	
	printf("y'i giriniz: ");
	scanf("%d",&y);	
	
	cikti = matris[x-1][y-1];
	for(i=0; i<N; i++){
		cikti += matris[x-1][i] * matris[y-1][i];
	}
	
	printf("\nToplam yol sayisi: %d\n",cikti);
	
	return 0;
}
