/*=======================================================================
  Esta biblioteca é para reversão do valor ADC, ideal para sensores ou
  dispositivos que retornam sinal analógico decrescente.

  Site  : https://elcereza.com/
   
  Autor : Gustavo Cereza
  Disponibilizado por : Elcereza
  Redes : @ellcereza
  Canal Telegram: https://t.me/elcereza
=======================================================================*/

#include "Elcereza_ADCr.h"

ADCr adc(false);                                                       // Desabilita configuração avançada
/*ADCr adc(true, 10);                                                     Habilita configuração avançada e define a resolução ADC de 10bits
                                                                          a resolução pode ser tanto o valor em bits como o valor resultante
                                                                          da exponênciação, como por exemplo: 1024
                                                                       */

void setup() {
  Serial.begin(115200);
  pinMode(A1, INPUT);
}

void loop() {
  int a = analogRead(A1);
  Serial.println(String(a) + " " + String(adc.reverse(a)));            // Comparativo entre o valor lido do ADC com o valor reverso do ADC
  delay(500);
}
