#include<Agenda.h>
//------------------------------
//  Operaciones Lista Doblemente Enlazada
//------------------------------

static Node* new_node( Evento x  )
{
   Node* n = (Node*) malloc( sizeof( Node ) );
   if( n != NULL ){
      n->datos = x;
      n->next = NULL;
      n->prev = NULL;
   }

   return n;
}

DLL* DLL_New()
{
    DLL* dll= (DLL*) malloc(sizeof(DLL));
    if(dll !=NULL){
        fprintf(stderr,"New():Creando una lista nueva\n");
        dll->first=dll->last=dll->cursor=NULL;
        dll->len=0;
    }
}

void DLL_Delete( DLL** this )
{
    assert(*this);
    fprintf(stderr, "Delete():: Borrando la lista\n");
    DLL_MakeEmpty(*this);
    free(*this);
    *this=NULL;
}

void DLL_Push_front( DLL* this, Evento item  )
{
    assert(this);
    fprintf(stderr,"Push_Front():: Insertando a la izquierda del frente de la lista\n");
    Node* (n)=new_node(item);
    if(DLL_IsEmpty(this)==true)
    {
        this->first=this->last=this->cursor=n;
    }
    else
    {
    n->next=this->first;
    this->first->prev=n;
    this->first=n;
    }
    ++this->len;
}

void DLL_Push_back( DLL* this, Evento item )
{
   Node* n = new_node( item );
   assert( n );

   if( this->first != NULL ){

      this->last->next = n;
      n->prev = this->last;
      this->last = n;
   } else{
      this->first = this->last = this->cursor = n;
   }
   ++this->len;
}

void DLL_Insert( DLL* this, Evento item )
{
    assert(this);
    assert(this->cursor);
    fprintf(stderr,"Insert():: Insertando a la derecha del cursor\n");
    if(DLL_IsEmpty(this) == true)
    {
        DLL_Push_front(this, item);
    }
    else{
    Node* n=new_node(item);
    Node* r=this->cursor->next;
    this->cursor->next=n;
    n->next=r;
    r->prev=n;
    n->prev=this->cursor;
    DLL_Cursor_next;
    }
}

void DLL_Pop_front( DLL* this )
{
    assert(this);
    assert( this->len );
    if(this->first != this->last)
    {
        Node* r= this->first->next;
        free(this->first);
        this->first=r;
        this->first->prev=NULL;
    }
    else{
        free(this->first);
        this->first=this->last=this->cursor=NULL;
    }
    --this->len;
}

void DLL_Pop_back( DLL* this )
{
   assert( this->len );
   // ERR: no se puede borrar nada de una lista vacía

   if( this->last != this->first ) // también funciona: if( this->len > 1 ){...}
   { 
      Node* x = this->last->prev;
      free( this->last );
      x->next = NULL;
      this->last = x;
   } else{
      free( this->last );
      this->first = this->last = this->cursor = NULL;
   }
   --this->len;
}

void DLL_Erase( DLL* this )
{
   assert( this->len );
   fprintf(stderr,"Erase():: Eliminando el elemento apuntado por el cursor \n");
   if( this->last != this->first ) 
   { 
      Node* right = this->cursor->next; 
      Node* left = this->cursor->prev;
      if(this->cursor->prev == NULL
      ){
          DLL_Pop_front(this);
      }
      else if(this->cursor->next ==NULL)
      {
        DLL_Pop_back(this);
      }
      else{
      free( this->cursor );
      this->cursor->next=NULL;
      left->next = right;
      right->prev = left;
      this->cursor = right;
      --this->len;
      }
   }  
   else{
    DLL_Pop_front(this);
   }
}

void DLL_Remove( DLL* this, Evento* key )
{
    assert(this);
    assert(this->len);
    if(DLL_Find_Event_by_name(this,key->nombre)==true){
        DLL_Erase(this);
        fprintf(stderr,"Remove()::El elemento borrado es: %s \n",key->nombre );
    }

    
}
void DLL_MakeEmpty( DLL* this )
{
    assert(this);
    while(this->first != NULL)
    {
        DLL_Pop_front(this);
    }
}

bool DLL_Find_Event_by_name( DLL* this, char key[MAX_EVENT] )
{
   for( this->cursor = this->first; 
        this->cursor != NULL; 
        this->cursor = this->cursor->next )
   {
      if( this->cursor->datos.nombre == key )
      {
         return true;
      }
   }
   return false;
}

void DLL_Cursor_front( DLL* this )
{
   this->cursor = this->first;
}

void DLL_Cursor_back( DLL* this )
{
    this->cursor = this->first;
}

void DLL_Cursor_next( DLL* this )
{
    assert(this->cursor);
    this->cursor=this->cursor->next;
}

void DLL_Cursor_prev( DLL* this )
{
   assert( this->cursor != NULL );

   Node* left = this->cursor->prev;
   this->cursor = left;
}


bool DLL_IsEmpty( DLL* this )
{
   return this->first == NULL;
}

size_t DLL_Len( DLL* this )
{
    return this->len;
}

void DLL_PrintStructure( DLL* this )
{
   if( DLL_IsEmpty( this ) )
   {
      fprintf( stderr, "Empty list. Nothing to show.\n" );
   } 
   else
   {
      fprintf( stderr, "\nNil->" );

      for( Node* it = this->first; it != NULL; it = it->next )
      {
         fprintf( stderr, "(%s  %d/%d/%d  %d:%d:%d )->", it->datos.nombre, it->datos.f.dia, it->datos.f.mes,
         it->datos.f.anio, it->datos.h.hora, it->datos.h.min, it->datos.h.seg);
      } 
      fprintf( stderr, "Nil\n" );
   }
}

//------------------------------
//  Operaciones Lista Enlazada
//------------------------------
static node* new_Node( Contacto c )
{
   node* n = (node*) malloc( sizeof( node ) );
   if( n ){
      n->data = c;
      n->next = NULL;
   }
   return n;
}
SLL*   SLL_New(){
    
    SLL* sll= (SLL*) malloc(sizeof(SLL));
    if(sll !=NULL){
        fprintf(stderr,"New():Creando lista nueva\n");
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

void SLL_Push_front( SLL* this, Contacto data )
{
   assert( this );
   node *n = new_Node(data);
   n->next=this->first;
   this->first=n;
   ++this->len;
}

void SLL_Push_back( SLL* this, Contacto data )
{
   node* n = new_Node( data );
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

size_t SLL_Len( SLL* this )
{
    return this->len;
}


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

bool   SLL_Find_by_name( SLL* this, char key[MAX_CONTACTS] )
{
   bool found = false;

   if( !SLL_Is_empty( this ) )
   {
      for( node* it = this->first; it->next != NULL && found == false ; it = it->next )
      {
         if( key == it->data.contact_name ) 
         {
            this->cursor = it;
            found = true;
         }
      }
   }
   return found;
}

void SLL_PrintStructure( SLL* this )
{
   if( SLL_Is_empty (this ) )
   {
      fprintf( stderr, "Empty list. Nothing to show.\n" );
   } 
   else
   {
      fprintf( stderr, "\nNil->" );

      // usando un for en lugar de while (mi preferido):
      for( node* it = this->first; it != NULL; it = it->next )
      {
         fprintf( stderr, "(%s  %d)->", it->data.contact_name, it->data.phone_number );
      } 
      fprintf( stderr, "Nil\n" );
   }
}

//----------------------------------------------------------------------
//  Operaciones AGENDA
//----------------------------------------------------------------------

Agenda* Agenda_new(){
      
      Agenda* lista = ( Agenda* ) malloc( sizeof( Agenda ) );
      if( lista != NULL ) {
          
            lista->list_eventos= DLL_New();
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

void   Agenda_add_date( Agenda* this, Evento data ){
        DLL_Push_front( this->list_eventos, data  );
}
void   Agenda_add_contact(Agenda* this, Contacto data ){
    SLL_Push_back(this->list_contactos, data);
}

bool   Agenda_Is_empty( Agenda* this ){
        if((DLL_IsEmpty(this->list_eventos)== true) && (SLL_Is_empty(this->list_contactos)==true)){
            return true;
        }
        else{
            return false;
        }
}
void   Agenda_Make_empty( Agenda* this ){
    DLL_MakeEmpty(this->list_eventos);
    SLL_Make_empty(this->list_contactos);
}

bool   Agenda_Find_Event( Agenda* this, char key[MAX_EVENT] ){
        DLL_Find_Event_by_name(this->list_eventos, key);
}
bool   Agenda_Find_contacto( Agenda* this, char key[MAX_CONTACTS] ){
        SLL_Find_by_name(this->list_contactos, key);
}

void    Print_Agenda( Agenda* this ){
        DLL_PrintStructure(this->list_eventos);
        SLL_PrintStructure(this->list_contactos);
}
