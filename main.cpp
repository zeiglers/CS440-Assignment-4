/* 
 * This is where I will read in relations and sort them
 * until there is 11 sorted lists of each type.
 * Then use fuction to join on proper sort
 */
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

struct DeptStruct {
   int did;
   char dname[40];
   double budget;
   int managerid;
};

struct EmpStruct {
   int eid;
   char ename[40];
   int age;
   double salary;
};

struct DeptMan {
   int did;
   char dname[40];
   double budget;
   int managerid;
   int age;
   double salary;
};

void readDept(DeptStruct *depts[]);
void freeDepts(DeptStruct *depts[]);
void readEmp(EmpStruct *emps[]);
void freeEmps(EmpStruct *emps[]);
void writeDeptMan(DeptStruct *dept, EmpStruct *emp);
/*For Debug*/void printDept(DeptStruct *dept);
/*For Debug*/void printEmp(EmpStruct *emp);

int main(int argc, char* argv[]) {
   DeptStruct* depts[11];
   EmpStruct* emps[11];
   for(int i = 0; i < 11; i++){
      depts[i] = NULL;
      emps[i] = NULL;
   }

   readDept(depts);
   readEmp(emps);
   /*For Debug*/printDept(depts[0]);

   /*For Debug*/printEmp(emps[0]);

   //Free all allocated memory
   freeDepts(depts);
   freeEmps(emps);
   return 0;
}

void readDept(DeptStruct *depts[]){

   ifstream file;
   file.open("Dept.csv");

   if (file.is_open()){
      string line;
      int i = 0;
      while(getline(file,line) && (i < 11)){
         string id, dnam, bud, manid;
         stringstream input(line);

         getline(input, id, ',');
         getline(input, dnam, ',');
         getline(input, bud, ',');
         getline(input, manid, ',');

         DeptStruct *dept = (DeptStruct*)malloc(sizeof(DeptStruct));
         
         stringstream temp(id);
         temp >> dept->did;
         dnam.copy(dept->dname, dnam.size() + 1);
         stringstream temp1(bud);
         temp1 >> dept->budget;
         stringstream temp2(manid);
         temp2 >> dept->managerid;

         depts[i] = dept;
         i++;
      }
   }
   file.close();

}

void freeDepts(DeptStruct *depts[]){
   for(int i = 0; i < 11; i++){
      if(depts[i] != NULL)
         free(depts[i]);
   }
}

void readEmp(EmpStruct *emps[]){

   ifstream file;
   file.open("Emp.csv");

   if (file.is_open()){
      string line;
      int i = 0;
      while(getline(file,line) && (i < 11)){
         string id, enam, ag, sal;
         stringstream input(line);

         getline(input, id, ',');
         getline(input, enam, ',');
         getline(input, ag, ',');
         getline(input, sal, ',');

         EmpStruct *emp = (EmpStruct*)malloc(sizeof(EmpStruct));
         
         stringstream temp(id);
         temp >> emp->eid;
         enam.copy(emp->ename, enam.size() + 1); 
         stringstream temp1(ag);
         temp1 >> emp->age;
         stringstream temp2(sal);
         temp2 >> emp->salary;

         emps[i] = emp;
         i++;
      }
   }
   file.close();

}

void freeEmps(EmpStruct *emps[]){
   for(int i = 0; i < 11; i++){
      if(emps[i] != NULL)
         free(emps[i]);
   }
}

/*For debug*/void printDept(DeptStruct *dept){
   cout << "DID: " << dept->did; 
   cout << " Department Name: " << dept->dname;
   cout << " Budget: " << dept->budget;
   cout << " Manager ID: " << dept->managerid << endl;
}

/*For debug*/void printEmp(EmpStruct *emp){
   cout << "EID: " << emp->eid << " Employee Name: " << emp->ename << " Age: " << emp->age << " Salary: " << emp->salary << endl;
}
