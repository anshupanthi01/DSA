#include <iostream>
#include <string.h>
#define MAX 15
using namespace std;
int top = -1, pos = 0;
char stack[MAX];
char infix[50] ;
char postfix[50];

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1; // Lowest precedence
    if (op == '*' || op == '/')
        return 2; // Higher precedence
}
char pop()
{
    char data = stack[top];
    top = top - 1;
    return data;
}

void push(char x)
{
    top = top + 1;
    stack[top] = x;
}
int main()
{
    // 33 to 47 operators ko ascii value
    int i, a, b;
    
    cout<<"Enter the expression: ";
    cin>>infix;
    int l = strlen(infix);
    for (i = 0; i < l; i++)
    {
        if (infix[i] >= 33 && infix[i] <= 47)
        {
            if (infix[i] == '(')
            {
                push(infix[i]);
            }
            else if (infix[i] == ')')
            {
                while (stack[top] != '(')
                {
                    char popped_op = pop();
                    postfix[pos] = popped_op;
                    pos++;
                }
                top = top - 1;
            }
            else
            {
                while (top > -1 && stack[top] != '(')
                {
                    if (precedence(stack[top]) >= precedence(infix[i]))
                    {
                        char poped = pop();
                        postfix[pos] = poped;
                        pos++;
                    }
                    else
                        break;
                }

                push(infix[i]);
            }
        }
        else
        {
            postfix[pos] = infix[i];
            pos++;
        }
    }
    if (top == -1)
        cout << postfix;
    else
    {
        while (top != -1)
        {
            postfix[pos] = pop();
            pos++;
        }
        cout << postfix;
    }
    return 0;
}