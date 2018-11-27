pwm_hw_c_mp.c
No início desta semana
30 de out
L
Leonardo Maezato moveu um item para
Pasta do Google Drive
30.10
C
pwm_hw_c_mp.c
30 de out

Frederico Alves de Oliveira Silva fez o upload de 1 item
C
pwm_hw_c_mp.c
/** Programa baseado no codigo disponibilizado em:
* Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
* Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/
*/

// Ajustando o PWM por HARDWARE na Raspberry Pi

#include <stdio.h>
#include <wiringPi.h>

#define pino_PWM0 18                    // o PWM sera acionado na GPIO18

int main() {                            // este programa deve ser rodado com 'sudo'
   int dc, ciclos;
   wiringPiSetupGpio();                 // usa a numeracao da GPIO
   pinMode(pino_PWM0, PWM_OUTPUT);      // configura a GPIO18 com o PWM por hardware

   // Ajustando a frequencia do PWM em 261,6Hz com 798 passos de duty cycle
   // frequencia PWM = 19,2 MHz / (divisor * range)
   // 261,6 = 19200000 / (divisor * 798) => divisor = 92

   pwmSetMode(PWM_MODE_MS);             // usando frequencia fixa
   pwmSetRange(798);                    // passos do duty cycle (max=4096)
   pwmSetClock(92);                     // fornece uma frequencia de 261,6Hz (max=4096)
   printf("Iniciando alarme de media prioridade...\n");
   int tsom = 500000;
   int tnsom = 200000;


   for(ciclos = 0; ciclos < 3; ciclos++){  // variando o duty cycle
         dc = 798/2;
         pwmWrite(pino_PWM0, dc);
         usleep(tsom);
         dc = 0;
         pwmWrite(pino_PWM0, dc);
         usleep(tnsom);
   }
   
   printf("Fim.\n");
   return 0;                            // a saida PWM permanece ligada apos o termino do programa
}