#define MAX 15
#include <iostream>
#include <string.h>
using namespace std;
int top = -1;
char postfix[50];
int stack[MAX];

int pop()
{
    int data = stack[top];
    top = top - 1;
    return data;
}

int push(int x)
{
    top = top + 1;
    stack[top] = x;
}

int main()
{
    int i, b, a;
    char ch;
    int var;
    cout << "Enter the postfix expression: ";
    cin >> postfix;
    int l = strlen(postfix);
    for (i = 0; i < l; i++)
    {
        cout << postfix[i] << "\n";
        if (postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '+' || postfix[i] == '-')
        {
            a = pop();
            b = pop();
            switch (postfix[i])
            {
            case '*':
                var = b * a;
                break;
            case '/':
                var = b / a;
                break;
            case '+':
                var = b + a;
                break;
            case '-':
                var = b - a;
                break;
            default:
                cout << "Invalid";
                break;
            }
            push(var);
        }
        else
        {
            push(postfix[i] - 48);
        }
    }
    cout << stack[top];
    return 0;
}
