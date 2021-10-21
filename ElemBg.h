/*typedef struct e{
    	char Ficha;
	    int NumCas;
}Elem;

void ImpElem(Elem e){
		printf(" \n%d==%c",e.NumCas,e.Ficha);
}*/

typedef struct e{
    	int Ficha;
	    int Cas;
}Elem;

void ImpElem(Elem e){
		printf(" \n%d==%d",e.Cas,e.Ficha);
}

/*int EsIgual(char*e1, char*e2){return strcasecmp(e1,e2)==0;}

int EsMoI(char*e1, char*e2){return strcasecmp(e1,e2)<=0;}

int EsMAoI(char*e1, char*e2){return strcasecmp(e1,e2)>=0;}

int EsMe(char*e1, char*e2){return strcasecmp(e1,e2)<0;}

int EsMa(char*e1, char*e2){return strcasecmp(e1,e2)>0;}*/
