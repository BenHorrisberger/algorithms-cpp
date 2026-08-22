#include <iostream>
#include <vector>
#include <span>
#include <algorithm>

void merge_sort_vector(std::span<int> input);
void recursive_routine(std::span<int> data, std::span<int> buffer);

int main()
{
    std::vector main_vec {2,4,6,3,1,5,7};
    merge_sort_vector(main_vec);
    for (int value : main_vec)
    {
         std::cout << value << ' ';
    }
    std::cout << "\n";
    return 0;
}

void merge_sort_vector(std::span<int> input)
{
    std::vector<int> input_copy(input.begin(), input.end());
    std::vector<int> write_buffer(input.size());
    recursive_routine(input_copy, write_buffer);
    std::copy(input_copy.begin(), input_copy.end(), input.begin()); 

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
