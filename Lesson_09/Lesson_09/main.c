#include <stdio.h>

void main()
{
	//unsigned int Num = 15;
	//int Ris;

	//__asm
	//{
	//	//Il nostro Num
	//	MOV EBX, Num
	//	CMP EBX, 2
	//	JE Primo
	//	JL NonPrimo
	//	//ECX è MaxDiv
	//	MOV ECX, EBX
	//	//equivale a dividere per 2
	//	SHR ECX, 1
	//	//il nostro divisore perchè DIV mette il risultato in EDX e EAX
	//	MOV EDI, 2

	//Ciclo:
	//	XOR EDX, EDX
	//	MOV EAX, EBX
	//	DIV EDI
	//	CMP EDX, 0
	//	JE NonPrimo
	//	INC EDI
	//	CMP EDI, ECX
	//	JLE Ciclo
	//	//il resto della divisione è in EDX e il quoziente in EAX
	//
	//Primo:
	//	MOV Ris, 1
	//	JMP Fine
	//
	//NonPrimo:
	//	MOV Ris, 0

	//Fine:
	//}

	//printf("Ris = %d\n", Ris);

	float Vet1[] = { -2, 4, 3, 4 };
	float Vet2[] = { 1, 8, 7, 9 };
	int Lung = sizeof(Vet1) / sizeof(Vet1[0]);
	float Ris;

	__asm
	{
		//inizializza l'unità floating point
		FINIT
		//con i vettori solitamente si opera con ECX nelle posizioni
		MOV ECX, Lung
		//inizializzo a 0 la somma, sono in cima allo stack
		FLDZ

	Ciclo:
		//subito sopra metto il primo valore di Vet1
		FLD Vet1[ECX * 4 - 4];
		//sottra dalla cima dello stack il primo valore di Vet2
		FSUB Vet2[ECX * 4 - 4];
		//moltiplica il valore in cima allo stack per se stesso
		//elevazione al quadrato
		FMUL ST, ST
		//senza operandi somma i due elementi in cima allo stack
		//soomma precedente e attuale
		FADD 
		LOOP Ciclo

		//radice quarata dell'elemento in cima allo stack e viene
		//inserito in posizione superiore
		FSQRT
		//stampa il valore in cima allo stack
		FSTP Ris
	}

	printf("Ris = %f\n", Ris);
}