
#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T>
class BST;
template <class T>
class treenode
{
    friend class BST<T>;

private:
    treenode *left;
    T data;
    treenode *right;
};
template <class T>
class BST
{
private:
    treenode<T> *root;

public:
    BST();
    int isEmpty();
    treenode<T> *getRoot();
    void inOrder(treenode<T> *node);
    void preOrder(treenode<T> *node);
    void postOrder(treenode<T> *node);
    int insert(T item);
    int Delete(T item);
    int find(treenode<T> *tree, T item);
};
template <class T>
BST<T>::BST()
{
    root = NULL;
}
template <class T>
treenode<T> *BST<T>::getRoot()
{
    return root;
}
template <class T>

int BST<T>::isEmpty()
{
    if (root == NULL)
        return 1;
    else
        return 0;
}
template <class T>
void BST<T>::inOrder(treenode<T> *currentnode)
{
    if (currentnode != NULL)
    {
        inOrder(currentnode->left);
        cout << currentnode->data << endl;
        inOrder(currentnode->right);
    }
}
template <class T>
void BST<T>::preOrder(treenode<T> *currentnode)
{
    if (currentnode != NULL)
    {
        cout << currentnode->data << endl;
        preOrder(currentnode->left);
        preOrder(currentnode->right);
    }
}
template <class T>
void BST<T>::postOrder(treenode<T> *currentnode)
{
    if (currentnode != NULL)
    {
        postOrder(currentnode->left);
        postOrder(currentnode->right);
        cout << currentnode->data << endl;
    }
}
template <class T>
int BST<T>::find(treenode<T> *tree, T item)
{
    if (!tree)
    {
        return 0;
    }
    if (tree->data == item)
        return 1;
    else if (item < tree->data)
        return find(tree->left, item);
    else
        return find(tree->right, item);
}

//inserts item into BST.
//Returns 1 if successful.
template <class T>
int BST<T>::insert(T item)
{
    treenode<T> *p = root, *q = NULL;
    while (p != NULL)
    {
        q = p;
        if (p->data == item)
            return 0; //item already in BST
        if (item < p->data)
            p = p->left;
        else
            p = p->right;
    }
    //makes the new BST node
    p = new treenode<T>;
    p->left = p->right = NULL;
    p->data = item;
    if (root == NULL) //if it is the first BST node
        root = p;
    else if (item < q->data)
        q->left = p;
    else
        q->right = p;
    return 1; //node successfully inserted
}
//deletes node with data equal to item from BST.
//returns 1 if deleted, else 0.
template <class T>
int BST<T>::Delete(T item)
{
    treenode<T> *p = root, *q = NULL, *r = NULL;

    while (p != NULL)
    {
        q = p;
        if (item < p->data)
        {
            p = p->left;
        }
        else if (item > p->data)
        {
            p = p->right;
        }
        else
            break;
    }
    if (p == NULL) //node with item not found
        return 0;
    if (p->left == NULL && p->right == NULL)
    {
        if (p == q->left)
            q->left = NULL;
        else
            q->right = NULL;
        delete p;
    }
    else if (p->left == NULL && p->right != NULL)
    {
        p->data = p->right->data;
        if (p == q->left)
            q->left = NULL;
        else
            q->right = NULL;
        delete p->right;
    }
    else if (p->left != NULL && p->right == NULL)
    {
        p->data = p->left->data;
        delete p->left;
    }
    else
    {
        r = q = p->left;
        while (q->right != NULL)
        {
            r = q;
            T d = q->data;
            q = q->right;
        }

        p->data = q->data;
        r->right = q->left;
        delete q;
    }
    return 1; //BST node deleted successfully
}
int main()
{
    int ch, item;
    BST<int> bt;
    int t, p;
    do
    {
        cout << "\n1.Insert 2.Delete 3.In-order 4.Pre-order ";
        cout << "5.Post-Order 6.Find Node 7.Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter data > ";
            cin >> item;

            bt.insert(item);
            break;

        case 2:
            cout << "Enter the element to be deleted > ";
            cin >> item;

            t = bt.Delete(item);
            if (t == 1)
                cout << "Element deleted";
            else
            {
                cout << "Element not found";
            }
            break;

        case 3:
            bt.inOrder(bt.getRoot());
            break;
        case 4:
            bt.preOrder(bt.getRoot());
            break;
        case 5:
            bt.postOrder(bt.getRoot());
            break;
        case 6:
            cout << "Enter the element to be found > ";
            cin >> item;

            p = bt.find(bt.getRoot(), item);
            if (p == 1)
            {
                cout << "Element found";
            }
            else
                cout << "Element not found";

            break;
        case 7:
            exit(0);
        }
    } while (ch != 7);
    return (0);
}