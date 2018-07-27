#include<stdio.h>
#define MAX 100001;                 // Max size of stack
int stack [MAX];
int top=-1;                         // current stack is empty

void push(int data){                //function to push elements
    if(top==MAX) {
        printf("Overflow");
        return; }
    top++;                          //incrementing size
    stack[top] = data;              // storing data
}

int pop() {                         //function to remove elements from top
    int data;
    if(top==-1) {                   // When stack is empty
        printf("stack empty");
        return;
    }
    data = stack[top];               // extracting top element
    top--;                           //decrementing size
    return data;
}
 int main() {
   int choice,value;
   printf("Options: 1. Push 2. Pop\n");
   scanf("%d",&choice);
   if(choice==1)
    {
        printf("Enter value");
        scanf("%d",&value);
        push(value);
    }
    else if(choice==2)
        printf(pop());
    else
        printf("Wrong option");
    return 0;
 }
