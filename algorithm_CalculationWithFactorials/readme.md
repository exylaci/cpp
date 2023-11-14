# Combination  

For n and k positive integers, n >= k, a combination of n and k is C(n,k) which is calculated using the following formula: n!/((n-k)!*k!). Calculate C(n,k) for values stored in a file. The file's first line contains the number of calculations to be completed (N), then it contains N lines with 2 numbers (n and k) separated by a space.  

## Example:  
```
3  
90 5  
45 6  
6 2  
```  
Your program needs to output the sum of digits of the results. In this case the results are 43949268, 8145060, 15, the sum of their digits is 75.

- combinel.txt: N=100, n<=16  
- combine2.txt: N=1000, n<=30  
- combine3.txt: N=10000, n<=100, k<=15 or n<=60  
Note: prepare to handle huge numbers precisely!  

## Input handling  
The provided input files do not have formatting errors or any data violating the said constraints. Simply reading from ***std::cin*** (or ***std:ifstream***) to N, then N times to n and k should be sufficient input handling.  
