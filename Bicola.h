#include "ElemBg.h"

typedef struct Nodo {
	     Elem dato;
	     struct Nodo*sig;
	     struct Nodo*ant;
}*ApNodoB;

typedef struct BNodo {
	     ApNodoB prim;
         ApNodoB ult;
}*Bicola;

int esnueva(Bicola q){return (q->prim==NULL)&&(q->ult==NULL);}

Bicola nueva(){
     Bicola t=(Bicola) malloc(sizeof(struct BNodo));
     t->prim=t->ult=NULL;
     return t; 
}

Bicola formari(Bicola q, Elem e){
     ApNodoB t=(ApNodoB) malloc(sizeof(struct Nodo));
     t->dato=e;
     if (esnueva(q)){
          q->ult=q->prim=t;
          t->sig=t->ant=NULL;
     }else{
          q->prim->ant=t;
          t->sig=q->prim;
          q->prim=t;
          t->ant=NULL;
     }
     return q;
}

Bicola formard(Bicola q, Elem e){
     ApNodoB t=(ApNodoB) malloc(sizeof(struct Nodo));
     t->dato=e;
     if (esnueva(q)){
          q->ult=q->prim=t;
          t->sig=t->ant=NULL;
     }else{
          q->ult->sig=t;
          t->ant=q->ult;
          q->ult=t;
          t->sig=NULL;
     }
     return q;
}

Elem primero(Bicola q){return q->prim->dato;}

Elem ultimo(Bicola q){return q->ult->dato;}

ApNodoB NodoPosBC(Bicola q, int n){
	if(n>0){
		int i;
		ApNodoB c;
		c=q->prim;
		for(i=1;i<n;i++){
			if(c->sig=NULL)
				return c;
			c=c->sig;
		}
		return c;
	}
}

Bicola desformari(Bicola q){
		q->prim=q->prim->sig;
		q->prim->ant=NULL;
	return q;
}

Bicola desformard(Bicola q){
		q->ult=q->ult->ant;
		q->ult->sig=NULL;
	return q;
}

void ImpCola(Bicola q){
	ApNodoB c;
	c=q->prim;
	while (c){
		ImpElem(c->dato);
		c=c->sig;
	}
}
