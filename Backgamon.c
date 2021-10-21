#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"Bg.h"

int main(){
	srand(time(NULL));
	Bicola q=Iniciar();
	IniciarTab(q);
	int cont1=0, cont2=0;
	while(NumF(q,1)!=-15||NumF(q,26)!=15){
		system("clear");
		ImpTab(q,cont1,cont2);
		Jugador1(q,&cont1,&cont2);
		system("clear");
		ImpTab(q,cont1,cont2);
		Jugador2(q,&cont1,&cont2);
	}
	if(NumF(q,1)!=-15)
		printf("\n\t\t El ganador es el Jugador 2");
	else if(NumF(q,26)!=15)
		printf("\n\t\t El ganador es el Jugador 1");
	return 0;
}
