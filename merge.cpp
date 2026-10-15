int* merge(int* arr1, const int* arr2, int len1, int len2)
{
    int pointer1 = len1 - len2 - 1;
    int pointer2 = len2 - 1;
    int pointer3 = len1 - 1;
    while(pointer2 >= 0)
    {
        if(pointer1 >= 0 && arr1[pointer1] > arr2[pointer2])
        {
            arr1[pointer3] = arr1[pointer1];
            pointer1--;
        }
        else
        {
            arr1[pointer3] = arr2[pointer2];
            pointer2--;
        }
        pointer3--;
    }
    return arr1;
}