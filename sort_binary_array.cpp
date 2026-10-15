// 1 способ
int* sort_binary_array(int* arr, int len)
{
    int countZero = 0, i = 0;
    while(i < len )
    {
        if( arr[i] == 0)
            countZero++;
        i++;
    }
    for(i = 0; i < countZero; i++)
        arr[i] = 0;
    for(i = countZero; i < len;i++)
        arr[i] = 1;
    return arr;
}
// 2 способ, как в презентации
int* sort_binary_array(int* arr, int len)
{
    int tmp, left = 0, right = len - 1;
    while(left < right)
    {
        if(arr[left] == 1)
        {
            tmp = arr[right];
            arr[right] = arr[left];
            arr[left] = tmp;
            right--;
        }
        else
            left++;
    }
    return arr;
}