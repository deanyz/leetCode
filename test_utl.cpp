#include "utl.hpp"

using namespace std;
int main()
{
    vector<int> nums { -2, 4, 5, 68, -9, 10 };
    printVector(nums);

    //partition(nums, 0, nums.size() - 1);
    quickSort(nums);
    printVector(nums);
    return 0;
}
