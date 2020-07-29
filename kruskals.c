#include <stdio.h>
int e,v;
int p[20];
int mst[20][20];
int a[10][3],adj[20][20];

void createAdj(int adj[][v+1],int a[][3])
{
	for(int i=0;i<v+1;i++)
	{
		for(int j=0;j<v+1;j++)
		{
			adj[i][j]=0;
		}
	}
	for(int i=0;i<e;i++)
	{
		int x=a[i][0];
		int y=a[i][1];
		int z=a[i][2];
		/*For an un-directed graph*/
		adj[x][y]=z;
		adj[y][x]=z;

	}
}
void add(int p,int q,int r)
{
	mst[p][q]=r;
	mst[q][p]=r;
}
int compressedFind(int a)
{
	if(p[a]<0)
		return a;
	a=compressedFind(p[a]);
	return a;
}
int WeightUnion(int u,int v)
/*applied only for root nodes*/
{
	if(p[u]>p[v])
	{
		p[u]=p[u]+p[v];
		p[v]=u;
	}
	else
	{
		p[v]=p[u]+p[v];
		p[u]=v;
	}
}

void sortEdge(int a[][3])
{
	int min,t;
	for(int i=0;i<e-1;i++)
	{
		min=i;
		for(int j=i+1;j<e;j++)
		{
			if (a[j][2]<a[min][2])
			{
				min=j;
				
			}
			for(int z=0;z<2;z++)
			{	
				t = a[i][z];
      			a[i][z] = a[min][z];
      			a[min][z] = t;
			}
		}	
	}
	for(int i=0;i<e;i++)
	printf("%d%d%d\n",a[i][0],a[i][1],a[i][2] );	
}

void kruskals(int adj[][v+1],int a[][3])
{
	int x,y,u,v;
	/*initialize  mst*/
	for(int i=0;i<v+1;i++)
	{
		for(int j=0;j<v+1;j++)
		{
			mst[i][j]=0;
		}
	}
	sortEdge(a);
	for(int i=0;i<e;i++)
	{
		u=a[i][0];
		v=a[i][1];
		x=compressedFind(u);
		y=compressedFind(v);
		if(x!=y)
		{
			add(a[i][0],a[i][1],a[i][2]);
			WeightUnion(x,y);

		}
	}
}
void print()
{
	for(int i=1;i<v+1;i++)
	{
		for(int j=1;j<v+1;j++)
		{
			/*if(mst[i][j]!=0)
			{
			x	printf("(%d-%d)-%d\n",i,j,mst[i][j] );
			}
			/*printf("%d",mst[i][j]);*/
		}
		printf("\n");
	}
}
int main()
{
	int a[10][3],adj[20][20];
	printf("Enter the number of vertices:\n");
	scanf("%d",&v);
	printf("Enter the number of edges:\n");
	scanf("%d",&e);
	printf("enter the edges and weight:\n");
	for(int i=0;i<e;i++)
	{
		printf("Enter the Source,Destination and the Weight:\n");
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
	}
	for(int i=0;i<v;i++)
	{
		p[i]=-1;
	}
	createAdj(adj,a);
	kruskals(adj,a);
	print();
	
	return 0;
}
	