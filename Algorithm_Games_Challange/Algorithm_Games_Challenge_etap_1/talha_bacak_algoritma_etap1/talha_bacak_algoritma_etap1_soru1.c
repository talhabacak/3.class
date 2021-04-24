#include <stdio.h>
#include <math.h>

int main(){
	int a;
	unsigned long long sayi;
	unsigned long long control;
	int flag = 1;
	int i;
	
	printf("bir a sayisi giriniz:\n");
	scanf("%d",&a);
	while(a < 1){
		printf("a 0 veya negatif olamaz, tekrar giriniz:\n");
		scanf("%d",&a);		
	}
	
	sayi = pow(10,a)-1;
	control = pow(10,a-1);
	
	while(flag == 1 && sayi > control){		
		i = 3;
		flag = 0;

                if(sayi % 2 == 0){
                        flag = 1;
                }
		while(flag == 0 && i <= sqrt(sayi)){
			if(sayi % i == 0){
				flag = 1;
			}
			i += 2; 
		}
		
		sayi -= 2;
	}
	
	printf("cikti: %llu",sayi+2);
	
	
	return 0;
}
