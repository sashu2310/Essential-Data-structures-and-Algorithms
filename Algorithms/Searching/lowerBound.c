#include<stdio.h>
int lowerBound(int n,int key,int *A) {
    int start=0,end=n-1,mid,ans=-1;
    while(start < end) {
        mid = start+(end-start)/2;
 //key is greater than or equal check the left half
        if(A[mid]>=key) 
            end = mid;
//got the element, since elements on the left half will be surely lesser than the given element so lets move to right half to find
        else if(A[mid]<key) {
            ans = A[mid];
            start = mid+1;
        }
    }
return ans;
}
int main() {
    int A[5] = {2,3,4,6,6,8};
    printf("%d",lowerBound(5,6,&A[0]));
    return 0;
}
