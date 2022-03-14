#include "stats.h"
#include <cassert>
#include <vector>
#include <cmath>
#include "p1_library.h"
using namespace std;

vector<vector<double> > summarize(vector<double> v) {
  assert(!v.empty());
  double count = 0;
  vector<vector<double> > summary;
  vector<double> values, freq, temp;
  for (unsigned int i = 0; i < v.size(); i++)
  {
    for (unsigned int j = 0; j < values.size(); j++)
    {
      if (v.at(i) == values.at(j))
      {
        count++;
      }
    }
    if(count == 0)
    {
      values.push_back(v.at(i));
    }
    count = 0;
  }

  for(unsigned int i = 0; i < values.size(); i++)
  {
    for (unsigned int j = 0; j < v.size(); j++)
    {
      if(values.at(i) == v.at(j))
      {
        count++;
      }
    }
    freq.push_back(count);
    count = 0;
  }

  for (unsigned int i = 0; i < values.size(); i++)
  {
    temp.push_back(values.at(i));
    temp.push_back(freq.at(i));
    summary.push_back(temp);
    temp.clear();
  }
  return summary;
}

int count(vector<double> v) {
  assert(!v.empty());
  return v.size();
}

double sum(vector<double> v) {
  assert(!v.empty());
  int sum = 0;
  for(unsigned int i = 0; i < v.size(); i++)
  {
    sum += v.at(i);
  }
  return sum;
}

double mean(vector<double> v) {
  assert(!v.empty());
  double sum, count;
  count = v.size();
  for(unsigned int i = 0; i < v.size(); i++)
  {
    sum += v.at(i);
  }
  return sum/count;
}

double median(vector<double> v) {
  assert(!v.empty());
  sort(v);
  int size = v.size();
  if(size % 2 == 0)
  {
    return (v.at(size/2) + v.at(size/2 + 1))/2;
  }
  else 
  {
    return v.at(size/2 + 0.5);
  }
}

double mode(vector<double> v) {
  assert(!v.empty());
  sort(v);
  int count = 0;
  int highestFreq = 0;
  int mode;
  for(unsigned int i = 0; i < v.size(); i++)
  {
    for (unsigned int j = 0; j < v.size(); j++)
    {
      if(v.at(i) == v.at(j))
      {
        count++;
      }
    }
    if(count > highestFreq)
    {
      highestFreq = count;
      mode = i;
    }
    else if (count == highestFreq)
    {
      if(v.at(i) < v.at(mode))
      {
        highestFreq = count;
        mode = i;
      }
    }
    count = 0;
  }
  return v.at(mode);
}

double min(vector<double> v) {
  assert(!v.empty());
  sort(v);
  return v.at(0);
}

double max(vector<double> v) {
  assert(!v.empty());
  sort(v);
  return v.at(v.size()-1);
}

double stdev(vector<double> v) {
  assert(!v.empty());
  double sum;
  double avg = mean(v);
  for(unsigned int i = 0; i < v.size(); i++)
  {
    sum += pow(avg - v.at(i), 2);
  }
  return sqrt(sum/(v.size()-1));
}

double percentile(vector<double> v, double p) {
  assert(!v.empty());
  sort(v);
  double rank, vP;
  double d = 0;
  double k = 0;
  if (p == 100)
  {
    return v.at(v.size()-1);
  }
  
  rank = p/100 * (v.size() - 1) + 1;
  d = modf(rank, &k);
  vP = v.at(k-1) + d * (v.at(k) - v.at(k-1));
  return vP;
}