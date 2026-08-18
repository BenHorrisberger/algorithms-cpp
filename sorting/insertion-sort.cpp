#include <iostream>
#include <array>

void print_arr(std::array<int, 6>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
         std::cout << arr[i] << ' ';
    }
    std::cout << "\n";
}

void insertion_sort(std::array<int, 6>& arr)
{
    int value_to_sort{};
    int compare_index{};
    unsigned int iteration = 0;

    for (int sort_index = 1; sort_index < arr.size(); sort_index++)
    {
        value_to_sort = arr[sort_index];
        compare_index = sort_index - 1;
        while (arr[compare_index] > value_to_sort)
        {
            arr[compare_index + 1] = arr[compare_index];
            compare_index--;
            if (compare_index < 0)
            {
                break;
            }
        }
        arr[compare_index + 1] = value_to_sort;

        std::cout << "Iteration " << iteration << ": ";
        print_arr(arr);
        iteration++;
    }
}

int main()
{
    std::array<int, 6> arr {5,2,4,6,1,3};
    std::cout << "Start array: ";
    print_arr(arr);
    insertion_sort(arr);
    std::cout << "Final array: ";
    print_arr(arr);
    return 0;
}
