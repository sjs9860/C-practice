#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct _Node{
  int val;
  struct _Node *next;
}Node;

typedef struct _SlinkList{
  Node *header;
  int size;
}SLinkList;

/*********************************************
 *
 * inintialize a linked list
 *
 ********************************************/
SLinkList *LinkList(){
  SLinkList *linklist=(SLinkList *)malloc(sizeof(SLinkList));
  linklist->header=NULL;
  linklist->size=0;
  return linklist;
}

/*********************************************
 *
 * inintialize a linked list with an array
 *
 ********************************************/
SLinkList *LinkListA(int *a, int n){
  Node *newnode, *r;
  int i=0;
  SLinkList *linklist=(SLinkList *)malloc(sizeof(SLinkList));
  newnode=(Node *)malloc(sizeof(Node));
  newnode->val=a[i];
  newnode->next=NULL;
  linklist->header=newnode;
  r=linklist->header;
  i++;
  while(i<n){
    newnode=(Node *)malloc(sizeof(Node));
    newnode->val=a[i];
    newnode->next=r->next;
    r->next=newnode;
    r=r->next;
    i++;
  }
  linklist->size=n;
  return linklist;
}

/*********************************************
 *
 * Insert on the left
 * insert a node at a specific location with a specific value,
 * the origin element at the location should be moved behind
 *
 ********************************************/
bool Insert(SLinkList *linklist, int location, int val){
  int j;
  Node *op = NULL;
  Node *newnode = (Node *)malloc(sizeof(Node));
  newnode->val=val;
  op=linklist->header;
  // linklist is empty, but location violate with the limit
  if(op==NULL&&location!=0) 
    return false;
  // insert an element at the start position 
  else if(location==0){ 
    linklist->header=newnode;
    newnode->next=op;
    linklist->size++;
  }
  // insert an element at location between (0,size-1]
  else if(location>0 && location<linklist->size){ 
    // the option mark should be one step before the specific location
    for(j=0; (j<location-1) && (op->next!=NULL); op=op->next) 
      j++;
    newnode->next=op->next;
    op->next=newnode;
    linklist->size++;
  }
  // append an element to the end 
  else if(location>=linklist->size){ 
    for(j=0;op->next!=NULL;op=op->next)
      ;
    op->next=newnode;
    newnode->next=NULL;
    linklist->size++;
  }
  return true;
}

/*********************************************
 *
 * delete a node at the specific location 
 *
 ********************************************/
bool Delete(SLinkList *linklist, int location){
  int j;
  Node *op = NULL;
  Node *op1 = NULL;
  op=linklist->header;
  // linklist is empty, or location violate with the limit
  if(op==NULL||location>=linklist->size) 
    return false;
  // delete the first node at location 0
  else if(location==0){
    linklist->header=op->next;
    free(op);
    op=NULL;
    linklist->size--;
    return true;
  }
  // delete an element at location between (0,size-1]
  else if(location>0&&location<linklist->size){
    for(j=0;j<(location-1)&&op->next!=NULL;op=op->next)
      j++;
    op1=op->next;
    op->next=op1->next;
    free(op1);
    op1=NULL;
    linklist->size--;
    return true;
  }
  else
    return false;
}
/*********************************************
 *
 * get the value of the node at a specific location
 *
 ********************************************/
int getValue(SLinkList *linklist, int location){
  int j;
  Node *op = NULL;
  op=linklist->header;
  if(op==NULL)
    return false;
  for(j=0;j!=location && op->next!=NULL;op=op->next)
    j++;
  if(j!=location)
    return false;
  else{
    return op->val;
  }
}

/*********************************************
 *
 * print the value of each node in the list
 *
 ********************************************/
void printList(SLinkList *linklist){
  Node *op = NULL;
  op=linklist->header;
  if(op==NULL)
    return ;
  while(op->next!=NULL){
    printf("%d ",op->val);
    op=op->next;
  }
  printf("%d \n",op->val);
  return ;
}
 
/*********************************************
 *
 * empty a linklist
 *
 ********************************************/
void Empty(SLinkList *linklist){
  Node *op = NULL;
  op=linklist->header;
  if(op==NULL)
    return;
  while(op->next!=NULL){
    linklist->header=op->next;
    free(op);
    op=linklist->header;
  }
  linklist->header=NULL;
  linklist->size=0;
  free(op);
  op=NULL;
  return;
}

/*********************************************
 *
 * destroy a linklist
 *
 ********************************************/
void Destroy(SLinkList *linklist){
  if(linklist->header!=NULL)
    Empty(linklist);
  free(linklist);
  linklist=NULL;
  return;
}

int main(){
  int i=0;
  int a[]={5,3,7,9,1};
  int n=sizeof(a)/sizeof(a[0]);
  //SLinkList *linklist = LinkList();
  SLinkList *linklist = LinkListA(a,n);
  /*for(;i<4;i++){
    Insert(linklist,i,i);
  }*/
  printList(linklist);
  Insert(linklist,10,10);
  Insert(linklist,3,100);
  printList(linklist);
  cout<<getValue(linklist,2)<<endl;
  cout<<getValue(linklist,3)<<endl;
  Delete(linklist,3);
  cout<<getValue(linklist,3)<<endl;
  printList(linklist);
  cout<<getValue(linklist,linklist->size-1)<<endl;
  Empty(linklist);
  Destroy(linklist);
  return 0;
}
