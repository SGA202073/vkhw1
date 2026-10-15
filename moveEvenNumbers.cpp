int* evenFirst(int* arr, int len)
{
    int tmp, evenIndex = 0;
    for(int i = 0; i< len; i++)
        if(arr[i] % 2 == 0)
        {
            tmp = arr[i];
            arr[i] = arr[evenIndex];
            arr[evenIndex] = tmp;
            evenIndex++;
        }
    return arr;
}
