#include <stdio.h>
#include <stdlib.h>
struct Job
{
    int jobNo;
    int profit;
    int deadline;
};

void printtable(struct Job arr[], int n)
{

    printf("\n _______________________________________________");
    printf("\n|               |               |               |");
    printf("\n|   Job No.     |     Profit    |   Deadline    |");
    printf("\n|_______________|_______________|_______________|\t");
    printf("\n|               |               |               |");
    for (int i = 0; i < n; i++)
    {
        struct Job currentobj = arr[i];
        printf("\n|\t%d\t|\t%d\t|\t%d\t|", currentobj.jobNo, currentobj.profit, currentobj.deadline);
    }
    printf("\n|_______________|_______________|_______________|\n");
}

void printProcess(struct Job jobArray[], int time_slots[], int num_slots, int num_jobs)
{
    struct Job currentJob;
    int profit = 0;
    printf("\n _______________________________________________________________________________");
    printf("\n|               |               |               |               |               |");
    printf("\n|   Time Slot   |     Job No.   |    Profit     |   Deadline    |  Total Profit |");
    printf("\n|_______________|_______________|_______________|_______________|_______________|\t");
    printf("\n|               |               |               |               |               |");
    for (int i = 1; i <= num_slots; i++)
    {
        int reqjobNo = time_slots[i];
        if (reqjobNo != -1)
        {
            for (int j = 0; j < num_jobs; j++)
            {
                if (jobArray[j].jobNo == reqjobNo)
                {
                    currentJob = jobArray[j];
                }
            }
            // printf("\n K is  : %d", k);
            profit += currentJob.profit;
            printf("\n|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|", i, currentJob.jobNo, currentJob.profit, currentJob.deadline, profit);
        }
        else
        {
            printf("\n|\t%d\t|\t--\t|\t--\t|\t--\t|\t--\t|", i);
        }
    }
    printf("\n|_______________|_______________|_______________|_______________|_______________|\n");
}

int initialize(struct Job arr[], int n)
{
    printf("\nEnter the following details : \n");
    int max_deadline = 0;
    int deadline;
    // todo taking inputs
    for (int i = 0; i < n; i++)
    {
        arr[i].jobNo = i + 1;
        printf("\nJob %d : \n", i + 1);
        printf("Profit : ");
        scanf("%d", &arr[i].profit);
        printf("Deadline : ");
        scanf("%d", &deadline);
        arr[i].deadline = deadline;
        if (deadline > max_deadline)
        {
            max_deadline = deadline;
        }
    }
    return max_deadline;
}
void swap(struct Job arr[], int i, int j)
{
    struct Job temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int Partition(struct Job arr[], int left, int right)
{
    struct Job temp = arr[right];
    int pivotProfit = arr[right].profit;
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (arr[j].profit > pivotProfit)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, right);
    return i + 1;
}

void sortJobs(struct Job arr[], int left, int right)
{
    if (left < right)
    {
        int pivot = Partition(arr, left, right);
        sortJobs(arr, left, pivot - 1);
        sortJobs(arr, pivot + 1, right);
    }
}

int Jobsequencing(struct Job jobArray[], int num_jobs, int num_slots)
{

    int *time_slots = (int *)malloc(sizeof(int) * num_slots);
    printf("\nArray Declared");
    for (int i = 1; i <= num_slots; i++)
    {
        time_slots[i] = -1;
        //?time_slots[i] = -1; means that time slot is not occupied by any Job
    }
    printf("\nArray Initialised");
    // for (int i = 1; i <= num_slots; i++)
    // {
    //     printf("%d ", time_slots[i]);
    // }
    // printf("\nIn Job sequencing : ");
    int max_profit = 0;
    // int *answer = (int *)malloc(sizeof(int) * num_jobs);
    int answer[20];
    // printf("\nANSWER ARRAY CREATED ");
    int k = 0;
    printf("\nInitially the table is : ");
    printProcess(jobArray, time_slots, num_slots, num_jobs);
    for (int i = 0; i < num_jobs; i++)
    {
        struct Job currentJob = jobArray[i];
        printf("\n For Job No. %d", currentJob.jobNo);
        printf("\nProfit : %d    Deadline : %d", currentJob.profit, currentJob.deadline);
        int time = currentJob.deadline;
        while (time > 0)
        {
            if (time_slots[time] == -1)
            {
                time_slots[time] = currentJob.jobNo;
                answer[k] = currentJob.jobNo;
                k++;
                max_profit += currentJob.profit;
                // printf("\nk is :%d ", k);
                break;
            }
            else
            {
                time--;
            }
        }
        // printf("\nPrint something : in jobsequencing function");
        printProcess(jobArray, time_slots, num_slots, num_jobs);
    }
    return max_profit;
}

int main()
{
    printf("\nJOB SEQUENCING WITH DEADLINES\n");
    int num_jobs;
    int max_deadline;
    printf("\nEnter the number of objects : ");
    scanf("%d", &num_jobs);

    struct Job *jobArray = (struct Job *)malloc(sizeof(struct Job) * num_jobs);
    int max_weight;

    max_deadline = initialize(jobArray, num_jobs);

    printtable(jobArray, num_jobs);
    printf("\nMax deadline is : %d", max_deadline);

    sortJobs(jobArray, 0, num_jobs - 1);
    printf("\nAfter Sorting :");

    printtable(jobArray, num_jobs);

    int max_Profit = Jobsequencing(jobArray, num_jobs, max_deadline);
    printf("\n\n FINAL ANSWER \n The maximum Profit is : %d\n", max_Profit);

    return 0;
}

//?Input :

// 7
// 3
// 1
// 5
// 3
// 20
// 4
// 18
// 3
// 1
// 2
// 6
// 3
// 30
// 2
