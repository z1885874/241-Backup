/*CSCI 241       Assignment 3   Spring 2021
Programmer: Christopher Huguelet
Section: 2
Date Due: 2/5/2021
Purpose: this program is created in order to demonstrate the Quick Sort method of sorting an unsorted array of numbers.
*/
#include <iostream>
#include <iomanip>

using namespace std;

int build_array(int[]);
void sort_array(int[], int, int);
int split_array(int[],int,int);
void print_array(int[], int);
int main()
{
	int start, end;
	int array [1000];
	int count = 0;	
	count = build_array(array); //buld array constructs the array before it is sorted.
	start = 0;
	end = count - 1;
	sort_array(array,start, end); //sequences them in order
	print_array(array,count); // prints out array in batches of 8 here
	
	return 0;
}

int build_array(int array[])
{
	int count = 0;
	while (cin >> array[count])
		{
			count++;
		}
		
		return count;
}


void sort_array(int array[], int start, int end) //procedure Quick_sort(array : list of sortable items, n : length of list)
{
	if (start < end)
	{
	int pivot = split_array(array, start, end);
	sort_array(array, start, pivot - 1);
	sort_array(array, pivot + 1, end);
	}	
}  

int split_array(int array[], int start, int end)
{
	int temp = 0;
	int mid = 0;
	int index = 0;
	int value = 0;
	int scand = 0;
	mid = ((start + end)/2);
	temp = array[start];
	array[start] = array[mid];
	array[mid] = temp;
	index = start;
	value = array[start];
	scand = start + 1;
	while (scand <= end)
	{
		if (array[scand] < value)
		{
			index = index + 1;
			temp = array[index];
			array[index] = array[scand];
			array[scand] = temp;
		}
		scand = scand + 1;
	}
	temp = array[start];
	array[start] = array[index];
	array[index] = temp;
	return index;			 
	
}

void print_array(int array[], int count)
{	
		int i;
		
		for (i = 0; i < count; i++)
			{
			cout << setw(8) << array[i] ;
			
			if ((i+1) % 8 == 0)
				cout << endl;
			}
		if (i % 8 !=0)
			cout << endl;
}

