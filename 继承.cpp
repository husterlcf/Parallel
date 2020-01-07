#include "iostream"
 
using namespace std;
 
class Parent_f
{
public:
    void show()
    {
        cout<<"This is Parent_f\n";
    }
};
class Parent_m
{
public:
    void show()
    {
        cout<<"This is Parent_m\n";
    }
};
class Son:public Parent_f,public Parent_m
{
public:
    void display()
    {
        cout<<"This is son\n";
    }
    void show()
    {
        cout<<"This is Son\n";
    }
};
int main()
{
    Son son;
    son.show();
    son.Parent_f::show();//注意和上面一条进行区别 
    son.display();
    cout << "Hello world!" << endl;
    return 0;

}
