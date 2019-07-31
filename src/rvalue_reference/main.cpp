/*
 * show rvalue_reference.
 * note: 1. copy constructor and assigning operator is implicitly deleted when the user declares move constructor
 *       2. std::move   @brief  Convert a value to an rvalue.
 *       3. Eliminate unnecessary const keywords
 *       4. judge whether a type is a reference type.  is_lvalue_reference, is_rvalue_reference, is_reference
 *       5. judge whether a type is a movable type. is_move_constructible, is_trivially_move_constructible, is_nothrow_move_constructible
 *       6. Throwing exceptions is dangerous for moving constructors.Use noexcept and try to write a move constructor that does not throw exceptions.
 *       7. std::move_if_noexcept   @brief  Conditionally convert a value to an rvalue.
 *       8. perfect forwarding.
 */

#include <iostream>
#include <type_traits>

using namespace std;

class HugeMem {
public:
    HugeMem(int size) : _sz(size > 0 ? size : 1) {
        _c = new int[_sz];
    }
    ~HugeMem() {
        delete [] _c;
    }
    HugeMem(HugeMem&& hm) noexcept : _sz(hm._sz), _c(hm._c) {
        hm._c = nullptr;
    }

    int _sz;
    int* _c;
};

int g_construct = 0;
int g_destruct = 0;
int g_moveConstr = 0;

class Moveable {
public:
    Moveable() : _i(new int(3)), _h(1024) { cout << "g_construct : " << ++g_construct << endl; }
    ~Moveable() {
        delete _i;
        cout << "g_destruct : " << ++g_destruct << endl;
    }
    Moveable(Moveable&& m) noexcept : _i(m._i), _h(move(m._h)) {
        m._i = nullptr;
        cout << "g_moveConstr : " << ++g_moveConstr << endl;
    }
    int* _i;
    HugeMem _h;
};

Moveable getTemp() {
    Moveable tmp = Moveable();
    cout << hex << "Huge men from " << __func__ << " @" << tmp._h._c << endl;
    return tmp;
}

int main()
{
    Moveable a(getTemp());
    cout << hex << "Huge men from " << __func__ << " @" << a._h._c << endl;

    cout << "is_rvalue_reference sring&& : " << is_rvalue_reference<string&&>::value << endl;
    cout << "is_move_constructible sring : " << is_move_constructible<string>::value << endl;
    return 0;
}




