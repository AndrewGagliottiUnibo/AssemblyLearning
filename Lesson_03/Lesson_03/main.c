#include <stdio.h>
#include <stdlib.h>

/*unsigned int per creare variabili double word
passare dal main al blocco asm e poi ritornare al main con i
risultati. Tipi di variabili a slide 3. IMPARARLI PER VELOCIZZARE.
Se usiamo operandi con segno abbiamo una non compatibilità dei bit:
In EAX ci sono 16 bit non 32 di un int normali.

*/

void main()
{
	/*
	//Esercizio 1
	unsigned short num1 = 5;
	unsigned short num2 = 0;
	unsigned int prodotto;

	__asm
	{
		XOR EAX, EAX
		XOR EBX, EBX
		XOR ECX, ECX
		MOV AX, num1
		MOV BX, num2

ciclo:
		CMP EBX, 0
		JE fine		
		ADD ECX, EAX
		DEC EBX
		JMP ciclo
fine:
		MOV prodotto, ECX

	}

	printf("Il prodotto tra %d e %d da' come risultato %d", num1, num2, prodotto);

	*/

	//Esercizio 2
	unsigned int num1 = 99;
	unsigned int radice;

	__asm
	{
		XOR EAX, EAX
		XOR EBX, EBX
		XOR ECX, ECX
		MOV ECX, num1
		MOV EBX, 1
ciclo:
		SUB ECX, EBX
		//CMP EAX, 0 si può omettere a causa dello stato dei flag
		//usare JB sarebbe un errore perchè il numero non sarebbe mai letto come negativo ma sempre come positivo+9

		JS fine	//si puo' usare anche JL
		INC EAX
		ADD EBX, 2
		JMP ciclo
fine:
		MOV radice, EAX

	}

	printf("La radice quadrata (o approsimata) di %d e' %d", num1, radice);
}
