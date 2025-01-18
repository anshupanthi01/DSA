#define MAX 15
#include <iostream>
#include <string.h>
using namespace std;
int top = -1;
char exp[50]="562*42/1-1*-4*+";
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

int main(){
    int i, b, a;
    char ch;
    int var;
    int l = strlen(exp);
    for(i = 0; i < l; i++)
    {
        cout<<exp[i]<<"\n";
        if(exp[i] == '*' || exp[i] == '/' || exp[i] == '+' || exp[i] == '-')
        {
            a = pop();
            b = pop();
            switch(exp[i])
            {
                case '*':
                var = b*a;
                break;
                case '/':
                var = b/a;
                break;
                case '+':
                var = b+a;
                break;
                case '-':
                var = b-a;
                break;
                default:
                cout<<"Invalid";
                break;
            }
            push(var);
        }
        else{
            push(exp[i]-48);
        }
    }
    cout<<stack[top];
    return 0;
}