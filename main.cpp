// JAAR
// 06/05/2023
// C++ Primer Plus 6th Ed
// CH 8 Program Ex 5
// Version 2

// Updates:
// +max function
// +min function
// +average function
// +global var SIZE

// Future goals:
// TODO: Create a function of pointers to all functions.

// Potential Use cases/errors:

// ------------------------------ Prompt---------------------------------------
// template function max5() (argument is array of 5 T)
// fixed size with max returning the largest element in the array.
// ------------------------------ Prompt---------------------------------------

// Headers:
#include <iostream>

using namespace std;

// Global Constants and Structures:
const int SIZE = 5;


// Prototypes:
template <typename T>
auto max(T (&arr)[SIZE]) -> T;
template <typename T>
auto min(T(&arr)[SIZE]) -> T;
template <typename T>
auto average(T(&arr)[SIZE]) -> T;

int main()
{
	int arr_i[]{ 5,4,3,2,1 };
	double arr_d[]{ 3.2, 4.3, 2.3, 43.2, -23.3 };

	int max_i = max(arr_i);
	double max_d = max(arr_d);
	cout << "Max int: " << max_i << "\n";
	cout << "Max double: " << max_d << "\n";
	int min_i = min(arr_i);
	double min_d = min(arr_d);
	cout << "Min int: " << min_i << "\n";
	cout << "Min double: " << min_d << "\n";
	double average_i = average(arr_i);
	double average_d = average(arr_d);
	cout << "Average int: " << average_i << "\n";
	cout << "Average double: " << average_d<< "\n";
}


// Finds the largest value in a list
// !Assume the array contains SIZE elements
// !Assume the operators less than and greater than work on the elements.
// Param: template T arr[]; 
// Return: T max_Value;
template <typename T>
auto max(T (&arr)[SIZE]) -> T
{
	T max_Value = arr[0];
	for (int i = 1; i < SIZE; i++)
	{
		if (arr[i] > max_Value)
		{
			max_Value = arr[i];
		}
	}
	return max_Value;
}

// Finds the smallest value in a list.
// !Assume the array contains SIZE elements
// !Assume the operators less than and greater than work on the elements.
// Param: template T arr[]; 
// Return: T min_Value;
template <typename T>
auto min(T (&arr)[SIZE])-> T
{
	T min_Value = arr[0];
	for (int i = 1; i < SIZE; i++)
	{
		if (arr[i] < min_Value)
		{
			min_Value = arr[i];
		}
	}
	return min_Value;
}

// Finds the average for an array of SIZE.
// !Assume the array contains SIZE elements
// !Assume the operators less than and greater than work on the elements.
// Param: template T arr[]; 
// Return: T min_Value;
template <typename T>
auto average(T(&arr)[SIZE]) -> T
{
	T average = 0;
	for (int i = 0; i < SIZE; i++)
	{
		average += arr[i];
	}
	return average / SIZE;
}

