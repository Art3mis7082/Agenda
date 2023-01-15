#ifndef contactos_INC
#define contactos_INC


//----------------------------------------------------------------------
//  Contactos 
//----------------------------------------------------------------------

typedef struct Contacto
{
    char contact_name[MAX_EVENT];
    int phone_number;
    
} Contacto;

//NO tienen operaciones, accesaremos directamente a los campos

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
void   SLL_Delete(       SLL** this );
/**
 * @brief Inserta un elemento en el frente de la lista.
 * @param this Referencia a un objeto SLL.
 * @param data El elemento a insertar.
 * @pre La lista debe existir.
 */
void   SLL_Push_front(   SLL* this, Contacto data );
/**
 * @brief Inserta un elemento atrás de la lista.
 * @param this Referencia a un objeto SLL.
 * @param data El elemento a insertar.
 * @pre La lista debe existir.
 */
void   SLL_Push_back(    SLL* this, Contacto data );
/**
 * 
 * @brief Inserta un elemento a la derecha del cursor.
 * @param this Referencia a un objeto SLL.
 * @param data El elemento a insertar.
 * @pre La lista debe existir.
 * @post El cursor se mueve a la derecha, es decir, al nuevo nodo.
 */
void   SLL_Insert(       SLL* this, Contacto data );
/**
 * @brief Devuelve una copia del elemento indicado por el cursor. El
 * comportamiento es indefinido si el cursor no apunta a una posición
 * válida.
 * @param this Referencia a un objeto SLL.
 * @return Una copia del elemento indicado por el cursor
 */
int    SLL_Get(          SLL* this );
/**
 * @brief Devuelve el elemento que está hasta el frente de la lista
 * @param this Referencia a un objeto SLL.
 */
void   SLL_Pop_front(    SLL* this );
/**
 * @brief Devuelve el número de elementos actualmente en la lista.
 * @param this Referencia a un objeto SLL.
 * @return El número de elementos actualmente en la lista.
 */
size_t SLL_Len(          SLL* this );
/**
 * @brief Indica si la lista está vacía
 * @param this Referencia a un objeto SLL
 * @return true si la lista está vacía; false en cualquier otro caso
 */
bool   SLL_Is_empty(     SLL* this );
/**
 * @brief Vacía la lista sin destruirla.
 * @param this Referencia a un objeto SLL.
 * @post La lista queda vacía.
 */
void   SLL_Make_empty(   SLL* this );
/**
 * @brief Mueve al cursor al inicio de la lista
 * @param this Referencia a un objeto SLL.
 * @return true si el cursor se pudo mover al inicio; 
 *         false en caso contrario.
 * @post El cursor NO se mueve si a la entrada apuntaba a NULL.
 */
void   SLL_Cursor_front( SLL* this );
/**
 * @brief Mueve al cursor al final de la lista
 * @param this Referencia a un objeto SLL.
 * @return true si el cursor se pudo mover al final; 
 *         false en caso contrario.
 * @post El cursor NO se mueve si a la entrada apuntaba a NULL.
 */
void   SLL_Cursor_back(  SLL* this );
/**
 * @brief Mueve al cursor al siguiente elemento a la derecha.
 * @param this Referencia a un objeto SLL.
 * @return true si el cursor se pudo mover a la derecha; 
 *         false en caso contrario.
 * @post El cursor NO se mueve si a la entrada apuntaba a NULL.
 */
void   SLL_Cursor_next(  SLL* this );
/**
 * @brief Busca si un elemento está en la lista; en caso afirmativo, coloca al cursor sobre él.
 * @param this Referencia a un objeto SLL.
 * @param key El valor que estamos buscando.
 * @return true si se encontró una coincidencia; false en caso contrario.
 * @post Coloca al cursor en el nodo en el que se hubiera encontrado una coincidencia
 */
bool   SLL_Find(         SLL* this, Contacto key );
/**
 * @brief Imprime la estructura que lleva almacenada la lista.
 * @param this Referencia a un objeto SLL.
 * @post Imprime los datos almacenados.
 */
void   SLL_PrintStructure( SLL* this );



#endif 