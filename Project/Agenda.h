#ifndef AGENDA
#define AGENDA

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#define MAX_EVENT 25
#define MAX_CONTACTS 1000

//----------------------------------------------------------------------
//  Eventos 
//----------------------------------------------------------------------

typedef struct
{
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct
{
    int hora;
    int min;
    int seg;
}Hora;

typedef struct
{
    char nombre[MAX_EVENT];
    Fecha f;
    Hora h;
    
}Evento;
//----------------------------------------------------------------------
//  Contactos 
//----------------------------------------------------------------------

typedef struct
{
    char contact_name[MAX_EVENT];
    int phone_number;
    
} Contacto;

//NO tienen operaciones, accesaremos directamente a los campos


//----------------------------------------------------------------------
//  Lista Doblemente enlazada para Eventos
//----------------------------------------------------------------------
typedef struct Node
{
	Evento datos;

	struct Node* next;
	struct Node* prev;
} Node;

typedef struct
{
	Node* first;
	Node* last;
	Node* cursor;
	size_t len;
} DLL;


DLL* DLL_New();
void DLL_Delete( DLL** this );

void DLL_Push_front( DLL* this, int item );
void DLL_Push_back( DLL* this, int item );
void DLL_Insert( DLL* this, int item );

void DLL_Pop_front( DLL* this );
void DLL_Pop_back( DLL* this );
void DLL_Erase( DLL* this );
void DLL_Remove( DLL* this, int key );

void DLL_MakeEmpty( DLL* this );

bool DLL_Find( DLL* this, int key );

void DLL_Cursor_front( DLL* this );
void DLL_Cursor_back( DLL* this );
void DLL_Cursor_next( DLL* this );
void DLL_Cursor_prev( DLL* this );
bool DLL_Cursor_end( DLL* this );

bool DLL_IsEmpty( DLL* this );
size_t DLL_Len( DLL* this );


void DLL_PrintStructure( DLL* this );


//----------------------------------------------------------------------
//  Lista Simplemente enlazada para Contactos
//----------------------------------------------------------------------
typedef struct node
{
	Contacto data;
	struct node* next;
} node;

typedef struct SLL
{
	node* first;
	node* last;
	node* cursor;
	size_t len;
} SLL;

SLL*   SLL_New();
void   SLL_Delete(       SLL** this );
void   SLL_Push_front(   SLL* this, Contacto data );
void   SLL_Push_back(    SLL* this, Contacto data    );
void   SLL_Pop_front(    SLL* this );
size_t SLL_Len(          SLL* this );
bool   SLL_Is_empty(     SLL* this );
void   SLL_Make_empty(   SLL* this );
void   SLL_Cursor_front( SLL* this );
void   SLL_Cursor_back(  SLL* this );
void   SLL_Cursor_next(  SLL* this );
bool   SLL_Find(         SLL* this, Contacto key );
void SLL_PrintStructure( SLL* this );

//----------------------------------------------------------------------
//  AGENDA
//----------------------------------------------------------------------

typedef struct
{
    DLL* list_eventos;
    SLL* list_contactos;
} Agenda; 


Agenda* Agenda_new();

void   Agenda_Delete( Agenda** this );

void   Agenda_add_date( Agenda* this, Fecha data );
void   Agenda_add_contact(Agenda* this, Contacto data );


bool   Agenda_Is_empty( SLL* this );
void   Agenda_Make_empty( SLL* this );

bool   Agenda_Find_Event( SLL* this, int key );
bool   Agenda_Find_contacto( SLL* this, int key );
int    Print_Agenda( SLL* this );




#endif   /* ----- #ifndef STOCK_INC  ----- */
