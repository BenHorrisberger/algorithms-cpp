#include <iostream>
#include <vector>

void bubble_sort_vector(std::vector<int>& input)
{
    std::size_t input_len = input.size();
    int tmp {};
    for (int i = 0; i < input_len; i++)
    {
        for (int j = input_len - 1; j > i; j--)
        {
            if (input[j] < input[j-1])
            {
                tmp = input[j];
                input[j] = input[j-1];
                input[j-1] = tmp;
            }
                
        }
    }
    return;
}

int main()
{
    std::vector vec {72,66,38,16,65,39,30,37,75,8,52,73,11,80,77,1,71,36,18,51,57,
                     41,47,96,5,15,49,68,74,40,32,12,4,29,92,60,70,85,21,27,25,45,
                     56,88,95,17,22,90,78,97,84,83,19,63,99,58,98,59,91,76,35,86,50
                    ,100,33,7,13,3,44,81,14,94,82,42,9,6,24,48,34,53,43,55,67,2,46,26
                    ,23,61,28,89,64,20,93,87,10,79,69,31,54,62};

    bubble_sort_vector(vec);

    for (int value : vec)
    {
        std::cout << value << "\n";
    }

    return 0;
}
