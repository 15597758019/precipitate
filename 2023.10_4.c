//���뻷�� Micorsoft Visual Studio 
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//ѧ����Ϣ
typedef struct _Student
{
	int stuNum;//ѧ��
	char name[20];//name
	int score;//�ɼ�
}Student;

typedef struct _Node
{
	Student student;
	struct _Node* next;
}Node;

void welcome();
void inputStudent(Node* head);
void printfStudent(Node* head);
void countStudent(Node* head);
void findStudent(Node* head);
void saveStudent(Node* head);
void loadStudent(Node* head);//��ȡ�ļ�
void modifyStudent(Node* head);
void deleteStudent(Node* head);
void sortStudent(Node* head);


int main(){
	//����ͷ�ڵ�
	Node*  head = malloc(sizeof(Node));
	head->next = NULL;
	loadStudent(head);

	while (1){
		welcome();
	char c = _getch();
	switch (c)
	{
	case'1':
		inputStudent(head);//����ѧ����Ϣ
		break;
	case'2':
		printfStudent(head);//��ӡѧ����Ϣ
		break;
	case'3':
		countStudent(head);//ͳ��ѧ������
		break;
	case'4':
		findStudent(head);//����ѧ����Ϣ
		break;
	case'5':
		modifyStudent(head);//�޸�ѧ����Ϣ
		break;
	case'6':
		deleteStudent(head);//ɾ��ѧ����Ϣ
		break;
	case'7':
		sortStudent(head);//���ɼ�����
		break;
	case'8':
		system("cls");
		printf("Bye Bye!\n");
		exit(0);//�˳�ϵͳ

		break;

	default:
		printf("����������\n");
    	//��ͣ����
		system("pause");
		//��տ���̨
		system("cls");
		break;
	}
	}

	return 0;
}

void welcome(){
	printf("*********************************************\n");
	printf("*\tѧ���ɼ�����\t*\n");
	printf("*********************************************\n");
	printf("*��ѡ�����б�\t\t*\n");
	printf("*********************************************\n");
	printf("*\t1.¼��ѧ����Ϣ\t\t*\n");
	printf("*\t2.��ӡѧ����Ϣ\t\t*\n");
	printf("*\t3.ͳ��ѧ����Ϣ\t\t*\n");
	printf("*\t4.����ѧ����Ϣ\t\t*\n");
	printf("*\t5.�޸�ѧ����Ϣ\t\t*\n");
	printf("*\t6.ɾ��ѧ����Ϣ\t\t*\n");
	printf("*\t7.��ѧ���ɼ�����\t\t*\n");

	printf("*\t8.�˳�ϵͳ\t\t*\n");
	printf("*********************************************\n");

}
void inputStudent(Node* head){
	Node* fresh = malloc(sizeof(Node));
	fresh->next = NULL;
	printf("������ѧ����ѧ�ţ��������ɼ�:");
	scanf("%d%s%d", &fresh->student.stuNum, fresh->student.name, &fresh->student.score);

	Node* move = head;
	while (move->next != NULL)
	{
		move = move->next;
	}
	//��ѧ�����뵽β��
	move->next = fresh;

	saveStudent(head);
	//��ͣ����
	system("pause");
	//��տ���̨
	system("cls");

}

void printfStudent(Node* head){
	Node* move = head->next;
	while (move != NULL)
	{
		printf("ѧ�ţ�%d ������%s �ɼ���%d\n", move->student.stuNum, move->student.name, move->student.score);
		move = move->next;

	}
	//��ͣ����
	system("pause");
	//��տ���̨
	system("cls");
}

void countStudent(Node* head){
	int count = 0;
	Node* move = head->next;
	while (move != NULL)
	{
		count++;
		move = move->next;
	}
	printf("ѧ����������Ϊ��%d\n", count);
	//��ͣ����
	system("pause");
	//��տ���̨
	system("cls");
}

void findStudent(Node* head){
	printf("������Ҫ���ҵ�ѧ����ѧ�ţ�");
	int stuNum;
	scanf("%d",&stuNum);
	Node* move = head->next;
	while (move != NULL)
	{
		if (stuNum == move->student.stuNum){
			printf("ѧ�ţ�%d ������%s �ɼ���%d\n", move->student.stuNum, move->student.name, move->student.score);
			//��ͣ����
			system("pause");
			//��տ���̨
			system("cls");
			return;
		}
		move = move->next;
	}
	printf("δ�ҵ�ѧ����Ϣ\n");
	//��ͣ����
	system("pause");
	//��տ���̨
	system("cls");
}

void saveStudent(Node* head){//����ѧ����Ϣ���ļ���
	FILE* file = fopen("./stu.info", "w");//���ļ�
	Node* move = head->next;
	while (move != NULL)
	{
		if (fwrite(&move->student, sizeof(Student), 1, file) != 1){
			printf("д��ʧ��\n");
			return;
		}
		move = move->next;
	}
	fclose(file);
}

void loadStudent(Node* head){
	FILE* file = fopen("./stu.info", "r");//��ȡ�ļ�
	if (!file){
		printf("û��ѧ���ļ���������ȡ\n");
		return;
	}
	Node* fresh = malloc(sizeof(Node));
	fresh->next = NULL;
	Node* move = head;
	while (fread(&fresh->student, sizeof(Student), 1, file) == 1)
	{
		move->next = fresh;
		move = fresh;
		fresh = malloc(sizeof(Student)*2);
		fresh->next = NULL;
	}    
	free(fresh);
	fclose(file);
	printf("��ȡ�ɹ���");
}

void modifyStudent(Node* head){
	printf("������Ҫ�޸ĵ�ѧ����ѧ�ţ�");
	int stuNum;
	scanf("%d", &stuNum);
	Node* move = head->next;
	while (move != NULL)
	{
		if (move->student.stuNum == stuNum){
			printf("������ѧ�����������ɼ�\n");
			scanf("%s %d", move->student.name, &move->student.score);
			saveStudent(head);
			printf("�޸ĳɹ�\n");
			system("pause");
			system("cls");
			return;
		}
			move = move->next;
	}
	printf("δ�ҵ�ѧ����Ϣ\n");
	system("pause");
	system("cls");
}

void deleteStudent(Node* head){
	printf("������Ҫɾ����ѧ��ѧ�ţ�");
	int stuNum = 0;
	scanf("%d", &stuNum);

	Node* move = head;
	while (move->next != NULL)
	{
		if (move->next->student.stuNum == stuNum){
			Node* tmp = move->next;//�ȴ�һ��Ҫɾ���Ľڵ�
			move->next = move->next->next;//��Ҫɾ���Ľڵ�����һ���ڵ�
			free(tmp);//�ͷ��ڴ�
			tmp = NULL;
			saveStudent(head);
			printf("ɾ���ɹ�\n");
			//��ͣ����
			system("pause");
			//��տ���̨
			system("cls");
			return;
		}
		move = move->next;
	}
	printf("δ�ҵ�ѧ����Ϣ\n");
	system("pause");
	system("cls");
}

void sortStudent(Node* head){
	Node* save = NULL;//������ѭ��move��ʹ�Ѿ��ƶ���λ�õ�ѧ�����ڱ��Ƚ�
	Node* move = NULL;
	for (Node* turn = head->next; turn->next != NULL; turn = turn->next){
		for ( move = head->next; move->next != save; move = move->next){
			if (move->student.score > move->next->student.score){
				Student temp = move->student;
				move->student = move->next->student;
				move->next->student = temp;
			}
		}
		save = move;
	}
	printfStudent(head);
}
