/*********************************************
 *
 * Implementation of stack with sequence list
 * and linked list separately 
 *
 * ******************************************/

#include <cstdlib>
#include <iostream>
using namespace std;

/*********************************************
 *
 * 
 *
 * ******************************************/
typedef struct _SeqStack{
  int *bottom;
  int length;
  int top;
}SeqStack;

SeqStack *initSeqStack(int max){
  SeqStack *stack = (SeqStack *)malloc(sizeof(SeqStack));
  stack->bottom = (int *)malloc(max*sizeof(int));
  stack->length=max;
  stack->top=-1;
  return stack;
}

void destroySeqStack(SeqStack *stack){
  free(stack->bottom);
  free(stack);
}

bool Push(SeqStack *stack, int val){
  if(stack->top < stack->length){
    stack->bottom[++stack->top]=val;
    return true;
  }
  else
    return false;
}

int Pop(SeqStack *stack){
  if(stack->top>-1){
    return stack->bottom[stack->top--];
  }
  else{
    printf("Pop failed! Since the stack is empty");
    return -65536;
  }
}
int getTop(SeqStack *stack){
  if(stack->top>-1){
    return stack->bottom[stack->top];
  }
  else{
    printf("getTop failed! Since the stack is empty\n");
    return -65536;
  }
}

int getNumber(SeqStack *stack){
  if(stack==NULL){
    printf("getNumber failed! Error input\n");
    return -65536;
  }
  else
    return stack->top+1;
}
/*********************************************
 *
 * 
 *
 * ******************************************/
typedef struct _Node{
  int val;
  struct _Node *next;
}Node;

typedef struct _SlinkList{
  Node *header;
  int size;
}SLinkList;

SLinkList *LinkList(){
  SLinkList *linklist=(SLinkList *)malloc(sizeof(SLinkList));
  linklist->header=NULL;
  linklist->size=0;
  return linklist;
}

int main(){
  int val;
  int stackLength = 10;
  SeqStack *stack = initSeqStack(stackLength);
  Push(stack,100);
  val=Pop(stack);
  printf("Top element is %d\n",val);
  val=Pop(stack);
  printf("Top element is %d\n",val);
  destroySeqStack(stack);
  return 0; 
}
