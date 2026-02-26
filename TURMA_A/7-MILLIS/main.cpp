#define ON_BUTTON 3
#define STOP_BUTTON 2
#define LED 4

bool onButton, stopButton, led;
bool onBuffer;
unsigned long timerLed;

void setup()
{
    pinMode(ON_BUTTON, INPUT);
    pinMode(STOP_BUTTON, INPUT);
    pinMode(LED, OUTPUT);
}

void io_mapping(){
    onButton = digitalRead(ON_BUTTON);
    stopButton = digitalRead(STOP_BUTTON);
    digitalWrite(LED, led);
}

void loop()
{    
    io_mapping();

    if(onButton){
        onBuffer = true;
    }
    else if (onBuffer){
        onBuffer = false;
        led = true;
        timerLed = millis();
    }

    if( (millis() - timerLed) >= 5000 || stopButton ){
        led = false;
    }  

}