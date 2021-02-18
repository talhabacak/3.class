#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define M 997
#define MM M-1

//The structure where the hash table is kept
struct hashTable {
	int kelime;				//numerical value of the word
	char dokuman[200];		//name of documents
};

//When the program runs, it reads the hash table if there is one before
//loadFactor return as return value
float readData(struct hashTable *hashT){
	FILE *table;	//hash table in the file it contains
	int i;		//To indicate the location in the hashT array
	float loadFactor;	//fullness rate
	
	table = fopen( "16011038.txt", "r" );
	if (table != NULL) {
		fscanf(table, "%f",&loadFactor);
		if (loadFactor>=0.8){
			printf("!!!UYARI!!! Loadfactor >= 0.8\n");
		}
		
		printf("LoadFactor: %f\n",loadFactor);

		i=0;
		while(!feof(table) && i<M){
			fscanf(table, "%d",&hashT[i].kelime);
			if(hashT[i].kelime!=0){
				fscanf(table, "%s",&hashT[i].dokuman);
			}
			i++;
		}
	}
	else{
		loadFactor=0;
	}
	
	fclose(table);

	return loadFactor;
}

//writes the hash table to the file
void writeData(struct hashTable *hashT,	float loadFactor){
	FILE *table;	//file containing hash table
	int i;		//to indicate the location in the hashT array
	
	table = fopen( "16011038.txt", "w" );
	if (table == NULL) {
		printf("Error opening file 16011038.txt\n");
		exit ( 1 );
	}
		
	fprintf(table,"%f\n",loadFactor);
	for(i=0; i<M; i++){
		fprintf(table,"%d",hashT[i].kelime);
		fprintf(table, "%s\n",hashT[i].dokuman);
	}

	fclose(table);
}

//Adds words from file to hash table
//return value is loadFactor
float add(struct hashTable *hashT, float loadFactor){
	char filename[30];	//name of the file to be added
	char word[30];		//word that cannot be added (if loadFactor = 1, print to the screen)
	char str[30];		//word taken from file
	int key;		//numerical value of the word
	int i;		//We use when searching the appropriate place in the hashT array
	int indis;		//where it is in the hashT array
	float toplam=loadFactor*M;		//total number of words in hashT array
	FILE *file;			//file to attach
		
	//getting input from file
	printf("\neklemek istediginiz dosya ismini giriniz\n");
	scanf( "%s", filename );
	
	file = fopen( filename, "r+" );
	if (file == NULL) {
		printf("Error opening file %s.\n",filename);
		exit ( 1 );
	}
		
	while(!feof(file)){
		fscanf(file,"%s",str);
		strcpy(word,str);
		key=horners(str);
		i=0;
		indis=h(key,i);
		while(hashT[indis].kelime!=key && hashT[indis].kelime!=0 && i<M){
			i++;
			indis=h(key,i);
		}
		if(hashT[indis].kelime==0){
			if(loadFactor<1.0){	
				hashT[indis].kelime=key;
				strcat(hashT[indis].dokuman,"-");
				strcat(hashT[indis].dokuman,filename);
			
				toplam++;
				loadFactor=toplam/M;
				if (loadFactor>=0.8){
					printf("!!!UYARI!!! Loadfactor > 0.8\n");
				}
			}
		}
		else if(hashT[indis].kelime==key){
			strcat(hashT[indis].dokuman,"-");
			strcat(hashT[indis].dokuman,filename);
		}
		if(loadFactor>=1){
			printf("%s\n",word);			
		}
	}
	
	writeData(hashT,loadFactor);
	
	printf("LoadFactor: %f\n",loadFactor);
	if(loadFactor<1){
		printf("dosya eklendi\n");
	}
	else{
		printf("dosyanin bir kismi eklenemedi\n");		
	}
	
	fclose(file);
	
	return loadFactor;
}

//finds the desired word
void search(struct hashTable *hashT){
	int indis;		//where it is in the hashT array
	int i=0;		//We use when searching the appropriate place in the hashT array
	unsigned long int key; //numerical value of the word
	char find[30];		//searched word
	
	printf("\nbulmak istediginiz kelimeyi giriniz\n");
	printf("Find: ");						
	scanf("%s",&find);	
	key=horners(find);
	indis=h(key,i);
	while(hashT[indis].kelime!=key && hashT[indis].kelime!=0 && i<M){
		i++;
		indis=h(key,i);
	}					
	
	if(hashT[indis].kelime==key){
		printf("aradiginiz kelime %d. adimda bulundu, su dokumanlarda bulunmaktadir:\n",i+1);
		printf("%s\n",hashT[indis].dokuman);
	}
	else{
		printf("aradiginiz kelime bulunamadi\n");
	}	
}

//Converting word to numerical value with horners text
//return value is this numerical value
int horners(char str[]){
	unsigned long int key=0;	//the value of the word
	int R=5;					//prime number constant
	int L=strlen(str);			//size of word
	int i;		//which letter is in the word

	for(i=0; i<L; i++){
		if(str[i]>96){
			str[i]-=96;
		}
		else{
			str[i]-=64;			
		}
		key+=pow(R,L-1-i)*str[i];
	}
	
	return key;
}

//double hash method
//return value is hash value
int h(int key, int i){
	int temp;	//variable that temporarily holds the intermediate result
	temp= h1(key)+i*h2(key);
	
	return temp%M;
}

//2.hash function
//return value is 2nd hash value
int h2(int key){
	return 1+(key%MM);
}

//1. hash function
//return value is 1st hash value
int h1(int key){
	return key%M;
}

//The process of selecting the desired state
void choose(struct hashTable *hashT,float loadFactor){
	int secim;	//choice status
	
	do{
		printf("\ndokuman eklemek icin 1'e, kelime aramak icin 2'ye, cikmak icin 3'e basiniz\n");
		scanf("%d",&secim);
		if(secim==1){
			loadFactor=add(hashT,loadFactor);
		}
		else if(secim==2){
			search(hashT);
		}	
	}while(secim!=3);
}

int main(){
	struct hashTable *hashT;		//place where to keep the hash table
	float loadFactor;		//occupancy rate of hash table
	
	hashT=(struct hashTable*)calloc(M,sizeof(struct hashTable));
	loadFactor=readData(hashT);
	choose(hashT,loadFactor);
	free(hashT);
	
	return 0;
}
