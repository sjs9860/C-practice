#include <iostream>
using namespace std;

void printSequence(int a[], int n, int i){
  cout<<i <<": ";
  for(int j=0; j<n; j++){
    cout<<a[j]<<" ";
  }
  cout<<endl;
}

/****************************************************************************
 *
 * 0. take the first element as key element
 * 1. index i,j points to the start and end element of the sequence
 * 2. repeat till i equals j
 *    2.1. left scan, till finding a element less than key element (j--)
 *    2.2. change r[i](key) with r[j], i++
 *    2.3. right scan, till finding a element larger than key element (i++)
 *    2.4. change r[i] with r[j](key), j--
 * 3. break the loop, return the location of i
 *
****************************************************************************/

int partition(int *a, int first, int end){
  int i,j,temp;
  i=first; j=end;
  while(i<j){
    //right scan, a[i] is the key
    while(i<j&&a[i]<=a[j]) j--;
    if(i<j){
      temp=a[j]; a[j]=a[i]; a[i]=temp;
      i++;
    }
    //left scan, a[j] is the key
    while(i<j&&a[i]<=a[j]) i++;
    if(i<j){
      temp=a[j]; a[j]=a[i]; a[i]=temp;
      j--;
    }
  }
  return i;
}

/******************************************************
 *
 * 
 *
******************************************************/

void quickSort(int *a, int first, int end){
  int pivot;
  if(first<end){  //end recursion
    pivot=partition(a,first,end);
    quickSort(a,first,pivot-1);
    quickSort(a,pivot+1,end);
  }
}

/******************************************************
 *
 * K&R simple qsort 
 *  sort v[left]...v[right] int increasing order
 *
******************************************************/

void swap(int v[], int i, int j){
    int temp;
    temp=v[i]; v[i]=v[j]; v[j]=temp;
}

void kQuickSort(int *v, int left, int right){
  int i,last;
  if(left>=right)
    return;
  swap(v,left,(left+right)/2);
  last=left;
  for(i=left+1; i<=right; i++)
    if(v[i]<v[left])
      swap(v, ++last, i);
  swap(v,last,left);
  kQuickSort(v, left, last-1);
  kQuickSort(v, last+1, right);
}

int main(){
  int a[5]={3,2,5,6,4};
  printSequence(a,5,0);
  kQuickSort(a,0,4);
  printSequence(a,5,0);
  return 0;
}
