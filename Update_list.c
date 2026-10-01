#include <stdio.h>
#include <stdlib.h>
#include "SRM_header.h"

struct node* update_list(struct node* head){

head	=	file_read(head);
int position,data;
struct node* ptr	=	head;

printf("Enter the Position the new data to be added : ");
scanf("%d",&position);

printf("Enter the new data to be added : ");
scanf("%d",&data);


if (ptr == NULL){
printf("The list is Empty!!");
return head;
}

else if (position == 1){
head	=	add_at_begining(head,data);
file_write(head);
return head;
}

else{

struct node* temp	=	malloc(sizeof(struct node*));
temp->Prev		=	NULL;
temp->data		=	data;
temp->Next		=	NULL;

while (position != 1){
ptr	=	ptr->Next;
position--;	
}

ptr->Prev->Next		=	temp;
temp->Prev		=	ptr->Prev;
temp->Next		=	ptr;
ptr->Prev		=	temp;

file_write(head);
return head;
}
}


