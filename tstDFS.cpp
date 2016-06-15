#include <iostream>
#include <stack>
using namespace std;

typedef struct Node{
  int self;
  Node *left;
  Node *right;
}node;

int main(){
    const int TREE_SIZE = 9; 
    stack<node*> visited, unvisited; 
    node nodes[TREE_SIZE]; 
    node* current; 
    for( int i=0; i<TREE_SIZE; i++) //初始化树 
        {    
            nodes[i].self = i;   
            int child = i*2+1;    
            if( child<TREE_SIZE ) //Left child       
            nodes[i].left = &nodes[child];    
            else nodes[i].left = NULL;    
            child++;    
            if( child<TREE_SIZE ) //Right child           
            nodes[i].right = &nodes[child];    
            else       nodes[i].right = NULL;
        }             
     unvisited.push(&nodes[0]); //先把0放入UNVISITED stack  
     while(!unvisited.empty()) //只有UNVISITED不空  
     {    
         current=(unvisited.top()); //当前应该访问的    
         unvisited.pop();      
         if(current->right!=NULL)     
         unvisited.push(current->right); // 把右边压入 因为右边的访问次序是在左边之后     
         if(current->left!=NULL)     
         unvisited.push(current->left);     
         visited.push(current);     
         cout<<current->self<<endl; 
      }
  return 0;
}
