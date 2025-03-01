class Solution {
public:
  bool isHappy(int n) {
    unordered_set<int> seen;

    while (n != 1 && seen.find(n) == seen.end()) {
      seen.insert(n);
      int currentSum = 0;

      while (n > 0) {
        int digit = n % 10;          // Extract last digit
        currentSum += digit * digit; // Square and add
        n /= 10;                     // Remove last digit
      }

      n = currentSum; // Update n
    }

    return n == 1;
  }
};