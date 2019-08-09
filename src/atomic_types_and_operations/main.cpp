#include <iostream>
#include <atomic>
#include <thread>
using namespace std;

atomic_llong total {0};

void func(int) {
    for (long long i=0; i<100000000LL; ++i) {
        total += i;
    }
}

int main()
{
    thread t1(func, 0);
    thread t2(func, 0);
    t1.join();
    t2.join();
    cout << total << endl;
    return 0;
}
