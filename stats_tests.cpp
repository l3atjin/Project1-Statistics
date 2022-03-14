/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 * Project UID 5366c7e2b77742d5b2142097e51561a5
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.h"
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

void test_sum_small_data_set();

// Add prototypes for you test functions here.
void test_sum_small_data_set()
{
  cout << "test_sum_small_data_set" << endl;

  vector<double> data;
  data.push_back(10);
  data.push_back(11);
  data.push_back(12);

  assert(sum(data) == 33);

  cout << "PASS!" << endl;
}

// Add the test function implementations here.

void test_summary_small_data_set()
{
  cout << "test_summary_small_data_set" << endl;

  vector<double> data;
  vector<vector<double> > testSummary;

  data.push_back(6);
  data.push_back(11);
  data.push_back(6);
  data.push_back(2);
  data.push_back(5);
  data.push_back(2);
  data.push_back(8);
  data.push_back(11);
  data.push_back(11);

  testSummary.push_back({6, 2});
  testSummary.push_back({11, 3});
  testSummary.push_back({2, 2});
  testSummary.push_back({5, 1});
  testSummary.push_back({8, 1});

  assert(summarize(data) == testSummary);

  cout << "PASS!" << endl;
}

void test_count_small_data_set()
{
  cout << "test_count_small_data_set" << endl;

  vector<double> data;
  data.push_back(10);
  data.push_back(11);
  data.push_back(12);

  assert(count(data) == 3);

  cout << "PASS!" << endl;
}

void test_mean_small_data_set()
{
  cout << "test_mean_small_data_set" << endl;

  vector<double> data;
  data.push_back(6);
  data.push_back(11);
  data.push_back(6);
  data.push_back(2);
  data.push_back(5);
  data.push_back(2);
  data.push_back(8);
  data.push_back(11);
  data.push_back(11);

  assert(mean(data) == sum(data)/data.size());

  cout << "PASS!" << endl;
}

void test_median_small_data_set()
{
  cout << "test_median_small_data_set" << endl;

  vector<double> data;
  data.push_back(6);
  data.push_back(11);
  data.push_back(6);
  data.push_back(2);
  data.push_back(5);
  data.push_back(2);
  data.push_back(8);
  data.push_back(11);
  data.push_back(11);

  assert(median(data) == 6);

  cout << "PASS!" << endl;
}

void test_mode_small_data_set()
{
  cout << "test_mode_small_data_set" << endl;

  vector<double> data;
  data.push_back(6);
  data.push_back(11);
  data.push_back(6);
  data.push_back(2);
  data.push_back(5);
  data.push_back(2);
  data.push_back(8);
  data.push_back(11);
  data.push_back(11);

  assert(mode(data) == 11);

  cout << "PASS!" << endl;
}

void test_min_small_data_set()
{
  cout << "test_min_small_data_set" << endl;

  vector<double> data;
  data.push_back(6);
  data.push_back(11);
  data.push_back(6);
  data.push_back(2);
  data.push_back(5);
  data.push_back(2);
  data.push_back(8);
  data.push_back(11);
  data.push_back(11);

  assert(min(data) == 2);

  cout << "PASS!" << endl;
}

void test_max_small_data_set()
{
  cout << "test_max_small_data_set" << endl;

  vector<double> data;
  data.push_back(6);
  data.push_back(11);
  data.push_back(6);
  data.push_back(2);
  data.push_back(5);
  data.push_back(2);
  data.push_back(8);
  data.push_back(11);
  data.push_back(11);

  assert(max(data) == 11);

  cout << "PASS!" << endl;
}

void test_percentile_small_data_set()
{
  cout << "test_percentile_small_data_set" << endl;

  vector<double> data;
  data.push_back(15);
  data.push_back(20);
  data.push_back(35);
  data.push_back(40);
  data.push_back(50);

  assert(percentile(data, 100) == 50);

  cout << "PASS!" << endl;
}

void test_stdev_small_data_set()
{
  cout << "test_stdev_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
  data.push_back(4);
  data.push_back(4);
  data.push_back(5);
  data.push_back(6);
  data.push_back(7);

  assert(stdev(data) == 2);

  cout << "PASS!" << endl;
}

int main()
{
  // Call your test functions here
  test_sum_small_data_set();
  test_summary_small_data_set();
  test_count_small_data_set();
  test_mode_small_data_set();
  test_median_small_data_set();
  test_min_small_data_set();
  test_max_small_data_set();
  test_mean_small_data_set();
  test_percentile_small_data_set();
  test_stdev_small_data_set();

  return 0;
}

