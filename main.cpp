#include "Array.hpp"

int main() {
    Array<double, 5> array1;
    array1[0] = 4.0;
    array1[2] = 3;
    array1[1] = array1[0];
    array1.print_array();

    const Array<int, 7> array2;
    // array2[1] = 9.0;
    array2.print_array();

    return 0;
}
