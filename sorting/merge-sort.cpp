#include <iostream>
#include <vector>
#include <span>
#include <algorithm>

void merge_sort_vector(std::span<int> input);
void recursive_routine(std::span<int> data, std::span<int> buffer);

int main()
{
    std::vector main_vec_0 {2,4,6,3,1,5,7};
    std::vector main_vec_1 {82,5,12,28,39,26,89,23,58,47,81,27,17,74,37,66,87,22,91,42,51,2,94,13,84,30,1,70,54,45,34,77,18,52,44,73,97,53,31,29,11,16,90,3,69,32,38,4,49,35,56,7,86,6,24,71,83,15,88,14,60,57,20,19,41,36,40,65,68,55,46,63,50,9,72,99,80,92,64,43,61,25,96,21,10,93,100,48,76,67,98,8,62,75,85,95,78,33,59,79};
    merge_sort_vector(main_vec_1);
    for (int value : main_vec_1)
    {
         std::cout << value << "\n";
    }
    std::cout << "\n";
    return 0;
}

void merge_sort_vector(std::span<int> input)
{
    std::vector<int> write_buffer(input.size());
    recursive_routine(input, write_buffer);

    return;
}

void recursive_routine(std::span<int> data, std::span<int> buffer)
{
    std::size_t data_len = data.size();
    if (data_len <= 1)
    {
        return;
    }

    unsigned int mid_index = data_len / 2;
    std::span left = data.subspan(0, mid_index);
    std::span right = data.subspan(mid_index, data_len-mid_index);
    
    recursive_routine(left, buffer);
    recursive_routine(right, buffer);

    std::merge(left.begin(), left.end(), right.begin(), right.end(), buffer.begin());
    std::copy_n(buffer.begin(), data_len, data.begin());

    return;
}
