#include <avr/io.h>
#include <util/delay.h>

int main (void)
{
    DDRD = 0b00000000;       //Set DDRD as input part
    PORTD = 0b11111111;      // Pull up DDRD Pins
    DDRB = 0b11111111;       // Set DDRB as output part
    DDRA = 0b11111111;      // Set DDRA as output part
    
    int c;
    
    while(1)
    {
        c = PIND;
        if (c == 0b11111100)        //If both sensors are low, go straight
        {
            PORTB = 0b00001010;
            PORTA = 0b00000000;
        }
        else if (c == 0b11111111)
        {
            PORTB = 0b00001010;
            PORTA = 0b00000100;
        }
        else if (c == 0b11111110)            //If left sensor is high, turn left (left motor - rev, right motor - fwd)
        {
            PORTB = 0b00000110;
            PORTA = 0b00000010;
            
        }
        else if (c == 0b11111101)         //If right sensor is high, turn right (left motor - fwd, right motor - rev)
        {
            PORTB = 0b00001001;
            PORTA = 0b00000001;
        }

    }
    
}
