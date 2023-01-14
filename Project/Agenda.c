#include<Agenda.h>
//------------------------------
//  Operaciones Lista Enlazada
//------------------------------
static Node* new_Node( Tipo data )
{
   Node* n = (Node*) malloc( sizeof( Node ) );
   if( n ){
      n->data = x;
      n->next = NULL;
   }
   return n;
}
SLL*   SLL_New(){
    
    SLL* sll= (SLL*) malloc(sizeof(SLL));
    if(sll !=NULL){
        fprintf(stderr,"New():Creando una lista nueva\n");
        sll->first=sll->last=sll->cursor=NULL;
        sll->len=0;
    }
}

void   SLL_Delete( SLL** this ){
    
    assert( *this );
    fprintf(stderr,"Delete():Borrando la lista\n");
    SLL_Make_empty(*this);
    free(*this);
    *this=NULL;
}

void   SLL_Push_back( SLL* this, Tipo data ){
    
   Node* n = newNode( data );
   if( n )
   {
      if( SLL_Is_empty( this ) )
      {
         this->first = this->last = this->cursor = n;
      }
      else{
         this->last->next = n;
         this->last = n;
      }
      ++this->len;
   }
}
void   SLL_Insert( SLL* this, Tipo data ){
    
    assert(this);
    assert( this->cursor);
    fprintf(stderr,"Insert(): Insertando nuevo nodo a la derecha del cursor\n");
    
    Node* n=newNode(data);
    Node* temp=this->cursor->next;
    this->cursor->next=n;
    this->cursor=n;
    n->next=temp;
    ++this->len;
    
}

void   SLL_Pop_front( SLL* this ){
    
    assert( this->first );
    if(this->len==1)
    {
        free(this->first);
        this->first = this->last = this->cursor = NULL;
    }
    else
    {
   Node* tmp = this->first->next;
   free( this->first );
   this->first = tmp;
    }
     --this->len;
}

int    SLL_Get( SLL* this ){
  
   assert( this->first );
   assert( this->cursor );
   
    return cursor->data;
}

size_t SLL_Len( SLL* this );

bool   SLL_Is_empty( SLL* this ){
     
    assert( this );
    return this->len==0;
}
void   SLL_Make_empty( SLL* this ){
    
    assert(this);
    while(this->first != NULL)
    {
        SLL_Pop_front(this);
    }
}

void SLL_Cursor_front( SLL* this ){
    
   this->cursor = this->first;
}

void SLL_Cursor_back( SLL* this ){
    
   this->cursor = this->last;
}

void SLL_Cursor_next( SLL* this ){
    
   if( this->cursor != NULL )
   {
      this->cursor = this->cursor->next;
   }
}

bool   SLL_Find( SLL* this, Tipo key );

//----------------------------------------------------------------------
//  Operaciones AGENDA
//----------------------------------------------------------------------

Agenda* Agenda_new(){
      
      Agenda* lista = ( Agenda* ) malloc( sizeof( Agenda ) );
      if( lista != NULL ) {
          
            lista->list_fechas= SLL_New();
            lista->list_contactos = SLL_New();
      }
      
      return lista;
}

void   Agenda_Delete( Agenda** this ){
    
    assert( *this );
    fprintf(stderr,"Delete():Borrando Agenda\n");
    Agenda_Make_empty(*this);
    free(*this);
    *this=NULL;
}

void   Agenda_add_date( Agenda* this, Fecha data );
void   Agenda_add_contact(Agenda* this, Contacto data );

bool   Agenda_Is_empty( SLL* this );
void   Agenda_Make_empty( SLL* this );

bool   Agenda_Find_fecha( SLL* this, Fecha key );
bool   Agenda_Find_contacto( SLL* this, Contacto key );

void    Print_Agenda( SLL* this )void DLL_PrintStructure( DLL* this ){
    
   if( Agenda_IsEmpty( this ) )
   {
      fprintf( stderr, "La agenda se encuentra vacía\n" );
   } 
   else
   {
      for( Node* it = this->first; it != NULL; it = it->next )
      {
         fprintf( stderr, "(%d)->", it->datos );
      } 
      fprintf( stderr, "Nil\n" );
   }
}
