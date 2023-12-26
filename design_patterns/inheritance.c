 /*
  * C is a procedural language,
  * so some design patterns simplest 
  * that some oop languages owns,
  * needs being implemented
  *
  * type punning
  */

#include<stdio.h>

struct Person {
 int age;
 char* name;
};

struct Developer {
  struct Person base;
  char* area;
  char* languagesUsed[10];
  char* seniority;
};

struct Developer buildJrCLangDeveloper(char* name, int age) {
    
    struct Person p;
    p.name = name;
    p.age = age;

    struct Developer d;
    d.base = p;
    d.area = "system";
    d.languagesUsed[0] = "c language";
    d.seniority = "jr";
   
    return d;
};

void printDeveloper(struct Developer d) {
  printf("Developer %s, with age %d\n",d.base.name, d.base.age);
  printf("His/her area is %s, with seniority %s and dominate %s\n", d.area, d.seniority, d.languagesUsed[0]);
}

int main(){
  
  struct Developer dev = buildJrCLangDeveloper("Matheus", 22);
  printDeveloper(dev);

}
