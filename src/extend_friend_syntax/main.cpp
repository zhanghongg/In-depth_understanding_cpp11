#include <iostream>

using namespace std;

template <typename T> class DefenderT {
public:
    friend T;
    void Defence(int x, int y) {}
    void Tackle(int x, int y) {}

private:
    int pos_x = 15;
    int pos_y = 0;
    int speed = 2;
    int stamina = 120;
};

template <typename T> class AttackerT {
public:
    friend T;
    void Move(int x, int y) {}
    void SpeedUp(float ratio) {}

private:
    int pos_x = 0;
    int pos_y = -30;
    int speed = 3;
    int stamina = 100;
};

using Defender = DefenderT<int>;
using Attacker = AttackerT<int>;

#define UNIT_TEST
#ifdef UNIT_TEST
class Validator {
public:
    void Validate (int x, int y, DefenderT<Validator>& d) {}
    void Validate (int x, int y, AttackerT<Validator>& a) {}
};

int main() {
    cout << "Hello World!" << endl;
    return 0;
}
#endif
