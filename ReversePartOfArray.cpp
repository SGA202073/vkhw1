#include<stdio.h>
#include<stdlib.h>
int lenght(FILE *IN)
{
    int n = 0, i;
    while(fscanf(IN, "%d", &i) == 1)
        n++;
    if(!feof(IN))
        return -1;
    return n-1;
}

void schit(FILE *IN, int *arr, int n, int *k)
{
    for(int i = 0; i < n; i++)
        fscanf(IN, "%d", &arr[i]);
    fscanf(IN, "%d", k);    
}
void reverseArray(int *arr, int left, int right)
{
    int tmp;
    while(left<right)
    {
        tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        left++;
        right--;
    }
}
int main()
{
    //последнее число в файле - часть, которую надо сдвинуть
    FILE*IN = fopen("input.txt", "r");
    if(IN == NULL)
        return -1;
    int i, len, k;
    len = lenght(IN);
    if(len == -1)
    {
        printf("в файле не только числа или файл пуст\n");
        fclose(IN);
        return -1;
    }
    if(len == 0)
    {
        printf("в файле нет массива\n");
        fclose(IN);
        return -1;
    }
    rewind(IN);
    int *arr = (int*)malloc(len*sizeof(int));
    if(arr == NULL)
    {
        fclose(IN);
        return -1;
    }
    schit(IN, arr, len, &k);
    printf("массив:");
    for(i = 0;i<len;i++)
        printf("%d ", arr[i]);
    if(k<0)
    {
        k = abs(k)%len;
        k = len - k;
    }
    else
        if(k>len)
            k = k%len;
    if(k%len != 0)
    {
        reverseArray(arr, 0, len-1);
        reverseArray(arr, 0, k-1);
        reverseArray(arr, k, len-1);
    }
    printf("развернутый массив: ");
    for( i = 0;i<len;i++)
        printf("%d ", arr[i]);
    printf("\n");
    fclose(IN);
    free(arr);
    return 0;
}