#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node *left,*right;
};
void append(Node **rootadd,int data)
{
    Node *temp,*newnode;
    temp = *rootadd;
    newnode = new Node();
    newnode->left = NULL;
    newnode->data = data;
    newnode->right = NULL;
    if(*rootadd == NULL)
        *rootadd = newnode;
    else
    {
        while(1)
        {
            if(data > temp->data)
            {
                if(temp->right != NULL)
                    temp = temp->right;
                else
                {
                    temp->right = newnode;
                    break;
                }
            }
            else
            {
                if(temp->left != NULL)
                    temp = temp->left;
                else
                {
                    temp->left = newnode;
                    break;
                }
            }
        }
    }
}   
void leafSum(Node *root, int &sum){
    if (!root)
        return;
    if (!root->left && !root->right)
        sum += root->data;
    leafSum(root->left, sum);
    leafSum(root->right, sum);
}
int main() 
{
   Node *root = NULL;
  int data,sum=0;
  do
  {
    cin>>data;
    if(data>0)
      append(&root,data);
  }while(data>0);
  leafSum(root,sum);
  cout<<"Sum of all leaf nodes are "<<sum;
  return 0;
}