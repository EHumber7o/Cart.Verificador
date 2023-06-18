#include <stdio.h>
#include <stdlib.h>

int main(void) {
  
  unsigned long int i, num_cart, soma, tam, somaf = 0, somas = 0, num_temp, temp, tam_d;
  
  do {
    tam_d = 0;
    printf("Digite o seu cartão: ");  
    scanf("%ld",&num_cart);
    num_temp = num_cart;
    for( i = 10; ; i *= 10){
      tam_d++;
      if((num_cart/i) == 0) {
        tam = i;
        break;
      }
    }
    for(i = 1; num_temp > 0; i++){
      if(i%2 == 0) {
        if (num_temp%10 < 5) somaf += 2 * (num_temp%10);
        else somaf+= ((2 * (num_temp%10))%10) + 1;
      }
      else somas += (num_temp%10);
      num_temp = num_temp/10;
    }
    soma = somas + somaf;
    if(soma%10 != 0) printf("Cartão Inválido.\nDigite Novamente!\n");
  } while (soma%10 != 0);
  tam/=10;
  if (tam_d > 12 && tam_d < 17) {
    if (num_cart/tam == 4 && (tam_d == 13 || tam_d == 16)) printf("Bandeira: Visa\n");
    else {
      tam/=10;
      if(tam_d==15 && ((num_cart/tam) == 34 || (num_cart/tam) == 37)) printf("Bandeira: American Express\n");
      else if(tam_d == 16 && ((num_cart/tam) >= 51 && (num_cart/tam) <= 55)) printf("Bandeira: Mastercard\n");
      else printf("Bandeira não encontrada.\n");
    }
  }
  else printf("Bandeira Inválida.\n");
  return 0;
}
