#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};

// creating new alias as a type for struct node      
struct node *head = NULL;

//Finding length of our linked list
int list_length() {
    struct node *temp = head;
    int length=0;
    while(temp!=NULL) {
        length++;
	temp=temp->next;
    }
    return length;
}

 //inserting node at the end of the linked list
void insert_at_tail(int data) {    
    struct node *temp, *current;
    temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if(head == NULL) 
        head = temp;
    else {
        current = head;
        while(current!=NULL) {
         current = current->next; 
         }
         current->next = temp;
    }
}

//inserting node at the beginning of the linked list
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

//Inserting at specified position
void insert_at_position(int data,int position) {
    struct node *temp,*p,*temp1;
    int k=1;
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
        temp->next = NULL;
        temp1 = head;
        // drive to the one node before the position
        while(p != NULL && k < position) {
            k++;
            p = temp1;
            temp1 = temp1->next;
        }
        //link new node to it's neighbour
        temp->next = temp1;
        //link previous node to new node
        p->next = temp;
    }
}

void delete_node(int position) {
    struct node *temp = head, *temp1;
    int k = 1;
    //considering 1 as the first position
    if(position<1 || list_length()<position || head==NULL)
    {
        printf("Error\n");
        return;
    } 
    if(position==1)
    {
        head = NULL;
        free(temp);
    }
    else 
    {
        while(temp != NULL && k<position) { 
            temp1 = temp;
            temp = temp->next; 
            k++;
            }
        temp1->next=temp->next;
        free(temp);
    }
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
