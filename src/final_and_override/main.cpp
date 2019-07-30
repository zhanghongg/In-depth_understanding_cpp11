#include <iostream>

using namespace std;

/*
 * show final
 */
class Base {
    virtual void fun();
};

class Derived : public Base {
    virtual void fun() final;
};

class DDerived : public Derived {
//    virtual void fun(); // error: overriding final function ‘virtual void Derived::fun()’           ^
};

/*
 * show override
 */
class Base1 {
    virtual void fun(int);
};

class Derived1 : public Base1 {
public:
    virtual void fun(int) override;
//    virtual void fun(double) override; // error: ‘virtual void Derived1::fun(double)’ marked ‘override’, but does not override                                                                                                                                                                                                    ^
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
