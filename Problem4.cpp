#include <vector>
#include <set>
#include <iostream>
#include <ctime>

using namespace std;

int binarySearch(vector<int> data, int value) {
  int index = 0;
  int left = 0, right = data.size();

  while (data[left] < value && data[right] >= value) {
    int m = left + (right - left) / 2;

    if (data[m] == value) {
      index = m;
      break;
    }

    if (data[m] < value) {
      right = m - 1;
    }
  }

  return index;
}

int main() {

  clock_t vecTot; // The total time for the vector to finish inserting the current element
  clock_t multTot; // The total time for the multiset to finish inserting the current element


  return 0;
}
