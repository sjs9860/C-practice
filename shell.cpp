#include <iostream>
using namespace std;

void printSequence(int a[], int n, int i){
  cout<<i <<": ";
  for(int j=0; j<n; j++){
    cout<<a[j]<<" ";
  }
  cout<<endl;
}

/******************************************************
 *
 * 缩小增量的划分排序 
 *
******************************************************/

void shellSort(int *a, int n){
  int d,i,j,watcher;
  for(d=n/2; d>=1; d=d/2)
    for(i=d; i<n; i++){
      watcher=a[i];
      for(j=i-d; j>-1 && a[j]>watcher; j=j-d)
        a[j+d]=a[j];
      a[j+d]=watcher;
    }
}

int main(){
  int a[5]={3,2,5,6,4};
  printSequence(a,5,0);
  shellSort(a,5);
  printSequence(a,5,0);
  return 0;
}
