#include <stdio.h>

void main()
{
	//Esercizio 3

	char Stringa[] = "Questa e' una stringa";
	int Lunghezza = sizeof(Stringa) - 1;
	char Carattere = 'u';
	int Posizione;

	__asm
	{
		XOR EAX, EAX			//i del diagramma di flusso
		MOV BL, Carattere		//C
		MOV ECX, Lunghezza

		Ciclo :
		CMP EAX, ECX			//i >= lungh?

		//Anche se è int la lughezza sarà sempre maggiore o uguale a 0	
		//i due operandi saranno sempre maggiori o uguali a 0 quindi	
		//useremo indifferentemente la condizione di salto				

			JAE Negativo
			MOV BH, Stringa[EAX]	//T  del diagramma di flusso
			CMP BH, BL
			JE Trovato
			INC EAX
			JMP Ciclo

			//Dobbiamo evitare problemi di codice dovuti alla sovrascrittura di posizione e quindi l'esito negativo lo 
			Negativo :
		MOV EAX, -1

			Trovato :
			MOV Posizione, EAX
	}

	printf("Posizione = %d\n\n", Posizione);
}


//	//Esercizio 4
//	//*
//	unsigned int Numero = 32;
//	unsigned int Risultato;				
//	//o 0 o 1 a seconda del risultato negativo o positivo
//
//	__asm
//	{
//		XOR EAX, EAX	
//		MOV ECX, Numero
//		JECXZ Fine
//
//	Ciclo:
//		TEST ECX, 1
//		JZ Continua
//		CMP ECX, 1
//		JE Potenza
//		JMP Fine
//
//	Continua:
//		SHR ECX, 1
//		JMP Ciclo
//
//	Potenza:
//		MOV EAX, 1
//
//	Fine:
//		MOV Risultato, EAX
//	}
//
//	printf("%d", Risultato);
//	//*/
//}