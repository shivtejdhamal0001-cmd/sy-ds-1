#include <stdio.h>
struct spo 
{
char name[200];
char sport[200];
int age;
float weight;
float height;
};
void accept(struct spo S[100],int n)
{
 for(int i=0;i<n;i++)
   {
   printf("Enter Name : \n");
   scanf("%s",S[i].name);
   printf("Enter Sport Name :\n");
   scanf("%s",S[i].sport);
   printf("Enter Age :\n");
   scanf("%d",&S[i].age);
   printf("Enter Weight:\n");
   scanf("%f",&S[i].weight);
   printf("Enter Height :\n");
   scanf("%f",&S[i].height);
   } 
}
void display(struct spo S[100], int n)
{
 for(int j=0;j<n;j++)
   {
   printf("Name :%s\n",S[j].name);
   printf("Sport :%s\n",S[j].sport);
   printf("Age:%d\n",S[j].age);
   printf("Weight :%.2f\n",S[j].weight);
   printf("Height:%.2f\n",S[j].height);
   }

}
int Linear_search(struct spo S[100],int n , int target,int res[100]) 
{    int count=0;
   int i =0; 
   while (i<n)
    { 
   if(S[i].age==target) 
   { 
      res[count]=i;
        count++;
   //break;
    } 
    i++; 
    } 
  return count;
 }
//void seq_search(struct spo S[100],int n , int target) 
//{
//}
void bubble_sort(struct spo S[100], int n)
{
struct spo temp;
for(int i=0;i<n-1;i++)
{
 for(int j=0;j<n-i-1;j++)
  {
  if(S[j].age>S[j+1].age)
  {
   temp=S[j];
   S[j]=S[j+1];
   S[j+1]=temp;
   }
  }
}
}  
int Bin_search(struct spo S[100], int n, int target,int res_2[100])
{
int l = 0;
int h = n - 1;
int mid;
int count_2 = 0;

while (l <= h)
{
mid = (l + h) / 2;

if (S[mid].age == target)
{
 res_2[count_2] = mid;
count_2++;

int i = mid - 1;
while (i >= 0 && S[i].age == target)
{
res_2[count_2] = i;
count_2++;
i--;
}
i=mid+1;
while(i<n &&S[i].age == target)
{
   res_2[count_2]=i;
   count_2++;
   i++;
}
return count_2;
}
else if (S[mid].age > target)
 {
   h = mid - 1;
 }
else
  {
   l = mid + 1;
  }
}
   
return count_2;
}

int main()
{ 
struct spo S[100];
int n;
printf("Enter size of data :\n");
 scanf("%d", &n);
  accept(S, n);
printf("\n");
display(S,n);
printf("Linear Search\n");
int res[100];
int count = Linear_search(S,n,24,res);
if(count == 0)
    printf("Not Found\n");
else
    {
    for(int i=0;i<count;i++)
        printf("Found at position %d\n", res[i] + 1);
    }

printf("Bin Search\n");
bubble_sort(S,n);
int res_2[100];
int count_2 =Bin_search(S,n,24,res_2);
if(count_2 == 0)
    printf("Not Found\n");
else
    {
    for(int i=0;i<count_2;i++)
    {
        printf("Found at position %d\n", res_2[i] + 1);
    }
   }
return 0;
}
