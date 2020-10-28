#include "Imagen.h"

class CJpg : public CImagen
{
public:
	int SetJpgFile(const char *pszJpgFile);

private:
	int UncompressImage();
};