
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