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


DLL* DLL_New();
void DLL_Delete( DLL** this );

void DLL_Push_front( DLL* this, Evento item );
void DLL_Push_back( DLL* this, Evento item );
void DLL_Insert( DLL* this, Evento item );

void DLL_Pop_front( DLL* this );
void DLL_Pop_back( DLL* this );
void DLL_Erase( DLL* this );
void DLL_Remove( DLL* this, Evento* key );

void DLL_MakeEmpty( DLL* this );

bool DLL_Find_Event_by_name( DLL* this, char key[MAX_EVENT] );

void DLL_Cursor_front( DLL* this );
void DLL_Cursor_back( DLL* this );
void DLL_Cursor_next( DLL* this );
void DLL_Cursor_prev( DLL* this );
bool DLL_Cursor_end( DLL* this );

bool DLL_IsEmpty( DLL* this );
size_t DLL_Len( DLL* this );


void DLL_PrintStructure( DLL* this );

int DLL_Concat(DLL* list_1, DLL* list_2, int len);
void DLL_mergesort(DLL* arr, int len);

#endif