#include<stdio.h>
#include<stdio.h>
#define MAX 100
void calculateIndegree(int graph[MAX][MAX],int vertices,int indegree[])
{
for(int i=0;i<vertices;i++)
{
indegree[i]=0;
for(int j=0;j<vertices;j++)
{
if(graph[j][i]==1)
{
indegree[i]++;
}
}
}
}
void topologicalSort(int graph[MAX][MAX],int vertices)
{
int indegree[MAX];
calculateIndegree(graph, vertices,indegree);
int queue[MAX],front=0,rear=0;
int topoOrder[MAX],topoIndex=0;
for(int i=0;i < vertices;i++)
{
if(indegree[i]==0)
{
queue[rear++]=i;
}
}
while(front<rear)
{
int current=queue[front++];
topoOrder[topoIndex++]=current;
for(int i=0;i<vertices;i++)
{
if(graph[current][i]==1)
{
graph[current][i]=0;
indegree[i]--;
if (indegree[i]==0)
{
queue[rear++]=i;
}
}
}
}
if(topoIndex!=vertices)
{
printf("The graph contains a cycle.Topological sorting is not possible.\n");
return;
}
printf("Topological Order: ");
for (int i = 0; i < topoIndex; i++) 
{
printf("%d ", topoOrder[i]);
    }
    printf("\n");
}

int main() {
    int vertices, edges, src, dest;
    int graph[MAX][MAX] = {0};

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1;
    }

    topologicalSort(graph, vertices);

    return 0;
}
