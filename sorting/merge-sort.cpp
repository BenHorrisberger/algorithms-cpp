#include <iostream>
#include <array>
#include <algorithm>

// need merge_sort and merge_arrays funcitons
// ==========================================
// THOUGHTS --
// need a way to initialize std::array size as a variable.

void merge_sort(std::array<int, 8>& arr)
{
    return;
}

void print_array(std::array<int, 8>& arr)
{
    for (int element : arr)
    {
        std::cout << element << ' ';
    }
    std::cout << "\n";
}

int main()
{
    std::array<int, 8> main_array {1,2,3,4,5,6,7,8};
    std::array<int, 4> main_sub_array;
    std::copy(main_array.begin(), main_array.begin() + 4, main_sub_array.begin());

    for (int element : main_sub_array)
    {
        std::cout << element << ' ';
    }
    std::cout << "\n";

    return 0;
}
