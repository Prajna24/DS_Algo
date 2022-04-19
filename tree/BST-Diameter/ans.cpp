#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node *left,*right;
        Node(int i)
        {
            data = i ;
            left = right = NULL ;
        }
}*root = NULL;
void append(int data)
    {
      Node *temp,*newnode;
      temp = root;
      newnode = new Node(data);
      
      if(root == NULL)
          root = newnode;
      else
      {
          while(true)
          {
              if(data > temp->data)
              {
                  if(temp->right != NULL)
                  {
                      temp = temp->right;
                  }
                  else
                  {
                      temp->right = newnode;
                      break;
                  }
              }
              else
              {
                  if(temp->left != NULL)
                  {
                      temp = temp->left;
                  }
                  else
                  {
                      temp->left = newnode;
                      break;
                  }
              }
          }
      }
  }

int max(int a, int b) { return (a >= b)? a: b; }

int height(Node *node) 
{ 
   if(node == NULL) 
       return 0; 
   return 1 + max(height(node->left), height(node->right)); 
}     
int diameter(Node *tree) 
{ 
   if (tree == NULL) 
     return 0; 
  int lheight = height(tree->left); 
  int rheight = height(tree->right); 
  int ldiameter = diameter(tree->left); 
  int rdiameter = diameter(tree->right); 
  return max(lheight + rheight + 1, max(ldiameter, rdiameter)); 
}  
int main()
{
    int data;
    do
    {
        cin>>data;
        if(data > 0)
            append(data);
    }while(data > 0);
    cout<<"Diameter of the given binary tree is "<<diameter(root);
    return 0;
}