#include<stdio.h>
//function implementing binary search algorithm 
int binarySearch(int n,int key,int *A) {
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
    int A[9] = {2,4,5,6,6,7,8,9,10};
    printf("%d",binarySearch(n,key,&A[0]));
    return 0;
}
