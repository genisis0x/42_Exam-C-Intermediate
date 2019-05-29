# 42_Exam-C-Intermediate--ExamShell
Repository is used for the prepration of C - Intermediate examshell in 42 School - Silicon Valley.It contains all of the Intermediate Questions and solutions to it.

Solution provided are fully tested and written by me, for some problem's there are more then one solution.

For better understanding pull the work and use debugger(LLDB or GBD) to see how each step works. 
Any suggestion's will be highly appreciated. -_-

##### 42 Intra Name -> maparmar
##### Email -> [:e-mail:](mailto:manmeetparmar@outlook.com?subject=[GitHub]%20Source%20Han%20Sans)

## LLDB Basic Working Steps:imp:
1. gcc -Wall -Wextra -Werror filename.c -g 
2. lldb ./a.out -- > Used to go into LLDB mode. 
3. b main --> to set breakpoint
4. r --> run
5. gui ---> Graphic User Interface.
6. use 's' key to go to each next step.

<h2>

```diff
- => If you found helpful then please do follow and give a star 
```
:v: :raised_hands: 
</h2>

## Steps to clone the work
1. cd ~
2. git clone https://github.com/Manmeet2018/C--Intermediate--Exam--42--.git
3. cd C--Intermediate--Exam--42--.git
4. Search Questions as per level.
5. Located at various directory distinguished by there difficulty levels and see the subject.en.txt to undertsand the question and for solutions see the *.c files and there working.
----
## <kbd>^-^</kbd> Status Report :skull:

char *:star2: = "Good_Question's";\
char *:smiling_imp: = "Very_Good_question's";

>> #### Subject Status level 0 :heavy_check_mark: :100:
1.  count_of_2 ->	✅
2.	equation ->	✅
3.	find_pivot ->	✅
4.	is_anagram ->	✅
5.	print_doublon ->	✅
>> #### Subject	Status level 1 :heavy_check_mark: :100:
1.	count_alpha ->	✅
2.	flood_fill ->	✅
3.	height_tree ->	✅
4.	queue ->	✅
5.	stack ->	✅
>> #### Subject Status level 2 :heavy_check_mark: :100:
1.	longest_sequence -> ✅
2.	ord_alphalong -> ✅
3.	reverse_tree -> ✅
4.	str_maxlenoc -> ✅ good solution Using Dp for LCS(Lowest Common String) :star2: :star2: // Pending solution -> LCS using segment tree O(N).
5.  is_looping  ✅
>> #### Subject Status level 3 :heavy_check_mark: :100:
1.	can_split -> ✅
2.	perimeter -> ✅
3.	width_tree -> ✅
4.	convert_bst-> ✅
5.	gold_gain -> ✅ -> Good solution Done with using space Complexity of O(M * N) and time complexity of O(M * N). :star2: :star2: :star2: :star2:
>> #### Subject Status level 4 :heavy_check_mark: :100:
1.	clone_list -> ✅ time complexity of O(N) -> "N" no of elements in list
2.	intersection -> ✅ time complexity of O(M) -> "M" highest size of list
3.	longest_subarray -> ✅ time complexity of O(M * N) -> Short (good solution) using -1 for odd and 1 for even number.
4.	range_comb -> #### Remaing :star2:
5.	volume_histogram -> ✅ time complexity of O(N) and Space complexity of O(1) :star2: :star2: :star2: -> Best Solutuon :D
>> #### Subject Status level 5 :star2: :star2: :heavy_check_mark:
1.	count_island -> #### Remaing
2.	g_diam -> ✅ :smiling_imp: 
  ##### Method 1: (used Backtracking and Basic adjacent matrix graph representation) -> Time complexity-- O(V * V) & Space    Complexity-- O(V).
  ##### Method 2: :smiling_imp: (used Backtracking and Basic  Adjacency list graph representation) -> Time complexity-- O(V + E) & Space Complexity-- O(V).
3.	infin_add -> ✅ --> time complexity O(N) -> N highest size between two strings :smiling_imp:
4.  infin_mult -> ✅ --> time complexity O(N * M)and Space Complexity of O(M + N) :smiling_imp:
