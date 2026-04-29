// https://www.tinkercad.com/things/82AqHwkxuVH-misturador?sharecode=D2NHqLnI2xzEi6ryN_LW3Yi3YoeFpWaQ7nxOAyKGo0U

bool bufferOn;
unsigned long timerLed;

void setup()
{
    pinMode(3, INPUT);
    pinMode(2, INPUT);
    pinMode(4, OUTPUT);
}

void loop()
{    
    if(digitalRead(3)){
        bufferOn = true;
        timerLed = millis();
    }
    else if(bufferOn){
        bufferOn = false;
        digitalWrite(4, true); //liga led
    }
    // pega o millis atual e subtrai em relação à referência salva (timerLed)
    // quando essa diferença der mais/igual que o tempo desejado, desliga led
    if( (millis() - timerLed) >= 5000 || digitalRead(2)){
        digitalWrite(4, false); // led
    }    
}
