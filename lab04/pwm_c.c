#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>
#include<string.h>
#include<termios.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int file, count, valor;
	if ((file = open("/dev/ttyACM0", O_RDWR | O_NOCTTY | O_NDELAY))<0){
		perror("Falha ao abrir o arquivo.\n");
		return -1;
	}
	struct termios options;
	tcgetattr(file, &options);
	options.c_cflag = B115200 | CS8 | CREAD | CLOCAL;
	options.c_iflag = IGNPAR | ICRNL;
	tcflush(file, TCIFLUSH);
	tcsetattr(file, TCSANOW, &options);
    	usleep(100000);
	int pino_PWM = 23;                         // pwm por software na GPIO23
	int brilho;				   // brilho == valor
	int range = 100;                           // periodo do PWM = 100us*range
	wiringPiSetupGpio();                       // usar a numeracao GPIO, nao WPi
	pinMode(pino_PWM,OUTPUT);	           // configura GPIO23 como saida
	softPwmCreate(pino_PWM, 1, range);         // inicializa PWM por software
	unsigned char receive[100];
	while (1) {
		   if ((count = read(file, (void*)receive, 100))<0){
		      perror("Falha ao ler da entrada.\n");
		      return -1;
		   }
		   if (count>0){
                           receive[count]=0;
			   printf("%s\n",receive);
	         	   if(strncmp(receive,"Valor correspondente: ",22)==0){
		         	   sscanf(receive,"%*s %*s %d",&brilho);
				   if(brilho>=0 && brilho<1024){
					   brilho = (brilho*100.0)/1023.0;
					   printf("Valor ajustado: %d\n",brilho);
					   softPwmWrite (pino_PWM, brilho);
					   
				   }
			   }
		   }
		   delay (50) ;
		   
		}





		//for (brilho = 0; brilho < range; brilho++) {
		  //softPwmWrite (pino_PWM, brilho); // altera o duty cycle do PWM
		  //delay (10) ;                     // aguarda 10ms
                //}
		//for (brilho = range; brilho > 0; brilho--) {
		  //softPwmWrite (pino_PWM, brilho);
		 // delay (10);
		//}
	
}
