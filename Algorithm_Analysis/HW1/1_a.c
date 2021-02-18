#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int N;			//size of array
	int i;			
	int j;			
	int min=10000;	//to keep the minimum difference
	int i_min;		//to keep the index of one of the numbers of minimum difference
	int j_min;		//  the index of the other from the numbers of minimum difference
	int temp;		//variable that keeps the difference
	int dizi[100];		//array
	
	printf("dizinin boyutunu giriniz\n");
	scanf("%d",&N);
	
	for(i=0; i<N; i++){
		printf("dizinin %d. elemanini giriniz\n",i);
		scanf("%d",&dizi[i]);	
	}
	
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(i!=j){					//same number check
				temp=fabs(dizi[i]-dizi[j]);	//absolute value difference of the 2 numbers in the array
				if(min>temp){			//Is the difference less than the min value?
					min=temp;			//If smaller, we assign to temp to the new min value
					i_min=i;			//index of the new minimum value
					j_min=j;			//index of the other new minimum value
				}
			}
		}
	}
	
	printf("birbirine en yakin sayilar :\n\t %d - %d\n",dizi[i_min],dizi[j_min]);
	
	return 0;
}
