#include <iostream>
#include <cstdlib>

using namespace std;

typedef unsigned char uint8;
struct RGBA {
    uint8 _r;
    uint8 _g;
    uint8 _b;
    uint8 _a;
    RGBA(uint8 r, uint8 g, uint8 b, uint8 a = 0) :
        _r(r), _g(g), _b(b), _a(a) {}
};

RGBA operator "" _C(const char* col, size_t n) {
    const char* p = col;
    const char* end = col + n;
    const char* r, *g, *b, *a;
    r = g = b = a = nullptr;

    for (; p != end; ++p) {
        if (*p == 'r')
            r = p;
        else if (*p =='g')
            g = p;
        else if (*p =='b')
            b = p;
        else if (*p =='a')
            a = p;
    }

    if ((r == nullptr) || (g == nullptr) || (b == nullptr))
        throw;
    else if (a == nullptr)
        return RGBA(atoi(r+1), atoi(g+1), atoi(b+1));
    else
        return RGBA(atoi(r+1), atoi(g+1), atoi(b+1), atoi(a+1));
}

std::ostream& operator << (std::ostream& out, RGBA& col) {
    return out << "r: " << (int)col._r << ", g: " << (int)col._g << ", b: " << (int)col._b << ", a: " << (int)col._a << endl;
}

void blend(RGBA&& col1, RGBA&& col2) {
    cout <<"blend " << endl << col1 << col2 << endl;
}

int main()
{
    blend("r255 g132 b115"_C, "r123 g31 b232 a8"_C);
    return 0;
}
