#include <iostream>
#include <cstring>

using namespace std;

struct Student {
    Student(bool g, int a) : _gender(g), _age(a) {}
    bool _gender;
    int _age;
};

class Singer {
public:
    enum Type {STUDENT, NATIVE, FOREIGNER};

    Singer(bool g, int a) : _s(g, a) { _t = STUDENT; }
    Singer(int i) : _id(i) { _t = NATIVE; }
    Singer(const char* n, int s) {
        int size = (s>9) ? 9: s;
        memcpy(_name, n, size);
        _name[s] = '\0';
        _t = FOREIGNER;
    }li

private:
    Type _t;
    union {     // anonymous unrestricted union;
        Student _s;
        int _id;
        char _name[10];
    };
};

int main()
{
    Singer(true, 13);
    Singer(310217);
    Singer("J Michael", 9);
    return 0;
}
