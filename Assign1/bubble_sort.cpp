/*CSCI 241       Assignment 1   Spring 2021
Programmer: Christopher Huguelet
Section: 2
Date Due: 1/21/2021
Purpose: this program is created in order to demonstrate the Bubble Sort method of coding.
*/
#include <iostream>
#include <iomanip>

using namespace std;

int build_array(int[]);
void sort_array(int[], int);
void print_array(int[], int);
int main()
{
	int array [1000];
	int count = 0;
	count = build_array(array); //buld array constructs the array before it is sorted.
	sort_array(array,count); //sequences them in order
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

void sort_array(int array[], int n)
{
    bool swapped = false;
    do
    {
        int i = 1;
        swapped = false;
        while (i < n)
        {
	    if (array[i - 1] > array[i])
            {
                swap(array[i - 1], array[i]);
                swapped = true;
            }
            i = i + 1;
        }
    }
    while(swapped == true);
}
void print_array(int array[], int count)
{	
		int i;
		for (i = 0; i < count; i++)
			{
			cout << setw(8) << array[i];
			
			if ((i+1) % 8 == 0)
				cout << endl;
			}
		if (i % 8 !=0)
			cout << endl;
}

