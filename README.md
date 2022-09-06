# Activity-Selection-Problem

### Background:
This project provides a solution for Activity Selection Problem using Greedy algorithmic approach. Greedy is a algorithmic approach which builds up solution piece by piece, these are chosen such that it is the most benificial approach, this provides a solution to optimization problems. In this aproach we make choice at every step that provides best solution at present and hence we get the optimal solution for complete problem.
Activity selection problem is a approach wherein we select the activity from the set of given activities such that we maaximum number of activities should be completed/selected using the given solution


### Problem Statement:
In this Activity Selection Problem we were given a problem and were expected to Modify the selecting criteria and suggest a logic to select the activity with maximum duration of resource usage.

| Index  | Start | End    |
| -----  | ----- | ------ |
| 1      | 1     | 4      |
| 2      | 3     | 5      |
| 3      | 0     | 6      |
| 4      | 5     | 7      |
| 5      | 3     | 8      |
| 2      | 3     | 5      |
| 1      | 1     | 4      |
| 2      | 3     | 5      |


### Explanation : 

DATA STUCTURE USED - Vectors : start,end and difference.
Start vector : Stores the start time of each activity.
End vector : Stores the end time of each activity.
Differnce vector : Stores the differnece(usage) of start and end time of each activity.

The approach to my solution is simple,<br /> 
Step 01 : We iterate through the start and end vectors and store the difference of ith indices into the respective ith index in the difference               vector, this vector stores the usage of each given activities.<br />
Step 02 : We again iterate and calculate the maximum usage activity (i.e. the activity with maximum difference value) from the difference vector.           This activity is selected.<br />
Step 03 : In this step, we iterate the start vector and select a maximum activity from the set of activities such that the end time of each of the           activities is less than the start time of the activity selected in Step 02 using conditional statements.<br />
Step 04 : Similiar to step 03, here we select maximum activities from the set of activities such that the start time of each of the selected                 activities is greater than or equal to the end time of activity selected in Step 02.<br />
