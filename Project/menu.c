#include <stdio.h>

#include "menu.h"
#include "agenda.h"

static void print_menu_title( Menu* menu ) {
   size_t len = strlen( menu->title );

   printf( "\n" );

   for( size_t i = 0; i < len + 2; ++i ) {
      printf( "=" );
   }

   printf( "\n %s\n", menu->title );

   for( size_t i = 0; i < len + 2; ++i ) {
      printf( "=" );
   }

   printf( "\n" );
}


Menu* Menu_New( MenuEntry* options, size_t num_options, char* title ) {
   Menu* m = malloc( sizeof( Menu ) );
   if( m ) {
      m->options = options;
      m->num_options = num_options;
      m->title = title;
   }

   return m;
}


void Menu_Delete( Menu** menu ) {
   assert( menu );
   assert( *menu );

   free( *menu );
   *menu = NULL;
}
 

int Menu_Run( Menu* menu ) {
   assert( menu );

   while( 1 ) {
      int option = Menu_Show( menu );

      if( option == 0 || menu->options[ option ].action == NULL ) {
         return 0;
      }
      else {
         return menu->options[ option ].action( menu->options[ option ].params );
      }

   }
}


void Menu_Set( Menu* menu, MenuEntry* options, size_t num_options, char* title ) {
   menu->options = options;
   menu->num_options = num_options;
   menu->title = title;
}

int Menu_Show( Menu* menu ) {
   size_t option = 0;

   while( 1 ) {
      print_menu_title( menu );

      for( size_t i = 0; i < menu->num_options; ++i )
      {
         printf( "%ld) %s\n", i, menu->options[ i ].text );
      }

      //Prompt para recibir la elección
      printf( "\n=? " );
      scanf( "%ld", &option ); 

      if( 0 <= option && option < menu->num_options ) {
         return option;
      }

      printf( "Opción no válida\n" );
   }
}

void Menu_Set_Title( Menu* menu, char* title ) {
   menu->title = title;
}



//------------------------------------------
// Submenús
//------------------------------------------

// el siguiente par de funciones son privadas, por lo tanto NO requieren
// prototipos (están marcadas como "static", que en C significan privadas al módulo).

static int suboption1( void* params ) {
   Agenda* object = (Agenda*) params;

   printf( "Soy la subopción de calendario \n" );
   Print_Agenda( Agenda* object );

   return 1;
}

// esta función no utiliza los parámetros
static int suboption2( void* params ) {
   printf( "Soy la subopción de contactos\n" );

   return 2;
   // no es a fuerza el valor 2, cualquier otro que te convenga está bien, pero ten cuidado con el cero,
   // incluso puedes usar valores negativos.
}

static int suboption3( void* params ) {
   printf( "Soy la subopción de eventos\n" );

   return 3;
}


#define SUBMENU1_OPTIONS 13
#define SUBMENU2_OPTIONS 4
#define SUBMENU3_OPTIONS 5

// Esta función NO es una operación de algún ADT, es simplemente una función que recibe
// a un objeto tipo DummyClass para utilizarlo:

//------------------------------------------
// Ver calendario
//------------------------------------------
int submenu_calendar ( DummyClass* obj ) {
   MenuEntry submenu_calendar_entries[ SUBMENU1_OPTIONS ] =
   {
      { "Salir", NULL },
      { "Enero", suboption1, (void*)obj },
      { "Febrero", suboption1, (void*)obj },
      { "Marzo", suboption1, (void*)obj },
      { "Abril", suboption1, (void*)obj },
      { "Mayo", suboption1, (void*)obj },
      { "Junio", suboption1, (void*)obj },
      { "Julio", suboption1, (void*)obj },
      { "Agosto", suboption1, (void*)obj },
      { "Septiembre", suboption1, (void*)obj },
      { "Octubre", suboption1, (void*)obj },
      { "Noviembre", suboption1, (void*)obj },
      { "Diciembre", suboption1, (void*)obj },
   };

   Menu* menu = Menu_New( submenu_calendar_entries, SUBMENU1_OPTIONS, "Elige el mes" );
   int ret_val = Menu_Run( menu );
   Menu_Delete( &menu );

   return ret_val;
}


//------------------------------------------
// Insertar, eliminar y contacto
//------------------------------------------

int submenu_contact( DummyClass* obj ) {
   MenuEntry submenu_contact_entries[ SUBMENU2_OPTIONS ] =
   {
      { "Salir", NULL },
      { "Crear contacto", suboption2, (void*)obj },
      { "Eliminar contacto", suboption2, (void*)obj },
      { "Ver contactos", suboption2, (void*)obj },
   };

   Menu* menu = Menu_New( submenu_contact_entries, SUBMENU2_OPTIONS, "¿Qué deseas hacer?" );
   int ret_val = Menu_Run( menu );
   Menu_Delete( &menu );

   return ret_val;
}


//------------------------------------------
// Insertar, eliminar y ver un evento
//------------------------------------------

int submenu_event( DummyClass* obj ) {
   MenuEntry submenu_event_entries[ SUBMENU3_OPTIONS ] =
   {
      { "Salir", NULL },
      { "Crear evento", suboption3, (void*)obj },
      { "Eliminar evento", suboption3, (void*)obj },
      { "Ver eventos", suboption3, (void*)obj },
      { "Acomodar eventos", suboption3, (void*)obj },

   };

   Menu* menu = Menu_New( submenu_event_entries, SUBMENU3_OPTIONS, "¿Qué deseas hacer?" );
   int ret_val = Menu_Run( menu );
   Menu_Delete( &menu );

   return ret_val;
}