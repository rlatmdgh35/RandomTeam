#include "stdafx.h"

int main()
{
	int personNum;
	int teamNum;

	cout << "인원 수를 입력해주세요." << endl;
	cin >> personNum;

	cout << "몇 팀으로 나눌 건지 입력해주세요." << endl;
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
		cout << "숫자를 골라주세요. 남은 숫자는" << endl;

		vector<int> input;

		for (int j = 0; j < maxNum; j++)
		{
			printf("%d ", test[i]);

			if (j / 6 == 0) cout << endl;
		}
		
		int a;
		cout << "입니다." << endl;

		input.push_back();

		for (int j = 0; j < i; j++)
		{
			if (input[i] == input[j])
			{
				system("cls");
				cout << "중복되는 숫자 입니다. 다시 입력해주세요." << endl;
				cin >> input[i];
			}
		}

		while (0 >= input[i] || input[i] > personNum)
		{
			system("cls");
			cout << "잘못 입력하셨습니다. 다시 입력해주세요." << endl;
			cin >> input[i];
		}

		system("cls");
		cout << "당신은 " << (test[input[i]] * teamNum / maxNum) + 1 << "번째 팀입니다." << endl; // (test[input] / (maxNum / teamNum)) + 1 -> (test[input] * teamNum / maxNum) + 1

		test[input[i]] = 0;
	}

	return 0;
}