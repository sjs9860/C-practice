#include <iostream>
#include <cstdio>
using namespace std;

void printSequence(int a[], int n, int i){
  cout<<i <<": ";
  for(int j=0; j<n; j++){
    cout<<a[j]<<" ";
  }
  cout<<endl;
}

/*************************************************
 *
 * heap sort needs the index starts from 1
 *
**************************************************/

void heapAdjust(int *a, int k, int m){
  int head,child,temp;
  head=k; child=2*head+1;
  while(child<m){
    //get the largest child;
    if(child+1<m&&a[child+1]>a[child]) child++;
    //adjust head and child
    if(a[child]>a[head]){
      temp=a[child]; a[child]=a[head]; a[head]=temp;
      head=child; child=2*head+1;
    }
    else break;
  }
}

void heapSort(int* a,int n){
  int i,temp;
  //initialize heap
  cout<<"Initialize heap:"<<endl;
  for(i=(n-1)/2; i>-1; i--){
    heapAdjust(a,i,n);
    printSequence(a,n,i);
  }
  //sorting
  cout<<"Start sorting:"<<endl;
  for(i=0;i<n;i++){
    //move top element of the heap to the end
    temp=a[0]; a[0]=a[n-i-1]; a[n-i-1]=temp;
    printSequence(a,n,i);
    //rebuild the heap
    heapAdjust(a,0,n-i-1);
    printSequence(a,n,i);
  }
}

int main(){
  int a[9]={3,1,5,7,2,4,9,6,6};
  //int a[5]={5,9,3,7,1};
  //int a[5]={5,7,9,3,1};
  //int a[5]={5,3,9,7,1};
  int n=sizeof(a)/sizeof(a[0]);
  heapSort(a,n);
  printSequence(a,n,0);
}
