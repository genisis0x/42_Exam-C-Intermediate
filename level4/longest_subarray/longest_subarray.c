/****************************************### Passed Exam Version ###*****************************************/

#include <string.h>
#include <stdlib.h>
#define is_odd(c) ((c - '0') % 2)

char    *longest_subarray(char *arr)
{
    int len = strlen(arr);
    int start, max_len = -1, sum = 0;
    int i,j;
    for(i = 0; i < len -1; i++)
    {
        sum = (is_odd(arr[i])) ? -1 : 1;
        for(j = i + 1; j < len; j++)
        {
            sum += (is_odd(arr[j])) ? -1 : 1;

            if(sum == 0 && max_len < j - i + 1)
            {
                max_len = j - i + 1;
                start = i;
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
    for(i = start, j = 0; i < start + max_len; i++, j++)
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
