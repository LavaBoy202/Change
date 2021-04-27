#include "coins.h"
#include <assert.h>

/////////////////////////////////////////////////////////////////////////////
// do not modify these constants:
const int COINS_MAX_TARGET = 4095;
const int COINS_FAIL = -1;
/////////////////////////////////////////////////////////////////////////////

// make_change(coins, len, target, qty) is passed len coin denominations
//   and determines how to produce the target amount using those coins
// notes: return value is the number of coins in solution or
//          COINS_FAIL if make_change could not find an answer
//        qty[i] is the number of coins[i] in the solution or 0 if COINS_FAIL
//        if a solution exists, the return value is the sum of qty elements
//        if the target is zero, the return value is zero
// requires: coins, qty are valid arrays with length >= len [not asserted]
//           coins are all unique positive values [not asserted]
//           coins is sorted in ascending order [not asserted]
//           0 <= target <= COINS_MAX_TARGET
//           0 < len
// effects: modifies qty (overwrites qty)
// time: O(n)
int make_change(const int coins[], int len, int target, int qty[]) {
  assert (len >0);
  assert ((0 <= target) && (target <= COINS_MAX_TARGET));
  int count_coins = 0;
  for (int i = len - 1; i >= 0; i--) {
    if (target >= coins[i]) {
      qty[i] = (target / coins[i]);
      count_coins += qty[i];
      target -= qty[i] * coins[i];
    }
  }
  if (target != 0) {
    return COINS_FAIL;
  }
  return count_coins;
}
