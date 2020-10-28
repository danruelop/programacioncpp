#include "Imagen.h"

class CPng : public CImagen
{
public:
	int SetPngFile(const char *pszFile);

private:
	int UncompressImage();
};