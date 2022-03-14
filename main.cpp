//main.cpp
//#include "stats.h"
#include "p1_library.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <limits>
#include "stats.h"
using namespace std;

int main() {
  string filename;
  string header;

  cout << "enter a filename" << endl;
  cin >> filename;
  cout << "enter a column name" << endl;
  cin >> header;
  cout << "reading column " << header << " from " << filename << endl;

  vector<double> data = extract_column(filename, header);
  vector<vector<double> > summary = summarize(data);

  /*for (unsigned int i = 0; i < data.size(); i++)
  {
    cout << data.at(i) << endl;
  }*/
  
  cout << "Summary (value: frequency)" << endl;
  for (unsigned int i = 0; i < data.size(); i++)
  {
    cout << summary.at(i).at(0) << ": " << summary.at(i).at(1) << endl;
  }
  cout << "count = " << count(data) << endl;
  cout << "sum = " << sum(data) << endl;
  cout << "mean = " << mean(data) << endl;
  cout << "stdev = " << stdev(data) << endl;
  cout << "median = " << median(data) << endl;
  cout << "mode = " << mode(data) << endl;
  cout << "min = " << min(data) << endl;
  cout << "max = " << max(data) << endl;

  cout << "  0th percentile = " << percentile(data, 0) << endl;
  cout << " 25th percentile = " << percentile(data, 25) << endl;
  cout << " 50th percentile = " << percentile(data, 50) << endl;
  cout << " 75th percentile = " << percentile(data, 75) << endl;
  cout << "100th percentile = " << percentile(data, 100) << endl;
}