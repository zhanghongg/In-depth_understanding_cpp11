#include <iostream>
#include <stdarg.h>
#include <stdio.h>
using namespace std;

// variadic function
double sumOfFloat(int count, ...) {
    va_list ap;
    double sum=0;
    va_start(ap, count);
    for (int i=0; i < count; i++) {
        sum += va_arg(ap, double);
    }
    va_end(ap);
    return sum;
}

int main0()
{
    cout << sumOfFloat(5,1.0,1.0,1.0,1.0,1.0) << endl;
    return 0;
}
// variadic template
// Elements is called the
// * template parameter pack.
template <typename... Elements> class tuple;
// non type variadic template
template <int... A> class NonTypeVariadicTemplate {};
NonTypeVariadicTemplate<1,2,3,4> ntvt;
int main1() {
    return 0;
}

// non type template unpack
template<long... nums> struct multiply;

template<long first, long... last>
struct multiply<first, last...> {
    static const long val = first * multiply<last...>::val;
};

template<>
struct multiply<> {
    static const long val = 1;
};

int main2() {
    cout << multiply<2, 3, 4, 5>::val << endl;
    return 0;
}

// use c++11 realize printf
#include <stdexcept>

void Printf(const char* s) {
    while (*s) {
        if(*s == '%' && *++s != '%')
            throw runtime_error("invalid format string: missing arguments");
        cout << *s++;
    }
}

template <typename T, typename... Args>
void Printf(const char* s, T value, Args... args) {
    while (*s) {
        if(*s == '%' && *++s != '%') {
            cout << value;
            return Printf(++s, args...);
        }
        cout << *s++;
    }
    throw runtime_error("extra arguments provided to Printf");
}

int main3() {
    Printf("hello %s \n", string("world"));
    return 0;
}

/*
 * template<typename... A> class T: private B<A>...{};    -->  class T<X,Y>: private B<X>, private B<Y> {};
 * template<typename... A> class T: private B<A...>{};    -->  class T<X,Y>: private B<X, Y> {};
 */

//example

template<typename... T> void DummyWrapper(T... t) {}
template <typename T> T pr(T t) {
    cout << t;
    return t;
}
template<typename... A>
void VTPrint(A... a) {
    DummyWrapper(pr(a)...);   // unpack -> pra(1),pra(", ") ...
}
int main4() {
    VTPrint(1111111111, ", ", 5555555, "...");
    return 0;
}

// example "sizeof..."
#include <cassert>
template <class... A> void Print(A... args) {
    assert(false); // non 6 args partial specialization
}

// realize 6 args partial specialization
void Print(int a1, int a2, int a3, int a4, int a5, int a6) {
    cout << a1 << ", " << a2 << ", " << a3 << ", " << a4 << ", " << a5 << ", " << a6 << endl;
}

template <class... A> int Vaargs(A... args) {
    int size = sizeof...(A);

    switch(size) {
    case 0: Print(99, 99, 99, 99, 99, 99); break;
    case 1: Print(99, 99, args..., 99, 99, 99); break;
    case 2: Print(99, 99, args..., 99, 99); break;
    case 3: Print(args..., 99, 99, 99); break;
    case 4: Print(99, args..., 99); break;
    case 5: Print(99, args...); break;
    case 6: Print(args...); break;
    default: Print(0, 0, 0, 0, 0, 0);
    }
    return size;
}

int main5() {
    Vaargs();
    Vaargs(1);
    Vaargs(1,2);
    Vaargs(1,2,3);
    Vaargs(1,2,3,4);
    Vaargs(1,2,3,4,5);
    Vaargs(1,2,3,4,5,6);
    Vaargs(1,2,3,4,5,6,7);
    return 0;
}

// example: variadic template + perfect forwarding

struct A {
    A() {}
    A(const A& a) { cout << "Copy Constructed " << __func__ << endl; }
    A(A&& a) { cout << "Move Constructed " << __func__ << endl; }
};

struct B {
    B() {}
    B(const B& a) { cout << "Copy Constructed " << __func__ << endl; }
    B(B&& a) { cout << "Move Constructed " << __func__ << endl; }
};

// define variadic template
template <typename... T> struct MultiTypes;
template<typename T1, typename... T>
struct MultiTypes<T1, T...> : public MultiTypes<T...> {
    T1 t1;
    MultiTypes<T1, T...>(T1 a, T... b) :
        t1(a), MultiTypes<T...>(b...) {
        cout << "MultiTypes<T1, T...> (T1 a, T... b)" << endl;
    }
};
template<> struct MultiTypes<> {
    MultiTypes<>() {
        cout << "MultiTypes<> ()" << endl;
    }
};

// perfect forwarding
template<template<typename...> class VariadicType, typename... Args>
VariadicType<Args...> Build(Args&&... args) {
    return VariadicType<Args...>(std::forward<Args>(args)...);
}

int main() {
    A a;
    B b;
    Build<MultiTypes>(a,b);
    return 0;
}


