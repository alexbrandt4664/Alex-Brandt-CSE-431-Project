#include <set>
#include <unordered_set>
#include <ctime>
#include <iostream>

using namespace std;

int main() {

  clock_t multiTot;
  clock_t uMultiTot;

  int insertAmount = 10; // The amount to insert on each pass
  do {
    cout << "Insertion Amount: " << insertAmount << endl;

    multiset<int> multi;
    clock_t multiStart = clock(); // The start time for the regular multiset
    for (int i = 0; i < insertAmount; i++) {
      multi.insert(i);
    }
    multiTot = clock() - multiStart;

    unordered_multiset<int> uMulti;
    clock_t uMultiStart = clock(); // Get the start time for unordered multiset
    for (int i = 0; i < insertAmount; i++) {
      uMulti.insert(i);
    }

    uMultiTot = clock() - uMultiStart; // Get the time it takes for the unordered multiset to finish inserting on this pass
    
    cout << "Multiset Time: "
          << ((double) multiTot) / (double) CLOCKS_PER_SEC
          << " seconds" << endl;

    cout << "Unordered Multiset Time: "
          << ((double) uMultiTot) / (double) CLOCKS_PER_SEC
          << " seconds" << endl;

    insertAmount *= 10;
  } while (((double) multiTot) / (double) CLOCKS_PER_SEC <= 3 || ((double) uMultiTot) / (double) CLOCKS_PER_SEC <= 3);

  return 0;
}
