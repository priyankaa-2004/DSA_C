#include<iostream>
using namespace std;

class abc{
    static int a;
    int b;
    public:
    void in(){
        a=5,b=6;
    }
    static void t1(){
        cout<<a<<endl;
    }
    void t2(){
        cout<<a<<b<<endl;
    }
};

int abc::a;

int main(){
abc ob1;
ob1.in();
ob1.t1();
ob1.t2();
return 0;
}