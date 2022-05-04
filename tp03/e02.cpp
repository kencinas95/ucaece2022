#include <cstdlib>
#include <iostream>


#define rand_range(s, e) ((std::rand() % e) + s)
#define bzero(x) (std::memset(x, 0, sizeof x))
#define MAX_ELEMENTS 10


void sort(int numbers[])
{
	int aux;
	for (int i = 0; i < MAX_ELEMENTS - 1; i++) 
	{
		for (int j = i; j < MAX_ELEMENTS; j++)
		{
			if (numbers[i] > numbers[j])
			{
				aux = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = aux;
			}
		}
	}
}


void show_inverse_order(int numbers[])
{
	for (int i = MAX_ELEMENTS - 1; i >= 0; i--)
	{
		std::cout << "Elemento ";
		std::cout << i + 1;
		std::cout << ": ";
		std::cout << numbers[i] << std::endl;
	}
}


int main(int argc, char const *argv[])
{
	std::srand(std::time(nullptr));

	int numbers[MAX_ELEMENTS];
	bzero(numbers);

	for (int i = 0; i < MAX_ELEMENTS; i++)
	{
		numbers[i] = rand_range(1, 100);
	}

	sort(numbers);
	show_inverse_order(numbers);

	return 0;
}