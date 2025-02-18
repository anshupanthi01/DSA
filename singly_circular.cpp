#include <iostream>
using namespace std;

struct node
{
    int data;
    node *link;
};

node *pfirst = NULL;
node *pnew, *pthis, *ptemp, *plast;
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
        plast = pnew;
        plast->link = pfirst;
    }
    else
    {
        pnew->link = pfirst;
        pfirst = pnew;
        plast->link = pfirst;
    }
}

void insertAtEnd()
{
    create();
    if (pfirst == NULL)
    {
        pfirst = pnew;
        plast = pnew;
        plast->link = pfirst;
    }
    else
    {
        plast->link = pnew;
        plast = pnew;
        plast->link = pfirst;
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
    if (loc < 1 || loc > count) {
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
        pnew->link = ptemp;
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
        while (pthis->link != pfirst)
        {
            cout << pthis->data << "->";
            pthis = pthis->link;
        }
        cout << pthis->data;
    }
}

void DelAtBeg()
{
    if (pfirst == NULL)
    {
        cout << "the list is empty";
    }
    else if (pfirst->link == pfirst)
        {
            cout << "the deleted data is: " << pfirst->link;
            count--;
            delete (pfirst);
            delete(plast);
            pfirst = NULL;
            plast = NULL;
        }
        else
        {
            cout << "the deleted data is:" << pfirst->data << endl;
            count--;
            ptemp = pfirst->link;
            delete (pfirst);
            pfirst=ptemp;
            plast->link =pfirst;
        }
    
}

void DelAtEnd()
{
    if (pfirst == NULL)
    {
        cout << "the list is empty";
    }
    else  if (pfirst->link == pfirst)
        {
            cout << "the deleted data is: " << pfirst->link;
            count--;
            delete (pfirst);
            delete(plast);
            pfirst = NULL;
            plast = NULL;
        }
        else
        {
            pthis = pfirst;
            while (pthis->link != plast)
            {
                pthis = pthis->link;
            }
            cout << "the deleted data is:" << pthis->link->data << endl;
            count--;
            // cout << plast->data;
            delete (plast);
            plast=pthis;
            plast->link = pfirst;
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
        cout << "the deleted data is:" << pthis->link->data << endl;
        delete (pthis->link);
        count--;
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
