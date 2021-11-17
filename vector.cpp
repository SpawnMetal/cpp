
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{1, 2, 3};

    // C-style
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << i << " = " << v[i] << std::endl;
    }

    std::cout << std::endl;

    // Modern C++:
    for (auto &num : v)
    {
        std::cout << num;
    }
}