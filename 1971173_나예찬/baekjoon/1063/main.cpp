#include <iostream>
#include <string>

void move(std::pair<int,int> * kPos, std::pair<int,int> * sPos, std::pair<int, int> v)
{
	std::pair<int, int> kNextPos = { kPos->first + v.first, kPos->second + v.second } , sNextPos = *sPos;
	if (kNextPos.first >= 1 && kNextPos.second >= 1 && kNextPos.first <= 8 && kNextPos.second <= 8)
	{
		if (kNextPos == sNextPos)
		{
			sNextPos.first += v.first;
			sNextPos.second += v.second;
			if (sNextPos.first >= 1 && sNextPos.second >= 1 && sNextPos.first <= 8 && sNextPos.second <= 8)
			{
				*sPos = sNextPos;
				*kPos = kNextPos;
				return;
			}
		}
		else
		{
			*kPos = kNextPos;
			return;
		}
	}
}

int main() {
	char columnChar;
	std::pair<int, int> kPos, sPos;
	std::cin >> kPos.first;
	columnChar = std::cin.get();
	kPos.second = columnChar - 'A' + 1;
	std::cin.ignore();

	std::cin >> sPos.first;
	columnChar = std::cin.get();
	sPos.second = columnChar - 'A' + 1;
	std::cin.ignore();

	int n;
	std::cin >> n;
	while (n--)
	{
		std::string command;
		std::cin >> command;
		if (command == "R")
		{
			move(&kPos, &sPos, { 0,1 });
		}
		if (command == "L")
		{
			move(&kPos, &sPos, { 0,-1 });
		}
		if (command == "B")
		{
			move(&kPos, &sPos, { 1,0 });
		}
		if (command == "T")
		{
			move(&kPos, &sPos, { -1,0 });
		}
		if (command == "RT")
		{
			move(&kPos, &sPos, { -1,1 });
		}
		if (command == "LT")
		{
			move(&kPos, &sPos, { -1,-1 });
		}
		if (command == "RB")
		{
			move(&kPos, &sPos, { 1,1 });
		}
		if (command == "LB")
		{
			move(&kPos, &sPos, { -1,1 });
		}
	}
	std::cout << static_cast<char>(kPos.first+'A'-1) << kPos.second << std::endl;
	std::cout << static_cast<char>(sPos.first+'A'-1) << sPos.second << std::endl;

	return 0;
}