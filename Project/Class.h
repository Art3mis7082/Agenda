#ifndef  CLASS_INC
#define  CLASS_INC

#include <stdlib.h>

typedef struct {
   int some_var;
} DummyClass;

DummyClass* DummyClass_New();
void DummyClass_Delete( DummyClass** d );
void DummyClass_Print( DummyClass* d );
void DummyClass_Set( DummyClass* d, int new_val );
int DummyClass_Get( DummyClass* d );

#endif   /* ----- #ifndef DUMMYCLASS_INC  ----- */