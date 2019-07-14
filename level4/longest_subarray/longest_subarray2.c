
 // O (N) -> Time Complexity
 // O (N) -> Space Complexity

#include <string.h>
#include <stdlib.h>
#define is_odd(c) ((c - '0') % 2)
#define max(a, b) (a > b ? a : b)
#include <stdio.h>

char    *longest_subarray(char *arr)
{
    int n = strlen(arr);
    int maxsize = -1, startindex; 

	// Create an auxiliary array sunmleft[]. 
	// sumleft[i] will be sum of array 
	// elements from arr[0] to arr[i] 

	int sumleft[n]; 

	// For min and max values in sumleft[] 

	int min, max; 
	int i; 

	// Fill sumleft array and get min and max 
	// values in it. Consider 0 values in arr[] 
	// as -1 

	sumleft[0] = ((is_odd(arr[0])) ? -1 : 1); 
	min = arr[0]; max = arr[0]; 
	for (i=1; i<n; i++) 
	{	 
		sumleft[i] = sumleft[i-1] + ((is_odd(arr[i]) ? -1 : 1)); 
		if (sumleft[i] < min) 
			min = sumleft[i]; 
		if (sumleft[i] > max) 
			max = sumleft[i]; 
	} 

	// Now calculate the max value of j - i such 
	// that sumleft[i] = sumleft[j]. The idea is 
	// to create a hash table to store indexes of all 
	// visited values. 
	// If you see a value again, that it is a case of 
	// sumleft[i] = sumleft[j]. Check if this j-i is 
	// more than maxsize. 
	// The optimum size of hash will be max-min+1 as 
	// these many different values of sumleft[i] are 
	// possible. Since we use optimum size, we need 
	// to shift all values in sumleft[] by min before 
	// using them as an index in hash[]. 

	int hash[max-min+1]; 

	// Initialize hash table 

	for (i=0; i<max-min+1; i++) 
		hash[i] = -1; 

	for (i=0; i<n; i++) 
	{ 
		// Case 1: when the subarray starts from 
		//		 index 0 

		if (sumleft[i] == 0) 
		{ 
		maxsize = i+1; 
		startindex = 0; 
		} 

		// Case 2: fill hash table value. If already 
		//		 filled, then use it 

		if (hash[sumleft[i]-min] == -1) 
			hash[sumleft[i]-min] = i; 
		else
		{ 
			if ((i - hash[sumleft[i]-min]) > maxsize) 
			{ 
				maxsize = i - hash[sumleft[i]-min];
				startindex = hash[sumleft[i]-min] + 1; 
			} 
		} 
	} 

    if(maxsize == -1)
    {
        char *r = (char *)malloc(sizeof(char) * 1);
        r[0] = '\0';
        return r;
    }
    char *r = (char *)malloc(sizeof(char) * (maxsize + 1));
    int j;    
    for(i = startindex, j = 0; i < startindex + maxsize; i++, j++)
        r[j] = arr[i];
    r[j] = '\0';
    return r;

}

int main (int ac, char **av)
{
    if(ac == 2)
    {
        printf("%s", longest_subarray(av[1]));
    }
    printf("\n");
    return 0;
}
