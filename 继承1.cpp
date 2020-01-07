#include<iostream>
 
using namespace std;
 
class Grandpa
{
public:
    int year_old;
};
 
class Parent_f:public Grandpa {};
class Parent_m:public Grandpa {};
 
class Son:public Parent_f,public Parent_m {};
 
int main()
{
    Son son;
    son
    cout << "Hello world!" << endl;
    return 0;
}

