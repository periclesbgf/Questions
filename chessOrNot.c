/*  THE PROGRAM WILL REQUEST AN ARRAY 8X8 WITH THE EXACLY LOCATION OF THE PIECES AND WILL RETURN IF IT'S IN CHECK OR NOT
NOTE: use 'Q' CAPITAL LETTERS to white piece or 'q' for black   */

/*
P: WHITE PAWN
T: WHITE TOWER
C: WHITE HORSE
B: WHITE BISHOP
Q: WHITE QUEEN
k: WHITE KING

p: black PAWN
t: black TOWER
c: black HORSE
b: black BISHOP
q: black QUEEN
k: black KING

*/


/* matrix example:
t c b k q b c t
p p p p p p p p
- - - - - - - -
- - - - - - - -
- - - - - - - -
- - - - - - - -
P P P P P P P P
T C B Q K B C T

OUTPUT: NON CHECK

matrix example:
- - - - - - - -
- p p p p p p p
K - - - - - - -
- - - - - - - -
- - - - - - - -
- - - - - - - -
- - - - - - - -
- - - - - - - -

OUTPUT: CHECK
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LINHAS 8
#define COLUNAS 8

char matriz[LINHAS][COLUNAS];

//Functions declaration

int peao (char tipo, int locLinha, int locColuna);
int torre (char tipo, int locLinha, int locColuna);
int cavalo (char tipo, int locLinha, int locColuna);
int bispo (char tipo, int locLinha, int locColuna);
int rainha (char tipo, int locLinha, int locColuna);
int rei (char tipo, int locLinha, int locColuna);

int main(){

        int confirmar = 2;

        for (int i = 0; i < LINHAS; i++){
                for(int j = 0; j < COLUNAS; j++){
                        scanf(" %c", &matriz[i][j]);
                }
        }

        for (int i = 0; i < LINHAS; i++){
                for(int j = 0; j < COLUNAS; j++){
                        if (matriz[i][j] == 'p'){
                                if (peao(matriz[i][j], i, j) == 1){
                                        confirmar = 1;
                                        break;
                                }
                                else {
                                        confirmar = 0;
                                }
                        }
                        if (confirmar == 1){
                                break;
                        }
                        if (matriz[i][j] == 't'){
                                if (torre(matriz[i][j], i, j) == 1){
                                        confirmar = 1;
                                        break;
                                }
                                else {
                                        confirmar = 0;
                                }
                        }
                        if (confirmar == 1){
                                break;
                        }
                        if (matriz[i][j] == 'c'){
                                if (cavalo(matriz[i][j], i, j) == 1){
                                        confirmar = 1;
                                        break;
                                }
                                else {
                                        confirmar = 0;
                                }
                        }
                        if (confirmar == 1){
                                break;
                        }
                        if (matriz[i][j] == 'b'){
                                if (bispo(matriz[i][j], i, j) == 1){
                                        confirmar = 1;
                                        break;
                                }
                                else {
                                        confirmar = 0;
                                }
                        }
                        if (confirmar == 1){
                                break;
                        }
                        if (matriz[i][j] == 'q'){
                                if (rainha(matriz[i][j], i, j) == 1){
                                        confirmar = 1;
                                        break;
                                }
                                else {
                                        confirmar = 0;
                                }
                        }
                        if (confirmar == 1){
                                break;
                        }
                        if (matriz[i][j] == 'k'){
                                if (rainha(matriz[i][j], i, j) == 1){
                                        confirmar = 1;
                                        break;
                                }
                                else {
                                        confirmar = 0;
                                }
                        }
                        if (confirmar == 1){
                                break;
                        }
                }
                if(confirmar == 1){
                        break;
                }
        }
        if (confirmar == 1){
                printf("XEQUE");
        }else{
                printf("NAO XEQUE");
        }

return 0;
}

int peao (char tipo, int locLinha, int locColuna){
        if (isupper(tipo) != 0){
                if (matriz[locLinha-1][locColuna-1] == 'k' || matriz[locLinha][locColuna+1] == 'k'){
                        return 1;
                }
        }
        else if (isupper(tipo) == 0){
                if (matriz[locLinha+1][locColuna-1] == 'K' || matriz[locLinha+1][locColuna+1] == 'K'){
                        return 1;
                }
        }
        else {
                return 0;
        }
}

int torre (char tipo, int locLinha, int locColuna){
        int c = 0;
        if (isupper(tipo) == 0){
                for (int i = locLinha + 1; i <= LINHAS; i++){
                        if (matriz[i][locColuna] == 'K'){
                                return 1;
                        }
                        else if (isalpha(matriz[i][locColuna]) != 0){
                                break;
                        }
                }
                for (int i = locLinha - 1; i != -1; i--){
                        if (matriz[i][locColuna] == 'K'){
                                return 1;
                        }
                        else if (isalpha(matriz[i][locColuna]) != 0){
                                break;
                        }
                }
                for (int j = locColuna + 1; j <= COLUNAS; j++){
                        if (matriz[locLinha][j] == 'K'){
                                return 1;
                        }
                        else if (isalpha(matriz[locLinha][j]) != 0){
                                break;
                        }
                        else{
                                c = 0;
                        }
                }
                for (int j = locColuna - 1; j != -1; j--){
                        if (matriz[locLinha][j] == 'K'){
                                return 1;
                                break;
                        }
                        else if (isalpha(matriz[locLinha][j]) != 0){
                                break;
                        }
                        else{
                                c = 0;
                        }
                }
        }
        if (c == 0){
                return 0;
        }
}

int cavalo (char tipo, int locLinha, int locColuna){
        if (isupper(tipo) == 0){
                if (matriz[locLinha - 2][locColuna -1] == 'K' || matriz[locLinha -2][locColuna + 1] == 'K'){
                        return 1;
                }
                else if (matriz[locLinha - 1][locColuna + 2] == 'K' || matriz[locLinha + 1][locColuna + 2] == 'K'){
                        return 1;
                }
                else if (matriz[locLinha + 2][locColuna - 1] == 'K' || matriz[locLinha + 2][locColuna + 1] == 'K'){
                        return 1;
                }
                else if (matriz[locLinha - 1][locColuna - 2] == 'K' || matriz[locLinha + 1][locColuna - 2] == 'K'){
                        return 1;
                }
                else{
                        return 0;
                }
        }
}

int bispo (char tipo, int locLinha, int locColuna){
        int c = 0;
        int col = locColuna;
        if (isupper(tipo) == 1){
                for (int i = locLinha + 1; i <= LINHAS; i++){
                        col= locColuna + 1;
                        if (isalpha(matriz[i][col]) != 0 && matriz[i][col] == 'k'){
                                return 1;
                        }
                        else if (isalpha(matriz[i][col]) != 0){
                                break;
                        }
                        col++;
                }
                col = locColuna - 1;
                for (int i = locLinha + 1; i < LINHAS; i++){
                        if (isalpha(matriz[i][col]) != 0 && matriz[i][col] == 'k'){
                                return 1;
                        }
                        if (isalpha(matriz[i][col]) != 0){
                                break;
                        }
                        col--;
                }
                col = locColuna - 1;
                for (int i = locLinha - 1; i != -1; i--){
                        if (isalpha(matriz[i][col]) != 0 && matriz[i][col] == 'k'){
                                return 1;
                        }
                        if (isalpha(matriz[i][col]) != 0){
                                break;
                        }
                        col--;
                }
                col = locColuna + 1;
                for (int i = locLinha - 1; i != -1; i--){
                        if (isalpha(matriz[i][col]) != 0 && matriz[i][col] == 'k'){
                                return 1;
                        }
                        if (isalpha(matriz[i][col]) != 0){
                                break;
                        }
                        col++;
                }
        }
        if (isupper(tipo) == 0){
                col = locColuna + 1;
                for (int i = locLinha + 1; i <= LINHAS; i++){
                        if (matriz[i][col] == 'K'){
                                return 1;
                        }
                        else if (isalpha(matriz[i][col]) != 0){
                                break;
                        }
                        col++;
                }
                col = locColuna - 1;
                for (int i = locLinha + 1; i < LINHAS; i++){
                        if (isalpha(matriz[i][col]) != 0 && matriz[i][col] == 'K'){
                                return 1;
                        }
                        if (isalpha(matriz[i][col]) != 0){
                                break;
                        }
                        col--;
                }
                col = locColuna - 1;
                for (int i = locLinha - 1; i != -1; i--){
                        if (isalpha(matriz[i][col]) != 0 && matriz[i][col] == 'K'){
                                return 1;
                        }
                        if (isalpha(matriz[i][col]) != 0){
                                break;
                        }
                        col--;
                }
                col = locColuna + 1;
                for (int i = locLinha - 1; i != -1; i--){
                        if (isalpha(matriz[i][col]) != 0 && matriz[i][col] == 'K'){
                                return 1;
                        }
                        if (isalpha(matriz[i][col]) != 0){
                                break;
                        }
                        col++;
                }
        }
        if(c == 0){
                return 0;
        }
}

int rainha (char tipo, int locLinha, int locColuna){
        if (isupper(tipo) != 0){
                if (bispo('B', locLinha, locColuna) == 1 || torre('T', locLinha, locColuna) == 1){
                        return 1;
                }
                else {
                        return 0;
                }
        }
        if (isupper(tipo) == 0){
                if (bispo('b', locLinha, locColuna) == 1 || torre('t', locLinha, locColuna) == 1){
                        return 1;
                }
                else {
                        return 0;
                }
        }
        else {
                return 0;
        }
}

int rei (char tipo, int locLinha, int locColuna){
        if (isupper(tipo) != 0){
                if (matriz[locLinha - 1][locColuna - 1] == 'k' || matriz[locLinha - 1][locColuna] == 'k' || matriz[locLinha - 1][locColuna + 1] == 'k' || matriz[locLinha][locColuna - 1] == 'k' || matriz[locLinha][locColuna + 1] == 'k' || matriz[locLinha + 1][locColuna - 1] == 'k' || matriz[locLinha + 1][locColuna] == 'k' || matriz[locLinha + 1][locColuna + 1] == 'k'){
                        return 1;
                }
                else {
                        return 0;
                }
        }
        if (isupper(tipo) == 0){
                if (matriz[locLinha - 1][locColuna - 1] == 'K' || matriz[locLinha - 1][locColuna] == 'K' || matriz[locLinha - 1][locColuna + 1] == 'K' || matriz[locLinha][locColuna - 1] == 'K' || matriz[locLinha][locColuna + 1] == 'K' || matriz[locLinha + 1][locColuna - 1] == 'K' || matriz[locLinha + 1][locColuna] == 'K' || matriz[locLinha + 1][locColuna + 1] == 'K'){
                        return 1;
                }
        }
        else {
                return 0;
        }
}

