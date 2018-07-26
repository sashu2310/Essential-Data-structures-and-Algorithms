#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};

// creating new alias as a type for struct node      
struct node *head = NULL;

// snode* create_node(){           //creating node through dynamic memory allocation
//     snode *temp;
//     temp = (snode*) malloc(sizeof(snode));  //malloc() function returns the address of the memory location from heap section
//     temp->next = NULL;
//     return temp;
// }

int list_length() {
    struct node *temp = head;
    int length=0;
    while(temp!=NULL)
        length++;
    return length;
}

void insert_at_tail(int data) {     //inserting node at the end of the linked list
    struct node *temp, *current;
    temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if(head == NULL) 
        head = temp;
    else {
        current = head;
        while(current!=NULL) {
         current = current->next; }
         current->next = temp;
    }
}
void insert_at_head(int data)
{
    struct node *temp, *p;
    temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if(head==NULL) {
        head = temp;
    }
    else
    {
        p = head;
        temp->next = p;
        head = temp;
    }
}
void insert_at_position(int data,int position) {
    struct node *temp,*p;
    //considering 1 as the first position 
    if(list_length()<position)  {
        printf("Not enough long");
        return;
    }
    //if position is at the end
    else if(list_length()==position)
        insert_at_tail(data);
    // if list is empty yet
    else if(position==1)
        insert_at_head(data);
    else {
    temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    p = head;
    position--;
    // drive to the one node before the position
    while(position--) {
        p = p->next;
    }
    //link new node to it's neighbour
    temp->next = p->next;
    //link previous node to new node
    p->next = temp;
    }
}

void delete_at_tail() {
    
}

void print(){                   //printing all the members of the linked list
    struct node *temp = head;
    while(temp!=NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
int main(){
	int n,data;
	scanf("%d", &n);              		// No. of elements to be inserted 
	while(n--) {
	    scanf("%d",&data);
	    insert_at_tail(data);
	}      
	print();                    //printing
}
