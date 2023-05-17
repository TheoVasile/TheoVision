#include <iostream>
#include <array>

using namespace std;

class Matrix{
    public:
        Matrix(int rows, int cols);
    private:
        int rows;
        int cols;
        array<array<float, rows>, cols> vals;
}