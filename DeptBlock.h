#include <vector>
#include <string>

using namespace std;

#ifndef _DEPTBLOCK_H
#define _DEPTBLOCK_H

#define BLOCK_SIZE  4096

typedef struct department {
  int did;
  char dname[40]
  double budget;
  int managerid;

} department;

class DeptBlock {

     public:
             vector<department *> departments;
             DeptBlock* overflow;

             DeptBlock();
             ~DeptBlock();
             bool contains(int manId)
             void add(department*);
};

#endif
