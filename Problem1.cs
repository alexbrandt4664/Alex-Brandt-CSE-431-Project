using System;
using System.Random;

/*
 * Sources: 
 * https://www.includehelp.com/dot-net/get-milliseconds-of-the-current-time-in-csharp.aspx#:~:text=To%20get%20the%20milliseconds%20only%20of%20the%20current,is%20the%20milliseconds%20value%20of%20the%20current%20time.
 * */

namespace Section1
{
    class Program
    {
        static void Main(string[] args)
        {
            int insertAmount = 10;

            do
            {
                Console.WriteLine("Insertion Amount: " + insertAmount);

                int insertSortArr[insertAmount];
                int quickSortArr[insertAmount];

                var rand = new Random();

                for (int i = 0; i < insertAmount; i++)
                {
                    int val = rand.Next();
                    insertSortArr[i] = val;
                    quickSortArr[i] = val;
                }

                int insertSortStartTime = DateTime.Now.Millisecond;
                InsertionSort(insertSortArr);
                int insertSortTotalTime = DateTime.Now.Millisecond - insertSortStartTime;

                int quickSortStartTime = DateTime.Now.Millisecond;
                QuickSort(quickSortArr, insertAmount);
                int quickSortTotalTime = DateTime.Now.Millisecond - quickSortStartTime;

                insertAmount *= 10;
            } while ()
        }

        // A utility function to print
        // array of size n
        static void PrintArray(int[] arr)
        {
            int n = arr.Length;
            for (int i = 0; i < n; ++i)
                Console.Write(arr[i] + " ");

            Console.Write("\n");
        }

        void InsertionSort(int[] original)
        {
            for (int i = 1; i < original.Length; i++)
            {
                int key = original[i];
                int j = i - 1;

                // Move elements of original[0..i-1], that are greater than the current key to one position ahead of their current position if they're greater than
                // the current key
                while (j >= 0 && original[j] > key)
                {
                    original[j + 1] = original[j];
                    j--;
                }

                original[j + 1] = key;
            }
        }

        void QuickSort(int[] original, int length) 
        {
            QuickSort(original, 0, length - 1);
        }

        void QuickSort(int[] original, int low, int up)
        {
            if (low >= up) // 0 or 1 element in sublist
                return;

            int p = Partition(original, low, up);
            QuickSort(original, low, p - 1); // Sort the left sublist
            QuickSort(original, p + 1, up); // Sort the right sublist
        }

        int Partition(int[] sub, int low, int up)
        {
            int temp, i, j, pivot;
            pivot = sub[low];
            i = low + 1; // Moves from left to right
            j = up; // Moves from right to left

            while (i <= j)
            {
                while (sub[i] < pivot && i < up)
                {
                    i++;
                }

                while (sub[j] > pivot)
                {
                    j--;
                }

                if (i < j) // Swap sub[i] and sub[j]
                {
                    temp = sub[i];
                    sub[i] = sub[j];
                    sub[j] = temp;
                    i++;
                    j--;
                } else {
                    break;
                }
            }

            // Proper place for pivot is j
            sub[low] = sub[j];
            sub[j] = pivot;
            return j;
        }
    }
}
