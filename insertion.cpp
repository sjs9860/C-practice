#include <iostream>
#include <cstdio>
using namespace std;

// print the result of each sorting step
void printSequence(int a[], int n, int i){
  cout<<i <<": ";
  for(int j=0; j<n; j++){
    cout<<a[j]<<" ";
  }
  cout<<endl;
}
/*
// we get a pointer, when array passed  as a formal parameter 
// so we need a length to the data pointed by the pointer
void insertionSort(int *a,int n){  
  for(int i=1; i<n; i++){
    if(a[i]<a[i-1]){
      int j=i-1;
      int watcher=a[i]; //copy the insertion element
      while(j>-1 && watcher<a[j]){
        a[j+1]=a[j];
        j--;
      }
      a[j+1]=watcher;
    }
    printSequence(a,n,i);
  }
}
*/
int* insertionSort(int *a,int n){
  //int size=sizeof(a)/sizeof(a[0]);
  //for(int i=1; i<size; i++){
  //cout<<sizeof(a)<<" "<<sizeof(a[0])<<endl;
  for(int i=1; i<n; i++){
    if(a[i]<a[i-1]){
      int j=i-1;
      int watcher=a[i]; //copy the insertion element
      while(j>-1 && watcher<a[j]){
        a[j+1]=a[j];
        j--;
      }
      a[j+1]=watcher;
      printSequence(a,n,i);
    }
    //printSequence(a,n,i);
    //printSequence(a,size,i);
  }
  return a;
}

// we get a pointer, when array passed  as a formal parameter 
// so we need a length to the data pointed by the pointer
int* insertionSort1(int *a,int n){  
  for(int i=1; i<n; i++){
    //if(a[i]<a[i-1]){
      int j=i-1;
      int watcher=a[i]; //copy the insertion element
      while(j>-1 && watcher<a[j]){
        a[j+1]=a[j];
        j--;
      }
      a[j+1]=watcher;
    //}
    printSequence(a,n,i);
  }
  return a;
}

int main(){
  int a[9]={3,1,5,7,2,4,9,6,10};
  int n=sizeof(a)/sizeof(a[0]);
  int *b=insertionSort(a,n);
  //char *str=NULL;
  //cout<<"sizeof(char*) = "<<sizeof(str)<<endl;
  //printSequence(b,9,0);
  printSequence(a,9,0);
}
