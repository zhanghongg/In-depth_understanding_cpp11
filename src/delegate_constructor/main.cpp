#include <iostream>
#include <list>
#include <deque>
#include <vector>

using namespace std;

class TDConstructed
{
private:
    template<class T> TDConstructed(T first, T last) :
        _l(first, last) {}
    list<int> _l;
public:
    TDConstructed(vector<short> &v) :
        TDConstructed(v.begin(), v.end()) {}
    TDConstructed(deque<int> &q) :
        TDConstructed(q.begin(), q.end()) {}
};

class DCExcept
{
public:
    DCExcept(double d)
        try : DCExcept(1,d) {
            cout << "Run the body" << endl;
        }
        catch(...){
            cout << "caught exception." << endl;
        }
private:
    DCExcept(int i, double d) {
        cout << "going to throw!" << endl;
        throw 0;
    }
    int _type;
    double _data;
};

int main()
{
    cout << "Hello World!" << endl;
    DCExcept d(1.0);
    return 0;
}
