#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#define MAX_EVENT 25
#define MAX_CONTACTS 1000

#include "fechas.h"
#include "contactos.h"
#include "agenda.h"


//------------------------------
//  Operaciones Lista Enlazada
//------------------------------

static node* new_Node( Contacto c ) {
   node* n = (node*) malloc( sizeof( node ) );
   if( n ) {
      n->data = c;
      n->next = NULL;
   }
   return n;
}

SLL* SLL_New() {
   SLL* sll= (SLL*) malloc(sizeof(SLL));
   if(sll !=NULL) {
      fprintf(stderr,"New():Creando lista nueva\n");
      sll->first=sll->last=sll->cursor=NULL;
      sll->len=0;
   }
}

void SLL_Delete( SLL** this ) {
   assert( *this );
   fprintf( stderr,"Delete():Borrando la lista\n" );
   SLL_Make_empty(*this);
   free(*this);
   *this=NULL;

}

void SLL_Push_front( SLL* this, Contacto data ) {
   assert( this );
   node *n = new_Node(data);
   n->next=this->first;
   this->first=n;
   ++this->len;

}

void SLL_Push_back( SLL* this, Contacto data ) {
   node* n = new_Node( data );
   if( n ) {
      if( SLL_Is_empty( this ) ) {
         this->first = this->last = this->cursor = n;
      }
      else{
         this->last->next = n;
         this->last = n;
      }
      ++this->len;
   }

}

void SLL_Pop_front( SLL* this )
{
   assert( this->first );
   
    if(this->len==1)
    {
        free(this->first);
        this->first = this->last = this->cursor = NULL;
    }
    else
    {
   node* tmp = this->first->next;
   free( this->first );
   this->first = tmp;
    }
     --this->len;
}

size_t SLL_Len( SLL* this ) {
   return this->len;

}

bool SLL_Is_empty( SLL* this ) { 
   assert( this );
   return this->len==0;

}

void SLL_Make_empty( SLL* this ) {
   assert(this);
   while(this->first != NULL) {
      SLL_Pop_front(this);
   }

}

void SLL_Cursor_front( SLL* this ) {
   this->cursor = this->first;

}

void SLL_Cursor_back( SLL* this ) {
   this->cursor = this->last;

}

void SLL_Cursor_next( SLL* this ) { 
   if( this->cursor != NULL ) {
      this->cursor = this->cursor->next;
   }

}

bool SLL_Find_by_name( SLL* this, char key[MAX_CONTACTS] ) {
   bool found = false;

   if( !SLL_Is_empty( this ) ) {
      for( node* it = this->first; it->next != NULL && found == false ; it = it->next ) {
         if( key == it->data.contact_name ) {
            this->cursor = it;
            found = true;
         }
      }
   }
   return found;
}

void SLL_PrintStructure( SLL* this ) {
   if( SLL_Is_empty (this ) ) {
      fprintf( stderr, "Empty list. Nothing to show.\n" );
   } 
   else {
      fprintf( stderr, "\nNil->" );

      // usando un for en lugar de while (mi preferido):
      for( node* it = this->first; it != NULL; it = it->next ) {
         fprintf( stderr, "(%s  %d)->", it->data.contact_name, it->data.phone_number );
      } 
      fprintf( stderr, "Nil\n" );
   }
}
