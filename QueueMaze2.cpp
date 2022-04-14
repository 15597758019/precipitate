//2020240098 贾旺 大数据203
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
enum{
	PATH,
	WALL,
	ENTR,
	EXIT,
	FOOT,
	FAKE
};
#define MaxSize 100
#define M 8
#define N 8
typedef struct
{   int i,j;     
	int di;   
} Box; 
typedef struct{
	Box data[MaxSize];
	int front=0,rear=0; 
}CirQueue;

int mg[M+2][N+2]= 
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};
void print(Box data[],int front)
{ 
	for(int i=front;i>0;i=data[i].di)
	{
		mg[data[i].i][data[i].j] = 4;
	}
}
bool mgpath1(int xi,int yi,int xe,int ye)
{   int i, j, ki, i1, j1;
	CirQueue qu;
	qu.rear++;
	qu.data[qu.rear].i=xi; qu.data[qu.rear].j=yi; qu.data[qu.rear].di=-1; 
	mg[xi][yi] = -1;		        
	while(qu.front!=qu.rear)		    
	{   qu.front++;
		i=qu.data[qu.front].i; j=qu.data[qu.front].j; 
		if (i==xe && j==ye)	    
		{   print(qu.data, qu.front);	
			return true;		
		}
		for (ki=0;ki<4;ki++)    
		{	
			switch(ki)
			{
				case 0:i1=i-1;   j1=j; break;
				case 1:i1=i;  j1=j+1; break;
				case 2:i1=i+1;  j1=j; break;
				case 3:i1=i;   j1=j-1; break;
			}
			if (mg[i1][j1]==0)
			{   
				qu.rear++;
				qu.data[qu.rear].i=i1; qu.data[qu.rear].j=j1; 
				qu.data[qu.rear].di=qu.front;	
				mg[i1][j1]=5;
			}
		}
	}
	return false;
}
void printMaze(){
	int i,j;
	for(i= 0;i<M+2;i++){
		for(j =0;j<N+2;j++){
			switch(mg[i][j]){
			case PATH:
				printf("  ");
				break;
			case WALL:
				printf("围");
				break;
			case ENTR:
				printf("囚");
				break;
			case EXIT:
				printf("回");
				break;
			case FOOT:
				printf("Ｏ");
				break;
			case FAKE:
				printf("//");
				break;
			}
			
		}
		
		printf("\n");
	}
}

int main()
{ 
	srand(time(NULL));
	//	printMaze();
	//	if (!mgpath1(1,1,M,N))
	//		printf("该迷宫问题没有解!");
	//	mg[M][N] = 3;
	//	mg[1][1] = 2;
	//	printMaze();
	//	return 1;
	int i = rand()%8+1;
	int j = rand()%8+1;
	int k = rand()%8+1;
	int l = rand()%8+1;
	while(mg[i][j]==1 || mg[k][l]==1)
	{
		i = rand()%8+1;
		j = rand()%8+1;
		k = rand()%8+1;
		l = rand()%8+1;
	}
	if(!mgpath1(i,j,k,l))
		printf("错误\n");
	mg[i][j] = 2;
	mg[k][l] = 3;
	printMaze();
	return 0;
}
