// JAAR
// 06/06/2023
// C++ Primer Plus 6th Ed
// CH 8 Program Ex 5
// Version 3

// Updates:
// +max, min, average function overload w/ int arr_size argument
// +max, min specialized function for character arrays.

// Future goals:
// TODO: Create a function of pointers to all functions.

// Potential Use cases/errors:

// ------------------------------ Prompt---------------------------------------
// template function max5() (argument is array of 5 T)
// fixed size with max returning the largest element in the array.
// PE 6: function overloading max(arr, int size);
// contains a specialization to an array of pointers where the char * with the
// largest string is return
// ------------------------------ Prompt---------------------------------------

// Headers:
#include <iostream>
#include <cstring>

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
template <typename T>
auto max(T arr[], int arr_size) -> T;
template <typename T>
auto min(T arr[], int arr_size) -> T;
template <typename T>
auto average(T arr[], int arr_size) -> T;
const char* max(const char* arr[], int arr_size);
const char* min(const char* arr[], int arr_size);

int main()
{
	int arr_i[]{ 5,4,3,2,1 };
	double arr_d[]{ 3.2, 4.3, 2.3, 43.2, -23.3 };
	int arr_i_6[]{ 3, 4, 2, 6, 4, 8 };
	double arr_d_4[]{ 3.23, 43.2, -34.2, 23.1 };

	// TODO: Extract all calls to a function. 
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

	// arr of 6 elements:
	cout << "\tFOR ARRAY OF n ELEMENTS\n";
	int max_i6 = max(arr_i_6, 6);
	cout << "Max int: " << max_i << "\n";
	cout << "Max double: " << max_d << "\n";
	double min_d4 = min(arr_d_4, 4);
	int min_i6 = min(arr_i_6, 6);
	cout << "Min int: " << min_i6 << "\n";
	cout << "Min double: " << min_d4 << "\n";
	double avg_d4 = average(arr_d_4, 4);
	double avg_i6 = average(arr_i_6, 6);
	cout << "Average int: " << avg_i6 << "\n";
	cout << "Average double: " << avg_d4 << "\n";

	cout << "\tSTRING SPECIALIZATION\n";

	const char* arr[]{ "This is a string.", "Other string.", "Last String."};
	const char* largest_string = max(arr, 3);
	const char* smallest_string = min(arr, 3);

	cout << "Largest string: " << largest_string << "\n";
	cout << "Smallest string: " << smallest_string << "\n";
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


// Finds the largest value in a list of int size
// !Assume the operators less than and greater than work on the elements.
// Param: template T arr[], int arr_size; 
// Return: T max_Value;
template <typename T>
auto max(T arr[], int arr_size) -> T
{
	T max_Value = arr[0];
	for (int i = 1; i < arr_size; i++)
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

// Finds the smallest value in a list of some int size.
// !Assume the operators less than and greater than work on the elements.
// Param: template T arr[], int arr_size; 
// Return: T min_Value;
template <typename T>
auto min(T arr[], int arr_size) -> T
{
	T min_Value = arr[0];
	for (int i = 1; i < arr_size; i++)
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
	return (double) average / SIZE;
}

// Finds the average for an array of int arr_size.
// !Assume the operators less than and greater than work on the elements.
// Param: template T arr[], int arr_size; 
// Return: T min_Value;
template <typename T>
auto average(T arr[], int arr_size) -> T
{
	T average = 0;
	for (int i = 0; i < arr_size; i++)
	{
		average += arr[i];
	}
	return (double) average / SIZE;
}

// Finds the largest string in a list of strings with some size arr_size.
// Param: const char* arr[], int arr_size 
// Return: const char* 
const char* max(const char* arr[], int arr_size)
{
	int current_string = 0;
	for (int i = 1; i < arr_size; i++)
	{
		if (strlen(arr[current_string]) < strlen(arr[i]))
		{
			current_string = i;
		}
	}
	return arr[current_string];
}

// Finds the smallest string in a list of strings with some size arr_size.
// Param: const char* arr[], int arr_size 
// Return: const char* 
const char* min(const char* arr[], int arr_size)
{
	int current_string = 0;
	for (int i = 1; i < arr_size; i++)
	{
		if (strlen(arr[current_string]) > strlen(arr[i]))
		{
			current_string = i;
		}
	}
	return arr[current_string];
}

