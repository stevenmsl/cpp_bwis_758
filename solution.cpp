#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <set>
#include <cstring>
using namespace sol758;
using namespace std;

/*takeaways
  - scan s from left to right one char at a time
  - compare the substring starting at the position
    i to each word in the words to see how long you
    can extend the substring
  - words = ["ab", "bc"] and S = "aabcd"
   - at position 1, s[1] ('a')
     - we found a match "ab", so we know
       we need to make s[1..2] bold
     - we also record the end position to
       be 3
   - at position 2, s[2] ('b')
     - we found another match "bc", so
       we need to make [2..3] bold
     - we simply extend the end position
       from 3 to 4
   - at position 3, s[3] ('c')
     - we didn't find any match
     - but we know 3 is less than the
       end position we recorded, so
       we need to make it bold
  - this is how we extend the substring
    that needs to be made bold by
    overlapping words if needed
*/

string Solution::makeBold(vector<string> &words, string s)
{
  const int n = s.size();
  auto bold = vector<bool>(n, false);
  auto end = -1;

  for (auto i = 0; i < n; i++)
  {
    for (auto word : words)
      /*find if s[i..word.size()] matches the word
       */
      if (s.substr(i).find(word) == 0)
        /* extend the end if this word is longer */
        end = max(end, i + (int)word.size());
    bold[i] = i < end;
  }

  string result;
  auto i = 0;
  while (i < n)
  {
    if (bold[i])
    {
      auto j = i;
      /* get the whole substring we need to make bold  */
      while (bold[i] && i < n)
        i++;
      result += "<b>" + s.substr(j, i - j) + "</b>";
    }
    else
      result += s[i++];
  }

  return result;
}