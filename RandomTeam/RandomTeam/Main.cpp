#include "stdafx.h"

int main()
{
	int personNum;
	int teamNum;

	cout << "�ο� ���� �Է����ּ���." << endl;
	cin >> personNum;

	cout << "�� ������ ���� ���� �Է����ּ���." << endl;
	cin >> teamNum;

	if (personNum < teamNum || personNum == 0)
		return 0;

	int division = personNum / teamNum;
	int maxNum = division * teamNum;

	vector<int> test;

	for (int i = 1; i <= maxNum; i++)
		test.push_back(i);

	srand(time(NULL));
	int rand1, rand2, temp;

	for (int i = 0; i < 350; i++)
	{
		rand1 = rand() % maxNum;
		rand2 = rand() % maxNum;

		temp = test[rand1];
		test[rand1] = test[rand2];
		test[rand2] = temp;
	}

	for (int i = 0; i < personNum; i++)
	{
		system("cls");
		cout << "���ڸ� ����ּ���. ���� ���ڴ�" << endl;

		vector<int> input;

		for (int j = 0; j < maxNum; j++)
		{
			printf("%d ", test[i]);

			if (j / 6 == 0) cout << endl;
		}
		
		int a;
		cout << "�Դϴ�." << endl;

		input.push_back();

		for (int j = 0; j < i; j++)
		{
			if (input[i] == input[j])
			{
				system("cls");
				cout << "�ߺ��Ǵ� ���� �Դϴ�. �ٽ� �Է����ּ���." << endl;
				cin >> input[i];
			}
		}

		while (0 >= input[i] || input[i] > personNum)
		{
			system("cls");
			cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
			cin >> input[i];
		}

		system("cls");
		cout << "����� " << (test[input[i]] * teamNum / maxNum) + 1 << "��° ���Դϴ�." << endl; // (test[input] / (maxNum / teamNum)) + 1 -> (test[input] * teamNum / maxNum) + 1

		test[input[i]] = 0;
	}

	return 0;
}