3. Explain your answers (10 points)

Please answer the following questions for each file you wrote as part of this assignment.

1. Implementing a binary search tree.
"Why This Works" Explanation: Explain the underlying logic and reasoning that makes your code solve the problem. 
Focus on the core concepts and principles your solution utilizes.

createNode:
Its pretty simple. First create a malloc the size of a node, assign node->data to value, and leave the rest null. This makes it so that each binary tree's left and right "children" slots are open and ready to be filled, if at all. Starts with no children.
insert:
Start at the root. Store this root in a temp variable that will later be used to both maintain the root* reference and return the root consistently in every instance of insert(), regardless of the iteration #, according to the requirements of the start code.

To insert using the BST property, you need to search through a while loop. So while there is still a left or a right, compare the value. Then, check the appropriate child of the root node and move on (If there is one). If its equal, then end the loop early and restore the root node to be reutrned.
 If there isn't a child node, and its not one thats already in the tree, thats when you decide what side of that last node the new node goes to. 
 Its a simple if less than, insert on the left side; greater than, to the right. 
 But if there's no root node yet (if its NULL, which happens on the first iteration), skip ALL OF THE ABOVE  STEPS. In that case, just return newNode(value) as the new root node.

search:
Quite similar to insert, except when you hit an end without children you end the functin by returning null. If it is equal, return the temp because it is non-NULL.
If the ending node is greater than or less then the value, but there is one that is on the other side of the comparison, return NULL becaue it does not exist. If it is equal at any point, it does exist. But we have the last case on the bottom of the while loop in case we have reached the bottom and there is no children on either side, check if it is equal, and if not return NULL. if so, return that node, because that is a non-null value. 




inOrderTraversal:
use the recursive formula mentioned in class.
freeTree:
quite similar in method to inOrderTraversal, except instead of L root R, its L R root, because it if were L root R,
it would not be able to delete all of the nodes. simple example:

   -4<--0-->6

   so it would first delete -4, than 0. without a 0, "root->right" does not exist because the "root" (0) doesnt exist.

   if you do it L then R then root,

   it would do -4, then 6, then delete 0 (root). 

   Delete all your children before you delete yourself.

   

2. my-grep
"Why This Works" Explanation: Explain the underlying logic and reasoning that makes your code solve the problem. 
Focus on the core concepts and principles your solution utilizes.


The my grep was fairly simple. All it required was that i declare a char array for each line of the generously large FILE_SIZE. Then i open the file using fopen and set that pointer to fp. if something goes wrong, it is null. so if fp == NULL return 1 and exit the program, otherwise, continue.
 then i use a while(fgets(chr,LINE_SIZE,fp)) to not only get the next line but to check if there is one. if there is one, go to the while loop to check using strstr if s exists in it. if it does, print the line we just loaded, otherwise, do nothing. if there is no more lines to print, exit the function.
 