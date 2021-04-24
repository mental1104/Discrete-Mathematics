# Chapter 2 Basic Structures: Sets, Functions, Sequences, Sums, and Matrices    

This is the solutions of **computer project and computer exploration** of Chapter 1.   

---
## Computer Project  
---

Usage:  
`g++ project.cpp`  
`./a.out [the number of project you want]`   

1. Given subsets A and B of a set with n elements, use bit
strings to find A, A ∪ B, A ∩ B, A − B, and A ⊕ B.  

[code](./project_1.hpp)  
Not many difference with [project 1.2](../chapter1/project_2.hpp)  

Usage && Example:  
`./a.out 1`   

```bash
espeon@Espeon:~/work/discrete/chapter2$ ./a.out 1
Please enter two bit strings with same length.
> 1010101
> 0101011
              1010101
              0101011
-----------------------------------------------------------------
Union:        1111111
Intersection: 0000001
Difference:   1010100
XOR:          1111110
```  

```
espeon@Espeon:~/work/discrete/chapter2$ ./a.out 1
Please enter two bit strings with same length.
> 1010101011
> 111
The size of two bit strings are not the same.
``` 
