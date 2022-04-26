#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol758;

/*
words = ["ab", "bc"] and S = "aabcd", we should return "a<b>abc</b>d"
*/

tuple<vector<string>, string, string>
testFixture1()
{
  auto words = vector<string>{"ab", "bc"};
  auto bold = "a<b>abc</b>d";
  return make_tuple(words, "aabcd", bold);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see " << get<2>(f) << endl;
  Solution sol;
  cout << sol.makeBold(get<0>(f), get<1>(f)) << endl;
}

main()
{
  test1();

  return 0;
}