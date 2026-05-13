#include <iostream>

int main() {
    // int* ptr{new int{5}};
    // int** ptrptr{&ptr};

    // // std::cout << *ptrptr << "\n";   // displays memory address of ptr
    // // std::cout << **ptrptr << "\n";  // displays 5

    // i  can delete ptr but not ptrptr because the pointer is on the stack! what if i put the
    // pointer on the heap?  - NO

    // historically used to create dynamic 2d arrays:

    const int length{5};
    int** array{new int*[length]};  // array of 10 int pointers - ROWS
    for (int count{0}; count < length; ++count) {
        array[count] = new int[5];
    }  // create 5x5 array

    // insert elements
    for (int row{0}; row < length; ++row) {
        for (int col{0}; col < length; ++col) {
            array[row][col] = col + 1;
        }
    }

    // display elements
    for (int row{0}; row < length; ++row) {
        for (int col{0}; col < length; ++col) {
            std::cout << array[row][col] << " ";
        }
        std::cout << "\n";
    }

    // delete elements
    for (int count{0}; count < length; ++count) {
        delete[] array[count];  // delete columns
    }
    delete[] array;  // delete rows. If delete the rows first, columns will be orphaned on the heap
                     // (no bueno)

    array = nullptr;  // doesn't really matter since main terminates soon BUT if we refactor to move
                      // this logic elsewhere, better to assign array to a nullptr

    return 0;
}