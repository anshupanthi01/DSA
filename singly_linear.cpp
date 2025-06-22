#include <iostream>
using namespace std;

struct node
{
    int data;
    node *link;
};

node *pfirst = NULL;
node *pnew, *pthis, *ptemp;
int count = 0, loc;

void create()
{
    pnew = new node;
    cout << "Enter the data: ";
    cin >> pnew->data;
    count++;
}

void insertAtBeg()
{
    create();
    if (pfirst == NULL)
    {
        pfirst = pnew;
        pnew->link = NULL;
    }
    else
    {
        pnew->link = pfirst;
        pfirst = pnew;
    }
}

void insertAtEnd()
{
    create();
    pnew->link = NULL; // assign null to the link field
    if (pfirst == NULL)
    {
        pfirst = pnew;
        // pnew->link = NULL;
    }
    else
    {
        pthis = pfirst;
        while (pthis->link != NULL)
        {
            pthis = pthis->link; // move until it points to the last node
        }
        pthis->link = pnew;
        pnew->link = NULL;
    }
} 

void insertbeforepos()
{
    create();
    cout << "Enter the location: ";
    cin >> loc;
    if (loc == 1)
    {
        insertAtBeg();
    }
    if (loc > count)
    {
        cout << "Invalid";
    }
    pthis = pfirst;
    for (int i = 1; i < loc - 1; i++)
    {
        pthis = pthis->link;
    }
    ptemp = pthis->link;
    pthis->link = pnew;
    pnew->link = ptemp;
}

void insertafterpos()
{
    create();
    cout << "Enter the location: ";
    cin >> loc;
    pthis = pfirst;
    for (int i = 1; i < loc; i++)
    {
        pthis = pthis->link;
    }
    ptemp = pthis->link;
    pthis->link = pnew;
    pnew->link = ptemp;
}

void display()
{
    if (pfirst == NULL)
    {
        cout << "the list is empty";
    }
    else
    {
        pthis = pfirst;
        while (pthis->link != NULL)
        {
            cout << pthis->data << "->";
            pthis = pthis->link;
        }
        cout << pthis->data;
        cout << "->NULL\n";
    }
}

void DelAtBeg()
{
    if (pfirst == NULL)
    {
        cout << "the list is empty";
    }
    else
    {
        if (pfirst->link == NULL)
        {
            delete (pfirst);
            pfirst = NULL;
        }
        else
        {
            ptemp = pfirst->link;
            delete (pfirst);
            pfirst = ptemp;
        }
    }
}

void DelAtEnd()
{
    if (pfirst == NULL)
    {
        cout << "the list is empty";
    }
    else
    {
        if (pfirst->link == NULL)
        {
            delete (pfirst);
            pfirst = NULL;
        }
        else
        {
            pthis = pfirst;
            while (pthis->link->link != NULL)
            {
                pthis = pthis->link;
            }
            delete (pthis->link);
            pthis->link = NULL;
        }
    }
}

void DelAtPos()
{
    cout << "Enter the location: ";
    cin >> loc;
    if (pfirst == NULL)
    {
        cout << "The list is empty!\n";
    }
    else
    {
        pthis = pfirst;
        for (int i = 1; i < loc - 1; i++)
        {
            pthis = pthis->link;
        }
        ptemp = pthis->link->link;
        delete(pthis->link); 
        pthis->link = ptemp;
    }
}
int main()
{
    int choice;
    char a;
    do
    {
        cout << "\n1. Insert from beginning\n";
        cout << "2. Insert at the end\n";
        cout << "3. Insert before specified position\n";
        cout << "4. Insert after specified position\n";
        cout << "5. Display\n";
        cout << "6. Delete from beginning\n";
        cout << "7. Delete at the end\n";
        cout << "8. Delete the specified position\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insertAtBeg();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertbeforepos();
            break;
        case 4:
            insertafterpos();
            break;
        case 5:
            display();
            break;
        case 6:
            DelAtBeg();
            break;
        case 7:
            DelAtEnd();
            break;
        case 8:
            DelAtPos();
            break;
        }
        cout << "\nContinue?(Y/N)\n";
        cin >> a;
    } while (a == 'y');

    return 0;
}
