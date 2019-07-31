/*
 * POD = trivial + standard layout.
 */

#include <iostream>
#include <type_traits>

using namespace std;

struct Trivial1 {};
struct Trivial2 {
public:
    int _a;
private:
    int _b;
};

struct Trivial3 {
    Trivial1 _a;
    Trivial2 _b;
};

struct Trivial4 {
    Trivial2 _a[23];
};

struct Trivial5 {
    int _x;
    static int _y;
};

struct NonTrivial1 {
    NonTrivial1() : _z(32) {}
    int _z;
};
struct NonTrivial2 {
    NonTrivial2();
    int _w;
};
NonTrivial2::NonTrivial2() = default;
struct NonTrivial3 {
    Trivial5 _a;
    virtual void f();
};

struct SLayout1 {};
struct SLayout2 {
private:
    int _x;
    int _y;
};
struct SLayout3 : SLayout1 {
    int _x;
    int _y;
    void f();
};
struct SLayout4 : SLayout1 {
    int _x;
    SLayout1 _y;
};
struct SLayout5 : SLayout1, SLayout3 {};
struct SLayout6 {static int _y;};
struct SLayout7 : SLayout6 { int _x; };

struct NonSLayout1 : SLayout1 {
    SLayout1 _x;
    int _i;
};
struct NonSLayout2 : SLayout2 { int _z; };
struct NonSLayout3 : NonSLayout2 {};
struct NonSLayout4 {
public:
    int _x;
private:
    int _y;
};


union U{};
union U1{ U1(){} };
enum E{};
typedef double* DA;
typedef void (*PF)(int, double) ;

int main()
{
    cout << is_trivial<Trivial1>::value << endl;
    cout << is_trivial<Trivial2>::value << endl;
    cout << is_trivial<Trivial3>::value << endl;
    cout << is_trivial<Trivial4>::value << endl;
    cout << is_trivial<Trivial5>::value << endl;
    cout << is_trivial<NonTrivial1>::value << endl;
    cout << is_trivial<NonTrivial2>::value << endl;
    cout << is_trivial<NonTrivial3>::value << endl;
    cout << "--------------------------" << endl;
    cout << is_standard_layout<SLayout1>::value << endl;
    cout << is_standard_layout<SLayout2>::value << endl;
    cout << is_standard_layout<SLayout3>::value << endl;
    cout << is_standard_layout<SLayout4>::value << endl;
    cout << is_standard_layout<SLayout5>::value << endl;
    cout << is_standard_layout<SLayout6>::value << endl;
    cout << is_standard_layout<SLayout7>::value << endl;
    cout << is_standard_layout<NonSLayout1>::value << endl;
    cout << is_standard_layout<NonSLayout2>::value << endl;
    cout << is_standard_layout<NonSLayout3>::value << endl;
    cout << is_standard_layout<NonSLayout4>::value << endl;
    cout << "--------------------------" << endl;
    cout << is_pod<U>::value << endl;
    cout << is_pod<U1>::value << endl;
    cout << is_pod<E>::value << endl;
    cout << is_pod<int>::value << endl;
    cout << is_pod<DA>::value << endl;
    cout << is_pod<PF>::value << endl;
    return 0;
}
