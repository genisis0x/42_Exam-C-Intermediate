/****************************************###Passed Exam Version###*****************************************/

#include <stdlib.h>
#include <string.h>

int is_odd(char c)
{
    return ((c - '0') % 2);
}

char    *longest_subarray(char *arr)
{
    int i, j;
    int sum = 0, start_index, max_len = -1;
    int len = strlen(arr);
    
    for(i = 0; i < len -1; i++)
    {
        sum = (is_odd(arr[i])) ? -1 : 1;
        for(j = i + 1; j < len; j++)
        {
            sum += (is_odd(arr[j])) ? -1 : 1;

            if(sum == 0 && max_len < j - i + 1)
            {
                max_len = j - i + 1;
                start_index = i;
            }
        }
    }
    if(max_len == -1)
    {
        char *r = (char *)malloc(sizeof(char) * 1);
        r[0] = '\0';
        return r;
    }
    char *r = (char *)malloc(sizeof(char) * (max_len + 1));
    for(i = start_index, j = 0; i < max_len + start_index; i++, j++)
        r[j] = arr[i];
    r[j] = '\0';
    return r;
}

// #include <stdio.h>
// int main(int ac, char **av)
// {
//     if(ac == 2)
//     {
//         char *r = longest_subarray(av[1]);
//         char *s = "Fuck";
//         printf("%s", (strlen(r)) ? r : s);
//     }
//     printf("\n");
// }
