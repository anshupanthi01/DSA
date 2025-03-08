#include <iostream>
using namespace std;
void TOH(int n, char S, char D, char M);
int main(){
    int n;
    cout<<"Enter the numDer of disks: ";
    cin>>n;
    TOH(n, 'S', 'D', 'M');
    return 0;
}
void TOH(int n, char S, char D, char M){
    if(n>0){
        TOH(n-1, M, S, D);
    }
}