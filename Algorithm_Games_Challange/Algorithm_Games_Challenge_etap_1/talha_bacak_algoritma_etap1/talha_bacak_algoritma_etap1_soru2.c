#include <stdio.h>

struct node{
    int val;
    struct node *next;
};


struct node *del(struct node* head, int k){
	struct node* current = head;
	struct node* before;
	int i;
	
	i = 0;
	while(i < k){
		before = current;
		current = current->next;
		i++;
	}

	before->next = current->next;
	free (current);
	
	return before;
}

struct node *findStart(struct node* head, int start){
	struct node* current = head;
    while (current->val != start) {
        current = current->next;
    }
	
	return current;
}

struct node *findEnd(struct node* head){
	struct node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
	
	return current;
}

void circular(struct node* head){
	struct node* current = head;
    current = findEnd(current);
    current->next = head;
}

void push(struct node *head, int val) {
    struct node* current = head;
    
    current = findEnd(current);
    
    current->next = malloc(sizeof(struct node));  	
    current->next->val = val;					
    current->next->next = NULL;					
}


int main(){
	int N;
	int start;
	int k;
	struct node *head;
	int i;
	
	head = malloc(sizeof(struct node));
	
	printf("N sayisini giriniz:\n");
	scanf("%d",&N);
	printf("k degerini giriniz:\n");
	scanf("%d",&k);
	printf("start degerini giriniz:\n");
	scanf("%d",&start);
	
	head->val = 1;
	head->next = NULL;
	
	for(i = 2; i <= N; i++){
		push(head, i);
	}
	circular(head);
	head = findStart(head, start);
	
	while(N > 1){
		head = del(head, k);
		N--;
	}
	
	printf("\ncikti = %d\n",head->val);
	
	free(head);
	
	return 0;
}
