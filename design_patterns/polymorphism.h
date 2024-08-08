#ifndef ANIMAL_H
#define ANIMAL_H


struct animal_vtable
{
  const char *(*sound) (void);	//function pointers return type *(name)(parameter)
};

typedef struct
{
  const struct animal_vtable vtable_;
  const char *name;
} Animal;

#endif
