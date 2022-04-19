#include <iostream>
using namespace std;

struct node {
    int data;
    struct node*prev;
    struct node*next;
};
struct node*root;
void append(int d){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    struct node*t=root;
    newnode->data=d;
    newnode->prev=NULL;
    newnode->next=NULL;

if(root==NULL){
     root = newnode;
}
else
{
    while(true){
        if(d<t->data){
            if(t->prev !=NULL){
                t=t->prev;
            }
            else{
                t->prev=newnode;
                break;
            }
        }
        else{
            if(t->next !=NULL){
                t=t->next;
            }
            else{
                t->next=newnode;
                break;
            }
        }
    }
}
}
int addBT(struct node* root){
    if(root==NULL)
        return 0;
    return (root->data + addBT(root->prev)+addBT(root->next));
}
int main() {
	int d;
	do{
	    cin>>d;
	    if(d>0)
	        append(d);
	}while(d!=-1);
	int sum=addBT(root);
	cout<<"Sum of all nodes are "<<sum;
	return 0;
}