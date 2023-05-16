#include "mbed.h"

SPI ser_port(p11, p12, p13); 
DigitalOut Led1(LED1);
DigitalOut led2(LED2);
DigitalOut cs(p14);//Väljande av slav
AnalogIn pot(p19);
unsigned char switch_ord;
unsigned char read_ord;



// main() runs in its own thread in the OS
int main()
{
    

    ser_port.format(8,0); // Välj format 8 bitar (1 byte)
    ser_port.frequency(1000000); // Klockfrekvens
        while (true) {
           // switch_ord=0xA1; //"ord" att skicka
            ser_port.write(switch_ord);
            ThisThread::sleep_for(50ms);   

            potRead=(pot.read())*100; // För att läsa en potetiometer skicka istället
            switch_ord=int(potRead);

    }
}

