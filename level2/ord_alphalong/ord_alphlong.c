/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:03:11 by maparmar          #+#    #+#             */
/*   Updated: 2019/05/10 08:35:59 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************* #### Passed Final Exam #### ****************************/

#include <unistd.h>
#include <stdlib.h>
typedef struct s_list
{
    char *str;
    int len;
    struct s_list *next;
    
} t_list;

t_list *head = NULL;

int is_alphanumeric(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || ('0' <= c && c <= '9'));
}
int is_space_tab(char c)
{
    return (c == ' ' || c == '\t');
}

int str_len(char *s)
{
    int count = 0;
    while(*s)
    {
        count++;
        s++;
    }
    return count;
}

t_list *new(int a, char *s)
{
    t_list *node;
     if (!(node = (t_list *)malloc(sizeof(t_list))))
    {
        return NULL;
    }
    node->str = s;
    node->len = a;
    node->next = NULL;
    return node;
}

void reverse_list(t_list *previous, t_list **current, t_list *future)
{
    t_list *current1 = *current;
    while(current1)
    {
        future = current1->next;
        current1->next = previous;
        previous = current1;
        current1 = future;
    }
    *current = previous;
}


void push(t_list *node)
{
    if(!head)
    {
        head = node;
        return ;
    }
    else
    {
        node->next = head;
        head = node;
        return ;
    }
}

char *str_trim(char * s, int start, int len)
{
    char *res = (char *)malloc(sizeof(char) * (len + 1));
    int r = 0;
    while (r < len)
    {
        res[r++] = s[start++];
    }
    res[r] = '\0';
    return res;
}

int ft_strcmp(char *a, char *b)
{
    char c, d;
    while(*a && *b)
    {
        c = *a;
        d = *b;
        if(c != d)
        {
            if ((c >= 'A' && c <= 'Z') || (d >= 'B' && d <= 'Z'))
            {
                if (c >= 'A' && c <= 'Z')
                {
                    c = c + 32;
                }
                if (d >= 'A' && d <= 'Z')
                {
                    d = d + 32;
                }
            }
        }
            if((c - d) > 0)
            {
                return 1;
            }
            else if (c - d < 0)
            {
                return -1;
            }
        a++;
        b++;
    }
    return 0;
}

void swap(t_list *a, t_list *b)
{
    char *temp1;
    if (a->len != b->len)
    {
        int temp  = a->len;
        a->len = b->len;
        b->len = temp;
        temp1 = a->str;
        a->str = b->str;
        b->str = temp1;
    }
    else
    {
        if (ft_strcmp(a->str, b->str) == 1)
        {
            temp1 = a->str;
            a->str = b->str;
            b->str = temp1;
        }
    }
}

void sort_int_list(t_list *lst)
{
    t_list *traverse = lst;
    t_list *future;
    while(traverse)
    {
        future = traverse->next;
        while(future)
        {
            if (str_len(traverse->str) >= str_len(future->str))
            {
                swap(traverse, future);
            }
            future = future->next;
        }
        traverse = traverse->next;
    }
}

void ft_print_list(t_list *node)
{
    t_list *temp;
    while(node)
    {
        temp = node;
        char *sr = node->str;
        while(*sr)
        {
            write(1, sr, 1);
            sr++;
        }
        if (node->next && (node->len != node->next->len))
        {
            write(1, "\n", 1);
        }
        if (!node->next)
        {
            write(1, "\n", 1);
            node = node->next;
            free(temp);
            return ;
        }
        else if (node->next && (node->len == node->next->len))
        {
            write(1, " ", 1);
        }
        node = node->next;
        free(temp);
    }
}

int main (int ac, char **av)
{
    int i = 0, l = 0, start = 0;
    if (ac == 2)
    {
        while (av[1][i])
        {
            while(is_space_tab(av[1][i]))
            {
                i++;
            }
            start = i;
            l = 0;
            while(!is_space_tab(av[1][i]) && is_alphanumeric(av[1][i]))
            {
                l++;
                i++;
            }
            char *node = str_trim(av[1], start, l);
            push(new (l, node));
        }
        reverse_list(NULL, &head, NULL);
        sort_int_list(head);
        ft_print_list(head);
    }
    else
    {
        write(1, "\n", 1);
    }
    return 0;
}

/**************************************** GOOD TEST CASES *************************************/

// TEST CASE1: 
/*Input:
"a why thrast my pimple pow pew allegiance deer menise euhemeristic sarge or brigatry antialbumid oars gif \
phthisicky a fore lash champing thule moody a detoxify fem a logs uh sprit tower ha beudanite inlet sat bedebt \
menses ya consulates beau red pawl chartographically egg mia ghazi mispled damper ped autoput lawless fireplug \
see boil bargehouse counterplan en off boiserie a bundy frugs sidder fishy ok ack \
clue selah brim oxygen a footsies tome closh oleraceous dam tug on bauge glood depolariser"

Output:
a a a a a a$
en ha my ok on or uh ya$
ack dam egg fem gif mia off ped pew pow red sat see tug why$
beau boil brim clue deer fore lash logs oars pawl tome$
bauge bundy closh fishy frugs ghazi glood inlet moody sarge selah sprit thule tower$
bedebt damper menise menses oxygen pimple sidder thrast$
autoput lawless mispled$
boiserie brigatry champing detoxify fireplug footsies$
beudanite$
allegiance bargehouse consulates oleraceous phthisicky$
antialbumid counterplan depolariser$
euhemeristic$
chartographically$
*/

// TEST CASE2: 
/*Input:
"kohlrabies aghas tv sued ox retry gardant bulk cornetter putt gruesome whelk centenary decd bite \
capo in ok lax empaled ox saga um bandboxical ugh cephalomotor becassine boletaceous sees alkanet \
friarbird a pucker entour beautifiers guenons tod arracacha porus"

Output:
a$
in ok ox ox tv um$
lax tod ugh$
bite bulk capo decd putt saga sees sued$
aghas porus retry whelk$
entour pucker$
alkanet empaled gardant guenons$
gruesome$
arracacha becassine centenary cornetter friarbird$
kohlrabies$
bandboxical beautifiers boletaceous$
cephalomotor$
*/

// TEST CASE3: 
/*Input:
"lorem ipsum dolor sit amet consectetur adipiscing elit curabitur sollicitudin pretium nibh"

Output:
sit$
amet elit nibh$
dolor ipsum lorem$
pretium$
curabitur$
adipiscing$
consectetur$
sollicitudin$
*/

// TEST CASE4:
/*Input: 
"garotes foreboder hash arsenicating accolent ow dims twain handsew outasks fratries hill tot a \ 
footraces a comanches potheen skim bike one bacterially nest nay my en dub areostyle railly pre \
fee joys nepit cite ow coadunate um pox conclavist a axon sparta corelational gyms em daemonian \
creepingly mirdha buy boxings detruncated vex catbird derealization juts stope gonial ear ziff a \
a ebionite am smug rue chiasm it preter bitripartite conglobing eflagelliferous gematria corrugator \
obliger koumyses bye uh oopak ye sos anagogics toughy of prexy fads laigh ok a buss dismiss glimmering \
aquiform push applenut doest a oh sedged mild decoy fally do seal mien indubitate uh pic yale kymnel \
aortoiliac beniseed a cercus acroesthesia bradyseismical utick creirgist tuts bostonite kiyas candidacies \
aye neo pow earl til a intakes ox entocnemial"

Output:
a a a a a a a a a$
am do em en it my of oh ok ow ow ox uh uh um ye$
aye buy bye dub ear fee nay neo one pic pow pox pre rue sos til tot vex$
axon bike buss cite dims earl fads gyms hash hill joys juts mien mild nest push seal skim smug tuts yale ziff$
decoy doest fally kiyas laigh nepit oopak prexy stope twain utick$
cercus chiasm gonial kymnel mirdha preter railly sedged sparta toughy$
boxings catbird dismiss garotes handsew intakes obliger outasks potheen$
accolent applenut aquiform beniseed ebionite fratries gematria koumyses$
anagogics areostyle bostonite coadunate comanches creirgist daemonian footraces foreboder$
aortoiliac conclavist conglobing corrugator creepingly glimmering indubitate$
bacterially candidacies detruncated entocnemial$
acroesthesia arsenicating bitripartite corelational$
derealization$
bradyseismical$
eflagelliferous$
*/