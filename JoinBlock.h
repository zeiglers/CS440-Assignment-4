#include <vector>
#include <string>

using namespace std;

#ifndef _JOINBLOCK_H
#define _JOINBLOCK_H

#define BLOCK_SIZE  4096

typedef struct deptManager {
  int did, age, managerid;
  char dname[40];
  char ename[40];
  double budget, salary;

} deptManager;

class JoinBlock {

     public:
             vector<deptManager *> deptManagerss;
             JoinBlock* overflow;

             JoinBlock();
             ~JoinBlock();
             bool contains(int manId)
             void add(deptManager*);
};

#endif
