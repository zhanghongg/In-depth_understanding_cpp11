#include <iostream>
#include <type_traits>
#include <map>
using namespace std;

using uint = unsigned int;
typedef unsigned int UINT;

template<typename T> using MapString = map<T, char*>;

int main()
{
    cout << is_same<uint, UINT>::value << endl;
    MapString<int> m;
    return 0;
}
