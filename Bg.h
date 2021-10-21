#include "Bicola.h"

typedef Elem Casilla;

int Dado1(){return rand()%6+1;}

int Dado2(){return rand()%6+1;}

Bicola Iniciar(){
	Bicola q=nueva();
	Casilla c;
	int i;
	for(i=1;i<=26;i++){
		c.Cas=i;
		c.Ficha=0;
		q=formard(q,c);
	}
	return q;
}

ApNodoB ApCas(Bicola q, int n){
	ApNodoB ap;
	ap=q->prim;
	if((n>0)&&(n<27)){
		while((ap->dato.Cas)!=n){
			ap=ap->sig;
		}
		return ap;
	}
}

void AcomodaF(Bicola q, int cas, int n){
	ApNodoB ap=ApCas(q,cas);
	int x=abs(n);
	if(n>0){
		 while(x--)
		     ap->dato.Ficha=(ap->dato.Ficha)+1;
	}else if(n<0){
		 while(x--)
		  	 ap->dato.Ficha=(ap->dato.Ficha)-1;
	}else{
		 ap->dato.Ficha=0;
	}
}

void IniciarTab(Bicola q){
	AcomodaF(q,2,2);
	AcomodaF(q,7,-5);
	AcomodaF(q,9,-3);
	AcomodaF(q,13,5);
	AcomodaF(q,14,-5);
	AcomodaF(q,18,3);
	AcomodaF(q,20,5);
	AcomodaF(q,25,-2);
}

int NumF(Bicola q, int cas){
	ApNodoB ap=ApCas(q,cas);
	return ap->dato.Ficha;
}

int NumC(Bicola q, int cas){
	ApNodoB ap=ApCas(q,cas);
	return ap->dato.Cas;
}

void ImpTab(Bicola q, int cont1, int cont2){
	printf("\n\n");
	int i;
	for(i=13;i>=10;i--){
		 printf(" %d",NumC(q,i));
	}
	for(i=9;i>=8;i--){
		 printf(" 0%d",NumC(q,i));
	}
	printf("      ");
	for(i=7;i>=2;i--){
		 printf(" 0%d",NumC(q,i));
	}
	printf("  | I/F");
	printf("\n--------------------------------------------|----\n");
	for(i=13;i>=8;i--){
		 printf(" %d ",NumF(q,i));
	}
	printf("|   |");
	for(i=7;i>=2;i--){
		 printf(" %d ",NumF(q,i));
	}
	printf("    %d",NumF(q,1));
	
	printf("\n");
	printf("\t\t   | %d |                    |\n",cont1);
	printf("\t\t   |   |                    |\n");
	printf("\t\t   |   |                    |\n");
	printf("\t\t   |   |                    |\n");
	printf("\t\t   |   |                    |\n");
	printf("\t\t   |   |                    |\n");
	printf("\t\t   |   |                    |\n");
	printf("\t\t   | %d |                    |",cont2);
	printf("\n");
	
	for(i=14;i<=19;i++){
		 printf(" %d ",NumF(q,i));
	}
	printf("|   |");
	for(i=20;i<=25;i++){
		 printf(" %d ",NumF(q,i));
	}
	printf("    %d",NumF(q,26));
	printf("\n--------------------------------------------|----\n");
	for(i=14;i<=19;i++){
		 printf(" %d",NumC(q,i));
	}
	printf("      ");
	for(i=20;i<=25;i++){
		 printf(" %d",NumC(q,i));
	}
	printf("  | I/F");
	printf("\n\n");
}

void QuitaF(Bicola q, int cas){
	ApNodoB ap=ApCas(q,cas);
	if((NumF(q,cas))!=0){
		 if((NumF(q,cas))>0){
			  ap->dato.Ficha=ap->dato.Ficha-1;
		 }else if((NumF(q,cas))<0){
			  ap->dato.Ficha=ap->dato.Ficha+1;
		 }
	}else{
		 ap->dato.Ficha=0;
	}
}

int esvaciaBr(int n){
	return (n==0);
}

int essucas(ApNodoB ap, char type){
	if((ap->dato.Ficha<0)&&(type=='N')){
		 return 1;
	}else if((ap->dato.Ficha>0)&&(type=='P')){
		 return 1;
	}else{
		return 0;
	}
}

int esvaciaCas(ApNodoB ap){
	return ap->dato.Ficha==0;
}

int EnfrentarNP(ApNodoB ap, char type){
	if(type=='N'){
		 return ap->dato.Ficha==1;
	}else if(type=='P'){
		 return ap->dato.Ficha==-1;
	}
}

int Condiciones(Bicola q,int cas, char type){
	ApNodoB ap=ApCas(q,cas);
	if(esvaciaCas(ap)){
		 return 1;
	}else if(essucas(ap,type)){
		 return 1;
	}else if(EnfrentarNP(ap,type)){
		 return 1;
	}else{
		 return 0;
	}
}

int CasD(Bicola q, int casI, int dado, char type){
	ApNodoB ap=ApCas(q,casI);
	int i;
	if(type=='N'){
		 for(i=1;i<=dado;i++){
			  if(ap->ant!=NULL){
			  	   ap=ap->ant;
			  }
		 }
	}else if(type=='P'){
		 for(i=1;i<=dado;i++){
			  if(ap->sig!=NULL){
			  	   ap=ap->sig;
			  }
		 }
	}
	return ap->dato.Cas;
}

int esposmov(Bicola q, int casI, int casD, int d1, int d2, char type){
	int caso1,caso2,caso3;
	caso1=CasD(q,casI,d1+d2,type);
	caso2=CasD(q,casI,d1,type);
	caso3=CasD(q,casI,d2,type);
	if(casD==caso1 || casD==caso2 || casD==caso3)
		return 1;
	else return 0;
}

void Jugador1(Bicola q, int *cont1, int *cont2){
	int casI,casD,ds,t=1;
	int d1,d2;
	char type='P';
	printf("\t\t Jugador 1: Positivos\n\t Press Enter para lanzar los dados ");
	getchar();
	d1=Dado1();d2=Dado2();
		
	if(d1==d2){
		 ds=(d1+d2)*2;
    }else{
    	 ds=d1+d2;
	}
	
	if(!esvaciaBr(*cont1)){
		casI=1;
		do{	
			 printf("\n Dado 1: %d\n Dado 2: %d\n Turno %d\n\n",d1,d2,t++);
			 do{
			      do{ 
				       fflush(stdin);
				       printf("\n Casilla a dirigirse: ");
				       scanf("%d",&casD);
				       if(!Condiciones(q,casD,type)){
				  	        printf(" Ingrese otra: ");
				       }
				  }while(!Condiciones(q,casD,type));
				  if(!esposmov(q,casI,casD,d1,d2,type)){
				  	   printf(" Ingrese otra: ");
				  }
			 }while(!esposmov(q,casI,casD,d1,d2,type));
			 *cont1=*cont1-1;
			 if(EnfrentarNP(ApCas(q,casD),type)){
			      *cont2=*cont2-1;
				  QuitaF(q,casD);
				  AcomodaF(q,casD,1);
			 }else{
			 	  AcomodaF(q,casD,1);
			 }
			 system("clear");
			 ImpTab(q,*cont1,*cont2);
			 ds=ds-abs(casI-casD);
			 if(esvaciaBr(*cont1)&&ds!=0){
				 printf("\n Dado 1: %d\n Dado 2: %d\n Turno %d\n\n",d1,d2,t++);
				 do{
					  do{ 
						   fflush(stdin);
						   printf("\n\n Casilla a mover: ");
						   scanf("%d",&casI);
						   if(!essucas(ApCas(q,casI),type)){
						        printf(" Esa no es tu casilla \n Ingrese otra ");
						   }
					  }while(!essucas(ApCas(q,casI),type));
					  do{ 
					       fflush(stdin);
						   printf("\n Casilla a dirigirse: ");
						   scanf("%d",&casD);
						   if(!Condiciones(q,casD,type)){
						   	    printf("\n Ingrese otra: ");
						   }
					  }while(!Condiciones(q,casD,type));
						   if(!esposmov(q,casI,casD,d1,d2,type)){
								printf("\n Ingrese otra: ");
						   }
				 }while(!esposmov(q,casI,casD,d1,d2,type));
				 QuitaF(q,casI);
				 if(EnfrentarNP(ApCas(q,casD),type)){
					  *cont2=*cont2-1;
					  QuitaF(q,casD);
					  AcomodaF(q,casD,1);
				 }else{
				 	  AcomodaF(q,casD,1);
				 }
				 system("clear");
				 ImpTab(q,*cont1,*cont2);
			 }
		}while(ds);
	}else{
		 do{ printf("\n Dado 1: %d\n Dado 2: %d\n Turno %d\n\n",d1,d2,t++);
			  do{
				   do{ 
					    fflush(stdin);
					    printf("\n\n Casilla a mover: ");
					    scanf("%d",&casI);
					    if(!essucas(ApCas(q,casI),type)){
						     printf("\n Esa no es tu casilla \n Ingrese otra ");
						}
				   }while(!essucas(ApCas(q,casI),type));
				   do{ fflush(stdin);
					    printf("\n Casilla a dirigirse: ");
					    scanf("%d",&casD);
					    if(!Condiciones(q,casD,type)){
					    	 printf("\n Ingrese otra: ");
						}
				   }while(!Condiciones(q,casD,type));
					    if(!esposmov(q,casI,casD,d1,d2,type)){
					    	 printf("\n Ingrese otra: ");
						}
			  }while(!esposmov(q,casI,casD,d1,d2,type));
			  QuitaF(q,casI);
			  if(EnfrentarNP(ApCas(q,casD),type)){
					*cont2=*cont2-1;
					QuitaF(q,casD);
					AcomodaF(q,casD,1);
			  }else{
			  	   AcomodaF(q,casD,1);
			  }
			  system("clear");
			  ImpTab(q,*cont1,*cont2);
			  ds=ds-abs(casI-casD);
		 }while(ds);
	}
}
void Jugador2(Bicola q, int *cont1, int *cont2){
	int casI,casD,ds,t=1;
	int d1,d2;
	char type='N';
	printf("\t\t Jugador 2: Negativos\n\t Press Enter para lanzar los dados ");
	getchar();
	d1=Dado1();d2=Dado2();
		
	if(d1==d2){
		 ds=(d1+d2)*2;
	}
	else{
		 ds=d1+d2;
	}
	
	if(!esvaciaBr(*cont2)){
		casI=26;
		do{	
		     printf("\n Dado 1: %d\n Dado 2: %d\n Turno %d\n\n",d1,d2,t++);
			 do{
			      do{ 
				       fflush(stdin);
					   printf("\n Casilla a dirigirse: ");
					   scanf("%d",&casD);
					   if(!Condiciones(q,casD,type)){
					   	    printf("\n Ingrese otra: ");
					   }
				  }while(!Condiciones(q,casD,type));
				  if(!esposmov(q,casI,casD,d1,d2,type)){
				  	   printf("\n Ingrese otra: ");
				  }
			 }while(!esposmov(q,casI,casD,d1,d2,type));
			 *cont2=*cont2+1;
			 if(EnfrentarNP(ApCas(q,casD),type)){
				  *cont1=*cont1+1;
				  QuitaF(q,casD);
				  AcomodaF(q,casD,-1);
			 }else{
			 	  AcomodaF(q,casD,-1);
			 }
			 system("clear");
			 ImpTab(q,*cont1,*cont2);
			 ds=ds-abs(casI-casD);
			 if(esvaciaBr(*cont1)&&ds!=0){
				  do{
						do{ 
							fflush(stdin);
							printf("\n\n Casilla a mover: ");
							scanf("%d",&casI);
							if(!essucas(ApCas(q,casI),type))
								printf("\n Esa no es tu casilla \n Ingresa otra ");
						}while(!essucas(ApCas(q,casI),type));
						do{ fflush(stdin);
							printf("\n Casilla a dirigirse: ");
							scanf("%d",&casD);
							if(!Condiciones(q,casD,type))
								printf("\n Ingrese otra: ");
						}while(!Condiciones(q,casD,type));
							if(!esposmov(q,casI,casD,d1,d2,type))
								printf("\n Ingrese otra: ");
				  }while(!esposmov(q,casI,casD,d1,d2,type));
				  QuitaF(q,casI);
				  if(EnfrentarNP(ApCas(q,casD),type)){
					   *cont1=*cont1+1;
					   QuitaF(q,casD);
					   AcomodaF(q,casD,-1);
				  }else{
				  	   AcomodaF(q,casD,-1);
				  }
				  system("clear");
				  ImpTab(q,*cont1,*cont2);
			 }
		}while(ds);
	}else{
		 do{ 
		      printf("\n Dado 1: %d\n Dado 2: %d\n Tirada %d\n\n",d1,d2,t++);
			  do{
				   do{ 
				        fflush(stdin);
					    printf("\n\n Casilla a mover: ");
					    scanf("%d",&casI);
					    if(!essucas(ApCas(q,casI),type)){
					    	 printf("\n Esa no es tu casilla \n Ingresa otra: ");
						}
				   }while(!essucas(ApCas(q,casI),type));
				   do{ fflush(stdin);
					    printf("\n Casilla a dirigirse: ");
					    scanf("%d",&casD);
					    if(!Condiciones(q,casD,type)){
					    	 printf("\n Ingrese otra: ");
						}
				   }while(!Condiciones(q,casD,type));
					    if(!esposmov(q,casI,casD,d1,d2,type)){
					    	 printf("\n Ingrese otra: ");
						}
			  }while(!esposmov(q,casI,casD,d1,d2,type));
			  QuitaF(q,casI);
			  if(EnfrentarNP(ApCas(q,casD),type)){
				   *cont1=*cont1+1;
				   QuitaF(q,casD);
				   AcomodaF(q,casD,-1);
			  }else{
			       AcomodaF(q,casD,-1);
			  }
			  system("clear");
			  ImpTab(q,*cont1,*cont2);
			  ds=ds-abs(casI-casD);
		 }while(ds);
	}
}
