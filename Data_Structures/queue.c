#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

//insertion at the tail only
void enqueue(int data) {
    struct node *temp,*p; 
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if(head == NULL)
        head=temp;
    else {
        p = head;
        while(p != NULL)
         p=p->next;
        p->next=temp;
    }
}

//deletion from the head only
void dequeue() {
    struct node *temp=head;
    head = temp->next;
    free(temp);
}

void print() {
    struct node *temp = head;
    while(temp!==NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}

int main() {
    int n,element,i;
    scanf("%d",&n);
    while(n--) {
        scanf("%d",&element);
        enqueue(element);
    }
    print();
    dequeue();
    print();
    return 0;
}
