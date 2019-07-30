#include <iostream>

using namespace std;

class HugeMem {
public:
    HugeMem(int size) : _sz(size > 0 ? size : 1) {
        _c = new int[_sz];
    }
    ~HugeMem() {
        delete [] _c;
    }
    HugeMem(HugeMem&& hm) : _sz(hm._sz), _c(hm._c) {
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
    Moveable(Moveable&& m) : _i(m._i), _h(move(m._h)) {
        m._i = nullptr;
        cout << "g_moveConstr : " << ++g_moveConstr << endl;
    }
    int* _i;
    HugeMem _h;
};

Moveable getTemp() {
    Moveable tmp = Moveable();
//    cout << hex << "Huge men from " << __func__ << " @" << tmp._h._c << endl;
    return tmp;
}

int main()
{
    Moveable&& a(getTemp());
//    cout << hex << "Huge men from " << __func__ << " @" << a._h._c << endl;
    return 0;
}
