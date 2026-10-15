int* moveZeros(int* arr, int len)
{
    int i, tmp,nonZeroIndex = 0;
    for( i = 0; i < len; i++)
        if(arr[i] != 0)
        {
            tmp = arr[i];
            arr[i] = arr[nonZeroIndex];
            arr[nonZeroIndex] = tmp;
            nonZeroIndex++;
        }
    return arr;
}