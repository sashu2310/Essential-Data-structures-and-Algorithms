#include<stdio.h>
//function implementing binary search algorithm 
int binarySearch(int n,int key) {
    int start=0,end=n-1,mid;
    while(start < end) {
        mid = start+end/2;
        //key found
        if(A[mid]==key)
            return mid;
        //key is small check the left half
        else if(A[mid]>key)
            end=mid-1;
        //key is greater check the right half
        else
            start=mid+1;
    }
return -1;
}
int main() {
    int n,i,key;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    printf("Enter number to be searched\n");
    scanf("%d",&key);
    //suppose array to be sorted
    printf("%d",binarySearch(n,key));
    return 0;
}
