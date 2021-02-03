

#include <iostream>

using namespace std;
int main() {
    int x = -1;
    cout << (-30 >> 31) <<endl;
    int y = x ^ (x >> 31);
    cout << y  << endl;

    cout << (0 ^ 1 ) <<endl;
    return 0;
}