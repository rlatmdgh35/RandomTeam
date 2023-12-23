#include "stdafx.h"

int maxNum;
int input_int;

vector<int> index;

void RemainNumber()
{
	printf("���� ���ڴ�\n");

	for (int i = 0; i < maxNum; i++)
	{
		if (i % 6 == 0) cout << endl;

		cout << index[i] << "	   ";
	}

	cout << "�Դϴ�." << endl << endl << "�Է� : ";
	cin >> input_int;
}

int main()
{
	int personNum;
	cout << "�ο� ���� �Է����ּ���." << endl;
	cin >> personNum;

	int teamNum;
	cout << "�� ������ ���� ���� �Է����ּ���." << endl;
	cin >> teamNum;

	if (personNum < teamNum || personNum == 0)
		return 0;

	int division = personNum / teamNum;
	if (personNum % teamNum == 0)
		maxNum = division * teamNum;
	else
		maxNum = (division + 1) * teamNum;

	vector<int> array;
	for (int i = 0; i < maxNum; i++)
	{
		array.push_back(i);
		index.push_back(i + 1);
	}

	srand(time(NULL));
	int rand1, rand2, temp;

	for (int i = 0; i < 350; i++)
	{
		rand1 = rand() % maxNum;
		rand2 = rand() % maxNum;

		temp = array[rand1];
		array[rand1] = array[rand2];
		array[rand2] = temp;
	}
	
	vector<int> input;
	for (int i = 0; i < personNum; i++)
	{
		system("cls");
		cout << "���ڸ� ����ּ���." << endl;
		RemainNumber();

		bool key = true;
		while (key)
		{
			if (0 >= input_int || input_int > personNum)
			{
				system("cls");
				cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
				RemainNumber();
			} // Have to input only int
			else key = false;
		}

		bool key2 = true;
		while (key || key2)
		{
			key = false;
			for (int j = 0; j < i; j++)
			{
				if (input_int == input[j])
				{
					key = true;
					key2 = true;
					system("cls");
					cout << "�ߺ��Ǵ� ���� �Դϴ�. �ٽ� �Է����ּ���." << endl;
					RemainNumber();
				}
				else key2 = false;
			}

			if (i == 0)
				key2 = false;
		}

		input.push_back(input_int);

		system("cls");
		int count = input[i] - 1;
		cout << "����� " << (array[count] * teamNum / maxNum) + 1 << "��° ���Դϴ�." << endl; // (array[input] / (maxNum / teamNum)) + 1 -> (array[input] * teamNum / maxNum) + 1
		index[count] = 0;

		system("pause");
	}

	return 0;
}