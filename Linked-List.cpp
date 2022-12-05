#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

int addNode(int data){
	
	if(head==NULL){
		struct node *newNode = (struct node *)malloc(sizeof(struct node));
		newNode->data = data;
		newNode->next = NULL;
		head = tail = newNode;
	}
	else{
	
		struct node *newNode = (struct node *)malloc(sizeof(struct node));
		newNode->data=data;
		newNode->next=NULL;
		tail->next = newNode;
		tail = newNode;
	}
}

int addNodeHead(int data){
		
		if(head==NULL){
			struct node *newN = (struct node *)malloc(sizeof(struct node));
			newN->data=data;
			newN->next=NULL;
			head = tail = newN;
		}
		else{
			struct node *newN = (struct node *)malloc(sizeof(struct node));
			newN->data=data;
			newN->next=head;
			head=newN;
		}
}

int print(){
	
	struct node *index = head;
	
	while(index!=NULL){
		printf("%d ",index->data);
		index = index->next;
	}	
}

int deleteNode(int data){

	struct node *prev = NULL;
	struct node *index = head;
	
	if(head==NULL){
		
		printf("Linked-List Bos\n");
		
	}	

	if(head->data==data){
		struct node *temp = head;
		head = head->next;
		free(temp);
	}
	
	while(index!=NULL&&index->data!=data){
		prev = index;
		index = index->next;
	}
	
	if(index==NULL){
		printf("Data Not Found.\n");
	}
	
	prev->next=index->next;
	
	if(tail->data==data){
		tail = prev;	
	}
	
	free(index);
}

int main(){
	
	addNode(10);
	addNode(15);
	addNode(20);
	addNode(25);
	
	addNodeHead(50);
	addNodeHead(40);
	
	print();
	
	printf("\n");
	
	deleteNode(10);
	print();
	printf("\n");
	deleteNode(123);
		
}
