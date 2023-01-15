#ifndef  agenda_INC
#define  agenda_INC

#include <stdlib.h>

typedef struct {
   int some_var;
} DummyClass;

DummyClass* DummyClass_New();
void DummyClass_Delete( DummyClass** d );
void DummyClass_Print( DummyClass* d );
void DummyClass_Set( DummyClass* d, int new_val );
int DummyClass_Get( DummyClass* d );

//----------------------------------------------------------------------
//  AGENDA
//----------------------------------------------------------------------

typedef struct Agenda
{
   DLL* list_eventos;
   SLL* list_contactos;
} Agenda; 


Agenda* Agenda_new();

void   Agenda_Delete( Agenda** this );

void   Agenda_add_date( Agenda* this, Evento data );
void   Agenda_add_contact(Agenda* this, Contacto data );


bool   Agenda_Is_empty( Agenda* this );
void   Agenda_Make_empty( Agenda* this );

bool   Agenda_Find_Evento( Agenda* this, Evento key );
bool   Agenda_Find_contacto( Agenda* this, char key[MAX_CONTACTS]);
void   Print_Agenda( Agenda* this );

#endif   /* ----- #ifndef DUMMYCLASS_INC  ----- */