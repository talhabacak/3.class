#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int N;			//size of array
	int i;			
	int j;			
	int min=10000;	//to keep the minimum difference
	int i_min;		//to keep the index of one of the numbers of minimum difference
	int j_min;		//the index of the other from the numbers of minimum difference
	int temp;		//variable that keeps the difference
	int dizi[100];		//array
	int flag;		//to stop the search if the difference is 0
	
	printf("dizinin boyutunu giriniz\n");
	scanf("%d",&N);
	
	for(i=0; i<N; i++){
		printf("dizinin %d. elemanini giriniz\n",i);
		scanf("%d",&dizi[i]);	
	}
	
	i=0;
	flag=0;
	
	while(i<N-1 && flag==0){
		j=i+1;						//No need to look again at the values we checked
		while(j<N && flag==0){
			temp=fabs(dizi[i]-dizi[j]);	//dizideki 2 sayinin mutlak farki
			if(min>temp){			//Is the difference less than the min value?
				min=temp;			//If smaller, we assign to temp to the new min value
				i_min=i;			//index of the new minimum value
				j_min=j;			//index of the other new minimum value
			}
			if(min==0){				//to exit the loop if the difference is 0
				flag=1;
			}
			j++;
		}
		i++;
	}
	
	printf("birbirine en yakin sayilar :\n\t %d - %d\n",dizi[i_min],dizi[j_min]);
	
	return 0;
}
