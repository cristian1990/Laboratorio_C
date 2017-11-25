#define CANT 100
typedef struct{
    int idPelicula;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[400];
    int puntaje;
    char linkImagen[400];
}EMovie;

char menu(void);
void alta(EMovie*);
void baja(EMovie*);
void modificar(EMovie*);
void listar(EMovie*);
int buscarLibre(EMovie*);
void toString(EMovie*);
int guardarEnArchivo(EMovie *);
int cargarDesdeArchivo(EMovie *);
void crearHtml(EMovie *);
