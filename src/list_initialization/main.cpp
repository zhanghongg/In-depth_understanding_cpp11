#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
 * list initialization of built-in type
 */
int a[] = {1, 2, 3};
int b[] {4, 5, 6};
vector<int> c{1, 2, 3};
map<int,float> d = {{1, 1.0f}, {2, 2.0f}, {3, 3.0f}};

/*
 * list initialization of custom type
 */
enum Gender {boy, gril};
class People {
public:
    People(initializer_list<pair<string, Gender>> l) {
        auto i = l.begin();
        for (; i != l.end(); ++i) {
            _data.push_back(*i);
        }
    }
private:
    vector<pair<string, Gender>> _data;
};
People p = {{"Garfield", boy}, {"HelloKitty", gril}};

/*
 * list initialization of func.
 */
void func(initializer_list<int> iv) {
    auto it = iv.begin();
    for (; it != iv.end(); ++it) {
        cout << *it << "\t";
    }
    if(iv.size() != 0)
        cout << endl;
}

/*
 * Prevent type narrowing.
 */
const int x = 1024;
const int y = 10;

char a1 = x;
char* b1 = new char(1024);

//char c1 = {x};
char d1 = {y};
//unsigned char e1{-1};

float f1{7};
//int g1{2.0f};
//float* h1 = new float{1e48};
float i = 1.2l;

int main()
{
    func({1, 2, 3});
    func({});
    return 0;
}
