#include <stdio.h>
#include <stdlib.h>
#include "SRM_header.h"

/*---------------------------------------------------------------------------------------------------------*/

int scanff (char name[],int n){
while (getchar() != '\n'); 
int ch, i=0;
while( (ch = getchar()) != '\n'){
if (i < n){
	name[i++]=ch;
}
}
name[i]='\0';	
return i;	
}

/*---------------------------------------------------------------------------------------------------------*/

/* This "add_to_empty" funtion create a signle node.*/

struct node* add_to_empty(struct node* head, int data){

struct node* temp	=	malloc(sizeof(struct node));
temp->Prev		=	NULL;
temp->data		=	data;
temp->Next		=	NULL;

head			=	temp;
return head;

}
/*End of the add_to_empty_function.*/

/*---------------------------------------------------------------------------------------------------------*/

/* This "add_at_end" funtion takes two inputs.
1)Head pointer of the list, 
2)Data of the new node.
this function create a new node and add that node at the end of the given list.*/

struct node* add_at_end(struct node*head, int data){

struct node* ptr	=	head;	

struct node* temp	=	malloc(sizeof(struct node));
temp->Prev		=	NULL;
temp->data		=	data;
temp->Next		=	NULL;

if (ptr->Next == NULL){
ptr->Next	=	temp;
temp->Prev	=	ptr;
return head;
}

else{
while(ptr->Next != NULL){
ptr 	=	ptr->Next;	
}
temp->Prev		=	ptr;	
ptr->Next		=	temp;
return head;
}
}
/*End of the add_to_End_function.*/

/*---------------------------------------------------------------------------------------------------------*/

void read_the_list(struct node* head){

int n=0;
struct node* ptr	=	head;
if (ptr == NULL){
printf("No data - The list is empty !!");
}

else{

while(ptr != NULL){

n++;
printf("The data of node %d is : %d\n",n,ptr->data);
ptr	=	ptr->Next;

}
}
}

struct node* add_at_begining(struct node* head, int data){

struct node* temp	=	malloc(sizeof(struct node));
temp->Prev		=	NULL;
temp->data		=	data;
temp->Next		=	NULL;

temp->Next		=	head;
head			=	temp;
return head;
}


struct node* delete_at_begining(struct node* head){
struct node* ptr 	=	head;

head			=	ptr->Next;
head->Prev		=	NULL;

free(ptr);

ptr			=	NULL;
return head;
}

struct node* delete_at_end(struct node* head){

struct node* ptr 	=	head;
while(ptr->Next != NULL){

ptr			=	ptr->Next;

}

ptr->Prev->Next		=	NULL;

free(ptr);

ptr			=	NULL;
return head;
}


struct node* delete_at_certain_position(struct node* head){

int position;
printf("Enter the position of the node you want to delete\n");
scanf("%d",&position);

struct node* ptr 	=	head;



if (position == 1){
head			=	delete_at_begining(head);
return head;
}

else{
while(position != 1){
ptr			=	ptr->Next;
position--;
}

if (ptr->Next == NULL){
head 			=	delete_at_end(head);
return head;
}

else{

ptr->Prev->Next        =    ptr->Next;
ptr->Next->Prev        =    ptr->Prev;

free(ptr);

ptr			=	NULL;
return head;

}
}
}


struct node* delete_the_matching_node(struct node* head, int key){
//printf("Hello");
struct node* temp1	=	head;
	while(temp1 != NULL){

		if(temp1->data	==	key){

			 if (temp1->Prev == NULL && temp1->Next == NULL){
                		free(temp1);
                		return NULL;
}                       
			else if (temp1->Next == NULL){
				temp1->Prev->Next	=	NULL;
				free(temp1);
				temp1=NULL;
				return head;

}
			else if(temp1->Prev == NULL){
				temp1->Next->Prev	=	NULL;
				head			=	head->Next;
				free(temp1);
				temp1=NULL;
				return head;
}

			else{
				temp1->Prev->Next 	=	temp1->Next;
				temp1->Next->Prev	=	temp1->Prev;
				free (temp1);
				temp1			=	NULL;
				return		head;
}
}
		else{
			temp1			=	temp1->Next;
}			

		
}
return head;
}


struct node * file_read(struct node* head){

char path [100];
printf("Enter the file path : \n");
scanff(path, (sizeof(path)));

int data;

FILE *fp	=	fopen(path,"r");

if (fp		==	NULL){
printf("Incorrect path name.");
}

else {
	fscanf(fp, "the mark is %d\n",&data);
	head = add_to_empty(head,data);
	while((fscanf(fp, "the mark is %d\n",&data))	== 1){
		head = add_at_end(head,data);

	}
     }
return		head;
}


void file_write(struct node* head){

struct node* ptr 	=	head;

char path [100];
printf("Enter the file path : \n");
scanff(path, (sizeof(path)));

FILE *fp	=	fopen(path,"w");

if (fp		==	NULL){
printf("Incorrect path name.");
}
 
else if (head == NULL){
printf("No data - The list is empty !!");
}

else {
	while(ptr != NULL){
	fprintf(fp, "the mark is %d\n",ptr->data);
	ptr	=	ptr->Next;
	}
     }
}

