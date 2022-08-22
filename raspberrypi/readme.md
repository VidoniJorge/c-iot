## config de red

abrimos el archivo 

    sudo nano /etc/wpa_supplicant/wpa_supplicant.conf

agregamos la siguiente configuración

``` json
    network = {
        ssid="mi nombre identificaros"
        psk="password"
        key_mgmt=WPA-PSK
    }
```

## ssh


    sudo raspi-config

Interdaciong Options --> SSH --> Yes --> Ok
Localisation Options --> change timesone -> argentina
hostname --> ok --> ______ --> ok

```
    sudo reboot -h now
```

``` 
    ssh pi@<ip.raspberrypi>
```


https://www.youtube.com/watch?v=0g7sazWXfEI
https://github.com/esp8266/arduino

https://github.com/esp8266/Arduino/blob/2.5.2/variants/d1_mini/pins_arduino.h#L37-L45
https://www.luisllamas.es/como-conectar-un-esp8266-a-una-red-wifi-modo-sta/
https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/readme.html


---

Torque: Momento de fuerza o capacidad de aplicar una fuerza a un punto rígido o cuerpo pesado.

RPM: Revoluciones por minuto, número de vueltas por minuto que puede dar un motor.

Voltaje: Cantidad de voltios que necesita un dispositivo para funcionar. Diferencia de potencial es la presión necesaria para provocar el flujo de corriente o electrones, se mide en Voltios (V).

Corriente: Cantidad de electricidad, es el flujo de electrones en un material conductor, se mide en amperios (A).

Amperaje: Valor de la corriente en algún dispositivo.

Resistencia: Oposición al flujo eléctrico en un conductor.

PLC: Programmable Logic Controller, dispositivo electrónico o computadora digital de tipo industrial para automatización de procesos en la industria.

RTU: Remote Terminal Unit, dispositivo basado en microprocesador, obtiene señales independientes y envía la misma a salas de control o PLC.

SBC: Single Board Computer, es una computadora completa en un solo circuito, tiene un microprocesador, RAM, I/O, conexión a pantalla, puertos USB y todo lo demás necesario para ser un computador funcional.

I/O: Inputs/Outputs, también conocido como E/S Entradas/Salidas, son los puertos usados para actuar o adquirir información en boards de desarrollo de hardware.

PCB: Printed Circuit Board, o Placa de circuito impreso, es una superficie diseñada y construida con caminos, pistas o buses de algún material conductor que permite comunicar dispositivos y minimizar el espacio de uso de los controladores en diseños específicos. Se pueden construir manualmente o tercerizar su desarrollo.

SoC: System on a Chip, desarrollo de controladores/procesadores que integren todo lo necesario para construir y acceder a un sistema completo en su board.

Bus de datos: Es un sistema que se encarga de transferir datos entre componentes digitales.

BIOS: Basic Input/Output System, es un software que es capaz de localizar y reconocer todos los dispositivos necesarios y conectados a un computador para el inicio de su sistema operativo.

WiFi: Tecnología de comunicación inalámbrica que permite conectar dispositivos a internet.

Bluetooth: Es una especificación en redes inalámbricas que permite transmisión de voz y datos entre diferentes dispositivos, mediante la radiofrecuencia segura de 2.4 GHz.

I2C: Es un puerto y protocolo de comunicación serial que define la trama de datos y conexiones físicas para transferir con dos conexiones, SDA y SCL.

SDA: Serial Data, puerto del protocolo de comunicación I2C.

SCL: Serial Clock, puerto del protocolo de comunicación I2C.

SPI: Serial Peripheral Interface, es un estandar de comunicaciones entre circuitos integrados. Cuenta con los puertos SCLK (Clock), MOSI (Master Output, Slave Input), MISO (Master Input, Slave Output), SS/Select (Selection).

RX: Receptor de señal.

TX: Transmisor de señal.