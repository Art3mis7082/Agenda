#include <stdio.h>
// incluir aquí este encabezado tiene una razón de ser (que no tiene nada que ver con el curso,
// sino con el concepto de "interfaces" y "abstracciones").

#include "Class.h"


DummyClass* DummyClass_New() {
   DummyClass* d = malloc( sizeof( DummyClass ) );
   if( d )
   {
      d->some_var = 0;
   }

   return d;
}

void DummyClass_Delete( DummyClass** d ) {
   free( *d );
   *d = NULL;
}

void DummyClass_Print( DummyClass* d ) {
   printf( "some_var = %d\n", d->some_var );
}

void DummyClass_Set( DummyClass* d, int new_val ) {
   d->some_var = new_val;
}

int DummyClass_Get( DummyClass* d ) {
   return d->some_var;
}