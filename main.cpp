#include "Array.hpp"

int main() {
    Array dArray1(3, 1.0, 2.0, 0.0);
    dArray1[0] = 4.0;
    dArray1[2] = 3;
    dArray1[1] = dArray1[0];
    dArray1.printArray();

    const Array dArray2(1, 7.0);
    // dArray2[1] = 9.0;
    dArray2.printArray();

    return 0;
}
