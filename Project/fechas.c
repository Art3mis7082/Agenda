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
//  Operaciones Lista Doblemente Enlazada
//------------------------------

static Node* new_node( Evento x  ) {
   Node* n = (Node*) malloc( sizeof( Node ) );
   if( n != NULL ) {
      n->datos = x;
      n->next = NULL;
      n->prev = NULL;
   }

   return n;
}

DLL* DLL_New() {
   DLL* dll= (DLL*) malloc(sizeof(DLL));
   if(dll !=NULL) {
      fprintf(stderr,"New():Creando una lista nueva\n");
      dll->first=dll->last=dll->cursor=NULL;
      dll->len=0;
   }
}

void DLL_Delete( DLL** this ) {
   assert(*this);
   fprintf(stderr, "Delete():: Borrando la lista\n");
   DLL_MakeEmpty(*this);
   free(*this);
   *this=NULL;

}

void DLL_Push_front( DLL* this, Evento item  ) {
   assert(this);
   fprintf(stderr,"Push_Front():: Insertando a la izquierda del frente de la lista\n");
   Node* (n)=new_node(item);
   if(DLL_IsEmpty(this)==true) {
        this->first=this->last=this->cursor=n;
   }
   else {
    n->next=this->first;
    this->first->prev=n;
    this->first=n;
   }
   ++this->len;
   
}

void DLL_Push_back( DLL* this, Evento item ) {
   Node* n = new_node( item );
   assert( n );

   if( this->first != NULL ) {

      this->last->next = n;
      n->prev = this->last;
      this->last = n;
   } 
   else {
      this->first = this->last = this->cursor = n;
   }
   ++this->len;
}

void DLL_Insert( DLL* this, Evento item ) {
   assert(this);
   assert(this->cursor);
   fprintf(stderr,"Insert():: Insertando a la derecha del cursor\n");
   if(DLL_IsEmpty(this) == true) {
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

void DLL_Pop_front( DLL* this ) {
   assert(this);
   assert( this->len );
   if(this->first != this->last) {
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

void DLL_Pop_back( DLL* this ) {
   assert( this->len );
   // ERR: no se puede borrar nada de una lista vacía

   if( this->last != this->first ) { // también funciona: if( this->len > 1 ){...}
   
      Node* x = this->last->prev;
      free( this->last );
      x->next = NULL;
      this->last = x;
   } 
   else {
      free( this->last );
      this->first = this->last = this->cursor = NULL;
   }
   --this->len;
}

void DLL_Erase( DLL* this ) {
   assert( this->len );
   fprintf(stderr,"Erase():: Eliminando el elemento apuntado por el cursor \n");
   if( this->last != this->first ) { 
      Node* right = this->cursor->next; 
      Node* left = this->cursor->prev;
      if(this->cursor->prev == NULL) {
         DLL_Pop_front(this);
      }
      else if(this->cursor->next ==NULL) {
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

void DLL_Remove( DLL* this, Evento* key ) {
   assert(this);
   assert(this->len);
   if(DLL_Find_Event_by_name(this,key->nombre)==true){
      DLL_Erase(this);
      fprintf(stderr,"Remove()::El elemento borrado es: %s \n",key->nombre );
   }
    
}

void DLL_MakeEmpty( DLL* this ) {
   assert(this);
   while(this->first != NULL) {
      DLL_Pop_front(this);
   }
}

bool DLL_Find_Event_by_name( DLL* this, char key[MAX_EVENT] ) {
   for( this->cursor = this->first; 
      this->cursor != NULL; 
      this->cursor = this->cursor->next ) {

      if( this->cursor->datos.nombre == key ) {
         return true;
      }
   }
   return false;
}

bool DLL_Find_Event_by_date( DLL* this, char key[MAX_EVENT] ) {
   for( this->cursor = this->first; 
      this->cursor != NULL; 
      this->cursor = this->cursor->next ) {
      
      if( this->cursor->datos.nombre == key ) {
         return true;
      }
   }
   return false;
}

void DLL_Cursor_front( DLL* this ) {
   this->cursor = this->first;
}

void DLL_Cursor_back( DLL* this ) {
   this->cursor = this->last;
}

void DLL_Cursor_next( DLL* this ) {
   assert(this->cursor);
   this->cursor=this->cursor->next;
}

void DLL_Cursor_prev( DLL* this ) {
   assert( this->cursor != NULL );

   Node* left = this->cursor->prev;
   this->cursor = left;
}

bool DLL_IsEmpty( DLL* this ) {
   return this->first == NULL;
}

size_t DLL_Len( DLL* this ) {
   return this->len;
}

void DLL_PrintStructure( DLL* this ) {
   if( DLL_IsEmpty( this ) ) {
      fprintf( stderr, "Empty list. Nothing to show.\n" );
   } 
   else {
      fprintf( stderr, "\nNil->" );

      for( Node* it = this->first; it != NULL; it = it->next ) {
         fprintf( stderr, "(%s  %d/%d/%d  %d:%d:%d )->", it->datos.nombre, it->datos.f.dia, it->datos.f.mes,
         it->datos.f.anio, it->datos.h.hora, it->datos.h.min, it->datos.h.seg);
      } 
      fprintf( stderr, "Nil\n" );
   }
}

int DLL_Concat(DLL* list_1, DLL* list_2, int len) {
    DLL* list_3=DLL_New();
    DLL_Cursor_front(list_1);
    DLL_Cursor_back(list_2);
    DLL_Cursor_front(list_3);
    list_3->first=list_1->first;
    list_3->last=list_2->last;
    int cont=1;

    if(cont < len/2) {
        DLL_Cursor_next(list_1);
        list_3->cursor->next==list_1->cursor;
        DLL_Cursor_next(list_3);
        cont++;
    }
    if(cont < len){
        DLL_Cursor_prev(list_2);
        list_3->cursor->next==list_2->cursor;
        DLL_Cursor_next(list_3);
        cont++;
    }
    
    DLL_Delete(&list_1);
    DLL_Delete(&list_2);
    return list_3;
}

void DLL_mergesort(DLL* arr, int len) {
    
   DLL_Cursor_front(arr);
   DLL_Cursor_next(arr);
   if (len == 1) { 
      return; 
   }
   if (len == 2) {
      if (arr->cursor->prev->datos.f.anio > arr->cursor->datos.f.anio) {
         DLL_Push_front(arr, arr->cursor->datos);
         DLL_Erase(arr);
             
         if(arr->cursor->prev->datos.f.mes > arr->cursor->datos.f.mes) {
            DLL_Push_front(arr, arr->cursor->datos);
            DLL_Erase(arr);
                
               if(arr->cursor->prev->datos.f.dia > arr->cursor->datos.f.dia) {
                  DLL_Push_front(arr, arr->cursor->datos);
                  DLL_Erase(arr);
               }
         }    
      }
   }

   int p = len/2;
  
   DLL* arr1 = DLL_New();
   int cont1=1;
   arr1->first=arr->first;
   DLL_Cursor_front(arr1);
   while(cont1<p) {
      DLL_Cursor_next(arr1);
      cont1++;
   } 
   arr1->last=arr1->cursor;
    
   DLL* arr2 = DLL_New();
   int cont2=1;
   arr2->last=arr->last;
   DLL_Cursor_back(arr1);
   while(cont2<p) {
      DLL_Cursor_prev(arr2);
      cont2++;
   } 
   arr2->first=arr2->cursor;

   DLL_mergesort(arr1, p);
   DLL_mergesort(arr2, p);
   arr=DLL_Concat(arr1,arr2,len);
    
}


