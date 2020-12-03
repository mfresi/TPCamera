//---------------------------------------------------------------------------

#ifndef LiaisonH
#define LiaisonH
#include <winsock.h>

class Liaison
{
	private:

	   HANDLE hCom;

	public:
	   bool OuvrirPort();
	   bool sendMsg(char* buffer);
	   bool readPort(char * c);
	   bool fermerPort();


};
#endif
