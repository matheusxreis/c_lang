
#include <stdio.h>

typedef struct {
   char first_name[20];
   char last_name[20];
   float points;
 } STUDENT;

 typedef struct {
   char first_name[20];
   char last_name[20];
   float salary;
 } EMPLOYEE;



void exec(EMPLOYEE* employees, STUDENT* student, int size) {
  for(int i = 0; i<size; i++){ 
    if(student[i].points>3.0){
      employees[i].salary += employees[i].salary * 0.10;
    }
  }
};

int main() {

  
  EMPLOYEE e;
  char name[] = "Emilye";
  char last_name[] = "Motta";

  for(int i = 0; i<6; i++){ 
    e.first_name[i] = name[i];
  };
  for(int i = 0; i<5; i++){
    e.last_name[i] = last_name[i];
  };
  e.salary = 3000;

  STUDENT s;
 
  for(int i = 0; i<6; i++){ 
    s.first_name[i] = name[i];
  };
  for(int i = 0; i<5; i++){
    s.last_name[i] = last_name[i];
  }; 
  s.points = 3.1;
  
  EMPLOYEE employees[] = {e};
  STUDENT studentes[] = {s};

  printf("%s %s => r$%f\n", employees[0].first_name, employees[0].last_name, employees[0].salary);
  exec(employees, studentes, sizeof(employees)/sizeof(employees[0]));
  printf("%s %s => r$%f\n", employees[0].first_name, employees[0].last_name, employees[0].salary);

  return 1;
}
