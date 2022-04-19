#include<bits/stdc++.h>
using namespace std;
struct node
{
        int data;
        struct node *left,*right;
};
struct node *root;
struct node* create(int n)
{
  struct node *temp = (struct node*)malloc(sizeof(struct node *));
  temp->data=n;
  temp->right=temp->left=NULL;
}
struct node* lca(struct node *root, int n1, int n2)
{
	if(root->data>n1 && root->data>n2)
		return lca(root->left,n1,n2);
	else if(root->data<n1 && root->data<n2)
  		return lca(root->right,n1,n2);
    return root;
}
void insert(struct node *temp,struct node *t)
{
  if(t->data<temp->data && t->right!=NULL)
    insert(temp,t->right);
  if(t->data<temp->data && t->right==NULL)
    t->right=temp;
  if(t->data>temp->data && t->left!=NULL)
    insert(temp,t->left);
  if(t->data>temp->data && t->left==NULL)
    t->left=temp;
}
int main()
{
  int n;
  cin>>n;
  while(n!=-1)
  {
    struct node *newnode = create(n);
    if(root==NULL)
      root=newnode;
    else
      insert(newnode,root);
    cin>>n;
  }
  int n1,n2;
  cin>>n1>>n2;
  struct node *temp = lca(root,n1,n2);
  cout<<temp->data;
}