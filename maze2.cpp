#include <stdio.h>
#include<stdlib.h>
#include<time.h>
enum{
	PATH,
	WALL,
	ENTR,
	EXIT,
	FOOT,
	FAKE
};
int mg[10][10]= {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
	{1, 0, 1, 1, 1, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
	{1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};
int M=8;//����
int N=8;//����
typedef struct
{
	int i;//��ǰ�����к�
	int j;//��ǰ�����к�
	int di;//��һ�����ߵ����ڷ���ķ�λ��
} Box; //���巽������
typedef struct
{
	Box data[100];
	int top;//ջ��ָ��
} StType; //����˳��ջ����
bool mgpath(int xi,int yi,int xe,int ye)//���·��Ϊ��(xi,yi)->(xe,ye)
{
	int i,j,k,di,find;
	StType st;//����ջst
	st.top=-1;//��ʼ��ջ��ָ��
	st.top++;//��ʼ�����ջ
	st.data[st.top].i=xi;
	st.data[st.top].j=yi;
	st.data[st.top].di=-1;
	mg[xi][yi]=-1;
	while(st.top>-1)//ջ��Ϊ��ʱѭ��
	{
		i=st.data[st.top].i;
		j=st.data[st.top].j;
		di=st.data[st.top].di;//ȡջ������
		if(i==xe&&j==ye)//�ҵ����ڣ����·��
		{
			for(k=0; k<=st.top; k++)
			{
				mg[st.data[k].i][st.data[k].j] = 4;
			}
			printf("\n");
			return true;
		}
		find=0;
		while(di<4&&find==0)//վ��һ�����߷���
		{
			di++;
			switch(di)
			{
			case 0:
				i=st.data[st.top].i-1;
				j=st.data[st.top].j;
				break;
			case 1:
				i=st.data[st.top].i;
				j=st.data[st.top].j+1;
				break;
			case 2:
				i=st.data[st.top].i+1;
				j=st.data[st.top].j;
				break;
			case 3:
				i=st.data[st.top].i;
				j=st.data[st.top].j-1;
				break;
			}
			if(mg[i][j]==0)
				find=1;//����һ���������ڷ���
		}
		if(find==1)//�ҵ�����һ�����߷���
		{
			st.data[st.top].di=di;//�޸�ԭջ��Ԫ�ص�diֵ
			st.top++;//��һ�����߷����ջ
			st.data[st.top].i=i;
			st.data[st.top].j=j;
			st.data[st.top].di=-1;
			mg[i][j]=-1;//�����ظ��ߵ��÷���
		}
		else//û��·����������ջ
		{
			mg[st.data[st.top].i][st.data[st.top].j]=5;//�ø�λ�ñ�Ϊ����·�������߷���
			st.top--;//���÷�����ջ
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
				printf("Χ");
				break;
			case ENTR:
				printf("��");
				break;
			case EXIT:
				printf("��");
				break;
			case FOOT:
				printf("��");
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
//		printMaze();
//
//	if(!mgpath(1,1,M,N))
//		printf("�޽�\n");
//	mg[1][1] = 2;
//	mg[M][N] = 3;
//	printMaze();
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
	if(!mgpath(i,j,k,l))
		printf("�޽�\n");
	mg[i][j] = 2;
	mg[k][l] = 3;
	printMaze();
	return 0;
}

