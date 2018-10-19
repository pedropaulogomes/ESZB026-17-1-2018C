#!/bin/bash

# ESZB026-17-1 - Script em BASH sessão 4.1 Bash Shell (lab02)

LED_GPIO=[16,20,21]

# funcoes Bash

function setLED
{   # $1 eh o primeiro argumento passado para a funcao
	echo $1 >> "/sys/class/gpio/gpio$LED_GPIO/value"
}

# Inicio do programa
for cont in {1..5} 
do
    for LED_GPIO in 20 21 16 
    do
	    
		if [ $LED_GPIO -eq 20 ]; then #LED vermelho
			    echo "Habilitando a GPIO numero $LED_GPIO"
			    echo $LED_GPIO >> "/sys/class/gpio/export"
			    sleep 1                        # esperar 1 segundo para garantir que a gpio foi exportada
			    echo "out" >> "/sys/class/gpio/gpio$LED_GPIO/direction"
			    
			    #Acende o LED
			    echo "Acendendo o LED $LED_GPIO"
			    setLED 1                       # 1 eh recebido como $1 na funcao setLED
			    sleep 2                         # espera-se 2s
			    
			    #Apaga o LED
			    echo "Apagando o LED $LED_GPIO"
			    setLED 0
			    
			    #Desabilita a GPIO
			    echo "Desabilitando a GPIO numero $LED_GPIO"
			    echo $LED_GPIO >> "/sys/class/gpio/unexport"
		elif [ $LED_GPIO -eq 21 ]; then #LED verde
			    echo "Habilitando a GPIO numero $LED_GPIO"
			    echo $LED_GPIO >> "/sys/class/gpio/export"
			    sleep 1                        # esperar 1 segundo para garantir que a gpio foi exportada
			    echo "out" >> "/sys/class/gpio/gpio$LED_GPIO/direction"
			    
			    #Acende o LED
			    echo "Acendendo o LED $LED_GPIO"
			    setLED 1                       # 1 eh recebido como $1 na funcao setLED
			    sleep 1                         # espera-se 1s
			    
			    #Apaga o LED
			    echo "Apagando o LED $LED_GPIO"
			    setLED 0
			    
			    #Desabilita a GPIO
			    echo "Desabilitando a GPIO numero $LED_GPIO"
			    echo $LED_GPIO >> "/sys/class/gpio/unexport"
		else #LED amarelo
			    echo "Habilitando a GPIO numero $LED_GPIO"
			    echo $LED_GPIO >> "/sys/class/gpio/export"
			    sleep 1                        # esperar 1 segundo para garantir que a gpio foi exportada
			    echo "out" >> "/sys/class/gpio/gpio$LED_GPIO/direction"
			    
			    #Acende o LED
			    echo "Acendendo o LED $LED_GPIO"
			    setLED 1                       # 1 eh recebido como $1 na funcao setLED
			    sleep 1                         # espera-se 1s
			    
			    #Apaga o LED
			    echo "Apagando o LED $LED_GPIO"
			    setLED 0
			    
			    #Desabilita a GPIO
			    echo "Desabilitando a GPIO numero $LED_GPIO"
			    echo $LED_GPIO >> "/sys/class/gpio/unexport"
		fi
		    
	    
    done
done
