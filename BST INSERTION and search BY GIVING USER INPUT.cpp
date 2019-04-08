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
    struct Node *temp=((struct Node*)malloc(sizeof(struct Node)));
    temp->key=item;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}


struct Node *insert(struct Node* node,int key)
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
}
struct Node *search(struct Node* root,int key)
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


}
int main()
{
    int i,n,x;

    struct Node* root=NULL;


    printf("Enter user input: \n");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {

        printf("Enter input: ");
        scanf("%d",&x);

        if(i==0)
        {
            root=insert(root,x);
        }
        else
            insert(root,x);
    }


    printf("Inorder: ");
    inorder(root);
    puts("");

    printf("Preorder: ");
    preorder(root);
    puts("");

    printf("Postorder: ");
    postorder(root);
    puts("");
    int b;
    printf("Seach your number: ");
    scanf("%d",&b);
    struct Node* ret;
    ret=search(root,b);
    if(ret==NULL)
    {
        printf("%d is Not Found.\n");
    }
    else{
        printf("Found %d",ret->key);
    }

    return 0;

}

