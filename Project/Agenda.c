#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#define MAX_EVENT 25
#define MAX_CONTACTS 1000

#include "fechas.h"
#include "contactos.h"
#include "agenda.h"


DummyClass* DummyClass_New() {
   DummyClass* d = malloc( sizeof( DummyClass ) );
   if( d ) {
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

//----------------------------------------------------------------------
//  Operaciones AGENDA
//----------------------------------------------------------------------

Agenda* Agenda_new() {      
   Agenda* lista = ( Agenda* ) malloc( sizeof( Agenda ) );
   if( lista != NULL ) {
      lista->list_eventos= DLL_New();
      lista->list_contactos = SLL_New();
   } 
      return lista;

}

void Agenda_Delete( Agenda** this ){
   assert( *this );
   fprintf(stderr,"Delete():Borrando Agenda\n");
   Agenda_Make_empty(*this);
   free(*this);
   *this=NULL;

}

void Agenda_add_date( Agenda* this, Evento data ) {
   DLL_Push_front( this->list_eventos, data  );

}

void Agenda_add_contact(Agenda* this, Contacto data ) {
   SLL_Push_back(this->list_contactos, data);

}

bool Agenda_Is_empty( Agenda* this ) {
   if( ( DLL_IsEmpty( this->list_eventos )== true ) && ( SLL_Is_empty( this->list_contactos )==true ) ) {
      return true;
   }
   else {
      return false;
   }
}

void Agenda_Make_empty( Agenda* this ) {
   DLL_MakeEmpty(this->list_eventos);
   SLL_Make_empty(this->list_contactos);
}

bool Agenda_Find_Event( Agenda* this, char key[MAX_EVENT] ) {
   DLL_Find_Event_by_name(this->list_eventos, key);
}

bool Agenda_Find_contacto( Agenda* this, char key[MAX_CONTACTS] ) {
   SLL_Find_by_name(this->list_contactos, key);
}

void Print_Agenda( Agenda* this ) {

   DLL_PrintStructure(this->list_eventos);
   SLL_PrintStructure(this->list_contactos);
  
}