#include <stdio.h>
void    equation(int n)
{
    int A = 0, B, C;
    {
        while( 11 * A <= n && A < 10)
        {
            int rem = n - (11 * A);
            B = rem % 10, C = rem / 10;
            if(B < 10 && C < 10)
                printf("A = %i, B = %i, C = %i\n", A, B, C);
            A++;
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
