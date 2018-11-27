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

   // Ajustando a frequencia do PWM em 1kHz com 192 passos de duty cycle
   // frequencia PWM = 19,2 MHz / (divisor * range)
   // 1000 = 19200000 / (divisor * 192) => divisor = 100

   pwmSetMode(PWM_MODE_MS);             // usando frequencia fixa
   pwmSetRange(192);                    // passos do duty cycle (max=4096)
   pwmSetClock(100);                     // fornece uma frequencia de 1kHz (max=4096)
   printf("...\n");

   int umseg = 1000000;

     for(ciclos = 54; ciclos < 58; ciclos++){  // variando o duty cycle
         dc = ciclos;
         pwmWrite(pino_PWM0, dc);
         printf("Duty cycle: %d", dc);
	 usleep(3*umseg);
	 printf("\n");
     }
   
   pwmWrite(pino_PWM0, 0);
   printf("Fim.\n");
   return 0;                            // a saida PWM permanece ligada apos o termino do programa
}
