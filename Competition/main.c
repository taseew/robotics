//
//  ObstacleAvoider.c
//  MCLineFollower
//
//
//

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

void takeReverse(void);
void goForward(void);
void turnLeft(void);
void turnRight(void);
void lngDelay(void);
void srtDelay(void);
void soundBuzzer(void);
void adjustSpeed(void);
void soundBuzzerandStop (void);

int main(void){
    
    DDRD = 0b00000000;   //setting part D as input part
    DDRB = 0b11111111;   //setting part B as output part
    PORTD = 0b11111111;  //pulling up part D
    int leftSensor = 0b11110001;   //Left: PD0 (pin 14)
    int rightSensor = 0b11110010;  //Right: PD1 (pin 15)
    int topSensor = 0b11110100; //Top: PD2 (pin 16)
    int frontSensor = 0b11111000;  //Front: PD3 (pin 17)
    
    int c;
    
    while(1){
        c = PIND;

        if (c == 0b11111100){   // L,R,T sensors low; Front high: No obstacle, no black line encountered
            goForward();
        }

        if (c == 0b11111101){   // L sensor high; R,T sensors low; turn Left
            turnLeft();
        }

        if (c == 0b11111110){   // R sensor high; L,T sensors low; turn Right
            turnRight();
        }

        if (c == 0b11111111){   // R sensor high; L,T sensors low; turn Right
            soundBuzzer();
            goForward();
        }
        
        if ((c == 0b11110000) | (c == 0b11110001)|(c == 0b11110010)|(c == 0b11110100)|(c == 0b11110011)| (c == 0b11110101) | (c == 0b11110111)){   // R sensor high; L,T sensors low; turn Right
            soundBuzzerandStop();
        }
        
        //
//        if (c == 0b11111011){   // L,R sensor high; T sensor low; marker encountered: beep
//            soundBuzzer();
//        }
//        
//        if (c == 0b11111100){   // T sensor high; L,R sensor low; cave encountered: slow down
//            adjustSpeed();
//        }
        
//        if (c == 0b11111111){   // L,R,T sensors high; cave and marker encountered: slow down and beep
//            soundBuzzer();
//            adjustSpeed();
//        }
//        
//        if (c == 0b11111101){   // L,T sensors high; cave and marker encountered: slow down and beep
//            soundBuzzer();
//            adjustSpeed();
//        }
        
        }
}


void takeReverse(void){
    PORTB = 0b00000101;
    lngDelay();
}

void goForward(void){
    PORTB = 0b00001010;
}

void turnLeft(void){
    PORTB = 0b00000110;
}

void turnRight(void){
    PORTB = 0b00001001;
}

void lngDelay(void) {
    _delay_ms(500);
}

void srtDelay(void) {
    _delay_ms(200);
}

void soundBuzzer(void) {
    PORTB = 0b00011010;
}

void soundBuzzerandStop(void) {
    PORTB = 0b00010000;
}


void adjustSpeed(void){
    
}


