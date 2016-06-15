#include <iostream>
using namespace std;

void printSequence(int a[], int n, int i){
  cout<<i <<": ";
  for(int j=0; j<n; j++){
    cout<<a[j]<<" ";
  }
  cout<<endl;
}

void bubbleSort(int *a, int n){
  int j,exchange,bound,temp;
  exchange=n-1;
  while(exchange){
    bound=exchange;
    for(j=0; j<bound; j++)
      if(a[j]<a[j+1]){
         temp=a[j+1]; a[j+1]=a[j]; a[j]=temp;
         exchange=j;
      }
    printSequence(a,n,j);
  }
}

int main(){
  int a[5]={3,2,5,6,4};
  printSequence(a,5,0);
  bubbleSort(a,5);
  printSequence(a,5,0);
  return 0;
}
