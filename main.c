#include <stdio.h>
#include <stdlib.h>
#include "SRM_header.h"

int main(){
printf("-------------------------------------------------------------------------------------------------------\n");

printf("WELCOME TO THE STUDENT RECORD MANAGEMENT.\nHers's what the application provide.\nThis application provides a Students Record text file that includes their names and marks\nHere is the list of functions you can do with this application\n");
printf("-------------------------------------------------------------------------------------------------------\n");
printf("create a new record list		Press 0.\nAdd a node in the existing list		Press 1.\nDelete a node in the existing list	Press 2.\nsort an existing list with marks	Press 3.\n");
printf("-------------------------------------------------------------------------------------------------------\n");

struct node* (*function_ptr[4]) (struct node*)={create_list,update_list,delete_list,sort_the_list};
struct node* head	= 	NULL;

int option;
printf("Enter the number : ");
scanf("%d",&option);



head			=	function_ptr [option] (head);

}

