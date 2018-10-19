//teste em c - acende LED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define GPIO_PATH16 "/sys/class/gpio/gpio16/"
#define GPIO_PATH20 "/sys/class/gpio/gpio20/"
#define GPIO_PATH21 "/sys/class/gpio/gpio21/"
#define GPIO_SYSFS  "/sys/class/gpio/"

void writeGPIO(char filename[], char value[]){
   FILE* fp;                           // cria um ponteiro fp
   fp = fopen(filename, "w+");         // abre o arquivo para escrita
   fprintf(fp, "%s", value);           // grava o valor no arquivo
   fclose(fp);                         // fecha o arquivo
}

// inicio do programa
int main(int argc, char* argv[]){

char *GPIO_NUMBER[] =  {"20", "21","16"};
int cont;
int max = 2;
int k;
int max2 = 4;

printf("Iniciando o programa em C para alterar a gpio.\n");


    for (k=0;k<=max2;k++)
    {
        for (cont=0;cont<=max;cont++)
        {

            if (GPIO_NUMBER[cont] == "20")
            {        

                // Habilita a GPIO 20
                printf("Habilitando a gpio, %s \n",GPIO_NUMBER[cont]);
                writeGPIO(GPIO_SYSFS "export", GPIO_NUMBER[cont]);
                usleep(100000);                  // aguarda 100ms
                writeGPIO(GPIO_PATH20 "direction", "out");

                // ACENDE O LED
                printf("Acendendo o LED %s \n",GPIO_NUMBER[cont]);
                writeGPIO(GPIO_PATH20 "value", "1");
                usleep(2000000);                  // aguarda 2s
                
                // APAGA O LED
                printf("Desligando o LED %s \n",GPIO_NUMBER[cont]);
                writeGPIO(GPIO_PATH20 "value", "0");

                // DESABILITA A GPIO
                printf("Desabilitando a gpio %s \n",GPIO_NUMBER[cont]);
                writeGPIO(GPIO_SYSFS "unexport", GPIO_NUMBER[cont]);

            }
            else if (GPIO_NUMBER[cont] == "21")
            {    

                // Habilita a GPIO 21
                printf("Habilitando a gpio %s \n",GPIO_NUMBER[cont]);
                writeGPIO(GPIO_SYSFS "export", GPIO_NUMBER[cont]);
                usleep(100000);                  // aguarda 100ms
                writeGPIO(GPIO_PATH21 "direction", "out");

                // ACENDE O LED
                printf("Acendendo o LED %s \n",GPIO_NUMBER[cont]);
                writeGPIO(GPIO_PATH21 "value", "1");
                usleep(1000000);                  // aguarda 1s

                // APAGA O LED
                printf("Desligando o LED %s \n",GPIO_NUMBER[cont]);
                writeGPIO(GPIO_PATH21 "value", "0");

                // DESABILITA A GPIO
                printf("Desabilitando a gpio %s \n",GPIO_NUMBER[cont]);
                writeGPIO(GPIO_SYSFS "unexport", GPIO_NUMBER[cont]);

            } 
            else 
            {

                // Habilita a GPIO 16
                printf("Habilitando a gpio %s \n",GPIO_NUMBER[cont]);
                writeGPIO(GPIO_SYSFS "export", GPIO_NUMBER[cont]);
                usleep(100000);                  // aguarda 100ms
                writeGPIO(GPIO_PATH16 "direction", "out");

                // ACENDE O LED
                printf("Acendendo o LED %s \n",GPIO_NUMBER[cont]);
                writeGPIO(GPIO_PATH16 "value", "1");
                usleep(1000000);                  // aguarda 1s

                // APAGA O LED
                printf("Desligando o LED %s \n",GPIO_NUMBER[cont]);
                writeGPIO(GPIO_PATH16 "value", "0");

                // DESABILITA A GPIO
                printf("Desabilitando a gpio %s \n",GPIO_NUMBER[cont]);
                writeGPIO(GPIO_SYSFS "unexport", GPIO_NUMBER[cont]);
            }
        
        }
    }
        printf("Fim do programa em C.\n");
        return 0;
}

