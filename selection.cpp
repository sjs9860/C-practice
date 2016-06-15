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

int* selectionSort(int a[],int n){
  int i,j,watcher,loc;
  for(i=0; i<n; i++){
    watcher=a[i];
    loc=-1;
    for(j=i+1; j<n; j++)
      if(watcher<a[j]){
        watcher=a[j]; loc=j;
      }
    if(loc>-1){
      a[loc]=a[i];
      a[i]=watcher;
    }
    printSequence(a,n,i);
  }
  return a;
}

int* selectionSort1(int a[],int n){
  int i,j,watcher,loc;
  for(i=0; i<n; i++){
    watcher=a[i];
    loc=i;
    for(j=i+1; j<n; j++)
      if(watcher<a[j]){
        watcher=a[j]; loc=j;
      }
    if(loc!=i){
      a[loc]=a[i];
      a[i]=watcher;
    }
    printSequence(a,n,i);
  }
  return a;
}

int main(){
  int a[9]={3,1,5,7,2,4,9,6,10};
  int n=sizeof(a)/sizeof(a[0]);
  //int *b=selectionSort(a,n);
  int *b=selectionSort1(a,n);
  printSequence(a,n,0);
}
