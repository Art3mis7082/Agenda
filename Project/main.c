#include <stdio.h>

#include "menu.h"
#include "agenda.h"

#include "contactos.h"
#include "fechas.h"
#include "contactos.h"

//#include "Agenda.h"

//------------------------------------------
// Imprimir calendario de un solo mes
//------------------------------------------

int print_calendar( void* params ) {
    DummyClass* dummy_object = (DummyClass*) params;

    printf( "print_calendar()\n" );

    // llama a un submenú:
    int salir = 0;
    do {
        salir = submenu_calendar( dummy_object );
    } while( salir != 0 );

    int cont = DummyClass_Get( dummy_object );
    ++cont;
    DummyClass_Set( dummy_object, cont );

    return 1;
    // puedes devolver lo que sea más conveniente a tu aplicación
}

//------------------------------------------
// Para eventos
//------------------------------------------

int option_dates( void* params ) {
    DummyClass* dummy_object = (DummyClass*) params;

    printf( "option_dates(): %d\n", DummyClass_Get( dummy_object ) );

    // llama a un submenú:
    int salir = 0;
    do {
        salir = submenu_event( dummy_object );
    } while( salir != 0 );

    int cont = DummyClass_Get( dummy_object );
    ++cont;
    DummyClass_Set( dummy_object, cont );

    return 2;
}


//------------------------------------------
// Para contactos
//------------------------------------------

int option_contacts( void* params ) {
    DummyClass* dummy_object = (DummyClass*) params;

    printf( "option_date(): %d\n", DummyClass_Get( dummy_object ) );

    // llama a un submenú:
    int salir = 0;
    do {
        salir = submenu_contact( dummy_object );
    } while( salir != 0 );

    int cont = DummyClass_Get( dummy_object );
    ++cont;
    DummyClass_Set( dummy_object, cont );

    return 3;
}


#define MAIN_MENU_OPTIONS 4

int main_menu( DummyClass* obj ) {
    /*
    * print_stock, insert_product y delete_product NO son objetos, son funciones 
    * que a su vez llamarían a las funciones del tipo abstracto (clase) correspondiente.
    */
    MenuEntry main_menu_entries[ MAIN_MENU_OPTIONS ] =
    {
        { "Salir", NULL },      // la primer opción siempre es Salir/NULL

        { 
            "Ver el calendario", // Texto para mostrar
            print_calendar,         // Callback (función que realiza el trabajo). Siempre debe ser int f(void*)
            (void*)obj           // le pasamos al objeto |obj| del tipo DummyClass
        },

        { "Eventos", option_dates, (void*)obj },
        { "Contactos", option_contacts, (void*)obj }
   
    };

    Menu* menu = Menu_New( main_menu_entries, MAIN_MENU_OPTIONS, "Agenda" );

    int ret_val = Menu_Run( menu );

    Menu_Delete( &menu );

    return ret_val;
    // puedes devolver lo que sea más conveniente a tu aplicación
}


int main() {
    DummyClass* an_object = DummyClass_New();
    // creamos al objeto principal de la aplicación

    do{;}while( main_menu( an_object ) != 0 );
    // inicia el procesamiento de los menús y le pasamos al objeto principal

    DummyClass_Delete( &an_object );
}
