#include<stdio.h>
int lowerBound(int n,int key,int *A) {
    int start=0,end=n-1,mid,ans;
    while(start < end) {
        mid = start+end/2;
        //key found
        if(A[mid]>key) {
            ans = mid;
            end = mid-1;
        }
        //key is small check the left half
        else if(A[mid]<=key)
            start = mid+1;
    }
return ans;
}
int main() {
int A[9] = {0,2,3,4,5,5,6,7,8};
printf("%d",lowerBound(9,5,&A[0]));
return 0;
}
