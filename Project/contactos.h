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

SLL*   SLL_New();
void   SLL_Delete(       SLL** this );
void   SLL_Push_front(   SLL* this, Contacto data );
void   SLL_Push_back(    SLL* this, Contacto data );
void   SLL_Insert(       SLL* this, Contacto data );
int    SLL_Get(          SLL* this );
void   SLL_Pop_front(    SLL* this );
size_t SLL_Len(          SLL* this );
bool   SLL_Is_empty(     SLL* this );
void   SLL_Make_empty(   SLL* this );
void   SLL_Cursor_front( SLL* this );
void   SLL_Cursor_back(  SLL* this );
void   SLL_Cursor_next(  SLL* this );
bool   SLL_Find(         SLL* this, Contacto key );
void   SLL_PrintStructure( SLL* this );



#endif 