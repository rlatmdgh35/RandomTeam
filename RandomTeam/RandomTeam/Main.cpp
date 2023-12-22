#include "stdafx.h"

int maxNum;
int input_int;

vector<int> index;

void RemainNumber()
{
	printf("남은 숫자는\n");

	for (int i = 0; i < maxNum; i++)
	{
		if (i % 6 == 0) cout << endl;

		cout << index[i] << "   ";
	}

	cout << "입니다." << endl << endl << "입력 : ";
	cin >> input_int;
}

int main()
{
	int personNum;
	cout << "인원 수를 입력해주세요." << endl;
	cin >> personNum;

	int teamNum;
	cout << "몇 팀으로 나눌 건지 입력해주세요." << endl;
	cin >> teamNum;

	if (personNum < teamNum || personNum == 0)
		return 0;

	int division = personNum / teamNum;
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
		cout << "숫자를 골라주세요. 남은 숫자는" << endl;
		RemainNumber();

		bool key = true;
		while(key)
		{
			if (0 >= input_int || input_int > personNum)
			{
				system("cls");
				cout << "잘못 입력하셨습니다. 다시 입력해주세요." << endl;
				RemainNumber();
			}
			else key = false;
		}


		for (int j = 0; j < i; j++)
		{
			while (true)
			{
				if (input_int == input[j])
				{
					system("cls");
					cout << "중복되는 숫자 입니다. 다시 입력해주세요." << endl;
					RemainNumber();
				}
				else
				{
					break;
				}
			}
		} // Need Fix

		input.push_back(input_int);

		system("cls");
		int count = input[i] - 1;
		cout << "당신은 " << (array[count] * teamNum / maxNum) + 1 << "번째 팀입니다." << endl; // (array[input] / (maxNum / teamNum)) + 1 -> (array[input] * teamNum / maxNum) + 1
		index[count] = 0;

		system("pause");
	}

	return 0;
}