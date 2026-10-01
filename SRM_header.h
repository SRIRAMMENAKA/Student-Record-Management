#ifndef SRM_header
#define SRM_header

struct node {
struct node * Prev;
int data;
struct node * Next;
};

struct node* create_list(struct node*);		

struct node* update_list(struct node*);

struct node* sort_the_list(struct node*);

struct node* delete_list(struct node*);	

/*---------------------------------------------------------------------------------------------------------*/

int scanff(char *,int);

struct node* add_to_empty(struct node *, int);

struct node* add_at_end(struct node *, int);

void read_the_list(struct node*);

struct node* add_at_begining(struct node*, int);

struct node* delete_at_end(struct node*);

struct node* delete_at_begining(struct node*);

struct node* delete_at_certain_position(struct node*);

struct node* delete_the_matching_node(struct node*, int);

void file_write(struct node*);

struct node * file_read(struct node* head);

void file_write(struct node* head);



#endif 