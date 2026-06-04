

## ex02--PmergeMe
merge-insert sort (Ford-Johnson algo inspired)
_idea: minimal times of comparisons_
1. pair comparisons
2. recursive sorting for the larger ones in pairs (the main sequence)
3. the "jac" sequence tells us which elements to move next in the smaller ones (the pending sequence), they are essentially the indice of the pending sequece.
4. 

Handy C++ STL function:
`lower_bound()` returns the first element equal or greater than the given value; This standard library function uses **binary search** by firstly looking at the middle.

## containers in c++
- vector
    `push_back()` add one element to the end of the vector
    `insert(position, value)` insert at random position
    `pop_back()` delete the last element
    access by index
    to traverse, `vect[i]` or `for (int i: vect)` or iterator
- deque
    double-ended queue
    similar to vector but has extra functions
    `push_front()`, `pop_front()`, `front()` and `back()`
    
- list
    good for inserting or deleting random element
- map
- stack
    stack is a List-In-First-Out container, its `push()` function add an element to the top of the stack; `pop()` deletes the top element, `top()` function enables the direct access of the top element.


    10 4 0 8 9
