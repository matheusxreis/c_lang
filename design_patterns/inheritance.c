 /*
  * C is a procedural language,
  * so some design patterns simplest 
  * that some oop languages owns,
  * needs being implemented
  *
  * type punning
  */

#include<stdio.h>
#include"inheritance.h"

static const char *
attack (void)
{
  return "Attacking";
};

static const char *
defense (void)
{
  return "Defensing";
};

const char *
read_mind (struct Mutant target)
{
  return "Reading mind....";
};

const char *
regenerate ()
{
  return "Regenerating....";
}

static const struct Mutant mutant[] = {
  attack,
  defense,
  3
};

static const Telepathic professorX = {
  mutant,
  read_mind
};

static const LongLived wolverine = {
  mutant,
  regenerate
};

int
main ()
{

  const int professorLevel = professorX.base->level;
  const int wolverineLevel = wolverine.base->level;

  const char *professorAttack = professorX.base->vtable_.attack ();
  const char *wolverineDefense = wolverine.base->vtable_.defense ();

  const char *readingMind = professorX.read_mind (&wolverine.base);
  const char *regenerating = wolverine.regenerate ();

  printf ("prof level -> %d, wolv level -> %d\n", professorLevel,
	  wolverineLevel);
  printf ("prof attack -> %s, wolv defense -> %s\n", professorAttack,
	  wolverineDefense);
  printf ("reading mind -> %s\n", readingMind);
  printf ("regenerating -> %s\n", regenerating);

};
