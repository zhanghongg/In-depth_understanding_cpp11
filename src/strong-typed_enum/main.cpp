#include <iostream>

using namespace std;

enum class Type { General, Light, Medium, Heavy };
enum class Type1 : char { General, Light, Medium, Heavy };
// feature
// can not implicitly convert
//
int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
