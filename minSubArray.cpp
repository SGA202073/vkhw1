int minSubArray(int* nums, int lenNums, int target)
{
    int max = lenNums + 1;
    int minLen = max;
    int left = 0;
    int curSum = 0;
    int windowSize;
    for( int right = 0; right < lenNums; right++)
    {
        curSum += nums[right];
        while(curSum >= target)
        {
            windowSize = right - left +1;
            if(windowSize < minLen)
                minLen = windowSize;
            curSum -= nums[left];
            left++;    
        }
    }
    if(minLen != max)
        return minLen;
    return 0;
}