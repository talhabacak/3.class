#include <stdio.h>

int main(){
	int sizeX;
	int sizeY;
	int X;
	int Y;
	int gun;
	int **matris;
	int i;
	int j;
	int **enfekte;
	int index = 0;
	int count = 0;
	int tempX;
	int tempY;
	int	countGunluk = 0;

	printf("Matris boyutu x ekseni:");
	scanf("%d", &sizeX);
	printf("Matris boyutu y ekseni:");
	scanf("%d", &sizeY);
	printf("Enfekte kisi x koordinati:");
	scanf("%d", &X);
	printf("Enfekte kisi y koordinati:");
	scanf("%d", &Y);
	printf("Gun sayisi:");
	scanf("%d", &gun);
	
	matris = (int**)calloc(sizeX, sizeof(int*));
	for(i=0; i<sizeX; i++){
		matris[i] = (int*)calloc(sizeY, sizeof(int));	
	}

	enfekte = (int**)calloc(sizeX*sizeY, sizeof(int*));
	for(i=0; i<sizeX*sizeY; i++){
		enfekte[i] = (int*)calloc(2, sizeof(int));	
	}

	enfekte[0][0] = X;
	enfekte[0][1] = Y;
	matris[X][Y] = 1;
		
	while(gun > 0){
		while(count <= countGunluk){
			tempX = enfekte[count][0];
			tempY = enfekte[count][1];
			for(i=tempX-1; i<=tempX+1; i++){
				if(i > -1 && i < sizeX){
					for(j=tempY-1; j<=tempY+1; j++){
						if(j > -1 && j < sizeY){
							if(matris[i][j] != 1){
								matris[i][j] = 1;	
								index++;
								enfekte[index][0] = i;
								enfekte[index][1] = j;
							}
						}
					}
				}
			}	
			count++;
		}
		countGunluk = index;
		gun--;	
	}
	
	printf("\nEnfekte kisi sayisi: %d", index);
	
	for (i = 0; i < sizeY; i++){
    	int* currentIntPtr = matris[i];
    	free(currentIntPtr);
	}
	for (i = 0; i < sizeX*sizeY; i++){
    	int* currentIntPtr = enfekte[i];
    	free(currentIntPtr);
	}
	return 0;
}
