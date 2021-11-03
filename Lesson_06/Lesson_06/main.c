#include <stdio.h>

void main()
{
	unsigned char Vettore[] = { 3, 7, 3, 7, 9 };
	unsigned int Lung = sizeof(Vettore) / sizeof(Vettore[0]);
	//0 parità pari, 1 parità dispari
	int Ris;

	//per accedere ai bit di un vettore si può usare o una maschera
	//di bit o la popcount

	__asm
	{
		//somma
		XOR EAX, EAX
		//lunghezza
		MOV ECX, Lung

	Ciclo1:
		//sposto un elemento del vettore in val, va valutato
		MOV BL, Vettore[ECX - 1]
		//valuto se il byte letto è uguale a 0
	Ciclo2:
		CMP BL, 0
		JE ProssimoByte

		//come AND ma non sovrascrive
		TEST BL, 1
		JZ ProssimoBit
		INC EAX

	ProssimoBit:
		SHR BL, 1
		JMP Ciclo2

	ProssimoByte:
		LOOP Ciclo1

		AND EAX, 1
		MOV Ris, EAX
	}

	printf("Ris: %d\n\n", Ris);
}