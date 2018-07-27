#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *top = NULL;

void push(int data) {
    struct node *temp,*p; 
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    p = top;
    temp->next = p;
    top = temp;
}

void pop() {
    if(top == NULL)
    {
        printf("Empty stack\n");
        return;
    }
    struct node *temp=top;
    top = temp->next;
    print("%d",temp->data);
    free(temp);
}

int main() {
    int n,element,i;
    scanf("%d",&n);
    while(n--) {
        scanf("%d",&element);
        push(element);
    }
    pop();
    return 0;
}
