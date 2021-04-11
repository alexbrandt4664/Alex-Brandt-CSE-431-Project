#include <vector>
#include <set>
#include <iostream>
#include <ctime>

using namespace std;

int binaryInsert(vector<int> elems, long insertKey) {
  int lowerBound = 0;
  int length = elems.size();
  int upperBound = length - 1;
  int mid;
  
  while (true) {
    mid = (upperBound + lowerBound) / 2;
    if (length == 0) {
        return mid = 0;
    }
    if (lowerBound == mid) {
        if (elems[mid] > insertKey) {
            return mid;
        }
    }
    if (elems[mid] < insertKey) {
        lowerBound = mid + 1;          // its in the upper 
        if (lowerBound > upperBound) {
            return mid += 1;
        }
    } else if (lowerBound > upperBound) {
        return mid;
    } else {
        upperBound = mid - 1;          // its in the lower   
    }
  }
}

int main() {

  clock_t vecTot; // The total time for the vector to finish inserting the current element
  clock_t multiTot; // The total time for the multiset to finish inserting the current element

  int insertAmount = 10; // The amount to insert on each pass
  do {
    cout << "Insertion Amount: " << insertAmount << endl;

    multiset<int> multi;
    clock_t multiStart = clock(); // The start time for the regular multiset
    for (int i = 0; i < insertAmount; i++) {
      multi.insert(i);
    }
    multiTot = clock() - multiStart;

    vector<int> vec;
    clock_t vecStart = clock(); // Get the start time for unordered multiset
    for (int i = 0; i < insertAmount; i++) {
      int index = binaryInsert(vec, i);
      vec.insert(vec.begin() + index, i);
    }

    vecTot = clock() - vecStart; // Get the time it takes for the unordered multiset to finish inserting on this pass
    
    cout << "Multiset Time: "
          << ((double) multiTot) / (double) CLOCKS_PER_SEC
          << " seconds" << endl;

    cout << "Unordered Multiset Time: "
          << ((double) vecTot) / (double) CLOCKS_PER_SEC
          << " seconds" << endl;

    insertAmount *= 10;
  } while (((double) multiTot) / (double) CLOCKS_PER_SEC <= 3 || ((double) vecTot) / (double) CLOCKS_PER_SEC <= 3);

  return 0;
}
