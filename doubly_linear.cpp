#include <iostream>
using namespace std;

struct node
{
    int data;
    node *link, *prev;
};

node *pfirst = NULL;
node *pnew, *pthis, *ptemp, *ptemp1, *plast;
int count = 0, loc;

void create()
{
    pnew = new node;
    cout << "Enter the data: ";
    cin >> pnew->data;
    pnew->link = NULL;
    pnew->prev = NULL;
    count++;
}

void insertAtBeg()
{
    create();
    if (pfirst == NULL)
    {
        pfirst = pnew;
        plast = pnew;
        pfirst->link = NULL;
        pfirst->prev = NULL;
    }
    else
    {
        pnew->prev = NULL;
        pnew->link = pfirst;
        pfirst->prev = pnew;
        pfirst = pnew;
    }
}

void insertAtEnd()
{
    create();
    if (pfirst == NULL)
    {
        pfirst = pnew;
        plast = pnew;
        pfirst->link = NULL;
        pfirst->prev = NULL;
    }
    else
    {
        plast->link = pnew;
        pnew->prev = plast;
        pnew->link = NULL;
        plast = pnew;
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
    if (loc < 1 || loc > count)
    {
        cout << "Invalid position!";
        return;
    }
    else
    {
        pthis = pfirst;
        for (int i = 1; i < loc - 1; i++)
        {
            pthis = pthis->link;
        }
        ptemp = pthis->link;
        pthis->link = pnew;
        pnew->prev = pthis;
        pnew->link = ptemp;
        ptemp->prev = pnew;
    }
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
    ptemp->prev = pnew;
    pnew->link = ptemp;
    pnew->prev = pthis;
    pthis->link = pnew;
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
        while (pthis != NULL)
        {
            cout << pthis->data << "->";
            pthis = pthis->link;
        }
    }
}

void DelAtBeg()
{
    if (pfirst == NULL)
    {
        cout << "the list is empty";
    }
    else if (pfirst->link == NULL)
    {
        cout << "the deleted data is: " << pfirst->link;
        count--;
        delete (pfirst);
        pfirst = NULL;
        plast = NULL;
    }
    else
    {
        cout << "the deleted data is:" << pfirst->data << endl;
        count--;
        ptemp = pfirst->link;
        delete (pfirst);
        pfirst = ptemp;
        plast->prev = NULL;
    }
}

void DelAtEnd()
{
    if (pfirst == NULL)
    {
        cout << "the list is empty";
    }
    else if (pfirst->link == NULL)
    {
        cout << "the deleted data is: " << pfirst->data;
        delete (pfirst);
        pfirst = NULL;
        plast = NULL;
        count--;
    }
    else
    {
        ptemp = plast->prev;
        cout << "the deleted data is: " << plast->data;
        delete (plast);
        ptemp->link = NULL;
        plast = ptemp;
        count--;
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
    else if (loc == 1)
    {
        DelAtBeg();
    }
    else if (loc == 0 || loc > count)
    {
        cout << "invalid operation\n";
    }
    else if (loc == count)
    {
        DelAtEnd();
    }
    else
    {
        pthis = pfirst;
        for (int i = 1; i < loc; i++)
        {
            pthis = pthis->link;
        }
        ptemp = pthis->prev;
        ptemp1 = pthis->link;
        cout << "the deleted data is:" << pthis->data << endl;
        delete (pthis);
        ptemp->link = ptemp1;
        ptemp1->prev = ptemp;
        count--;
    }
}
int main()
{
    int choice;
    char a;
    cout << "\n1. Insert from beginning\n";
    cout << "2. Insert at the end\n";
    cout << "3. Insert before specified position\n";
    cout << "4. Insert after specified position\n";
    cout << "5. Display\n";
    cout << "6. Delete from beginning\n";
    cout << "7. Delete at the end\n";
    cout << "8. Delete the specified position\n";
    do
    {
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
