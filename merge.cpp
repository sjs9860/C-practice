#include <cstdlib>
#include <iostream>
using namespace std;

void printSequence(int a[], int n, int i){
  cout<<i <<": ";
  for(int j=0; j<n; j++){
    cout<<a[j]<<" ";
  }
  cout<<endl;
}

/*****************************************************
 *
 * function: merge
 *   merge two ordered subsequence into a large ordered
 *   subsequence. s,t,l are the indexes of the sequence
 *     a(s)...a(t-1)|a{t}...a(l) ----->
 *     al(s)...al(t-1)al(t)...al(l)
 *
*****************************************************/

void Merge(int *a, int *al, int s, int t, int l){
  int i,j,k;
  i=s; j=t; k=s;
  while(i<=(t-1)&&j<=l){
    if(a[i]<a[j]) al[k++]=a[i++];
    else al[k++]=a[j++];
  }
  while(i<=(t-1)) al[k++]=a[i++];
  while(j<=l) al[k++]=a[j++];
}

/*****************************************************
 *
 * non-recursive merge sort
 * 
 * function: 
 *   mergePass : merge each equally long ordered subsequence
 *   into a whole ordered sequence
 *   mergeSort : sort unsorted sequence with mergePass 
 *                       
*****************************************************/

void mergePass(int *a, int *al, int n, int interval){
  int i,k; i=0;
  while(i<=n-2*interval){
    Merge(a,al,i,i+interval,i+2*interval-1);
    i+=2*interval;
  }
  if(i<=n-interval) Merge(a,al,i,i+interval,n-1);
  else{ k=i; while(i<n) al[k++]=a[i++];}
}

void mergeSort(int *a, int *al, int n){
  int h=1;
  int i,k; i=k=0;
  while(h<n){
    mergePass(a,al,n,h);
    h=2*h;
    if(h<n){
      mergePass(al,a,n,h);
      h=2*h;
    }
    else{
      while(i<n)
      a[i++]=al[k++];
    }
  }
}

/*****************************************************
 *
 * recursive merge sort
 *    s,t are indexes, start & terminal
 *
*****************************************************/

void rMergeSort(int *a, int *al, int s, int t){
  int m;
  if(s==t) al[s]=a[s];
  else{
    m=(s+t)/2;
    rMergeSort(a,al,s,m);
    rMergeSort(a,al,m+1,t);
    Merge(al,a,s,m,t);
  }
}

int main(){
  int a[]={1,3,2,4,5,6,7};
  int n=sizeof(a)/sizeof(a[0]);
  cout<<"Size of the array is: "<<n<<endl;
  printSequence(a,n,0);
  int *al=(int *)malloc(sizeof(a));
  //mergeSort(a,al,n);
  rMergeSort(a,al,0,n-1);
  printSequence(a,n,0);
  free(al);
  return 0;
}
