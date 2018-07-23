#include <stdio.h>

struct node {
    int data;
    struct link_list *next;
};
typedef struct node snode;      // creating new alias as a type for struct node
snode *head = NULL;

snode* create_node(){           //creating node through dynamic memory allocation
    snode *temp;
    temp = (snode*) malloc(sizeof(snode));  //malloc() function returns the address of the memory location from heap section
    temp->next = NULL;
    return temp;
}

int list_length() {
	int length=0;
	node *temp = head;
	while(temp!=Null) {
		length++;
		temp=temp->next; }
	return length;
		
}

void insert_at_tail(int data) {     //inserting node at the end of the linked list
    snode *temp, *p;
    temp = create_node();
    temp->data = data;
    if(head == NULL) {
        head = temp;
    }
    else {
        p = head;
        while(p!=NULL) {
         p = p->next; }
         p->next = NULL;
    }
}

void insert_at_head(int data)		// Insert the newly created node at the beginning of the list
{
    snode *temp, *p;
    temp = create_node();
    temp->data=data;
    if(head==NULL) {
        head = temp;
    }
    else
    {
        p=head;
        temp->next=p;
        head=temp;
    }
}

void insert_at_position(int data,int position) {	//Insert the newly created node at any specified position 
    int length;
    node *temp,*p;
    temp=create_node();
    temp->data = data;
    p = head;
    if(length = list_length()<position-1)    	//checking whether list is long enough
	    printf("Position doesn't exists");
    while(temp!=NULL || i<position) {
        p = p->next;
    }
    temp->next = p->next;
    p->next = temp;
}

void print(){                   //printing all the members of the linked list
    snode *temp = head;
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
