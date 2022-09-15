#include <bits/stdc++.h>
#include <math.h>
using namespace std;
struct Tree
{
    int data;
    Tree *left = NULL, *right = NULL;
};
void mirror(Tree *T)
{
    Tree *temp;
    temp = T->left;
    T->left = T->right;
    T->right = temp;
    return;
}
void traversal_mirror(Tree *T)
{
    if (T == NULL)
        return;

    traversal_mirror(T->left);
    traversal_mirror(T->right);
    mirror(T);
}
void inorder_traversal(Tree *T)
{
    if (T == NULL)
        return;

    inorder_traversal(T->left);
    cout << T->data << " ";
    inorder_traversal(T->right);
}
int main()
{
    Tree *T;
    T->data = 1;
    Tree *l = new Tree;
    l->data = 2;
    Tree *r = new Tree;
    r->data = 3;
    T->left = l;
    T->right = r;
    inorder_traversal(T);
    traversal_mirror(T);
    cout<<"\n";
    inorder_traversal(T);
}
