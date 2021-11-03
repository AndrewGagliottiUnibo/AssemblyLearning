#include <stdio.h>

void main()
{
	int Vettore[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, -1, -2, -3 };
	unsigned int Lung = sizeof(Vettore) / sizeof(int);
	int Somma;
	int Media;

	__asm
		{
		//Azzero il registro per la somma
			XOR EAX, EAX
		//Salvo i valori che necessito nei registri
			MOV ECX, Lung
		//Inizio codice
	Ciclo:
			ADD EAX, Vettore[4*ECX - 4]
		//Decrementa già da per se ECX
			LOOP Ciclo
		//Salvo i dati nelle variabili
			MOV Somma, EAX
		//CDQ estende il segno di EAX in EDX
			CDQ
			IDIV Lung
			MOV Media, EAX
		}

	printf("Somma = %d\n", Somma);
	printf("Media = %d\n\n", Media);
}