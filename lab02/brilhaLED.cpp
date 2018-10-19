// ESZB026-17-1 - Script em BASH sessão 4.1 Bash Shell (lab02)

#include<iostream>
#include<fstream>
#include<string>
#include<unistd.h>
using namespace std;


#define GPIO_PATH16 "/sys/class/gpio/gpio16/"
#define GPIO_PATH20 "/sys/class/gpio/gpio20/"
#define GPIO_PATH21 "/sys/class/gpio/gpio21/"
#define GPIO_SYSFS "/sys/class/gpio/"

void writeGPIO(string path, string filename, string value){
   fstream fs;
   fs.open((path + filename).c_str(), fstream::out);
   fs << value;
   fs.close();
}

int main(int argc, char* argv[]){

char *GPIO_NUMBER[] = {"20","21","16"};
int cont;
int cont2;
int max = 2;
int max2 = 4;

    cout << "Iniciando o programa em C++ para alterar as gpios. " << endl;

for (cont2=0;cont2<=max2;cont2++){
    for (cont = 0; cont<= max;cont++){
    
        if (GPIO_NUMBER[cont] == "20")
        {
            // HABILITANDO A GPIO20
            cout << "Habilitando a gpio " << GPIO_NUMBER[cont] << endl;
            writeGPIO(string(GPIO_SYSFS), "export", GPIO_NUMBER[cont]);
            usleep(100000);
            writeGPIO(string(GPIO_PATH20), "direction", "out");

            // ACENDENDO O LED
            cout << "Acendendo o LED " << GPIO_NUMBER[cont] << endl;
            writeGPIO(string(GPIO_PATH20), "value", "1");
            usleep(2000000);            // 2s
            // APAGANDO O LED
            cout << "Desligando o LED " << GPIO_NUMBER[cont] << endl;
            writeGPIO(string(GPIO_PATH20), "value", "0");
            
            // DESABILITANDO O LED
            cout << "Desabilitando a gpio " << GPIO_NUMBER[cont] << endl;
            writeGPIO(string(GPIO_SYSFS), "unexport", GPIO_NUMBER[cont]);
        }
        else if (GPIO_NUMBER[cont] == "21")
        {

            // HABILITANDO A GPIO21
            cout << "Habilitando a gpio " << GPIO_NUMBER[cont] << endl;
            writeGPIO(string(GPIO_SYSFS), "export", GPIO_NUMBER[cont]);
            usleep(100000);
            writeGPIO(string(GPIO_PATH21), "direction", "out");

            // ACENDENDO O LED
            cout << "Acendendo o LED " << GPIO_NUMBER[cont] << endl;
            writeGPIO(string(GPIO_PATH21), "value", "1");
            usleep(1000000);            // 1s

            // APAGANDO O LED
            cout << "Desligando o LED " << GPIO_NUMBER[cont] << endl;
            writeGPIO(string(GPIO_PATH21), "value", "0");
            
            // DESABILITANDO O LED
            cout << "Desabilitando a gpio " << GPIO_NUMBER[cont] << endl;
            writeGPIO(string(GPIO_SYSFS), "unexport", GPIO_NUMBER[cont]);
        }
        else
        {

            // HABILITANDO A GPIO16
            cout << "Habilitando a gpio " << GPIO_NUMBER[cont] << endl;
            writeGPIO(string(GPIO_SYSFS), "export", GPIO_NUMBER[cont]);
            usleep(100000);
            writeGPIO(string(GPIO_PATH16), "direction", "out");

            // ACENDENDO O LED
            cout << "Acendendo o LED " << GPIO_NUMBER[cont] << endl;
            writeGPIO(string(GPIO_PATH16), "value", "1");
            usleep(1000000);            // 1s

            // APAGANDO O LED
            cout << "Desligando o LED " << GPIO_NUMBER[cont] << endl;
            writeGPIO(string(GPIO_PATH16), "value", "0");
            
            // DESABILITANDO O LED
            cout << "Desabilitando a gpio " << GPIO_NUMBER[cont] << endl;
            writeGPIO(string(GPIO_SYSFS), "unexport", GPIO_NUMBER[cont]);
        }
    }
}
    cout << "Fim do programa em C++." << endl;
    return 0;
}
