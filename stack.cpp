#define MAX 5
#include <iostream>
using namespace std;

int main()
{
    int stack[MAX], data;
    int a, TOP = -1;
    char ch;
    
    do{
        cout<< "1. Push" <<"\n";
        cout<< "2. Pop"<<"\n";
        cout<< "3. display"<<"\n";
        cout<< "4. Exit"<<"\n";
    cin>> a;
    switch(a)
    {
        case 1:
        if(TOP == MAX - 1){
        cout<< "Stack is overflow";
        }
        else{
            TOP = TOP+1;
            cout<<"Enter data: ";
            cin>>data;
            stack[TOP] = data;
        }
        break;
        case 2:
        if(TOP<0){
            cout<<"Stack underflow";
        }
        else{
            
            data = stack[TOP];
            cout<<"Deleted item is \t"<<data;
            TOP = TOP - 1;
        }
        break;
        case 3:
        if(TOP<0)
        {
            cout<<"Stack underflow";
        }
        else{
            for(int i=0; i<=TOP; i++)
            {
                cout<<stack[i];
            }
        }
        break;
        case 4:
        exit(0);
        break;
}

    cout<<"Continue?1(Y/N)"<<endl;
    cin>>ch;
}
    while(ch!='n');
    return 0;
}