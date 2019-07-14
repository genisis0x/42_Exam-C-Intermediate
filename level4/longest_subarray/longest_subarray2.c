
 // O (N) -> Time Complexity
 // O (N) -> Space Complexity

#include <string.h>
#include <stdlib.h>
#define is_odd(c) ((c - '0') % 2)
#define max(a, b) (a > b ? a : b)

char    *longest_subarray(char *arr)
{
    int n = strlen(arr);
    int prefix_sum[n];
    int min, max;
    int i,j;
    int max_size = -1;
    int start_index;

    prefix_sum[0] = (is_odd(arr[0])) ? -1 : 1;
    min = arr[0]; max = arr[0];

    for(i = 1; i < n; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + (is_odd(arr[0])) ? -1 : 1;
        
        if(prefix_sum[i] < min)
            min = prefix_sum[i];
        if(prefix_sum[i] > min)
            max = prefix_sum[i];      
    }

    // We need to find the subarray where subarray sum is 0 and start index is not 0. 
    // This problem is equivalent to finding two indexes i & j in sumleft[] such that 
    // sumleft[i] = sumleft[j] and j-i is maximum. 
    // To solve this, we can create a hash table with size = max-min+1
    // where min is the minimum value in the sumleft[] 
    // and max is the maximum value in the sumleft[]

    // Hash

    int hash[max - min+1];
    for(i = 0; i < n; i++)
        hash[i] = -1;
    for (i=0; i<n; i++) 
    { 
        // Case 1: when the subarray starts from  
        //         index 0 
  
        if (prefix_sum[i] == 0) 
        { 
           max_size = i+1;
           start_index = 0; 
        } 
   
        // Case 2: fill hash table value. If already 
        //         filled, then use it 
  
        if (hash[prefix_sum[i]-min] == -1) 
            hash[prefix_sum[i]-min] = i; 
        else
        { 
            if ((i - hash[prefix_sum[i]-min]) > max_size) 
            { 
                max_size = i - hash[prefix_sum[i]-min]; 
                start_index = hash[prefix_sum[i]-min] + 1; 
            } 
        } 
    }

    if(max_size == -1)
    {
        char *r = (char *)malloc(sizeof(char) * 1);
        r[0] = '\0';
        return r;
    }
    char *r = (char *)malloc(sizeof(char) * (max_size + 1));
    for(i = start_index, j = 0; i < start_index + max_size; i++, j++)
        r[j] = arr[i];
    r[j] = '\0';
    return r;

}

#include <stdio.h>
int main (int ac, char **av)
{
    if(ac == 2)
    {
        printf("%s", longest_subarray(av[1]));
    }
    printf("\n");
    return 0;
}
