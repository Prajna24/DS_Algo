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
int findMax(Node *root)  
{  
    if (root == NULL)  
      return 0;  
    int res = root->data;  
    int lres = findMax(root->left);  
    int rres = findMax(root->right);  
    if (lres > res)  
        res = lres;  
    if (rres > res)  
        res = rres;  
    return res;  
}  
int main()
{
    Node *root = NULL;
    int data;
    do
    {
        cin>>data;
        if(data > 0)
            append(&root,data);
    }while(data > 0);
    cout<<"Maximum element is "<<findMax(root);
    return 0;
}