#include"polymorphism.h"
#include<stdio.h>

static const char *sound(void) {
  return "awaw";
};

static const Animal dog = {
    { sound },
    "Dog"
};

static const char *sound2(void) {
  return "meow";
};

static const Animal cat = {
  { sound2 },
  "Cat"
};

int main() {
  const char* dog_sound = dog.vtable_.sound();
  const char* cat_sound = cat.vtable_.sound();

  printf("dog sound -> %s\n", dog_sound);
  printf("cat sound -> %s\n", cat_sound);
}



