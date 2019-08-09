#include <iostream>

using namespace std;

// range of application : array index, switch-case, enum initialize ...
constexpr int get() { return 1; }


constexpr int Fibonacci(int n) {
    return (n == 1) ? 1 : ((n == 2) ? 1 : Fibonacci(n-1) + Fibonacci(n-2));
}

int main0()
{
    int fibo[] = {
        Fibonacci(11), Fibonacci(12),
        Fibonacci(13), Fibonacci(14),
        Fibonacci(15), Fibonacci(16)
    };
    for (int& e : fibo) {
        cout << e << "\t";
    }
    return 0;
}

template <long num>
struct SFibonacci {
    static const long val = SFibonacci<num-1>::val + SFibonacci<num-2>::val;
};
template<> struct SFibonacci<2> { static const long val = 1; };
template<> struct SFibonacci<1> { static const long val = 1; };
template<> struct SFibonacci<0> { static const long val = 0; };
int main() {
    int fibo[] = {
        SFibonacci<11>::val, SFibonacci<12>::val,
        SFibonacci<13>::val, SFibonacci<14>::val,
        SFibonacci<15>::val, SFibonacci<16>::val,
    };
    for (int& e : fibo) {
        cout << e << "\t";
    }
    return 0;
}
