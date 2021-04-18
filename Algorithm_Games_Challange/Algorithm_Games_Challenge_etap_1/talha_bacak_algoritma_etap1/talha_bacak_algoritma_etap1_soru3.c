#include <stdio.h>
#include <math.h>

int count=0;
int satir=0;

void recursive(int **matris, int N, int row, int col){
	int size = 2 * N + 3;
	
	if (abs(row - col) <= N){
		if((N+2) <= (row+col) && (row+col) <= 3*N+2){
			matris[row][col] = 1;
			count++;	
		}
	}

	col++;
	if (col % size == 0){
		printf("%d. satir : %d\n", satir, count);
		count=0;
		satir++;
		
		col = 0;
		row++;
	}

	if (row < size){
		recursive(matris, N, row, col);
	}
}

int main(){
	int N;
	int **matris;
	int i;
	int j;
	
	printf("N degerini giriniz\n");
	scanf("%d", &N);
	
	matris = (int**)calloc(2*N+3, sizeof(int*));
	for(i=0; i<2*N+3; i++){
		matris[i] = (int*)calloc(2*N+3, sizeof(int));	
	}
		
	recursive(matris, N, 0, 0);
	
	for(i=0; i<2*N+3; i++){
		for(j=0; j<2*N+3; j++){
			printf("%d ",matris[i][j]);
		}	
		printf("\n");
	}
	
	
	return 0;
}
