#include <iostream>
#include <algorithm>

using namespace std;

int action1(int& e) { e *= 2; }
int action2(int& e) { cout << e << "\t"; }

int main()
{
    //
    int arr[5] = {1, 2, 3, 4, 5};
    for_each(arr, arr + sizeof(arr) / sizeof (arr[0]), action1);
    for_each(arr, arr + sizeof(arr) / sizeof (arr[0]), action2);
    // automatic range  --  range-based
    for (int& e : arr)
        cout << e << "\t";
    return 0;
}
s-
