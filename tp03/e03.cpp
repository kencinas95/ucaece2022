#include <cstdlib>
#include <iostream>
#include <ctime>

#define MAX_ELEMENTS 		100
#define rnd_range(s, e) 	((std::rand() % e) + s)
#define bzero(x) 			(std::memset(x, 0, sizeof x))
#define bset(a, v) 			(std::memset(a, v, sizeof a))
#define yn(b)				(b ? "Yes" : "No")



bool contains(int numbers[], int number)
{
	int i = 0;
	bool contains_value = false;

	while (i < MAX_ELEMENTS && !contains_value)
	{
		contains_value = numbers[i] == number;
		i++;
	}

	return contains_value;
}


int get_index_of(int numbers[], int number, bool inverse = false)
{
	int index = -1;

	if (contains(numbers, number))
	{		
		int i = inverse ? MAX_ELEMENTS : 0;
		int step = inverse ? -1 : 1;

		while ((inverse ? i >= 0 : i < MAX_ELEMENTS) && index == -1)
		{
			if (numbers[i] == number)
			{
				index = i;
			} else {
				i += step;
			}			
		}
	}	

	return index;
}


void get_indexes_of(int numbers[], int indexes[], int number)
{	
	if (contains(numbers, number))
	{
		int i = 0;
		for (int j = 0; j < MAX_ELEMENTS; j++)
		{
			if (numbers[j] == number)
			{
				indexes[i] = j;
				i++;
			}
		}
	}
}


void get_first_and_last_index_of(int numbers[], int number, int &first, int &last)
{	
	first = get_index_of(numbers, number);
	last = get_index_of(numbers, number, true);
	
	int i = MAX_ELEMENTS - 1;
	do
	{
		if (numbers[i] == number)
		{
			last = i;
		} else {
			i--;
		}
	} while (i >= 0 && last == -1);	
}


int main(int argc, char const *argv[])
{	
	std::srand(std::time(nullptr));

	int numbers[MAX_ELEMENTS];
	int indexes[MAX_ELEMENTS];
	int number = rnd_range(1, 10);

	bzero(numbers);
	bset(indexes, -1);

	for (int i = 0; i < MAX_ELEMENTS; i++)
	{
		numbers[i] = rnd_range(1, 10);
		std::cout << "[" << i << "] = " << numbers[i] << std::endl;
	}

	std::cout << "Contains (" << number << "): " << yn(contains(numbers, number)) << std::endl;	
	std::cout << "Index of (" << number << "): " << get_index_of(numbers, number) << std::endl;
	
	get_indexes_of(numbers, indexes, number);	
	std::cout << "All indexes (" << number << ")" << std::endl;
	for (int i = 0; i < MAX_ELEMENTS; i++)
	{
		if (indexes[i] != -1)
		{
			std::cout << "[" << i << "] -> " << indexes[i] << std::endl;			
		}
	}

	int first = -1, last = -1;
	get_first_and_last_index_of(numbers, number, first, last);

	std::cout << "First index: ";
	std::cout << first << std::endl;

	std::cout << "Last index: "	;
	std::cout << last << std::endl;

	return 0;
}