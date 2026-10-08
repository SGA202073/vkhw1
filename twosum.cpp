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

void schit(FILE *IN, int *arr, int n, int *target)
{
    for(int i = 0; i < n; i++)
        fscanf(IN, "%d", &arr[i]);
    fscanf(IN,"%d", target );
}

int twosum(int *arr, int target, int len, int *result)
{
    int left = 0;
    int right = len - 1;
    int sum;
    while(left < right)
    {
        sum = arr[left] +arr[right];
        if(sum == target)
        {
            result[0] = left;
            result[1] = right;
            return 1;
        }
        else
        {
            if(sum < target)
                left++;
            else
                right++;
        }
    }
        return 0;
}
int main()
{
    // массив будет из целых чисел
    // проверка на отсорттированность опущена,последний элемент в файле - target
    FILE*IN = fopen("input.txt", "r");
    if(IN == NULL)
        return -1;
    int len, target;
    int result[2];
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
    schit(IN, arr, len, &target);
    if(twosum(arr, target, len, result) ==  0)
        printf("нет таких чисел\n");
    else
        printf("такие числа - %d и %d, их индексы - %d и %d\n", arr[result[0]], arr[result[1]], result[0], result[1] );
    fclose(IN);
    free(arr);
    return 0;
}