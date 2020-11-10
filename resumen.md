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

  
  