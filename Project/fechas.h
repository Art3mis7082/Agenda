#ifndef fechas_INC
#define fechas_INC

//----------------------------------------------------------------------
//  Eventos 
//----------------------------------------------------------------------

typedef struct Fecha
{
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct Hora
{
    int hora;
    int min;
    int seg;
}Hora;

typedef struct Evento
{
    char nombre[MAX_EVENT];
    Fecha f;
    Hora h;
    
}Evento;

//----------------------------------------------------------------------
//  Lista Doblemente enlazada para Eventos
//----------------------------------------------------------------------
typedef struct Node
{
	Evento datos;

	struct Node* next;
	struct Node* prev;
} Node;

typedef struct DLL
{
	Node* first;
	Node* last;
	Node* cursor;
	size_t len;
} DLL;

/**
 * @brief Crea una lista doblemente enlazada
 *
 * @return Una referencia a la nueva lista
 * @post Una lista existente en el heap
 */
DLL* DLL_New();
/**
 * @brief Destruye una lista.
 *
 * @param this Una lista.
 */
void DLL_Delete( DLL** this );

/**
 * @brief Inserta un elemento en el inicio de la lista.
 *
 * @param this Una lista.
 * @param item El elemento a insertar
 */
void DLL_Push_front( DLL* this, Evento item );
/**
 * @brief Inserta un elemento en el fondo de la lista.
 *
 * @param this Una lista.
 * @param item El elemento a insertar
 */
void DLL_Push_back( DLL* this, Evento item );
/**
 * @brief Inserta un elemento a la derecha del cursor
 *
 * @param lista Una referencia a la lista de trabajo
 * @param item El elemento a insertar
 *
 * @post Coloca al cursor en el nuevo nodo
 *
 */
void DLL_Insert( DLL* this, Evento item );

/**
 * @brief Elimina el elemento al frente de la lista.
 *
 * @param this Referencia a una lista.
 *
 * @post El cursor se mantiene en la posición en la que estaba cuando entró la
 * función.
 */
void DLL_Pop_front( DLL* this );
/**
 * @brief Elimina el elemento al fondo de la lista.
 *
 * @param this Referencia a una lista.
 *
 * @post El cursor se mantiene en la posición en la que estaba cuando entró la
 * función.
 */
void DLL_Pop_back( DLL* this );
/**
 * @brief Elimina el elemento apuntado por el cursor.
 *
 * @param this Una lista.
 *
 */
void DLL_Erase( DLL* this );
/**
 * @brief Elimina el primer nodo que coincida con la llave. ej. elimina todos los que valgan 'key'
 *
 * @param this Una lista
 * @param key  Valor buscado
 *
 */
void DLL_Remove( DLL* this, Evento* key );
/**
 * @brief Elimina todos los elementos de la lista sin eliminar la lista.
 *
 * @param this Una lista
 */
void DLL_MakeEmpty( DLL* this );
/**
 * @brief Busca un valor en la lista. Si lo encuentra coloca ahí al cursor.
 *
 * @param this Una lista.
 * @param key El valor que se está buscando.
 *
 * @post Si se encontró una coincidencia coloca al cursor en ese nodo; en caso contrario el cursor es NULL.
 *
 */
bool DLL_Find_Event_by_name( DLL* this, char key[MAX_EVENT] );

/**
 * @brief Coloca al cursor al inicio de la lista.
 *
 * @param this Una referencia a la lista de trabajo
 */
void DLL_Cursor_front( DLL* this );
/**
 * @brief Coloca al cursor al final de la lista.
 *
 * @param this Una referencia a la lista de trabajo
 */
void DLL_Cursor_back( DLL* this );
/**
 * @brief Mueve al cursor al siguiente elemento a la derecha.
 *
 * @param this Una lista.
 */
void DLL_Cursor_next( DLL* this );
/**
 * @brief Mueve al cursor al siguiente elemento a la izquierda.
 *
 * @param this Una lista.
 */
void DLL_Cursor_prev( DLL* this );

/**
 * @brief Indica si la lista está vacía.
 *
 * @param this Referencia a una lista.
 *
 * @return true si la lista está vacía; false en caso contrario.
 */
bool DLL_IsEmpty( DLL* this );
/**
 * @brief Devuelve el número actual de elementos en la lista.
 *
 * @param this Una lista.
 *
 * @return Devuelve el número actual de elementos en la lista.
 */
size_t DLL_Len( DLL* this );

/**
 * @brief Imprime la estructura de la lista. Es para uso de depuración, no es de uso general.
 *
 * @param this Una lista.
 */
void DLL_PrintStructure( DLL* this );


int DLL_Concat(DLL* list_1, DLL* list_2, int len);
void DLL_mergesort(DLL* arr, int len);

#endif