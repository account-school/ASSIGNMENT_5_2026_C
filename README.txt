3. Explain your answers (10 points)

Please answer the following questions for each file you wrote as part of this assignment.

1. Implementing a binary search tree.
"Why This Works" Explanation: Explain the underlying logic and reasoning that makes your code solve the problem. 
Focus on the core concepts and principles your solution utilizes.


2. my-grep
"Why This Works" Explanation: Explain the underlying logic and reasoning that makes your code solve the problem. 
Focus on the core concepts and principles your solution utilizes.


The my grep was fairly simple. All it required was that i declare a char array for each line of the generously large FILE_SIZE. Then i open the file using fopen and set that pointer to fp. if something goes wrong, it is null. so if fp == NULL return 1 and exit the program, otherwise, continue.
 then i use a while(fgets(chr,LINE_SIZE,fp)) to not only get the next line but to check if there is one. if there is one, go to the while loop to check using strstr if s exists in it. if it does, print the line we just loaded, otherwise, do nothing. if there is no more lines to print, exit the function.
 