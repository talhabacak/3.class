#include <stdio.h>

int main(){
	int sec;
	int i;
	int distance = 0;
	int flag = 0;
	char slot[100];
	
	printf("Slotlarin durumunu giriniz: ");
	scanf("%s", &slot);
	printf("Secilen slotu giriniz: ");
	scanf("%d", &sec);
	
	i=sec-1;
	while((slot[i+distance] != NULL || (i-distance) > -1) && flag == 0){
		if(slot[i+distance] == '1'){
			flag = 1;
			printf("%d\n", i+distance+1);		
		}
		else if(slot[i-distance] == '1'){
			flag = 1;
				printf("%d\n", i-distance+1);		
		}
		distance++;
	}
		
	if(flag == 0){
		printf("Urun bulunamdi\n");
	}
		
	return 0;
}
