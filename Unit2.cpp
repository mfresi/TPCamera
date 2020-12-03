//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include <stdio.h>
#include <stdlib>
#include <windows.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
// Fonction pour initialiser la connexion avec l'orniateur et la caméra.
void __fastcall TForm2::buttonConnexionClick(TObject *Sender)
{
   portserie.OuvrirPort();
}
//---------------------------------------------------------------------------
// Fonction qui envoie la trame pour faire une rotation vers la gauche à la caméra.
void __fastcall TForm2::ButtonGaucheClick(TObject *Sender)
{
	char trameG[9];

	trameG[0] = 0x81;
	trameG[1] = 0x01;
	trameG[2] = 0x06;
	trameG[3] = 0x01;
	trameG[4] = 0x18;
	trameG[5] = 0x14;
	trameG[6] = 0x01;
	trameG[7] = 0x03;
	trameG[8] = 0xFF;

	portserie.sendMsg(trameG);
}
//---------------------------------------------------------------------------
// Fonction qui envoie la trame pour faire une rotation vers le haut à la caméra.
void __fastcall TForm2::ButtonHautClick(TObject *Sender)
{
	char trameH[9];

	trameH[0] = 0x81;
	trameH[1] = 0x01;
	trameH[2] = 0x06;
	trameH[3] = 0x01;
	trameH[4] = 0x18;
	trameH[5] = 0x14;
	trameH[6] = 0x03;
	trameH[7] = 0x01;
	trameH[8] = 0xFF;

	portserie.sendMsg(trameH);
}
//---------------------------------------------------------------------------
// Fonction qui envoie la trame pour faire une rotation vers la droite à la caméra.
void __fastcall TForm2::ButtonDroitClick(TObject *Sender)
{
	char trameD[9];

	trameD[0] = 0x81;
	trameD[1] = 0x01;
	trameD[2] = 0x06;
	trameD[3] = 0x01;
	trameD[4] = 0x18;
	trameD[5] = 0x14;
	trameD[6] = 0x02;
	trameD[7] = 0x03;
	trameD[8] = 0xFF;

	portserie.sendMsg(trameD);
}
//---------------------------------------------------------------------------
// Fonction qui envoie la trame pour faire une rotation vers le bas à la caméra.
void __fastcall TForm2::ButtonBasClick(TObject *Sender)
{
	char trameB[9];

	trameB[0] = 0x81;
	trameB[1] = 0x01;
	trameB[2] = 0x06;
	trameB[3] = 0x01;
	trameB[4] = 0x18;
	trameB[5] = 0x14;
	trameB[6] = 0x03;
	trameB[7] = 0x02;
	trameB[8] = 0xFF;

	portserie.sendMsg(trameB);
}
//---------------------------------------------------------------------------
// Fonction qui envoie la trame pour mettre la caméra au centre.
void __fastcall TForm2::ButtonCentreClick(TObject *Sender)
{
	char trameC[5];

	trameC[0] = 0x81;
	trameC[1] = 0x01;
	trameC[2] = 0x06;
	trameC[3] = 0x04;
	trameC[4] = 0xFF;

	portserie.sendMsg(trameC);
}
//---------------------------------------------------------------------------
// Fonction qui permet de zoomer et dézoomer.
void __fastcall TForm2::ZoomEtDezoomChange(TObject *Sender)
{
	char trameZD[6];

	trameZD[0]= 0x81;
	trameZD[1]= 0x01;
	trameZD[2]= 0x04;
	trameZD[3]= 0x07;
	trameZD[4]= 0x03;
	trameZD[5]= 0xFF;

	char zoomordezoom;
	zoomordezoom = ZoomEtDezoom->Position;
	trameZD[4] = zoomordezoom;

	portserie.sendMsg(trameZD);
}
//---------------------------------------------------------------------------
// Fonction qui fait un balayage de la salle trois fois.
void __fastcall TForm2::ButtonBalayageClick(TObject *Sender)
{
	char trameBalay[9];

	for(int i=0;i<3;i++)
	{
		trameBalay[0] = 0x81;
		trameBalay[1] = 0x01;
		trameBalay[2] = 0x06;
		trameBalay[3] = 0x01;
		trameBalay[4] = 0x18;
		trameBalay[5] = 0x14;
		trameBalay[6] = 0x02;
		trameBalay[7] = 0x03;
		trameBalay[8] = 0xFF;

		portserie.sendMsg(trameBalay);
        // On fait une pause de 3 secondes.
		Sleep(3000);

		trameBalay[0] = 0x81;
		trameBalay[1] = 0x01;
		trameBalay[2] = 0x06;
		trameBalay[3] = 0x01;
		trameBalay[4] = 0x18;
		trameBalay[5] = 0x14;
		trameBalay[6] = 0x01;
		trameBalay[7] = 0x03;
		trameBalay[8] = 0xFF;

		portserie.sendMsg(trameBalay);
        // On fait une pause de 3 secondes.
		Sleep(3000);
	}
}
//---------------------------------------------------------------------------

