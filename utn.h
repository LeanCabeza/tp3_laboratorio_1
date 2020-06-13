
int utn_getString(char *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int intentos);
int validarLetra (char letras[]);
int validarNumero (char numeros[]);

int utn_getNumero(int *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
int isValidInt(int numero, int maximo, int minimo);

int isValidFloat(float numero, float maximo, float minimo);
int utn_getFloat(float *resultado, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos);

int isValidChar(char letra, char maximo, char minimo);
int getChar( char *resultado,char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos);
