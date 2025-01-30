#define MAX 3
#include <iostream>
using namespace std;

int main()
{
    int queue[MAX], data;
    int a, rear = -1, front = -1;
    char ch;
    do
    {
        cout << "1. Enqueue" << "\n";
        cout << "2. Dequeue" << "\n";
        cout << "3. Display" << "\n";
        cout << "4. Exit" << "\n";
        cin >> a;
        switch (a)
        {
        case 1:
            if (rear == MAX - 1)
            {
                cout << "Queue is overflow";
            }
            else
            {
                cout << "Enter data: ";
                cin >> data;
                rear = rear + 1;
                if (front == -1)
                {
                    front = 0;
                }
                queue[rear] = data;
            }
            break;
        case 2:
            if (front == -1)
            {
                cout << "queue is underflow\n";
            }
            else
            {
                cout << queue[front];
                front = front + 1;
                if (front > rear)
                {
                    front = -1;
                    rear = -1;
                }
            }

            break;
        case 3:
            if (front == -1)
            {
                cout << "queue underflow";
            }
            else
            {
                for (int i = front; i <= rear; i++)
                {
                    cout << queue[i] << "\n";
                }
            }
            break;
        case 4:
            exit(0);
            break;
        }
    end:

        cout << "\nContinue?(Y/N)" << endl;
        cin >> ch;
    } while (ch == 'y');
    return 0;
}
