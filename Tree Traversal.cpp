#include<stdio.h>
#include<stdlib.h>
#include<bits\stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node *left;
    Node *right;
};
void inorder(struct Node* root)
{

    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }

}

void preorder(struct Node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node* root)
{
    if(root!=NULL)
    {

        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->key);
    }
}

struct Node *newnode(int item)
{
    struct Node *temp=((struct Node*)malloc(sizeof(struct Node)));//[allocates  memory equal to the size of the node]//
    temp->key=item;//[parameter hishebe jeta ashbe,ta key er moddhe set korbe]//
    temp->left=NULL;//[new node,so left n right both are null]
    temp->right=NULL;
    return temp;
}



/*struct Node *insert(struct Node* node,int key)
{
    if(node==NULL)
    {
        struct Node* t= newnode(key);
        return t;
    }

    if(key<node->key)
    {
        node->left=insert(node->left,key);

    }
    else if(key>node->key)
    {
        node->right=insert(node->right,key);
    }
    return node;
}*/
/*struct Node *search(struct Node* root,int key)
{
    //juif(root -> key==key || root==NULL)
    if(root==NULL  || root -> key==key)
    {
        return root;
    }
    if(key>root->key)
    {

        return search(root->right, key); //calling a function named search,and parameter data type is not needed to call a function at anywhere//

    }
    else
    {
        return search(root->left,key);
    }


}*/
int main()
{
    int i,n,x;

    struct Node* root= newnode(1);
    root ->left=newnode(2);
    root->right=newnode(3);//3 or nijer ekti node create kore tar address 1 k dilo,r key value=3//
   root->left->left=newnode(4);
   root->left->right=newnode(5);
   root->right->left=newnode(6);
   root->right->right=newnode(7);
   root->right ->left->right=newnode(13);



    printf("Inorder: ");
    inorder(root);
    puts("");

    printf("Preorder: ");
    preorder(root);
    puts("");

    printf("Postorder: ");
    postorder(root);
    puts("");


    return 0;

}

