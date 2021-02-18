#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int resultControl=0;	//for result check

//output
void display(int N, int **matris){
	char renk1[8]="kirmizi";		//
	char renk2[8]="turuncu";		//
	char renk3[5]="sari";			//
	char renk4[6]="yesil";			//	colors
	char renk5[5]="mavi";			//
	char renk6[4]="mor";			//
	char renk7[6]="siyah";			//
	char renk8[6]="beyaz";			//
	int i;		//row
	int j;		//column
	
	printf("----------------------------------------------------------------------------------------------------------------------------\n");
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(matris[i][j]==1){			//
				printf("%s",renk1);			//
			}								//
			else if(matris[i][j]==2){		//
				printf("%s",renk2);			//
			}								//
			else if(matris[i][j]==3){		//
				printf("%s",renk3);			//
			}								//
			else if(matris[i][j]==4){		//
				printf("%s",renk4);			//		Converting the numbers in 
			}								//		the matrix to colors and 
			else if(matris[i][j]==5){		//		printing them on the screen
				printf("%s",renk5);			//
			}								//
			else if(matris[i][j]==6){		//
				printf("%s",renk6);			//
			}								//
			else if(matris[i][j]==7){		//
				printf("%s",renk7);			//
			}								//
			else if(matris[i][j]==8){		//
				printf("%s",renk8);			//
			}								//
			else{
				printf("%d",matris[i][j]);
			}
			printf("\t\t");
		}
		printf("\n");
	}
}

//shifts the specified line one right
void kaydir(int N, int **matris, int i){
	int j;						//column
	int temp=matris[i][N-1];	//value of last column of specified row
	
	for(j=N-1; j>0; j--){
		matris[i][j]=matris[i][j-1];
	}
	matris[i][0]=temp;
}

//Is it equal to those above the row it is in, its control
//true if equality, return false otherwise
bool isEqual(int N, int **matris, int i){
	int i1;		//row of the 1st parameter to be compared
	int i2;		//row of the 2nd parameter to be compared
	int j=0;	//column to compare
	
	while(j<N){
		i1=0;
		while(i1<i-1){
			i2=i1+1;
			while(i2<i){
				if(matris[i1][j]==matris[i2][j]){
					return true;
				}
				i2++;
			}
			i1++;		
		}
		j++;
	}
	
	display(N,matris);
	
	return false;
}

//recursive backtracking algorithm
//return value true or false
bool backtracking(int N, int **matris,int i){
	int count;		//the number of columns in a row
	
	//returns false if no result
	resultControl++;
	if(resultControl>=N*N*N){
		return false;
	}
	
	if(i>N){
		return true;
	}
	else if(i<=0){
		return false;
	}
	
	for(count=0; count<N; count++){
		if(!isEqual(N,matris,i)){				//is there the same number in the column
			if(backtracking(N,matris,++i)){		//If not, go down 1 row
				return true;
			}									
		}
		kaydir(N,matris,i);						//if there is, a slide to the right
	}
	
	kaydir(N,matris,i-1);		
	
	if(backtracking(N,matris,--i)){		//go up one row
		return true;
	}

	return false;		
}

//input
//return value is size of matrix
int input(	int N, int **matris){
	char renk1[8]="kirmizi";		//
	char renk2[8]="turuncu";		//
	char renk3[5]="sari";			//
	char renk4[6]="yesil";			//		colors
	char renk5[5]="mavi";			//
	char renk6[4]="mor";			//
	char renk7[6]="siyah";			//
	char renk8[6]="beyaz";			//
	char temp[8];		//variable we will get the user input color
	int i;		//row
	int j;		//column
	int control;		//Check for incorrect color spelling
	
	do{
		printf("N sayisini giriniz. (3<=N<=8 olmali)\n");
		scanf("%d",&N);
	}while(N<3 || N>8);
	
	printf("\nRenkleri su sekilde giriniz:\nkirmizi, turuncu, sari, yesil, mavi, mor, siyah, beyaz\n\n");
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			do{
				control=0;
				printf("%d. satir %d. sutun rengini yaziniz\n",i,j);
				scanf("%s",temp);
				
				if(!strcmp(temp,renk1)){			//
					matris[i][j]=1;					//
				}									//
				else if(!strcmp(temp,renk2)){		//
					matris[i][j]=2;					//
				}									//
				else if(!strcmp(temp,renk3)){		//
					matris[i][j]=3;					//
				}									//
				else if(!strcmp(temp,renk4)){		//		numerical transfer 
					matris[i][j]=4;					//		of colors to matrix
				}									//			
				else if(!strcmp(temp,renk5)){		//
					matris[i][j]=5;					//
				}									//
				else if(!strcmp(temp,renk6)){		//
					matris[i][j]=6;					//
				}									//
				else if(!strcmp(temp,renk7)){		//
					matris[i][j]=7;					//
				}									//
				else if(!strcmp(temp,renk8)){		//
					matris[i][j]=8;					//
				}									//
				else{								
					control=1;
				}
			}while(control==1);
		}
	}
	return N;
}


int main(){
	int N;			//size of matrix
	int **matris;	//pointer of matrix
	int i;			//to create the matrix
	
	matris=(int**)calloc(8,sizeof(int*));			//
	for(i=0; i<8; i++){								//		creating dynamic 
		matris[i]=(int*)calloc(8,sizeof(int));		//		   matrix
	}												//
	
	N=input(N, matris);				//input

	//the algorithm itself
	if(backtracking(N,matris,1)){	//
		printf("\n\n\nSonuc:\n");	//		If it turns true,
		display(N,matris);			//		result will print
	}								//
	else{								//
		printf("\n\n\nSonuc Yok\n");	// If it turns false there is no result
	}									//
	
	free(matris);
	
	return 0;
}
