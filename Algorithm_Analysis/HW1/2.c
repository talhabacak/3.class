#include <stdio.h>
#include <stdlib.h>

//Placing the 1's
void siyah(int boyut, int orta,int **matris){
	int hedef;	//The limit of how many we do 1 per row in the matrix
	int i;
	int j;
	
	for(i=1;i<boyut-1;i++){	
		if(i<=orta){		//will increase to the median row (equal to i)
			hedef=i;		
		}
		else{				//will decrease again after the median line
			hedef--;		
		}

		j=0;	//how many ones around the middle of the line
		while(j<hedef){		//Checking how many 1s are to the left and right of the medial column of row i of the matrix
			matris[i][orta-j]=1;	//the left side of the medial column of the i row of the matrix makes 1
			matris[i][orta+j]=1;	//the right side of the median column of the i row of the matrix makes 1
			j++;
		}
	}
}

//print the matrix to the screen and find the number 1 in each row
void displayMatris(int boyut, int **matris, int satir[]){	//the size of the matrix, itself, the array to hold the number 1 in each row
	int i;
	int j;
	
	for(i=0; i<boyut; i++){
		printf("\n");
		satir[i]=0;
		for(j=0; j<boyut; j++){
			if(matris[i][j]==1){
				satir[i]++;
			}
			
			printf("%d ",matris[i][j]);
		}
	}
}

//printing the number 1 in the lines and finding the total number 1
void displayBlack(int boyut, int satir[]){		//size of matrix, array holding number 1 in each row
	int i;
	int toplam=0;	//total number of 1
	
	printf("\n\n");
	for(i=0; i<boyut; i++){
		printf("%d. satirdaki siyah nokta sayisi : %d\n",i,satir[i]);
		
		toplam+=satir[i];
	}
	
	//printing the total number of 1
	printf("\ntoplam siyah nokta sayisi : %d",toplam);
}

int main(){
	int N;				//value of N
	int boyut;			//size of matrix
	int orta;			//middle of the matrix
	int **matris;		
	int i;
	int satir[100];		//Array to keep the number 1 in each row
	
	printf("N degerini giriniz\n");
	scanf("%d",&N);
	
	boyut=2*N+3;		//matrix size (boyut * boyut)	
	orta=boyut/2;		//center of matrix (matris[orta][orta])
	
	//Constructing the matrix with dynamic memory allocation method
	matris=(int**)calloc(boyut,sizeof(int*));
	for(i=0; i<boyut;i++){
		matris[i]=(float*)calloc(boyut,sizeof(float));
	}
	
	siyah(boyut, orta, matris);
	
	displayMatris(boyut, matris, satir);
	
	displayBlack(boyut, satir);
	
	return 0;
}
