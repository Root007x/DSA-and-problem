#include <iostream>
#include <algorithm>
using namespace std;

struct Job
{
    string id;
    int deadLine;
    int profit;
};

int min(int a, int b)
{
    return (a < b) ? a : b;
}

void jobSequence(Job jobList[], int n)
{

    int jobSeq[n]; // To store result (Sequence of jobs)
    int slot[n] = {0};

    for (int i = 0; i < n; i++)
    { // for all given jobs
        for (int j = min(n, jobList[i].deadLine); j > 0; j--)
        { // search from last free slot
            if (slot[j] == 0)
            {
                jobSeq[j] = i; // Add this job to job sequence
                slot[j] = 1;   // mark this slot as occupied
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
        if (slot[i])
            cout << jobList[jobSeq[i]].id << " "; // display the sequence
}

int main()
{
    Job jobList[] = {
        {"j1", 2, 20},
        {"j2", 2, 15},
        {"j3", 1, 10},
        {"j4", 3, 5},
        {"j5", 3, 1}};

    int n = 5;
    cout << "Following is maximum profit sequence of job sequence: ";
    jobSequence(jobList, n);
}