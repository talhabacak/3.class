#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define boyut 100

// user
struct node{
	float puan[100];	// Points she/he gave to each book
	float ortalama;		// Average of the points awarded
	char isim[5];		// user name
};

// For book titles
struct node2{
	char ad[100];	// Book title
};

int kitapSayisi;	// Total number of books
int userNumber=0;	// Total number of users (U) (U1.....U20 )

float sim(struct node *kitap, int kisi1, int kisi2);


// finds most similar K contacts requested
void kisiSort(struct node *kitap, int kisi, int k, int *enBenzer){
	float benzerlik[100];		// similarity of other persons with respect to the specified person
	float temp1;	// for swap 
	int temp2;		// for swap
	int max;	// index of the most similar person identified that moment
	int i;
	int j;
	
	for(i=0; i<userNumber; i++){
		benzerlik[i]=sim(kitap,kisi,i);
		enBenzer[i]=i;
	}
	
	for (i=0; i<k; i++){ 
        max = i; 
        for (j=i+1; j<userNumber; j++) {
			if (benzerlik[j] > benzerlik[max]) {
				max = j; 				
			}        	
		}
		
		temp1 = benzerlik[max]; 
    	benzerlik[max] = benzerlik[i]; 
    	benzerlik[i] = temp1; 
		
		temp2 = enBenzer[max]; 
    	enBenzer[max] = enBenzer[i]; 
    	enBenzer[i] = temp2;
    }
}

// Prediction algorithm
// returns prediction value
float pred(struct node *kitap, int a, int book, int k, int *enBenzer){
	float toplam1=0;		// Sum of the denominator in the formula
	float toplam2=0;		// sum of the numerator in the formula
	float similarity;		// Instead of calling functions over and over, we'll use this to assign it to the variable
	float sonuc=kitap[a].ortalama;		// Average value in the formula
	int b;		// The index numbers of the most similar persons in the formula will be kept
	int i;	
		
	kisiSort(kitap,a,k,enBenzer);
	
	for(i=0; i<k; i++){
		b=enBenzer[i];
		similarity=sim(kitap,a,b);	
		toplam1+=similarity*(kitap[b].puan[book]-kitap[b].ortalama);
		toplam2+=similarity;
	}
	
	sonuc+=toplam1/toplam2;
	
	return sonuc;
}

// Similarity algorithm
// retun Person Coefficient 
float sim(struct node *kitap, int kisi1, int kisi2){
	float toplam1=0;		// the numerator in the formula
	float toplam2=0;		// The first sum in the denominator in the formula
	float toplam3=0;		// The second sum in the denominator in the formula
	float ortalama1=0;		// Average of books that kisi1 read jointly with kisi2
	float ortalama2=0;		// Average of books that kisi2 reads jointly with kisi1
	float katsayi;		//Person Coefficient
	int count=0;		//for average calculation
	int j;	//index of each book
	
	for(j=0; j<kitapSayisi; j++){
		if(kitap[kisi1].puan[j]!=0.0 && kitap[kisi2].puan[j]!=0.0){
			ortalama1+=kitap[kisi1].puan[j];
			ortalama2+=kitap[kisi2].puan[j];
			count++;
		}
	}
	
	ortalama1/=count;
	ortalama2/=count;	
	
	for(j=0; j<kitapSayisi; j++){
		if(kitap[kisi1].puan[j]!=0.0 && kitap[kisi2].puan[j]!=0.0){
			toplam1+=(kitap[kisi1].puan[j]-ortalama1)*(kitap[kisi2].puan[j]-ortalama2);
			toplam2+=(kitap[kisi1].puan[j]-ortalama1)*(kitap[kisi1].puan[j]-ortalama1);
			toplam3+=(kitap[kisi2].puan[j]-ortalama2)*(kitap[kisi2].puan[j]-ortalama2);
		}
	}
	
	katsayi=toplam1/(sqrt(toplam2)*sqrt(toplam3));
	
	return katsayi;
}

// Data input
void input(struct node *kitap,struct node2 *kitapIsmi){
	int count;		// Index
	FILE *fp;		// Input file
	char tempc;		// to extract data from the file
	char control;	// Performs the necessary check if the file with the .csv extension has spaces between semicolons or if there are no 0
	float toplam;	// To find the average of the points given by each user
	int i;
	int j;	// index of book
	
	fp=fopen("RecomendationDataSet.csv","r");
	if (fp == NULL) {
		printf("Error opening file RecomendationDataSet.csv\n");
		exit ( 1 );
	}
	
	while(tempc!=';'){
		fscanf(fp,"%c",&tempc);
	}
	i=0;
	while(tempc!='\n'){
		count=0;
		fscanf(fp,"%c",&tempc);
		while(tempc!=';' && tempc!='\n'){
			kitapIsmi[i].ad[count]=tempc;
			count++;
			fscanf(fp,"%c",&tempc);
		}
		i++;
	}
	kitapSayisi=i;
	
	i=0;
	while(!feof(fp)){
		count=0;
		do{
			fscanf(fp,"%c",&tempc);
			if(tempc!=';'){
				kitap[i].isim[count]=tempc;
				count++;
			}
		}while(tempc!=';' && !feof(fp));
		
		toplam=0;
		j=0;
		count=0;
		while(tempc!='\n' && !feof(fp)){
			control=tempc;
			fscanf(fp,"%c",&tempc);			
			if(tempc >='0' && tempc<='9'){
				kitap[i].puan[j]=tempc-'0';
				toplam+=kitap[i].puan[j];
				if(kitap[i].puan[j]!=0){
					count++;
				}
				j++;
			}
			else if(tempc==';' && (control<'0' || control>'9')){
				kitap[i].puan[j]=0;				

				j++;
			}
		}

		if(count!=0){
			kitap[i].ortalama=toplam/count;	
		}

		while(kitapSayisi!=j){
			kitap[i].puan[j]=0;
			j++;
		}
		i++;
	}
	
	fclose(fp);
	
}

// Generated output for each user
void display(struct node *kitap, struct node2 *kitapIsmi, int NU, int k, int *enBenzer){
	int i;		// The most similar people
	int j;		// index of book
	int U;		// The index of the most similar person
	float begenme;		// To keep the prediction value
	float max=-1;		//the Sort variable to find the maximum forecast
	char maxKitap[100];		//Variable to keep the title of the book to be recommended
	
	printf("\n%s kullanicisina en yakin kullanicilar(k=%d) ve hesaplanan pearson benzerlikleri sirasiyla:\n",kitap[NU].isim,k);
	kisiSort(kitap,NU,k,enBenzer);
	for(i=0; i<k; i++){
		U=enBenzer[i];
		printf("%d. '%s' , %f \n",i+1,kitap[U].isim,sim(kitap,NU,U));		
	}
	
	printf("%s kullanicisinda okunmamis olan kitaplar icin hesaplanan tahmini begenme degerleri:\n",kitap[NU].isim);
	for(j=0; j<kitapSayisi; j++){
		if(kitap[NU].puan[j]==0){
			begenme=pred(kitap,NU,j,k,enBenzer);
			printf("-> '%s' , %f \n",kitapIsmi[j].ad,begenme);		
			if(begenme>max){
				max=begenme;
				strcpy(maxKitap,kitapIsmi[j].ad);
			}
		}
	}
	
	printf("Sonuc olarak onerilen kitap: %s\n",maxKitap);
	printf("_______________________________________________________________________________________________________________\n");	
	
}

/*	    METHOD 1	*/	
// Performs desired operations for all NU users
void yontem1(struct node *kitap, struct node2 *kitapIsmi, int k, int *enBenzer){
	int i;
	for(i=0; i<boyut; i++){
		if(kitap[i].isim[0]=='N'){
			display(kitap,kitapIsmi,i,k,enBenzer);
//			delay(1000);
		}
	}
}

/*  	METHOD 2	*/					
// person of NU desired by the user and output according to k
void yontem2(struct node *kitap, struct node2 *kitapIsmi, int k, int *enBenzer){
	char oner[6];
	int i;
	
	printf("\n---------------------------------------------------------------------------------------------------------------\n");	
	printf("_______________________________________________________________________________________________________________\n");	
	
	printf("\n\nKitap onerisi yapilacak kullanici (NU) adini giriniz: ");
	scanf("%s",oner);
	
	printf("Benzer kullanici sayisini (k) giriniz:");
	scanf("%d",&k);
	
	// We find the index of the desired NU person
	i=0;
	while(strcmp(oner,kitap[i].isim) && i<boyut){
		i++;
	}
	display(kitap,kitapIsmi,i,k,enBenzer);
}

int main(){
	struct node *kitap;			// the actual structure from which we will get the data
	struct node2 *kitapIsmi;	// The structure we will take the names of the books
	int *enBenzer;			// The array to be used for the Sort
	int k=3;			// value of k
	int i;
	
	kitap=(struct node*)calloc(boyut,sizeof(struct node));			// Data
	kitapIsmi=(struct node2*)calloc(boyut,sizeof(struct node2));	// Data
	enBenzer=(int*)calloc(boyut,sizeof(int));			
	
	input(kitap,kitapIsmi);		// getting input from file
	
	/* The number of NU is determined */
	i=0;
	while(i<boyut){
		if(kitap[i].isim[0]=='U'){
			userNumber++;
		}
		i++;
	}
	
	// I added 2 different methods because you want different requests in different documents you shared
	yontem1(kitap, kitapIsmi, k, enBenzer);
	yontem2(kitap, kitapIsmi, k, enBenzer);
	
	free(kitap);
	free(kitapIsmi);
	free(enBenzer);
	
	return 0;
}
