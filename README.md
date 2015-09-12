# Сигнализация для магазина, офиса, дома

Как это работает?

В случае обнаружения нежелательного проникновения в охраняемое помещение, 
сигнализация оповещает вас письмом на email и звонком на мобильный телефон.

Управление сигнализацией осуществляется с сайта 
[makridenkov.ru/signals](http://signals.makridenkov.com/).

Подробнее о сигнализации по [ссылке](http://signals.makridenkov.com/).

## Железо
Железо, аппаратная часть, сигнализации реализованы на платформе Arduino UNO [купить](http://www.buyincoins.com/details/high-quality-arduino-uno-atmega328p-pu-module-atmega8u2-avr-usb-cable-board-product-10252.html).

Датчики движения - стандартные для Arduino [купить](http://www.buyincoins.com/details/pyroelectric-infrared-pir-motion-sensor-detector-module-product-7078.html).

Для соединения Arduino с интернетом используется Ethernet shield w5100 [купить](http://www.ebay.com/sch/?_kw=Ethernet%20shield%20W5100&_clu=2&_fcid=56&_localstpos=&_sc=1&_sop=15&_stpos=&gbr=1).


Принципиальная электрическая схема в файле [shema.png](https://github.com/SergXIIIth/signals/blob/master/shema.png)

Программа для Arduino в файле [arduino.ino](https://github.com/SergXIIIth/signals/blob/master/arduino.ino)
