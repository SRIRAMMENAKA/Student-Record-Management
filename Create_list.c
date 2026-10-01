#include <stdio.h>
#include "SRM_header.h"

struct node* create_list(struct node* head){

int n, data,i;
printf("Enter the Number of nodes\n");
scanf("%d",&n);
printf("Enter the 1st node Data\n");
scanf("%d",&data);

head		=	add_to_empty(head, data);

for(i=1; i<n; i++){
printf("Enter the %d node Data\n",i+1);
scanf("%d",&data);

head	=	add_at_end(head,data);
}
file_write(head);
return head;
}


