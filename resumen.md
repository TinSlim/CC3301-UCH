# Resumen C1

## Tipos

### Tipos Primitivos

- Enteros con signo: char, short, int, long int, long long int.
- Sin signo: unsigned ...
- Reales: float, double.
- Punteros: int*, float*.

### Binario

- Base 8 usa prefijo 0, ejemplo: 013.
- Base 16 usa prefijo 0x, ejemplo: 0x13. No olvidar que {a:10, b:11, c:12, d:13, e:14, f:15} 
- Base 2 usa prefijo 0b, ejemplo 0b

### Bits

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
- 8 bit = [ 0 , (2^64)]