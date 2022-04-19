#include<iostream>
using namespace std;
struct node {
	int data;
  	struct node *left;
  	struct node *right;
};
struct node*root;
void append(int d){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    struct node*t=root;
    newnode->data=d;
    newnode->left=NULL;
    newnode->right=NULL;

if(root==NULL){
     root = newnode;
}
else
{
    while(true){
        if(d<t->data){
            if(t->left !=NULL){
                t=t->left;
            }
            else{
                t->left=newnode;
                break;
            }
        }
        else{
            if(t->right !=NULL){
                t=t->right;
            }
            else{
                t->right=newnode;
                break;
            }
        }
    }
}
}
int su(struct node *root,int k){
  int co=0,ks=-1;
  struct node *curr=root;
  while(curr!=NULL){
    if(curr->left==NULL){
      co++;
      if(co==k)
        ks=curr->data;
      curr=curr->right;
    }
    else{
      struct node *pre=curr->left;
      while(pre->right!=NULL && pre->right!=curr)
        pre=pre->right;
      if(pre->right==NULL){
        pre->right=curr;
        curr=curr->left;
      }
      else{
        pre->right=NULL;
        co++;
        if(co==k)
          ks=curr->data;
        curr=curr->right;
      }
    }
  }
  return ks;
}
int main()
{
  //type your code
  int d;
  do{
    cin>>d;
    if(d>0)
      append(d);
  }while(d!=-1);
  int k;
  cout<<"Enter the kth value:"<<endl;
  cin>>k;
  su(root,k);
  cout<<"Smallest kth value "<<su(root,k);
  return 0;
}