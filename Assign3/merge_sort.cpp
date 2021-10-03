/*CSCI 241       Assignment 3   Spring 2021
Programmer: Christopher Huguelet
Section: 2
Date Due: 2/5/2021
Purpose: this program is created in order to demonstrate the Merge Sort method of sorting an unsorted array of numbers.
*/
#include <iostream>
#include <iomanip>

using namespace std;

int build_array(int[]);
void merge_sort(int[], int, int);
void merge_sort(int[], int);
void print_array(int[], int);
void merge(int[], int, int, int);	
int main()
{
	int array [1000];
	int count = 0;
	count = build_array(array); //buld array constructs the array before it is sorted.
	merge_sort(array,count-1); //sequences them in order
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

/**
 * Sort an array using merge sort.
 * 
 * 1. Divide the unsorted list into n sublists, each containing one element. A list of one element is sorted by definition.
 * 2. Repeatedly merge sorted sublists (called "runs") to produce longer runs until there is only one run remaining. This is the sorted list.
 * 
 * @param array is an array that is then sorted by this function.
 * @param start is the first element of the the list
 * @param end is the last element of the list
 * @return void
 * @see http://faculty.cs.niu.edu/~mcmahon/CS241/Notes/Sorting_Algorithms/merge_sort.html
 */
 void merge_sort(int array[], int start, int end) //procedure insertion_sort(array : list of sortable items, n : length of list)
{
	//if start < end
    if (start < end)
    {
        //mid ← (start + end) / 2
        int mid = (start + end) / 2;
        //merge_sort(array, start, mid)
        merge_sort(array, start, mid);
        //merge_sort(array, mid + 1, end)
        merge_sort(array, mid + 1, end);
        //merge(array, start, mid, end)
        merge(array, start, mid, end);
    //end if
    }
}      

/**
 * Sort an array using merge sort.
 * 
 * 1. Divide the unsorted list into n sublists, each containing one element. A list of one element is sorted by definition.
 * 2. Repeatedly merge sorted sublists (called "runs") to produce longer runs until there is only one run remaining. This is the sorted list.
 * 
 * @peram array is an array that is then sorted by this function.
 * @peram end is the last element of the list
 * @return void
 * @see http://faculty.cs.niu.edu/~mcmahon/CS241/Notes/Sorting_Algorithms/merge_sort.html
 */
void merge_sort(int array[], int end)
{
	merge_sort(array, 0, end);
}

/**
 * Merge arrays that have been sorted
 * 
 * 1. loop over both arrays
 * 2. merge them into the temp array
 * 3. copy elements back into the array
 * 
 * @param array is the array that contains the sublists to be merged.
 * @param start is the first element of the first sublist
 * @param mid is the first element of the second sublist
 * @param end is the last element of the second sublist
 * @return void
 * @see http://faculty.cs.niu.edu/~mcmahon/CS241/Notes/Sorting_Algorithms/merge_sort.html
 */
void merge(int array[], int start, int mid, int end)
{
	
	//temp : temporary array of size (end - start + 1)
    int temp[(end - start) + 1];
    //i ← start
    int i = start;
    //j ← mid + 1
    int j = mid + 1;
    //k ← 0
    int k = 0;
    //while i <= mid and j <= end
    while( i <= mid && j <= end )
    {
        //if array[i] < array[j]
        if (array[i] < array[j])
        {
            //temp[k] ← array[i]
            temp[k] = array[i];
			//i ← i + 1
            i++;
        }
        //else
        else
        {
            //temp[k] ← array[j]
            temp[k] = array[j];
            //j ← j + 1
            j++;
        //end if
	    }
        //k ← k + 1
        k++;
    
    //end while
	}
    //while i <= mid
    while( i <= mid)
    {
        //temp[k] ← array[i]
        temp[k] = array[i];
        //i ← i + 1
        i++;
        //k ← k + 1
        k++;
    //end while
    }
    //while j <= end
    while(j <= end)
    {    
        //temp[k] ← array[j]
        temp[k] = array[j];
        //j ← j + 1
        j++;
        //k ← k + 1
		k++;
    //end while
    }
    //Copy elements of temp back into array
    for(int l = start, m = 0; l <= end; l++, m++)
    {
		array[l] = temp[m]; 
    }
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

