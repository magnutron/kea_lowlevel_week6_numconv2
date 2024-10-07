#ifndef NUMCONV2_H
#define NUMCONV2_H

void num_ui();
int dec_to_int( char str[] ); // - der modtager en streng i decimal og returnerer en int
int bin_to_int( char str[] ); // - der modtager en streng i binær og returnerer en int
int hex_to_int( char str[] ); // - der modtager en streng i hexadecimal og returnerer en int
int oct_to_int( char str[] ); // - der modtager en streng i octal og returnerer en int
void int_to_dec( int num, char str[] ); // - der modtager en int og returnerer en streng i decimal
void int_to_bin( int num, char str[] ); // - der modtager en int og returnerer en streng i binær
void int_to_hex( int num, char str[] ); // - der modtager en int og returnerer en streng i hexadecimal
void int_to_oct( int num, char str[] ); // - der modtager en int og returnerer en streng i octal

#endif // NUMCONV2_H