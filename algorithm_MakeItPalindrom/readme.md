# Color lists  
  
You live in a village near a school. Your house had a long fence with narrow unpainted vertical planks. You found this boring, so you replaced each plank with a random colored one. Amos is a child who passes your house twice a day in opposite directions.  
The input for all tasks consists of 10 test cases. Each of them has:  
  
### Input:  
A single list of positive integers that represents the colors of the painted rails from left to right. (You don't have to check the input for correctness.) You get the input in a C++ file, color_lists_inputs.cpp.inc.  
  
### Output:  
You have to provide a space-separated list of integers, the answers for each test case (see the input style with the "sample inputs" and a suggested template code below, you only have to implement the solution logic).  

## Task 1:  
Amos reads out the rail colors when passing by to and from school, and complains if the color lists in the morning and in the afternoon are different.   
You want to repaint some rails so that the color lists Amos reads out become equal. How many rails do you have to repaint at the minimum to achieve this?  
  
### Sample test case: colors = (`1,2,2,3,4,1,4,1,1,2,2,2,2`)  
### Sample answer: `3` (e.g. 1,2,2,`2`,4,1,4,1,`4`,2,2,2,`1`)  
### Answer for the sample inputs (test_cases_task_1_2 below) is: `3 5 39`  
  
## Task 2:  
Repainting the rails was a good plan, but is not viable, as you realized that you cannot buy the same colors as a bucket of paint. So you decide to replace some rails with the removed unpainted ones (which are not read out at all) so that the color lists Amos reads out become equal. How many rails do you have to replace at the minimum to achieve this?  
  
### Sample test case: colors = {`1,2,2,3,4,1,4,1,1,2,2,2,2`}  
### Sample answer: `6`     (e.g.`-`,2,2,`-`,`-`,1,4,1,`-`,2,2,`-`,`-`)  
### Answer for the sample inputs (test_cases_task_1_2 below) is: `6 4 35`  
  
## Task 3:  
While showing your plan to Amos, he starts to read out from paper, and you realize that Amos does not like saying the same color multiple times. If the same color is painted multiple times next to each other, he only says it once (unpainted rails are not taken into consideration at all), e.g. colorlist 1,2,2,-,2,-,1,1 becomes 1,2,1 when he reads it.  
Fortunately, you only used 2 different colors this time (for all Task 3 test cases). How many rails at the minimum do you have to replace with an unpainted one in this case so that the two lists to and from school sound the same?  

### Sample test case: colors = {`1,1,1,2,2,2,1,1,1,2,2,2,2,1,1,2,2,1,1,1,2,2`}  
### Sample answer: `2`     (e.g. 1,1,1,2,2,2,1,1,1,2,2,2,2,1,1,2,2,1,1,1,`-`,`-`  
                 which reads out `1,2,1,2,1,2,1`)  
### Answer for the sample inputs: (test_cases_task_3 below): `2 0 3`  
