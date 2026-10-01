#include <stdio.h>
#include "SRM_header.h"

struct node* delete_list(struct node* head){	

head	=	file_read(head);
read_the_list(head);
int val;

printf("Enter which operation do you want to perform.\n");
printf("delete_the_first_node 			- Press 0.\n");
printf("delete_the_last_node 			- Press 1.\n");
printf("delete_a_node_at_certain_position	- Press 2.\n");
scanf("%d",&val);

if (val == 0){
head 		=	delete_at_begining(head);
file_write(head);
return head;
}

else if (val == 1){
head 		=	delete_at_end(head);
file_write(head);
return head;
}

else if (val == 2){
head 		=	delete_at_certain_position(head);
file_write(head);
return head;
}

else {
printf("The entered value is invalid.");
}
}
