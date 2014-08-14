#include <IRremote.h>

/**
* Testing Motor driver with H-bridge
*/


#define IR_FORWARD  0xFD807F
#define IR_BACKWARD 0xFD906F
#define IR_LEFT     0xFD20DF
#define IR_RIGHT    0xFD609F
#define IR_STOP     0xFDA05F

int irPin = 6;

IRrecv irrecv(irPin);

decode_results results;

void setup() {
    for (int i = 2; i <= 5; i++) {
        pinMode(i, OUTPUT);
        digitalWrite(i, LOW);
    }
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    
    Serial.begin(9600);
    irrecv.enableIRIn();
}

void loop() {
    if (irrecv.decode(&results)) {
        Serial.println(results.value, HEX);
        if (results.value == IR_FORWARD) {
            forward();
        }
        if (results.value == IR_BACKWARD) {
            backward();
        }
        if (results.value == IR_LEFT) {
            left();
        }
        if (results.value == IR_RIGHT) {
            right();
        }
        if (results.value == IR_STOP) {
            stopall();
        }
        irrecv.resume();
    }
    
//    while(Serial.available() == 0);
//    
//    char val = Serial.read();
//    
//    //Serial.println(val);
//    
//    switch (val) {
//        case 'w':
//            forward();
//            delay(1000);
//            stopall();
//            break;
//        case 's':
//            backward();
//            delay(1000);
//            stopall();
//            break;
//        case 'a':
//            left();
//            delay(1000);
//            stopall();
//            break;
//        case 'd':
//            right();
//            delay(1000);
//            stopall();
//            break;
//        default:
//            Serial.println("Invalid!!!");
//            Serial.flush();
//            break;
//    }
}

void forward() {
    stopall();
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
}

void backward() {
    stopall();
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
}

void right() {
    stopall();
    digitalWrite(2, HIGH);
    digitalWrite(5, HIGH);
}

void left() {
    stopall();
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
}

void stopall() {
    for (int i = 2; i <= 5; i++) {
        digitalWrite(i, LOW);
    }
}
