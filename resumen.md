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