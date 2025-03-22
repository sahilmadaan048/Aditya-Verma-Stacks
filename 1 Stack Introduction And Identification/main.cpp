/*
NIT Bhopal

flipkart  intern at 24 CTC and 16 Base

there are very few new problems 


*/

ONE CONCEPT

1. Nearest greater to left
2. Nearest Greater to Right => next largest element
3. Nearest smallest to left => next smallest element
4. Nearest smallest to right

5. Stock Span Problem
6. Maximum Area of Histogram

LEARN NEW CONCEPTS

7. Maximum area of rectangle in Binary Matrix
8. Rain Water Trapping
9. Implementing a min stack => with or without using extra space
10. Implement stack using heap 
11. The celebrity problem
12. Longest valid parenthesis
13. Iterative tower of hanoi (the recusion code is using the recursion stacl space only
here we can just imlement it manually to do have the same functionality)


IDENTIFICATION

most of them have arrays, probability has a chance of being stack or heap 
heap mei you will want to sort 

normal o(n^2) ==> 

for(int i=0; i<n; i++){
    for(int j=0; j<n; j++) {

    }
}

dependent o(n^2) loops

//j is dependent on i
for(int i=0; i<n; i++){
    for(int j=0; j<i; j++) {
        //when
        /*
            j is from 0 to i
            j is from i to 0
            j is from i to n
            j is from n to i

            if something like this exists there surely is
            a more optimised solution possible using stacks
        */
    }
}
