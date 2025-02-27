/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

//
// I - a nestedlist which is a vector of NestedIntegers
// O - needs to be a flatted list in vector form
// C - length must at least be 1, values can be both positive and negative
// E - even if the length is 1 of the outer lists it could have n number of
// nested lists

// Keys:
// Steps:

class NestedIterator {
private:
  vector<int> flattenedList;
  int index;

  // this works by iterating through each of the indexes in
  void flatten(const vector<NestedInteger> &nestedList) {
    for (const auto &ni : nestedList) {
      if (ni.isInteger()) {
        flattenedList.push_back(
            ni.getInteger()); // ensures that the only contains just a val and
                              // then appeneds it to the flattenedList
      } else {
        flatten(ni.getList()); // recursively returns the flattened sublist and
                               // then adds it to the private flattenedList
      }
    }
  }

public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    flatten(nestedList);
    index = 0;
  }

  int next() {
    // grab the next integer in the list
    // return the next integer
    return flattenedList[index++];
  }

  bool hasNext() {
    // returns true if there are still some integers in the nested list and
    // false otherwise
    return index <
           flattenedList.size(); // checking that the flattenedList.size() is
                                 // greated than the index
  }
};
