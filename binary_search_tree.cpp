#include <iostream>
using namespace std;

struct node
{
    int data;
    node *lchild, *rchild;
    // node *root = NULL, *pnew, *pthis, *ppthis;
};
node *root = NULL, *pnew, *pthis, *ppthis;

void create()
{
    cout << "Enter the number of nodes: ";
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        pnew = new node;
    step1:
        cout << "Enter the data: ";
        cin >> pnew->data;
        pnew->lchild = NULL;
        pnew->rchild = NULL;
        if (root == NULL)
        {
            root = pnew;
        }
        else
        {
            pthis = root;
            while (pthis != NULL)
            {
                ppthis = pthis;
                if (pthis->data > pnew->data)
                {
                    pthis = pthis->lchild;
                    if (pthis == NULL)
                    {
                        ppthis->lchild = pnew;
                    }
                }
                else if (pthis->data < pnew->data)
                {
                    pthis = pthis->rchild;
                    if (pthis == NULL)
                    {
                        ppthis->rchild = pnew;
                    }
                }
                else
                {
                    cout<<"duplicate node pls enter another value";
                    goto step1;
                }
            }
        }
    }
}
void preorder(node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void inorder(node *p)
{
    if (p != NULL)
    {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}
void postorder(node *p)
{
    if (p != NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << " ";
    }
}
int main()
{
    char a;
    create();
    // do
    while(1)
    {
        cout << "\n1.Preorder\n";
        cout << "2.Inorder\n";
        cout << "3.Postorder\n";
        cout << "4.Exit\n";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Preorder: ";
            preorder(root);
            break;
        case 2:
            cout << "Inorder: ";
            inorder(root);
            break;
        case 3:
            cout << "Postorder: ";
            postorder(root);
            break;
        case 4:
            return 0;
        }
        // cout << "\nContinue?(Y/N)\n";
        // cin >> a;
    } 
    // while (a == 'y');
}