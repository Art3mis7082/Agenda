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


/// @brief Crea un objeto agenda.
/// @return Dirección asignada para la nueva agenda.
Agenda* Agenda_new();
/// @brief Borra la agenda (SLL y DLL de los TADS)
/// @param this Objeto agenda
void   Agenda_Delete( Agenda** this );

/// @brief Añadir evento a la agenda
/// @param this Objeto agenda
/// @param data parámetros del objeto Evento
void   Agenda_add_date( Agenda* this, Evento data );
/// @brief Añadir contacto a la agenda
/// @param this Objeto agenda 
/// @param data nombre y número telefónico del contacto
void   Agenda_add_contact(Agenda* this, Contacto data );

/// @brief Verifica que las listas no estén vacías
/// @param this Objeto agenda
/// @return Si las listas de contactos y eventos están vacías
bool   Agenda_Is_empty( Agenda* this );
/// @brief Vacía las listas de Agenda (TAD contactos y eventos)
/// @param  this Objeto agenda
void   Agenda_Make_empty( Agenda* this );

/// @brief Busca un evento por medio de un nombre
/// @param this Objeto agenda
/// @param key nombre del evento
/// @return El evento que se busca
bool   Agenda_Find_Event( Agenda* this, Evento key );
/// @brief Busca un contacto dentro de la lista de contactos por número
/// @param this Objeto agenda 
/// @param key número de la lista de contactos
/// @return El contacto según el número dado
bool   Agenda_Find_contacto( Agenda* this, char key[MAX_CONTACTS]);
/// @brief Imprime la agenda del mes
/// @param this Objeto agenda
void   Print_Agenda( Agenda* this );

#endif   /* ----- #ifndef DUMMYCLASS_INC  ----- */