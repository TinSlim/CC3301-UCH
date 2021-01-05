# Resumen C1

# Tipos

## Tipos Primitivos

- Enteros con signo: char, short, int, long int, long long int.
- Sin signo: unsigned ...
- Reales: float, double.
- Punteros: int*, float*.

## Binario

- Base 8 usa prefijo 0, ejemplo: 013.
- Base 16 usa prefijo 0x, ejemplo: 0x13. No olvidar que {a:10, b:11, c:12, d:13, e:14, f:15} 
- Base 2 usa prefijo 0b, ejemplo 0b

# Bits

## Tipos

### Enteros sin signo

| Tipo            | 64 bits | 32 bits | 16 bits |
|------------- |---------|---------|---------|
| u-char         | 1       | 1       | 1       |
| u-short        | 2       | 2       | 2       |
| u-int            | 4       | 4       | 2       |
| u-long         | 8       | 4       | 4       |
| u-long long | 8       | 8       | 8       |

- 1 bit = [ 0 , (2^8) [  = [0 , 255]
- 2 bit = [ 0 , (2^16) [ = [0, 65535]
- 4 bit = [ 0 , (2^32) [
- 8 bit = [ 0 , (2^64) [

### Enteros con signo

| Tipo      | 64 bits | 32 bits | 16 bits |
|-----------|---------|---------|---------|
| char      | 1       | 1       | 1       |
| short     | 2       | 2       | 2       |
| int       | 4       | 4       | 2       |
| long      | 8       | 4       | 4       |
| long long | 8       | 8       | 8       |

- 1 bit = [ -(2^7) , (2^7) [  = [-128 , 127]
- 2 bit = [ -(2^15) , (2^15) [
- 4 bit = [ -(2^31) , (2^31) [
- 8 bit = [ -(2^63) , (2^63) [


## Representación 

### Negativos

- El -28 en un char:
  - Valor absoluto = 28
  - Representar en binario: 28 = 11100
  - Extender en bits (8): 0011100
  - Calcular complemento: 1100011
  - Sumar 1: **1100100** = -28 

### Reales

- El 6.25 en float:
  - 6 = 110 y 25 = .01 se obtiene **110.01**
  - Se normaliza (mover el punto) = **1.1001 * (2^2)** 
  - Ver signo, 0 si es positivo, 1 si es negativo.
  - (Signo)-(Exponente+127)-(decimales)
  - 0-(127 + 2 = 129 en binario)-(1001)
  - Se obtiene **0|10000001|10010000...**

# Precedencia y Asociatividad

%% ToDo %%
  
## Overflow

Cualquier operación entera devuelva al menos un entero
```c
char a = 127; //127 es lo máximo para un char
char b = 1;
int c = a + b; // -128, se convierte en la suma int
```

# Bits Operaciones

## Operaciones

| Símbolo | Operación   | Ejemplo      | Resultado |
|---------|-------------|--------------|-----------|
| &       | and         | 1100 & 1010  | 1000      |
| \|      | or          | 1100 \| 1010 | 1110      |
| ^       | xor         | 1100 ^ 1010  | 0110      |
| ~       | not         | ~1100        | 0011      |
| <<      | shift left  | 111011<<2    | 101100    |
| >>      | shift right | 111011>>2    | 001110    |

**Ojo**, si el número posee signo negativo, al usar >>, aparencen 1s.

## Mapa de Bits

%% ToDo %%

##  Máscaras

- X & m : borra bits de x que en **m** son 0.
- X | m : enciende bits de x que en **m** son 1.

- j primeros bits en 0 : ( (unsigned) -1 ) >> j.
- j últimos bits en 0 : ( (unsigned) -1 ) << j.


# Variables
```c
char a;     // Declaración
char b = 1; // Asignación
```

Variables Globales: Van afuera de **toda** función. Se crean cuando parte la ejecución.

```c
int u;     // Bueno
int v = 1; // Bueno
int v = u; // Malo
```

Si se instancia nuevamente una de la variables globales en una función (ej main), se usa la de la función.


# Punteros

## Punteros

```c
int v = 20;
int *p;     // Puntero
```

Puntero apunta al byte más pequeño.
Operador contenido es * y dirección **&**.
```c
v = 22;
p = &v;     // Apunta a v
int c = *p; // c = v
```

## Arreglos

```c
int arr[10];  // Arreglo de 10 elementos (0...9)
arr[0] = 0;   // Primer elemento = 0
int* p, q;    // p es puntero, q es entero
```

## Funciones útiles

### Swap

```c
void swap (int *p, int *q) {
    int t = *p;
    *p = *q;
    *q = t;
}
```
### Swap de Punteros
```c
void swap_ptr (int **p, int **q) {
    int *t = *p;
    *p = *q;
    *q = t;
}
```

## Variables Dinámicas

```c
int *r = malloc(10 * sizeof(int)); 
// Crea un arreglo de 10 elementos
free(r);
// Libera la memoria
```
Puntero nulo es **NULL**, que corresponde a dirección 0x00.


# Strings

Son char* y terminan en 0.

| 'h' | 'o' | 'l' | 'a' | 0 |

### Tipos

**String Constante:** Se escriben: `` char *r = "hola"; `` , estos son inmutables.

**String:** Se escriben: `` char r[] = "hola"; `` , en estos casos se puede hacer `` r[0] = 'H'; `` y cambiará la primera letra.

- ``strlen(s)`` Entrega largo de String s.
- ``strcpy(s,"bye")`` s pasa a ser bye
- ``strcmp(const char *str1, const char *str2)`` entrega 0< si str1<str2, entrega 0 si son iguales y 0> si str1>str2.

Si s es menor a la palabra que se le reemplaza, se escribe en memoria no solicitada.

# Typedef

```c
typedef unsigned int uint;
uint a = 1; // es unsigned int

typedef unsigned int* puint;
puint p; //es puntero a unsigned int
``` 

# Estructuras

### Ejemplo complejos:

```c
// Se crea estructura
struct compl {
    double r,im;
}

// Se crea un número complejo
struct compl x;
x.r = 2.5; x.im = -5.8;
``` 


```c
// Se usa typedef
typedef struct compl Compl;

// Se crea número complejo
Compl z = {1,10}
``` 

## Funciones con estructuras

### Ejemplo suma de complejos

```c
Compl suma (Compl x, Compl y) {
    Compl z = { x.r + y.r , x.im + y.im}
    return z;
}
``` 

### Ejemplo mover un complejo

```c
void mover (Compl* p, double r, double im) {
    pz->r += r;
    pz->im += im;
}
``` 

### Crear un complejo nuevo

```c
Compl* nuevoCompl (double r, double im) {
    Compl *z = malloc(sizeof(Compl));
    z->r = r;
    z->im = im;
    return z;
}
``` 

Se pueden armar estructuras de datos recursivas, para se debe usar puntero a estructura. Además crear estructuras con typedef.

```c
typedef struct nodo {
    int x;
    Nodo *prox;
} Nodo;
``` 

## Puntero a Función

Se crean funciones.
```c
double f( double x ) {
    . . .
}

double g( double x ) {
    . . .
}
```

Se crea función que recibe función como parámetro.
```c
void H(Fun r) {   // H(f) {
    . . .         // . . . 
    (*r)(4.8);    // f(4.8);
}                 //}
``` 

``Fun`` es tipo puntero a función que recibe un ``double`` y entrega un ``double``, se pueden declarar más tipos así con:
```c
typedef double (*Fun) (double);
``` 

Entonces, para declarar un puntero a función se puede hacer así:
```c
// Crea el puntero a función que recibe un double, entrega un double y el puntero se llama miFuncion
double (*miFuncion) (double); 

// Se apunta el puntero a una función ya creada
miFuncion = f; // f se creó arriba

// Para usarla usar * y valores que recibe
(*miFuncion) (2.32)
```

# Archivos

- El tipo para los archivos es FILE.
-  Se debe importar con:
```c
 #include <stdio.h>
 ```
- Para abrir un archivo:
 ```c
 // Lectura
 FILE *in = fopen("pers.txt","r");

 // Ecritura 
FILE *in = fopen("pers.txt","w");

// Ambos
FILE *in = fopen("pers.txt","r+");
```

- Para leer texto:
```c
// Lee un byte y entrega EOF si acabó el archivo, es un char
int fgetc(FILE *stream);

// Lee una línea en un string de a lo más size-1 bytes, si size<len(linea), corta la línea
char *fgets(char *s, int size, FILE *stream);
```
- Para escribir texto:
```c
// Escribe un char, se entrega como int
int fputc(int char, FILE *stream);

// Escribe un string
int fputs(const char* s, FILE *stream);
```

- Con formato
```c
// Envía texto formateado al stream
int fprintf(FILE *stream, const char *format, ...);
// Ej: fprintf(fp, "%s %s %s %d", "We", "are", "in", 2020);

// Lee texto formateado del stream
int fscanf(FILE *stream, const char *format, ...);
// Ej: fscanf(fp, "%s %s %s %d", str1, str2, str3, &year);
```

- Otras funciones
```c
// Chequea fin del archivo
int feof(FILE *stream);

// Chequea error
int ferror(FILE *stream);

// Avanza cabezal
int fseek(FILE *stream, long offset, int whence);

// Cierra el archivo
int fclose(FILE *stream);
```
Para fseek se tienen 3 valores para  ``whence``, que es desde donde se empieza el offset:
  - ``SEEK_SET`` : Inicio del archivo.
  - ``SEEK_CUR`` : Posición actual.
  - ``SEEK_END`` : Fin del archivo.
  
Preferir funciones que usen buffer, ya que son más seguras.

## Archivos Binarios

```c
// Lectura
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

// Escritura
size_t fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream);
```
Los parámetros son ``size``, que es el tamaño en bytes del elemento y ``nmemb`` la cantidad de elementos, ``ptr`` es un bloque de memoría de donde se escribe o donde se guarda.

### Ejemplo de uso:
```c
FILE *out = fopen("pers.bin","w");
fwrite(pers, sizeof(Persona),3,out);
fclose(out);

FILE *in = fopen("pers.bin","r");
Persona *pers2 = malloc(100*sizeof(Persona));
int ent = fread(pers2,sizeof(Persona),100,in);
```
Escribir en disco ocurre cuando:
  - Se llena el buffer.
  - Se cierra el archivo (``fclose(stream)``).
  - Se usa ``fflush(stream)``.

Para los errores:
  - ``fopen`` retorna NULL.
  - ``fread`` retorna negativo.
  - Para explicar error usar:
  ```c
  void perror(const char *str);
  ```

  Para determinar el tamaño del archivo:
  ```c
  fseek(archivo,0,SEEK_END);
  int sizeFile = ftell(archivo);
  int numElements = sizeFile / sizeof(Elements);
  ```

  # Threads
  Importar con:
  ```c
  #include <pthread.h>
  ```
  
  Funciones de threads:
  ```c
// Crear thread
int pthread_create(pthread *thread, pthread_attr *attr, void *(*start) (void *arg), void *arg);

int pthread_create(pthread *t, NULL, void *(*f) (void *a), void *a);

// Esperar un thread
int pthread_join(pthread_t t, void**pret);

int pthread_join(pthread_t t, NULL);
```

### ¿Cómo abordar un ejercicio de Threads?
1. Revisar parámetros y retorno de la función que se va a paralelizar.
2. Crear una estructura donde se pueda guardar los resultados de la función.
3. Crear una función de tipo ``void *f_thread (void *ptr)`` que recibe la estructura y usa la función **paralelizable**.
4. En función grande, crear tantos thread y estructuras como se quiera tener.
5. Hacer el ciclo ``for`` que haga ``pthread_create`` para cada estructura con su respectivo thread.
6. Hacer el ciclo ``for`` que haga ``pthread_join`` para obtener resultados. 


# Mutex

Perminten la exclusión mutua, haciendo que una zona crítica quede cerrada y se espera a que se desocupe para acceder a ella denuevo.

Operaciones:

```c
// Inicia Mutex
int pthread_mutex_init(pthread_mutex_t *m, NULL)

// Destruye Mutex
int pthread_mutex_destroy(pthread_mutex_t *m)

// Bloquea Mutex
int pthread_mutex_lock(pthread_mutex_t *m)

// Desbloquea Mutex
int pthread_mutex_unlock(pthread_mutex_t *m)
```

Ejemplo uso:

```c
Diccionario dicc;
thread_mutex_t m;

void init() {
  dicc = nuevo Diccionario();
  pthread_mutex_init(&m,NULL)
}

int autorizar(int cuenta, int monto) {
  int ret = 0; // Falso
  pthread_mutex_lock(&m);                   // Se bloquea
  if (monto <= saldo) {                     //
    int nuevo_saldo = saldo - monto;        //
    modificar(dicc, cuenta, nuevo_saldo);   //
    ret = 1;                                //
  }                                         //
  pthread_mutex_unlock(&m);                 // Se desbloquea
  return res;
}
```

# Condiciones

Perminte esperar eficientemente hasta que ocurra el evento.

Operaciones:

```c
// Inicia Condición
int pthread_cond_init(pthread_cond_t *cond, NULL);

// Destruye Condición
int pthread_cond_destroy(pthread_cond_t *cond);

// Espera
int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *m);

// Despierta todos
int pthread_cond_broadcast(pthread_cond_t *cond);

// Despierta solo uno
int pthread_cond_signal(pthread_cond_t *cond);
```

Ejemplo de read:

```c
int writing = 0; // Falso
pthread_mutex m;
pthread_cond c;

void enterRead() {
  lock(&m);          // Se bloquea
  while (writing) {  //
    wait(&c,&m)      // Se espera 
  }                  //
  readers++;         //
  unlock(&m);        // Se desbloquea
}
```


# Sistema de Archivos
Ejemplos:
```c
int fd_in = open("/home/jperez/datos.txt", O_RDONLY);
int fd_out = open("salida.txt", O_WRONLY | O_CREAT)
```
> ``fd_in`` y ``fd_out`` son file descriptors, identifican un archivo.

> Al dejar de usar se debe cerrar: ``int close(int fd);``.

**Para leer:**
```c
ssize_t read(int fd, void *buf, size_t nbytes);
```
Donde buf es donde se leerá, lee nbytes desde fd. Retorna cantidad efectiva de bytes leídos, si devuelve 0 se alcanzó fin del archivo y <0 en caso de error.

**Para escribir:**
```c
ssize_t write(int fd, void *buf, size_t nbytes);
```
Debe retornar nbytes, sino hubo error. 

Todo programa ya tiene file desriptors:
- 0: Entrada estándar.
- 1: Salida estándar.
- 2: Salida estándar de errores.

**Permisos**

Hay tres de usario:
- Propietario = U.
- Grupo = G.
- Otro.

Hay 3 de accesos:
- Lectura = r.
- Escritura = w.
- Execución: x.

CHMOD permite definir permisos para acceder a archivo:
```shell
$ chmod ug = rw datos.txt
```
Ver permisos:
```shell
$ ls -l datos.txt
```


TODO más de archivos


# Procesos

Para crear procesos se debe usar un ``Fork``. Los procesos tienen un **PID**. Retorna dos veces, en el padre el **PID** del hijo y en el hijo 0.

Ejemplo:

```c
int g = 0;
int main() {
  pid_t child = fork();
  if (child == 0) {
    g = v = 1;
    printf("Hijo g= %d v = %d \n",g,v);
    exit(210);
  }
  else {
    int status;
    waitpid(child,&status,0);  // Espera muerte del hijo
    int rc = EXITSTATUS(status)
    printf("Hijo g= %d v = %d \n",g,v);
  }
}
```
```shell
$ Hijo g=1 v=1
$ Padre g=0 v=0 rc=210 child=1013
```

El proceso hijo muere al usar exit, el padre debe enterrar a sus hijos con ``waitpid``.

Si el pid de waitpid es -1, se espera a cualquier hijo y se entrega el pid del que terminó.

# Pipes

Es un canal de comunicación entre procesos.
Se crean con:

```c
int fds[2];
pipe(fds);
```
Donde ``fds[0]`` sera file descriptor de lectura y ``fds[1]`` de escritura.

Ejemplo:

```c
int fd[2];
pipe(fd);
pid_t pid = fork();
if (pid ==0){
  close(fd[0]);
  qsort(a,i,h-1);
  write(fd[1],&a[1],(n-1) * sizeof(int));
  exit(0);
}
else {
  close(fd[1]);
  qsort(a,n+1);
  read(fd[0],&a[i],(n-1) * sizeof(int)); // preferir usar leer
  close(fd[0]);
  waitpid(pid,NULL,);
}
```

# Set Jump / Long Jump

Uso:
```c
jmp_buf exp; // global

if (setjmp(exp) == 0) { // try
   ...
} else {  // catch
   ...
}

// En alguna parte del try:
if (...) {
  longjmp(excp,1); // throw
}
```

# Señales

Ejemplo con global:

```c
volatile int cont;
void ring() {
  cont = 0;
}

long long buscarFactor( . . . ) {
  uint k;
  cont = 1;
  void(*hdlr)() = signal(SIGALRM,ring);
  alarm(deltat); // usa el tiempo deltat en el cronometro
  for (k=1; k<= j && cont; k++) {
    if (x%k == 0)
      break;
  }
  alarm(0); // desactiva cronometro
  signal(SIGALRM,hdlr); // restaura la rutina
  . . .
}
```
**Con Jump**
```c
jmp_buf excp;
void ring() {
  longjmp(excp,1);
}

long long buscarFactor( . . . ) {
  uint k;
  cont = 1;
  void(*hdlr)() = signal(SIGALRM,ring);
  
  if (setjmp(excp) == 0) {
    alarm(deltat);
    for (k=1; k<= j && cont; k++) {
      if (x%k == 0)
        break;
    }
  }
  else {
  }
  alarm(0); // desactiva cronometro
  signal(SIGALRM,hdlr); // restaura la rutina
  . . .
}
```


-------

# Anexos

Leer

```c
int leer (int fd, void *buff, int n) {
  if (n == 0) 
    return 0;
  do {
    int rc = read(fd,buf,n);
    if (rc <= 0) 
      return 1;
    n -= rc;
    buf = (char*) buf + rc;
  } while (n > 0);
  return 0;
}