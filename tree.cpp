#include<iostream>
using namespace std;
void func(int n){
    if(n>0){
        cout<<n<<"\t";
        func(n-1);
        func(n-1);
    }
}
int main(){
    func(3);
}