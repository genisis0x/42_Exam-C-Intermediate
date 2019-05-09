/****************************************### Passed Exam Version ###*****************************************/

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
            sum += (is_odd(arr[j])) ? -1 : 1; // add '-1' if number is odd and '+1' if the number is even.

            if(sum == 0 && max_len < j - i + 1) // update max_len & start_index, if the sum is zero and the max_len is less then the current max_len
            {
                max_len = j - i + 1;
                start_index = i;
            }
        }
    }
    if(max_len == -1) // if the max_len is unchanged -> No valid String // just return "0" 
    {
        char *r = (char *)malloc(sizeof(char) * 1);
        r[0] = '\0';
        return r;
    }
    char *r = (char *)malloc(sizeof(char) * (max_len + 1)); // calculate the desired string and return it.
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
