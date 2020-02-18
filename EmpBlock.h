#include <vector>
#include <string>

using namespace std;

#ifndef _EMPBLOCK_H
#define _EMPBLOCK_H

#define BLOCK_SIZE  4096

typedef struct employee {
  int eid;
  char ename[40]
  int age;
  double salary;

} employee;

class EmpBlock {

     public:
             vector<employee *> employees;
             EmpBlock* overflow;

             EmpBlock();
             ~EmpBlock();
             bool contains(int id)
             void add(employee*);
};

#endif
