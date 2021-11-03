#include <stdio.h>

void main()
{
	unsigned int Num = 1254154;
	char Ris[8];

	__asm
	{
		//EAX = Num
		MOV EAX, Num
		//EBX = i
		MOV EBX, 7

	Ciclo:
		//ECX = Tmp
		MOV ECX, EAX
		//Mascheratura
		AND ECX, 15
		CMP ECX, 9
		JG Lettera
		MOV DL, 48
		JMP Continua

	Lettera:
		MOV DL, 55

	Continua:
		ADD DL, CL
		MOV Ris[EBX], DL
		SHR EAX, 4
		DEC EBX
		JNS Ciclo
	}

	for (int i = 0; i < 8; i++)
		printf("%c", Ris[i]);

	printf("\n\n");
}