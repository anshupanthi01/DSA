#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next, *prev;
};

node *head = NULL;
node *pnew, *pthis, *ptemp, *ptemp1;
int count = 0, loc;

void create()
{
    pnew = new node;
    cout << "Enter the data: ";
    cin >> pnew->data;
    pnew->next = NULL;
    count++;
}

void insertAtBeg()
{
    create();
    if (head->next == head)
    {
        head->next=pnew;
        pnew->prev=head;
        pnew->next=head;
        head->prev=pnew;
    }
    else
    {
        ptemp=head->next;
        head->next=pnew;
        pnew->prev=head;
        pnew->next=ptemp;
        ptemp->prev=pnew;
    }
}

void insertAtEnd()
{
    create();
    if (head->next == head)
    {
        head->next=pnew;
        pnew->prev=head;
        pnew->next=head;
        head->prev=pnew;
    }
    else
    {
        ptemp=head->prev;
        head->prev=pnew;
        pnew->next=head;
        pnew->prev=ptemp;
        ptemp->next=pnew;
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
        pthis = head->next;
        for (int i = 1; i < loc - 1; i++)
        {
            pthis = pthis->next;
        }
        ptemp = pthis->prev;
        ptemp->next = pnew;
        pnew->prev = ptemp;
        pnew->next = pthis;
        pthis->prev = pnew;
    }
}

void insertafterpos()
{
    create();
    cout << "Enter the location: ";
    cin >> loc;
    pthis = head->next;
    for (int i = 1; i < loc; i++)
    {
        pthis = pthis->next;
    }
    ptemp = pthis->next;
    ptemp->prev = pnew;
    pnew->next = ptemp;
    pnew->prev = pthis;
    pthis->next = pnew;
}

void display()
{
    if (head->next == head)
    {
        cout << "the list is empty";
    }
    else
    {
        pthis = head->next;
        while (pthis->next != head)
        {
            cout << pthis->data << "->";
            pthis = pthis->next;
        }
        cout<<pthis->data;
    }
}

void DelAtBeg()
{
    if (head->next == head)
    {
        cout << "the list is empty";
    }
    else if (head->next == head->prev)
    {
        cout << "the deleted data is: " << head->next->data;
        count--;
        delete (head->next);
    }
    else
    {
        cout << "the deleted data is:" << head->next->data << endl;
        count--;
        ptemp = head->next->next;
        delete (head->next);
        head->next = ptemp;
        ptemp->prev = head;
    }
}

void DelAtEnd()
{
    if (head->next == head)
    {
        cout << "the list is empty";
    }
    else
    {
        ptemp = head->prev->prev;
        cout << "the deleted data is: " << head->prev->data;
        delete (head->prev);
        head->prev=ptemp;
        ptemp->next=head;
        count--;
    }
}

void DelAtPos()
{
    cout << "Enter the location: ";
    cin >> loc;
    if (head->next == head)
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
        pthis = head->next;
        for (int i = 1; i < loc; i++)
        {
            pthis = pthis->next;
        }
        ptemp1 = pthis->next;
        ptemp = pthis->prev;
        ptemp->next = ptemp1;
        ptemp1->prev = ptemp;
        cout << "the deleted data is:" << pthis->data << endl;
        delete (pthis);
        count--;
    }
}
int main()
{
    int choice;
    char a;
    head = new node;
    head->data = 0;
    head->prev = head;
    head->next = head;
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
