#include <stdio.h>

#include "menu.h"
#include "Class.h"

#include "submenu.h"
// la opción delete_product manda llamar a este submenu

#include "Agenda.h"

int print_calendar( void* params ) {
    DummyClass* dummy_object = (DummyClass*) params;

    printf( "print_stock()\n" );
    DummyClass_Print( dummy_object );


    return 1;
    // puedes devolver lo que sea más conveniente a tu aplicación
}

int insert_date( void* params ) {
    DummyClass* dummy_object = (DummyClass*) params;

    printf( "insert_date(): %d\n", DummyClass_Get( dummy_object ) );

    // llama a un submenú:
    int salir = 0;
    do {
        salir = submenu1( dummy_object );
    } while( salir != 0 );

    int cont = DummyClass_Get( dummy_object );
    ++cont;
    DummyClass_Set( dummy_object, cont );

    return 2;
}

int delete_date( void* params ) {
    DummyClass* dummy_object = (DummyClass*) params;

    printf( "delete_date(): %d\n", DummyClass_Get( dummy_object ) );

    // llama a un submenú:
    int salir = 0;
    do {
        salir = submenu1( dummy_object );
    } while( salir != 0 );

    return 3;
}

print_pendings( void* params ) {
    DummyClass* dummy_object = (DummyClass*) params;

    printf( "print_pendings(): %d\n", DummyClass_Get( dummy_object ) );

    // llama a un submenú:
    int salir = 0;
    do {
        salir = submenu1( dummy_object );
    } while( salir != 0 );

    return 4;

}


#define MAIN_MENU_OPTIONS 5

int main_menu( DummyClass* obj ) {
    /*
    * Observa que print_stock, insert_product y delete_product NO son objetos, son funciones 
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

        { "Insertar un pendiente nuevo", insert_date, (void*)obj },
        { "Eliminar un pendiente", delete_date, (void*)obj },
        { "Ver pendientes", print_pendings, (void*)obj }
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
