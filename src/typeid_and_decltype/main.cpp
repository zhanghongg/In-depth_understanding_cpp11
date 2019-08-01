#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;

struct White {};
struct Black {};

int main0()
{
    /*
     * typeid
     */
    White a;
    Black b;
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;

    White c;
    bool a_b_sametype = (typeid(a).hash_code() == typeid(b).hash_code());
    bool a_c_sametype = (typeid(a).hash_code() == typeid(c).hash_code());
    cout << "Same type ?" << endl;
    cout << "A and B ? " << (int)a_b_sametype << endl;
    cout << "A and C ? " << (int)a_c_sametype << endl;

    /*
     * decltype
     */
    int i = 0;
    decltype (i) j = 0;
    cout << typeid (j).name() << endl;

    float a1 = 0;
    double b1 = 0;
    decltype (a1+b1) c1;
    cout << typeid (c1).name() << endl;

    return 0;
}

/*
 * Application of decltype
 */

// 1. use decltype with using/typedef
using size_t = decltype (sizeof(0));
using ptrdiff_t = decltype ((int*)0 - (int*)0);
using nullptr_t = decltype (nullptr);

// 2. increase code readability
int main() {
    vector<int> vec;
    typedef decltype (vec.begin()) vectype;
    for (vectype i = vec.begin(); i < vec.end(); i++) {
        // TODO
    }
    for (decltype (vec)::iterator it = vec.begin(); it < vec.end(); it++) {
        // TODO
    }
}

// 3. reuse anonymous types
