#include <stdio.h>
#include <stdlib.h>
#include "SRM_header.h"


struct node* sort_the_list(struct node* head){
	head	=	file_read(head);
	read_the_list(head);
	//printf("before while welcome\n");

	struct node*	temp	=	NULL;
	struct node*	temp2	=	head;
	struct node*	new_head =	NULL;
		

	while(temp2 !=	NULL){
			
			temp		=	temp2;
			int key		=	temp->data;
			while(temp->Next != NULL){
				
				if(temp->Next->data < key){
					key	=	temp->Next->data;
					temp	=	temp->Next;

				}
				else{
					temp	=	temp->Next;
				
				}
			}
			if (new_head == NULL){
				new_head	=	add_to_empty(new_head, key);	
				}
			else{
				new_head	=	add_at_end(new_head, key);
				}

			temp2			=	delete_the_matching_node(temp2,key);
		}
		read_the_list(new_head);
		file_write(new_head);
		return new_head;
}




