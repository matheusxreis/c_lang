


struct mutant_vtable {
 const char* (*attack)(void);  
 const char* (*defense)(void);
};

struct Mutant {
  const struct mutant_vtable vtable_;
  int level;  
};

const typedef struct {
  const struct Mutant* base;
  const char* (*read_mind)(struct Mutant* target);
} Telepathic;


const typedef struct {
  const struct Mutant* base;
  const char* (*regenerate)();
} LongLived;
