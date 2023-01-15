#ifndef AGENDA_INC
#define AGENDA_INC

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

/**
 * @brief Crea una nueva lista SLL
 * @return Referencia a la nueva lista
 */
SLL*   SLL_New();
/**
 * @brief Destruye una lista SLL
 * @param this Referencia a un objeto SLL
 * @post La lista se destruyó y no debiera ser utilizado de nuevo
 */
void   SLL_Delete( SLL** this );

/**
 * @brief Inserta un elemento en el frente de la lista.
 * @param this Referencia a un objeto SLL.
 * @param data El elemento a insertar.
 * @pre La lista debe existir.
 */
void   SLL_Push_back( SLL* this, Tipo data );
/**
 * @brief Inserta un elemento a la derecha del cursor.
 * @param this Referencia a un objeto SLL.
 * @param data El elemento a insertar.
 * @pre La lista debe existir.
 * @post El cursor se mueve a la derecha, es decir, al nuevo nodo.
 */
void   SLL_Insert( SLL* this, Tipo data );

/**
 * @brief Devuelve una copia del elemento indicado por el cursor. El
 * comportamiento es indefinido si el cursor no apunta a una posición
 * válida.
 * @param this Referencia a un objeto SLL.
 * @return Una copia del elemento indicado por el cursor
 */
int    SLL_Get( SLL* this );

void   SLL_Pop_front( SLL* this );

/**
 * @brief Devuelve el número de elementos actualmente en la lista.
 * @param this Referencia a un objeto SLL.
 * @return El número de elementos actualmente en la lista.
 */
size_t SLL_Len( SLL* this );

/**
 * @brief Indica si la lista está vacía
 * @param this Referencia a un objeto SLL
 * @return true si la lista está vacía; false en cualquier otro caso
 */
bool   SLL_Is_empty( SLL* this );
/**
 * @brief Vacía la lista sin destruirla.
 * @param this Referencia a un objeto SLL.
 * @post La lista queda vacía.
 */
void   SLL_Make_empty( SLL* this );

void   SLL_Cursor_front( SLL* this );
void   SLL_Cursor_back( SLL* this );
/**
 * @brief Mueve al cursor al siguiente elemento a la derecha.
 * @param this Referencia a un objeto SLL.
 * @return true si el cursor se pudo mover a la derecha; 
 *         false en caso contrario.
 * @post El cursor NO se mueve si a la entrada apuntaba a NULL.
 */
void   SLL_Cursor_next( SLL* this );

/**
 * @brief Mueve al cursor al siguiente elemento a la derecha.
 * @param this Referencia a un objeto SLL.
 * @return true si el cursor se pudo mover a la derecha; 
 *         false en caso contrario.
 * @post El cursor NO se mueve si a la entrada apuntaba a NULL.
 */
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
