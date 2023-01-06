#include <stdio.h>

#include <stdio.h>

#include "submenu.h"

// el siguiente par de funciones son privadas, por lo tanto NO requieren
// prototipos (están marcadas como "static", que en C significan privadas al módulo).

static int suboption1( void* params )
{
   DummyClass* dummy_object = (DummyClass*) params;

   printf( "Soy la sub opción 1: %d\n", DummyClass_Get( dummy_object ) );

   return 1;
   // este valor es devuelto a la función llamadora (en este ejemplo, a delete_product()); ten cuidado
   // si regresas un 0 ya que este valor evita llamar de manera recurrente al menú correspondiente.
}

// esta función no utiliza los parámetros
static int suboption2( void* params )
{
   printf( "Soy la sub opción 2\n" );

   return 2;
   // no es a fuerza el valor 2, cualquier otro que te convenga está bien, pero ten cuidado con el cero,
   // incluso puedes usar valores negativos.
}



#define SUBMENU1_OPTIONS 3

// Esta función NO es una operación de algún ADT, es simplemente una función que recibe
// a un objeto tipo DummyClass para utilizarlo:
int submenu1( DummyClass* obj )
{
   MenuEntry submenu1_entries[ SUBMENU1_OPTIONS ] =
   {
      { "Salir", NULL },
      { "Subopción 1", suboption1, (void*)obj },
      { "Subopción 2", suboption2, NULL },
   };

   Menu* menu = Menu_New( submenu1_entries, SUBMENU1_OPTIONS, "SUBMENÚ 1" );

   int ret_val = Menu_Run( menu );

   Menu_Delete( &menu );

   return ret_val;
}