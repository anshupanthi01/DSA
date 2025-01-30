#define MAX 5
#include <iostream>
using namespace std;

int main()
{
    int queue[MAX], data;
    int a, rear = -1, front = -1;
    char ch;
    int i;
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
            if (front == (rear + 1) % MAX)
            {
                cout << "Queue is overflow";
            }
            else
            {
                cout << "Enter data: ";
                cin >> data;
                rear = (rear + 1) % MAX;
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
                if (front == rear)
                {
                    front = -1;
                    rear = -1;
                    if (front == -1)
                    {
                        cout << "queue is underflow\n";
                    }
                }
                else
                {
                    data = queue[front];
                    cout << "dequeued data is:" << data << endl;
                    front = (front + 1) % MAX;
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
                i = front;
                while (i != rear)
                {
                    cout << queue[i] << "\n";
                    i = (i + 1) % MAX;
                }
                cout<< queue[i];
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
