#include <string.h>
#include <stdlib.h>

int odd_num(char c)
{
    return (!((c - '0') % 2));
}

char* longest_subarray(char* arr)
{
    int len = strlen(arr);
    int sum = 0, start_index, max_len = -1;
    int i, j;
    for(i = 0; i < len -1; i++)
    {
        sum = (odd_num(arr[i]) == 1) ? -1 : 1;
        for(j = i + 1; j < len; j++)
        {
            odd_num(arr[j]) == 1 ? (sum += -1) : (sum += 1);

            if(sum == 0 && max_len < j - i + 1)
            {
                max_len = j - i + 1;
                start_index = i;
            }
        }
    }
    if (max_len == -1)
    {
        return NULL;
    }
    char *res = (char *)malloc(sizeof(char) * (max_len + 1));
    for(i = start_index, j = 0; i < max_len; i++)
    {
        res[j] = arr[i];
    }
    res[max_len] = '\0';
    return res;
}

#include <stdio.h>
int main (int ac, char **av)
{
    printf("%s", longest_subarray(av[1]));
    return 0;
}
