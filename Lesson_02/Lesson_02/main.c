#include <stdio.h>

void main()
{
	//inizio blocco assembler
	/*	EIP cambia ogni volta perchè punta all'istruzione successiva.
	*	I registri all'inizio hanno sempre valori casuali.
	*	i numeri negativi sono in complemento a 2.
	*	Attenzione: Per le etichette non possono essere usate parole chiave del linguaggio C! Vi consigliamo di usare parole in italiano per eliminare ogni dubbio!
	*	Per informazioni teoriche sui comandi andare a slide 30 del lucido 3
	*	Quando si fa il compare si salva il risultato nel registro delle flag
	*
	*/
	__asm
	{
		//valore copiato in un registro
			MOV EAX, 2
			MOV EBX, 3
		//somma valore, farlo in due basi numeriche diverse porterebbe ad errori
			ADD EAX, EBX
		//somma bit a bit
			AND EAX, EBX
		//incrementa
			INC EAX
		//decrementa
			DEC EAX
		//differenza, ricordarsi la regola del complemento a due (1-3) ritorna -2 in complemento a 2 in formato esadecimale
			SUB EAX, EBX

			MOV EAX, 2
			MOV EBX, 3
		//così si saltano le istruzioni fino al richiamo dell'etichetta, si può fare anche all'indietro
		//attenzione a non creare loop infiniti, usare nomi in italiano per evitare confusione con comandi del c o simili
			JMP Etichetta
			MOV ECX, 5
		Etichetta:
			MOV EDX, 7
			MOV EAX, 3
			//confronta i due argomenti passati e setta alcune flag del registro in maniera opportuna...se uso un salto condizionato
			//esse si baseranno sulle flag. confrontiamo il 3 con il 5 e se è maggiore salta alla fine altrimenti ripeti tutto
			//è un ciclo
		E1:	CMP EAX, 5
			JG Fine
			INC EAX
			JMP E1
			Fine: SUB EAX, 5

			//Esercizi slide 6

	/********************************************************************************************************/
			//01
			MOV	EAX, 1
			MOV EAX, 10
			L1:	ADD	EBX, 2
			DEC EAX
			JNZ L1

	/********************************************************************************************************/
			//02
			MOV EBX, 10
			MOV EAX, 0
			C1:	CMP EBX, EAX
			JE  Finec
			INC EAX
			DEC EBX
			JMP C1
			Finec:

	/********************************************************************************************************/
			//03
			MOV ECX, 1
			MOV EAX, 0
			Ciclo: CMP ECX, 10
			JGE Finex
			ADD EAX, ECX
			INC ECX
			JMP Ciclo
			Finex: MOV	EDX, EAX

	/********************************************************************************************************/
			//04
			MOV ECX, 2
			MOV EAX, 1
			Ciclico: CMP ECX, 10
			JG	Fines
			//MUL
			MUL	ECX
			INC	ECX
			JMP Ciclico
			Fines: MOV EDX, EAX

			/********************************************************************************************************/

	}

}