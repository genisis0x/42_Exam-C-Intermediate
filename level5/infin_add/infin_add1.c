#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int len(char *s)
{
    int i, c = 0;
    for(i = 0; s[i]; i++)
    {
      c = (s[i] == '-') ? c : c + 1;
    }
    return c;
}
int ft_strcmp(char *s1, char *s2)
{
    while((*s1 || *s2) != 0)
    {
        if(*s1 == *s2)
        {
            s1++;
            s2++;
        }
        return *s1 - *s2;
    }
    return 0;
}

void swap(char **s1, char **s2)
{
    char *temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void infi_add(char *s1, char *s2, int l1, int l2)
{
    int i, j;
    int carry = 0;
    int *arr = (int *)malloc(sizeof(int) * l2 + 1);
    for(i = 0; i <= l2; i++)
    {
        arr[i] = 0;
    }
    for(i = l1 - 1, j = l2 - 1; i >= 0; i--, j--)
    {
        arr[j + 1] = (s1[i] - '0') + (s2[j] - '0') + carry;
        carry = arr[ j + 1] / 10;
        arr[j + 1] %= 10;
    }

    for(i = l2 - l1 - 1 ; i >= 0; i--)
    {
        arr[i + 1] = (s2[i] - '0') + carry;
        carry = arr[i + 1] / 10;
        arr[i + 1] %= 10;
    }
    if(carry > 0)
    {
        arr[0] = carry;
    }
    i = 0;
    while(arr[i] == 0)
        i++;
    if (i == l2)
    {
        write(1, "0", 1);
        return;
    }
    while(i <= l2)
    {
        char c = arr[i++] + '0';
        write(1, &c, 1);
    }
}

void infi_sub(char *s1, char *s2, int l1, int l2)
{
    int i, j;
    int carry = 0;
    int *arr = (int *)malloc(sizeof(int) * l2);
    for(i = 0; i <= l2; i++)
    {
        arr[i] = 0;
    }
    for(i = l1 -1, j = l2 - 1; i >= 0; i--, j--)
    {
        arr[j] = (s2[j] - '0') - (s1[i] - '0') - carry;
        if(arr[j] < 0)
        {
            carry = 1;
            arr[j] += 10;
        }
        else
        {
            carry = 0;
        }
        
    }
    for(i = l2 - l1 - 1; i >= 0; i--)
    {
        arr[i] = (s2[i] - '0') - carry;
        if(arr[i] < 0)
        {
            carry = 1;
            arr[i] += 10;
        }
        else
        {
            carry = 0;
        }
        
    }
    i = 0;
    while(arr[i] == 0)
        i++;
    if (i == l2)
    {
        write(1, "0", 1);
        return;
    }
    while(i < l2)
    {
        char c = arr[i++] + '0';
        write(1, &c, 1);
    }
}
int main(int ac, char **av)
{
    if(ac == 3)
    {
        char *s1 = av[1];
        char *s2 = av[2];
        int lens1 = len(s1);
        int lens2 = len(s2);

        if(lens1 > lens2)
        {
            swap(&s1, &s2);
            int temp = lens1;
            lens1 = lens2;
            lens2 = temp;
        }
        if(*s1 == '-')
        {
            if(*s2 == '-')
            {
                s1++, s2++;
                write(1, "-", 1);
                infi_add(s1, s2, lens1, lens2);
            }
            else
            {
                s1++;
                if(ft_strcmp(s1, s2) == 0 && lens1 == lens2)
                {
                    write(1, "0\n", 2);
                    return 0;
                }
                if(ft_strcmp(s1, s2) > 0 && lens1 == lens2)
                    write(1, "-", 1);
                infi_sub(s1, s2, lens1, lens2);
            }
        }
        else if(*s2 == '-')
        {
            s2++;
            if(ft_strcmp(s1, s2) == 0 && lens1 == lens2)
                {
                    write(1, "0\n", 2);
                    return 0;
                }
            if(ft_strcmp(s1, s2) > 0 && lens1 == lens2)
                ;
            else
                write(1, "-", 1);
            infi_sub(s1, s2, lens1, lens2);
        }
        else
        {
            infi_add(s1, s2, lens1, lens2);
        }
        
        write(1, "\n", 1);
    }
    return 0;
}