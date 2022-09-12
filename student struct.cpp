#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <locale.h>

//���������, ����������� ��������

struct Student
{
	char lastname[30];
	char group[10];
};

//������� ��������� ��������� ������ ������� ���������, ������������ � ��������� "students", �����s� ������ � ������ group � �� ������� ���������� �� ����� "�"

void surname(Student students[], int N, char group[10], char c)
{
  //��������� ���-�� ���������, ������� ����� ����� �������. ��� ����� ����� k

	int k = 0;

	for (int i = 0; i < N; i++)
	{
		//���� ������ i-�� �������� ����� group � ������ ����� ��� ������� ����� "C", �� k++

		if ((strcmp(students[i].group, group) == 0) && (students[i].lastname[0] == c))
		{
			k++;
		}
	}

	//�������� ������ ��� k �������

	char** lastNames = (char**)malloc(k * sizeof(char*));

	k = 0;

	//������ � ������ "lastNames" ��� ���������� �������

	for (int i = 0; i < N; i++)
	{
		if ((strcmp(students[i].group, group) == 0) && (students[i].lastname[0] == c))
		{
			lastNames[k++] = students[i].lastname;
		}
	}

	//������� �� � �������

	for (int i = 0; i < k; i++)
	{
		printf("%s\n", lastNames[i]);
	}

	//��������� ������ �� ��� ������� lastNames
	
	free(lastNames);
}

int main()
{
	setlocale(LC_ALL, "RUS");

	//������� ������ �������� � �������������� ��� �������

	Student students[6] = {
		"Ivanov","21vv-4",
		"Savkin","21vv-4",
		"Savostin","21vv-4",
		"Snegirev","21vv-4",
		"Petrov","21vv-4",
		"Dugerenko","21vv-4",
	};

	//���� �������� �������� ������ �� �������

	char group[10];

	//������ �������� ������ �� �������

	printf("������� �������� ������ \n");

	gets_s(group);

	printf("������� ������ ����� ������� �������� \n");

	//������ �� ������� ������ ����� �������


	char c = getchar();

	//�������� ���� �������

	surname(students, 6, group, c);
}