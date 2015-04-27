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
void longDelay(void);
void shortDelay(void);


int main(void){
    
    DDRD = 0b00000000;   //setting part D as input part
    DDRB = 0b11111111;   //setting part B as output part
    PORTD = 0b11111111;  //pulling up part D
    
    int c;
    
    while(1){
        c = PIND;
        
//        if (c == 0b11110000){   //All sensors within the table OR two back sensors outside the table; go fwd
//            goForward();
//        }
//
//        if (c == 0b11110011){   //All sensors within the table OR two back sensors outside the table; go fwd
//            goForward();
//        }

        if (c == 0b11111100){   //Both front sensors out of the table; go back and then turn right
            takeReverse();
            turnRight();
            shortDelay();
        }

//
//        if (c == 0b11110001){   //Back left sensor out of the table; go fwd and then turn left
//            goForward();
//            turnLeft();
//            shortDelay();
//        }
//        
//        if (c == 0b11110010){   //Back right sensor out of the table; go fwd and then turn right
//            goForward();
//            turnRight();
//            shortDelay();
//        }
//
//        if (c == 0b11110100){   //Front Right sensor out of the table; go back and then turn right to align
//            takeReverse();
//            turnLeft();
//            shortDelay();
//        }
//        
//        if (c == 0b11111000){   //Front Left sensor out of the table; go back and then turn left to align
//            takeReverse();
//            turnRight();
//            shortDelay();
//        }
//
//        if (c == 0b111101001){   //Both Left sensors out of the table; Turn right
//            turnRight();
//        }
//
//        if (c == 0b11110110){   //Both Right sensors out of the table; Turn left
//            turnLeft();
//        }
//
//
//        if (c == 0b11110111){   //Both back sensors & front right sensor out of the table; go fwd and then turn left
//            turnLeft();
//        }
//
//        if (c == 0b11111011){   //Both back sensors & front left sensor out of the table; go fwd and then turn right
//            turnRight();
//        }
//
//        if (c == 0b11111101){   //Both front sensors & back left sensor out of the table; go back and then turn right
//            turnRight();
//        }
//
//        if (c == 0b11111101){   //Both front sensors & back right sensor out of the table; go back and then turn left
//            turnLeft();
//        }
        
    }
}


void takeReverse(void){
    PORTB = 0b00000101;
    longDelay();
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

void longDelay(void) {
    _delay_ms(1000);
}

void shortDelay(void) {
    _delay_ms(200);
}

