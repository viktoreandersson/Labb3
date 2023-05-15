#include "mbed.h"
#include <chrono>
using namespace std; 

SPISlave ser_port(p11, p12, p13, p14); 
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);


unsigned char switch_ord;
unsigned char read_ord;


void lampor(unsigned char pot){



    led1=!led1;
    ThisThread::sleep_for(chrono::milliseconds(pot));   
    led2=!led2;
    ThisThread::sleep_for(chrono::milliseconds(pot));   
    led3=!led3;
    ThisThread::sleep_for(chrono::milliseconds(pot));   
    led4=!led4;

}

// main() runs in its own thread in the OS
int main()
{


    led1=0;
    led2=0;
    led3=0;
    led4=0;
    
    

    ser_port.format(8,0); // Välj format 8 bitar (1 byte)
    ser_port.frequency(1000000); // Klockfrekvens
        while (true) {
            switch_ord=0xA0; //"ord" att skicka
            ThisThread::sleep_for(50ms);   
        if (ser_port.receive()){

            read_ord=ser_port.read();
            ser_port.reply(switch_ord);
        }

        lampor(read_ord); //Kalla på funktionen, för flexibiltet 

    }
}

