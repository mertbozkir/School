#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

//Öncelikle tanýmlanmasý gereken deðiþkenler

//bigram ve trigram deðerleri
const char matrix_bigram_strings[10][3] ={"th", "he", "in", "er", "an", "en", "ch", "de", "ei", "te"};

const char matrix_trigram_strings[10][4]={"the", "and", "ing", "ent", "ion", "der", "sch", "ich", "nde", "die"};


//dillerin bulunduðu dizi
const char languages[2][8]={"english", "german"};


//Ýngilizce dilinin frekans deðerleri
 const float frequency_eng[20]={ 2.71, 2.33, 2.03, 1.78, 1.61, 1.13, 0.01, 0.01, 0.01, 0.01, 1.81, 0.73, 0.72, 0.42, 0.42, 0.01, 0.01, 0.01, 0.01, 0.01 };
 //Almanca dilinin frekans deðerleri
 const float frequency_germ[20]={ 0.01, 0.89, 1.71, 3.90, 1.07, 3.61, 2.36, 2.31, 1.98, 1.98, 0.01, 0.01, 0.01, 0.01, 0.01, 1.04, 0.76, 0.75, 0.72, 0.62 };


float calculated_frequencies[20];
float distances [2]={0,0};


void filter_str(char str[]);
void calculate_frequencies_bi(char str[]);
void calculate_frequencies_tri(char str[]);
void calculate_distances();
void detect_lang();

int main()
{
	char yazi[200];

    printf("Herhangi bir yazi giriniz: \n") ;
    gets(yazi) ;

    filter_str(yazi);
    calculate_frequencies_bi(yazi);
    calculate_frequencies_tri(yazi);
    calculate_distances();
    detect_lang();

    printf("\n\n\n\nProje sahipleri => Mert Bozkir ve Enes Tektas");

	return 0;

}

void filter_str(char str[]){
    char ascii_control[61] ;
    int s = 0 ;
    for(char x = 'A'; x <= 'Z';x++){
        ascii_control[s] = x ;
        s++;
    }
    for(char y = 'a'; y <= 'z';y++){
        ascii_control[s] = y ;
        s++ ;
    }
    ascii_control[s] = ' ' ;

    for(int i = 0,j;i < strlen(str);i++){

        for(j = 0;j < s + 1;j++){
            if(str[i] == ascii_control[j]){
                break;
            }
        }
        if(j == (s + 1)){
            str[i] = ' ' ;
        }

    }

    printf("Filtreli yazi(Bazi karakterler silindikten sonra):\n\n\n");
    printf(str);





}
void calculate_frequencies_bi(char str[]){

char control[3], text_div[3];
float sayac = 0.0 ;

for(int i = 0,c = 0;i < 10;i++){
    for(int j = 0;j < 2;j++){
        control[j] = matrix_bigram_strings[i][j] ;
    }
    control[2] = '\0' ;
    sayac = 0.0 ;
    c = 0 ;
    while(c != strlen(str)-1){
        for(int m = 0;m < 2;m++){
            text_div[m] = str[c] ;
            c++ ;
        }
        text_div[2] = '\0' ;
        c -= 1 ;

        if(strcmp(text_div, control) == 0){
            sayac++ ;
        }
    }

    calculated_frequencies[i] = sayac ;

}

printf("\n\n\n") ;
printf("Bigramlarýn frekanslarý :\n\n\n") ;



for(int i = 0;i < 10;i++){
   printf(" %.2f, ",calculated_frequencies[i]) ;
}


}


void calculate_frequencies_tri(char str[]){
printf("\n") ;
char control[4], text_div[4];
float sayac = 0.0 ;

for(int i = 0,c = 0;i < 10;i++){
    for(int j = 0;j < 3;j++){
        control[j] = matrix_trigram_strings[i][j] ;
    }
    control[3] = '\0' ;
    sayac = 0.0 ;
    c = 0 ;
    while(c != strlen(str)-2){
        for(int m = 0;m < 3;m++){
            text_div[m] = str[c] ;
            c++ ;
        }
        text_div[3] = '\0' ;
        c -= 2 ;

        if(strcmp(text_div,control) == 0){
            sayac++ ;
        }
    }

    calculated_frequencies[i + 10] = sayac ;

}
printf("\n\n - -- - - - - -- - - - - -- - - -- - - - - -- - \n\n") ;
printf("The trigram's frequencies :\n\t\n") ;
for(int i = 10;i < 20;i++){
   printf(" %.2f, ",calculated_frequencies[i]) ;
}
}


void calculate_distances(){
    float sum = 0.0 ;

    printf("\n\n\n\n") ;
    printf("oklid hesaplamasina gore uzaklik:\n") ;

    for(int i = 0;i < 20;i++){
        sum += pow((calculated_frequencies[i] - frequency_eng[i]),2) ;
    }

    distances[0] = sqrt(sum) ;
    printf("\n Bu yazinin ingilizce diline uzakligi ") ;
    printf("%f\n",distances[0]) ;

    sum = 0.0 ;
    for(int i = 0;i < 20;i++){
        sum += pow((calculated_frequencies[i] - frequency_germ[i]),2) ;
    }

    distances[1] = sqrt(sum) ;
    printf("\n Bu yazinin almanca diline uzakligi:") ;
    printf("%f\n\n\n\n",distances[1]) ;

}


void detect_lang(){

 printf("Sonuc:\n\n") ;
 if(distances[0] < distances[1]){
    printf("Yazinin dili  %s.",languages[0]) ;
 }
 else
    {
    printf("Yazinin dili %s",languages[1]) ;
 } }


