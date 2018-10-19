#!/usr/bin/python3

# ESZB026-17-1 - Script em BASH sessão 4.1 Bash Shell (lab02)

import sys
from time import sleep
LED_PATH16 = "/sys/class/gpio/gpio16/"
LED_PATH20 = "/sys/class/gpio/gpio20/"
LED_PATH21 = "/sys/class/gpio/gpio21/"
SYSFS_DIR = "/sys/class/gpio/"

def writeLED ( filename, value, path ):
	"Esta funcao escreve o valor 'value' no arquivo 'path+filename'"
	fo = open( path + filename,"w")
	fo.write(value)
	fo.close()
	return

# inicio do programa
for cont in range(0,5):
    for LED_NUMBER in ["20","21","16"]:
        if LED_NUMBER == "20": # LED VERMELHO
            # HABILITA O LED    
            print("Habilitando a gpio " + LED_NUMBER)
            writeLED ( filename="export", value=LED_NUMBER, path=SYSFS_DIR )
            sleep(0.1)
            writeLED ( filename="direction", value="out", path=LED_PATH20 )
            
            # ACENDE O LED
            print("Acendendo o LED " + LED_NUMBER)
            writeLED (filename="value", value="1", path=LED_PATH20)
            sleep(2)            

            # APAGA O LED
            print("Desligando o LED " + LED_NUMBER)
            writeLED (filename="value", value="0", path=LED_PATH20)

            # DESABILITA O LED    
            print("Desabilitando a gpio " + LED_NUMBER)
            writeLED (filename="unexport", value=LED_NUMBER, path=SYSFS_DIR)
        elif LED_NUMBER == "21": # LED VERDE
            # HABILITA O LED
            print("Habilitando a gpio " + LED_NUMBER)
            writeLED (filename="export", value=LED_NUMBER, path=SYSFS_DIR)
            sleep(0.1)
            writeLED (filename="direction", value="out", path=LED_PATH21)
            
            # ACENDE O LED
            print("Acendendo o LED " + LED_NUMBER)
            writeLED (filename="value", value="1", path=LED_PATH21)
            sleep(1)

            # APAGA O LED
            print("Desligando o LED " + LED_NUMBER)
            writeLED (filename="value", value="0", path=LED_PATH21)

            # DESABILITA O LED
            print("Desabilitando a gpio " + LED_NUMBER)
            writeLED (filename="unexport", value=LED_NUMBER, path=SYSFS_DIR)

        else: # LED AMARELO
            # HABILITA O LED
            print("Habilitando a gpio " + LED_NUMBER)
            writeLED (filename="export", value=LED_NUMBER, path=SYSFS_DIR)
            sleep(0.1)
            writeLED (filename="direction", value="out", path=LED_PATH16)

            # ACENDE O LED
            print("Acendendo o LED " + LED_NUMBER)
            writeLED (filename="value", value="1", path=LED_PATH16)
            sleep(1)

            # APAGA O LED
            print("Desligando o LED " + LED_NUMBER)
            writeLED (filename="value", value="0", path=LED_PATH16)

            # DESABILITA O LED
            print("Desabilitando a gpio " + LED_NUMBER)
            writeLED (filename="unexport", value=LED_NUMBER, path=SYSFS_DIR)




