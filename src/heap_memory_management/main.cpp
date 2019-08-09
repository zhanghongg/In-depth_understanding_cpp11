#include <iostream>
#include <memory>
using namespace std;

// auto_ptr deprecated
// * unique_ptr, shared_ptr, weak_ptr

int main0()
{
    unique_ptr<int> up1(new int(11));
//    unique_ptr<int> up2 = up1;    //error
    cout << *up1 << endl;
    unique_ptr<int> up3 = move(up1);
    cout << *up3 << endl;
//    cout << *up1 << endl; // run error
    up3.reset(); // explicitly free memory
    up1.reset(); // no run error
//    cout << *up3 << endl; // error

    shared_ptr<int> sp1(new int(22));
    shared_ptr<int> sp2 = sp1;
    cout << *sp1 << endl;
    cout << *sp2 << endl;
    sp1.reset();
    cout << *sp2 << endl;;
    return 0;
}

/*
 * weak_ptr
 */

void check(weak_ptr<int>& wp) {
    shared_ptr<int> sp = wp.lock();
    if (sp != nullptr)
        cout << "still " << *sp << endl;
    else
        cout << "pointer is invalid." << endl;
}
int main() {
    shared_ptr<int> sp1(new int(22));
    shared_ptr<int> sp2 = sp1;
    weak_ptr<int> wp = sp1;
    cout << *sp1 << endl;
    cout << *sp2 << endl;
    check(wp);

    sp1.reset();
    cout << *sp2 << endl;
    check(wp);

    sp2.reset();
    check(wp);


}
