void sortColors(int* nums, int len)
{
    int tmp, low = 0, mid = 0, high = len- 1;
    while(mid <= high)
    {
        if(nums[mid] == 0)
        {
            tmp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = tmp;
            low++;
            mid++;
        }
        else
        {
            if(nums[mid] == 1)
                mid++;
            else
            {
                tmp = nums[high];
                nums[high] = nums[mid];
                nums[mid] = tmp;
                high--;
            }
        }
    }
}