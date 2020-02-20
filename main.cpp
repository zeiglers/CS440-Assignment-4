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

int readDept(DeptStruct* depts[]);
void freeDepts(DeptStruct* depts[], int size);
int readEmp(EmpStruct* emps[]);
void freeEmps(EmpStruct* emps[], int size);
void writeDeptMan(DeptStruct *dept, EmpStruct *emp);
/*For Debug*/void printDept(DeptStruct *dept);
/*For Debug*/void printEmp(EmpStruct *emp);

int main(int argc, char* argv[]) {
   DeptStruct* depts = NULL;
   EmpStruct* emps = NULL;
   depts = new DeptStruct[5];
   emps = new EmpStruct[5];
   int numDepts;
   numDepts = readDept(&depts);
   int numEmps = readEmp(&emps);
cout << "num depts: " << numDepts << endl;
cout << numEmps << endl;
//cout << "Read files\n";
//   /*For Debug*/printDept(depts[0]);

//   /*For Debug*/printEmp(emps[0]);

   //Free all allocated memory
   freeDepts(&depts, numDepts);
   freeEmps(&emps, numEmps);
   return 0;
}

int readDept(DeptStruct* depts[]){
//cout << "Read Depts\n";
   ifstream file;
   file.open("Dept.csv");

//   *depts = new DeptStruct[5];
   int size = 5;
   int i = 0;
   if (file.is_open()){
cout << "File open\n";
      string line;
      while(getline(file,line)){
cout << "While: " << i << endl;
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

         if(i >= size){
            size += size;
            DeptStruct* temp = new DeptStruct[size];
           
            for(int j = 0; j < i; j++){
                  temp[j] = *depts[j];
            }
//cout << "Finished for loop\n";
            free(*depts);
            *depts = temp;
         }

         depts[i] = dept;
         i++;
      }
   }
   file.close();
cout << i << " is I\n";
   return i;
}

void freeDepts(DeptStruct* depts[], int size){
cout << "Free Depts\n";
   for(int i = 0; i < size; i++){
      if(depts[i] != NULL)
         free(depts[i]);
         depts[i] = NULL;
   }
}

int readEmp(EmpStruct* emps[]){

   ifstream file;
   file.open("Emp.csv");

//   *emps = new EmpStruct[5];
   int size = 5;
   int i = 0;
   if (file.is_open()){
      string line;
      while(getline(file,line)){
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

         if(i >= size){
            size += size;
            EmpStruct* temp = new EmpStruct[size];
            for(int j = 0; j < i; j++){
               temp[j] = *emps[j];
            }
            free(*emps);
            *emps = temp;
         }

         emps[i] = emp;
         i++;
      }
   }
   file.close();
   return i;
}

void freeEmps(EmpStruct* emps[], int size){
cout << "Free Emps\n";
   for(int i = 0; i < size; i++){
      if(emps[i] != NULL)
         free(emps[i]);
         emps[i] = NULL;
cout << i << endl;
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
