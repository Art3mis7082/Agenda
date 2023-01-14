#ifndef AGENDA
#define AGENDA

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#define MAX 25

//----------------------------------------------------------------------
//  Fechas y Contactos
//----------------------------------------------------------------------

typedef struct
{
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct
{
    char contact_name[MAX];
    int phone_number;
    
} Contacto;

typedef struct
{
    Fecha f;
    Contacto c;
}Tipo;

//NO tienen operaciones, accesaremos directamente a los campos


//----------------------------------------------------------------------
//  Lista Simplemente enlazada
//----------------------------------------------------------------------

typedef struct Node {

      Tipo data;
      struct Node* prev;
      struct Node* next;
} Node;


typedef struct SLL
{
	Node* first;
	Node* last;
	Node* cursor;
	size_t len;
} SLL;

SLL*   SLL_New();
void   SLL_Delete( SLL** this );

void   SLL_Push_back( SLL* this, Tipo data );
void   SLL_Insert( SLL* this, Tipo data );

void   SLL_Pop_front( SLL* this );

int    SLL_Get( SLL* this );
size_t SLL_Len( SLL* this );

bool   SLL_Is_empty( SLL* this );
void   SLL_Make_empty( SLL* this );

void   SLL_Cursor_front( SLL* this );
void   SLL_Cursor_back( SLL* this );
void   SLL_Cursor_next( SLL* this );
bool   SLL_Find( SLL* this, int key );

//----------------------------------------------------------------------
//  AGENDA
//----------------------------------------------------------------------

typedef struct
{
    SLL* list_fechas;
    SLL* list_contactos;
} Agenda; 


Agenda* Agenda_new();

void   Agenda_Delete( Agenda** this );

void   Agenda_add_date( Agenda* this, Fecha data );
void   Agenda_add_contact(Agenda* this, Contacto data );


bool   Agenda_Is_empty( SLL* this );
void   Agenda_Make_empty( SLL* this );

bool   Agenda_Find_fecha( SLL* this, int key );
bool   Agenda_Find_contacto( SLL* this, int key );
int    Print_Agenda( SLL* this );




#endif   /* ----- #ifndef STOCK_INC  ----- */
