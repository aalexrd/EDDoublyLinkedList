#include "LinkedList.h"
#include <iostream>
#include <time.h>

std::string getString();
int getInt();

int main()
{
	srand(time(nullptr));
	LinkedList<int> list;
	for (int i = 0; i < 10; ++i)
		list.add(rand() % 100);
	std::cout << list.toString();
	std::cout << std::endl << "Ingrese un numero a eliminar: ";
	list.removeItem(getInt());
	std::cout << list.toString();
	std::cin.get();
}

std::string getString()
{
	std::string line;
	while (true)
	{
		getline(std::cin, line);
		if (line.empty())
			continue;
		return line;
	}
}

int getInt()
{
	std::string number = getString();
	std::string n;
	if (number[0] == 45)
		n.push_back(number[0]);
	for (unsigned int i = 0; i < number.length(); i++)
		if (number[i] > 47 && number[i] < 58)
			n.push_back(number[i]);
	return n.empty() ? getInt() : atoi(n.c_str());
}
