#include <stdio.h>
void    equation(int n)
{
    {
        for (int A = 0, B, C; 11 * A <= n && A < 10; A++)
        {
            int rem = n - (11 * A);
            B = rem % 10, C = rem / 10;
            if(B < 10 && C < 10)
                printf("A = %i, B = %i, C = %i\n", A, B, C);
        }
    }    
}


// int main ()
// {
//     int n;
//     scanf("%d", &n);
//     equation(n);
//     return 0;
// }
