#include <iostream>
#include <vector>
using namespace std;

bool possible(vector<long long>& a, long long c, long long w) {
    long long area = 0;
    for (long long x : a) {
        long long side = x + 2 * w;
        area += side * side;
        if (area > c) return false; // early exit optimization
    }
    return area <= c;
}

int main() {
    vector<long long> a = {2, 3, 4};
    long long c = 100;
    long long w = 1;

    if (possible(a, c, w))
        cout << "Possible\n";
    else
        cout << "Not possible\n";

    return 0;
}
