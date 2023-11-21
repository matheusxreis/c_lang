#include"stack.c"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_SPACE 6 

struct Car {
  char* plate;
  int move_times;
};
typedef struct Stack Parking;  

void in(Parking* parking, struct Car* car){

  if(parking->top >= MAX_SPACE - 1) {
    printf("Parking is full\n");
    return;
  };
  car->move_times = 0;

  printf("Car with plate %s is entering...\n", car->plate);
  push(parking, car);
};

struct Car out(Parking* parking, char* plate){

  struct Stack s = create();
  struct Car r;

  while(!empty(parking) 
      && (strcmp(plate, (*(struct Car*)stacktop(parking)).plate)!=0) ) {
     push(&s, pop(parking));
  }

  if(!empty(parking)){
    r = *(struct Car*)pop(parking);
  }else {
    printf("Car not found\n");
    exit(1);
  }

  while(!empty(&s)) {
      (*(struct Car*)stacktop(&s)).move_times++;
      push(parking, pop(&s));
  };

  printf("Car with plate %s is moving out... this car has been moved %d times\n",r.plate, r.move_times);
  
  return r;
};

int main() {

 struct Car c1, c2, c3, c4, c5, c6;
 c1.plate = "CAR1";
 c2.plate = "CAR2";
 c3.plate = "CAR3";
 c4.plate = "CAR4";
 c5.plate = "CAR5";
 c6.plate = "CAR6";



 Parking parking = create();

 in(&parking, &c1);
 in(&parking, &c2);
 in(&parking, &c3);
 in(&parking, &c4);
 in(&parking, &c5);
 in(&parking, &c6);

 out(&parking, "CAR2"); // move: 0
 out(&parking, "CAR3"); // move: 1
 out(&parking, "CAR4"); // move: 2
 out(&parking, "CAR1"); // move: 0
 out(&parking, "CAR6"); // move: 4
 out(&parking, "CAR5"); // move: 4
 
 return 1;

}
