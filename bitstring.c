#include<stdio.h>
#define MAX_SIZE 8
void displaySet(int set)
{
printf("{");
for(int i=0;i<MAX_SIZE;i++)
{
if(set & (1<<i))
{
printf("%d",i);
}
}
printf("} -Bitstring:");
for(int i = MAX_SIZE-1;i>=0;i--)
{
printf("%d",(set>>i)&1);
}
printf("\n");
}
int createSet(int n)
{
int set=0,element;
printf("Enter %d elements:",n);
for (int i=0;i<n;i++)
{
scanf("%d",&element);
if(element>=0 && element<MAX_SIZE)
{
set|=(1<< element);
}
else
{
printf("element %d out of range!Please enter elements between 0 and %d.\n",element,MAX_SIZE-1);
i--;
}
}
return set;
}
int unionSet(int setA, int setB)
{
return setA | setB;
}
int intersectionSet(int setA, int setB)
{
return setA & setB;
}
int differenceSet(int setA, int setB)
{
return setA&~setB;
}
int main()
{
int nA,nB;
printf("Enter the num of elements in set A:");
scanf("%d",&nA);
int setA = createSet(nA);
printf("Enter the num of elements in set B:");
scanf("%d",&nB);
int setB = createSet(nB);
printf("Set A:");
displaySet(setA);
printf("Set B:");
displaySet(setB);
int union_result = unionSet(setA,setB);
printf("Union of A and B:");
displaySet(union_result);
int intersection_result = intersectionSet(setA,setB);
printf("Intersection of A and B:");
displaySet(intersection_result);
int difference_result = differenceSet(setA,setB);
printf("Difference of A and B (A-B):");
displaySet(difference_result);
return 0;
}
