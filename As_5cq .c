#include <stdio.h>
#include <string.h>

typedef struct print_job
{
    int job_id;
    char job_title[20];
}Job;

Job queue[20];
int front = 0;
int rear = 0;
int count = 0;

void enque(Job job);
void deque();
void display();



int main()
{    Job job;
    int choice;
    do
    {
     printf("Enter 1 : add to queue\n");
        printf("Enter 2: remove from queue\n");
        printf("Enter 3 : display queue\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("job deteils\n");
                printf("Enter job id : ");
                scanf("%d",&job.job_id);
                printf("Enter job title :");
                scanf(" %[^\n]",job.job_title);
                enque(job);
                break;
            case 2:
                deque();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }while(choice<=3);
    return 0;
}
void enque(Job job)
{
    if(count < 20)
    {
        queue[rear].job_id = job.job_id;
        strcpy(queue[rear].job_title, job.job_title);
        rear = (rear+1)%20;
        count++;
        printf("Job has been queued\n");
    }
    else
    {
        printf("Queue is full \n");
    }
}

void deque()
{

    if(count > 0)
    {
        Job save = queue[front];
        front = (front+1)%20;
        count--;
        printf("Deleted job id is %d and title is %s \n",save.job_id,save.job_title);
    }
      else
    {
        printf("Queue is empty \n");
    }
}

void display()
{
    if(count == 0)
    {
        printf("Queue is Empty. \n");
    }
     else
    {
        printf("Job queue is as follows :\n");
        int i = front;
        int j;
        for(j = 0; j < count; j++)
        {
            printf("Job id : ");
            printf("%d",queue[i].job_id);
            printf("\nJob title : ");
            printf("%s",queue[i].job_title);
            printf("\n");
            i = (i+1)%20;
        }
    }
}
