//оказалось, что нужно писать не всю программу, а только кусок кода, как в презентации, поэтому далее будет именно так
int* merge_sorted_arrays(const int* arr1, const int* arr2, int len1, int len2) 
{
    int i = 0, j = 0, k = 0, len = len1+len2;
    int* merged_arr = (int*)malloc(len*sizeof(int));
    if(merged_arr == NULL)
        return NULL;
    while(i < len1 && j < len2)
    {
        if(arr1[i] < arr2[j])
        {
            merged_arr[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            merged_arr[k] = arr2[j];
            j++;
            k++;
        }
    }
    while(i < len1)
    {
        merged_arr[k] = arr1[i];
        k++;
        i++;
    }
    while(j < len2)
    {
        merged_arr[k] = arr2[j];
        k++;
        j++;
    }
    return merged_arr;
}