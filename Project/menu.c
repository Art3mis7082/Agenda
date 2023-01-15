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


#define MAX_CHAR 50
#define MAX_NUM 20
#define MAX_DAY 31

//------------------------------------------
// Submenús
//------------------------------------------

// funciones privadas, estas NO requieren
// prototipos (están marcadas como "static", que en C significan privadas al módulo).

static int suboption1( void* params ) {
   Agenda* object = (Agenda*) params;

   printf( "Soy la subopción de calendario \n" );
   
   Print_Agenda( params );

   return 1;
}

// esta función no utiliza los parámetros
static int suboption2( void* params ) {

   Contacto* n_c;

   printf( "Soy la subopción de crear contactos\n" );

   printf( "Introduce el nombre del contacto: ");
   scanf( " %ld ", c_n->contact_name);
   printf( "Introduce su número de teléfono ");
   scanf( " %ld ", c_n->phone_number);

   Agenda_add_contact( nombre, numero );

   return 2;
   // no es a fuerza el valor 2, cualquier otro que te convenga está bien, pero ten cuidado con el cero,
   // incluso puedes usar valores negativos.
}

static int suboption3( void* params ) {

   Agenda* object = (Agenda*) params;

   char nombre[MAX_CHAR];
   
   printf( "Soy la subopción de buscar contactos\n" );

   printf( "Introduce el nombre del contacto: ");
   scanf( " %ld ", nombre);

   Agenda_Find_contacto( params , nombre );

   return 2;
   
}

static int suboption4( void* params ) {
   Agenda* object = (Agenda*) params;

   Evteno* n_e;

   printf( "Soy la subopción de crear eventos\n" );

   printf( "Introduce el nombre del evento: ");
   scanf( " %ld ", n_e->nombre);
   printf( "Introduce el dia ");
   scanf( " %ld ", n_e->f.dia);
   printf( "Introduce el numero de mes ");
   scanf( " %ld ", n_e->f.mes);
   printf( "Introduce el año ");
   scanf( " %ld ", n_e->f.anio);

   Agenda_add_date()

   return 3;
}

static int suboption5( void* params ) {

   Agenda* object = (Agenda*) params;

   char nombre[MAX_CHAR];
   
   printf( "Soy la subopción de buscar evento\n" );

   printf( "Introduce el nombre del evento: ");
   scanf( " %ld ", nombre);

   Agenda_Find_Event( params , nombre );

   return 2;
   
}

static int suboption6( void* params ) {
   printf( "Esta opción no está disponible :c regrese en el siguiente parche\n" );

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
      { "Eliminar contacto", suboption6, (void*)obj },
      { "Buscar contacto", suboption3, (void*)obj },
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
      { "Crear evento", suboption5, (void*)obj },
      { "Eliminar evento", suboption6, (void*)obj },
      { "Ver eventos", suboption3, (void*)obj },
      { "Acomodar eventos", suboption3, (void*)obj },

   };

   Menu* menu = Menu_New( submenu_event_entries, SUBMENU3_OPTIONS, "¿Qué deseas hacer?" );
   int ret_val = Menu_Run( menu );
   Menu_Delete( &menu );

   return ret_val;
}
