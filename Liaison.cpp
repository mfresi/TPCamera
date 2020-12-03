//---------------------------------------------------------------------------

#pragma hdrstop

#include "Liaison.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <winsock.h>
#include <stdlib>
#include <stdio.h>


bool Liaison::OuvrirPort()   //on ouvre le port souhaite et on le configure
{
  this->hCom = CreateFileA("COM1",GENERIC_READ | GENERIC_WRITE,0,NULL,OPEN_EXISTING,FILE_FLAG_NO_BUFFERING,NULL);   //3e valeur = sécu,4e = ouvrir un port existant

  if(hCom == INVALID_HANDLE_VALUE)
  {
	  return false;
  }
  else
  {
	DCB conf;

	GetCommState(this->hCom,&conf);

	conf.BaudRate = CBR_9600;
	conf.StopBits = ONESTOPBIT;
	conf.Parity = NOPARITY;
	conf.ByteSize=8;
	SetCommState(this->hCom,&conf);
	COMMTIMEOUTS comm;
	comm.ReadIntervalTimeout = MAXDWORD;
	comm.ReadTotalTimeoutMultiplier=0;
	comm.ReadTotalTimeoutConstant=0;
	comm.WriteTotalTimeoutMultiplier=0;
	comm.WriteTotalTimeoutConstant=0;

	SetCommTimeouts(hCom,&comm);

	return true;
  }
}

bool Liaison::sendMsg(char * buffer)
{
	bool etat = false;
	unsigned long tailleRead;

	etat = WriteFile(this->hCom,buffer,strlen(buffer),&tailleRead,NULL);

	if(etat == true)
	{
        return true;
	}
	else
	{
        return false;
	}
}

bool Liaison::fermerPort()
{
	bool etat;

	etat = CloseHandle(this->hCom);

	if(etat == 0)
	{
        return false;
	}
	else
	{
        return true;
	}
}