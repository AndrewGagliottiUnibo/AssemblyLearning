#include <stdio.h>


void main()
{
	int Vettore[] = { 3, 7, 3, 3, 5, 1, 4, -3, -7, -9, 2, 6 };
	unsigned int Lung = sizeof(Vettore) / sizeof(Vettore[0]);

	__asm 
	{
		//Pos
		MOV ECX, Lung
		DEC ECX

	Ciclo:
		//Max
		MOV EAX, Vettore[4*ECX]
		//MaxPos
		MOV ESI, ECX
		//I
		MOV EDI, ECX

	CicloInterno:
		DEC EDI
		JS Prossimo
		MOV EDX, Vettore[4*EDI]
		CMP EAX, EDX
		JG CicloInterno
		MOV EAX, EDX
		MOV ESI, EDI
		JMP CicloInterno

	Prossimo:
		//Temp
		MOV EBX, Vettore[4*ECX]
		MOV Vettore[4*ECX], EAX
		MOV Vettore[4*ESI], EBX
		DEC ECX
		CMP ECX, 0
		//è inutiile ordinare l'elemento in posizione 1, esso è implicitamente già ordinato
		JG Ciclo
	}

	for (int i = 0; i < Lung; i++)
		printf("Vettore[%2d] = %d\n", i, Vettore[i]);
}