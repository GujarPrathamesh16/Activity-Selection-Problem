# Activity-Selection-Problem

### Background:
This project provides a solution for Activity Selection Problem using Greedy algorithmic approach. Greedy is a algorithmic approach which builds up solution piece by piece, these are chosen such that it is the most benificial approach, this provides a solution to optimization problems. In this aproach we make choice at every step that provides best solution at present and hence we get the optimal solution for complete problem.
Activity selection problem is a approach wherein we select the activity from the set of given activities such that we maaximum number of activities should be completed/selected using the given solution


### Problem Statement:
In this Activity Selection Problem we were given a problem and were expected to Modify the selecting criteria and suggest a logic to select the activity with maximum duration of resource usage.

| Index  | Start | End    |
| -----  | ----- | ------ |
| 1      | 0     | 1      |
| 2      | 2     | 5      |
| 3      | 4     | 7      |
| 4      | 2     | 8      |
| 5      | 5     | 9      |
| 6      | 8     | 10     |
| 7      | 9     | 11     |
| 8      | 11    | 14     |
| 9      | 13    | 16     |


### Code:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\t";
    }
    cout << endl;
}
int findMaxIndex(vector<int> v)
{
    int max = 0, k = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (max < v[i])
        {
            max = v[i];
            k = i;
        }
    }
    return k;
}
void MaxUsage(vector<int> start, vector<int> end)
{

    vector<int> difference;
    for (int i = 0; i < start.size(); i++)
    {
        difference.push_back(end[i] - start[i]);
    }

    int maxIndex = findMaxIndex(difference);

    int j = 99, flag = 1;
    while (flag == 1)
    {
        int maxi = 0;
        for (int i = 0; i < start.size(); i++)
        {

            if (end[i] < start[maxIndex] && start[i] != start[maxIndex] && i != j && maxi < difference[i])
            {
                maxi = difference[i];
                j = i;
                flag = 1;
            }
        }
        cout << "Activity - " << (j + 1) << endl;
        flag = 0;
    }

    cout << "Activity - " << (maxIndex + 1) << endl;
    j = 99, flag = 1;
    while (flag == 1)
    {
        int maxi = 0;
        for (int i = 0; i < start.size(); i++)
        {

            if (start[i] >= end[maxIndex] && i != j && maxi < difference[i])
            {
                maxi = difference[i];
                j = i;
                flag = 1;
            }
        }
        cout << "Activity - " << (j + 1) << endl;
        flag = 0;
    }
}
int main()
{
    vector<int> start = {0, 2, 4, 2, 5, 8, 9, 11, 13};
    vector<int> end = {1, 5, 7, 8, 9, 10, 11, 14, 16};
    cout << "-----Selected Activities are----- " << endl;
    MaxUsage(start, end);
    return 0;
}
```


### Output:
```
-----Selected Activities are----- 
Activity - 1
Activity - 4
Activity - 8
```


### Test Cases:
   [1] vector<int> start = {0, 2, 4, 2, 1, 8, 10, 11, 13};
       vector<int> end = {2, 5, 7, 5, 9, 10, 12, 14, 16};
       -----Selected Activities are----- 
       Activity - 5
       Activity - 8




### Explanation : 

DATA STUCTURE USED - Vectors : start, end and difference.<br />
Start vector : Stores the start time of each activity.<br />
End vector : Stores the end time of each activity.<br />
Difference vector : Stores the differnece(usage) of start and end time of each activity.<br />

The approach to my solution is simple,<br /> 
Step 01 : We iterate through the start and end vectors and store the difference of ith indices into the respective ith index in the difference               vector, this vector stores the usage of each given activities.<br />
Step 02 : We again iterate and calculate the maximum usage activity (i.e. the activity with maximum difference value) from the difference vector.           This activity is selected.<br />
Step 03 : In this step, we iterate the start vector and select a maximum activity from the set of activities such that the end time of each of the           activities is less than the start time of the activity selected in Step 02 using conditional statements.<br />
Step 04 : Similiar to step 03, here we select maximum activities from the set of activities such that the start time of each of the selected                 activities is greater than or equal to the end time of activity selected in Step 02 using conditional statements.<br />
