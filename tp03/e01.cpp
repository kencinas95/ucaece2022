#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX_STUDENTS 50
#define MIN_ALLOWED_AGE 13
#define MAX_ALLOWED_AGE 80

void itest();
int get_random_number_from_range(int, int);
float get_average_age_from_students(int[]);
int get_count_of_students_with_age_greater_than_average(int [], float);


int main(int argc, char const *argv[])
{
	// Initialize randomizer
	srand(time(NULL));
	itest();
	return 0;
}

void itest()
{
	int students[MAX_STUDENTS];

	for (int i = 0; i < MAX_STUDENTS; i++)
	{
		students[i] = 0;
	}

	int n_students = get_random_number_from_range(1, MAX_STUDENTS);
	for (int i = 0; i < n_students; i++)
	{
		students[i] = get_random_number_from_range(MIN_ALLOWED_AGE, MAX_ALLOWED_AGE);		
	}
	printf("Total students: %d\n", n_students);

	double average = get_average_age_from_students(students);
	int c_gt_average = get_count_of_students_with_age_greater_than_average(students, average);
	printf("Students with age over average: %d\n\n", c_gt_average);
}

int get_random_number_from_range(int start, int end)
{
	return (rand() % end) + start;
}

float get_average_age_from_students(int students[])
{
	int s = 0;
	int c = 0;

	for (int i = 0; i < MAX_STUDENTS; i++)
	{
		if (students[i] != 0)
		{
			s += students[i];
			c++;
		}
	}

	return c != 0 ? s/(float)c : 0.0;
}

int get_count_of_students_with_age_greater_than_average(int students[], float average)
{
	int c = 0;
	printf("Average age for students is: %f\n", average);
	for (int i = 0; i < MAX_STUDENTS; i++)
	{
		if (students[i] > average) 
		{
			printf("Student number %d has an age over average: %d\n", i + 1, students[i]);
			c++;
		}
	}
	return c;
}

