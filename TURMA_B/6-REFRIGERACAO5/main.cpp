
#define ON_BUTTON 2
#define LEVEL_SENSOR 3
#define QUALITY_SENSOR 4
#define PRESSURE_SENSOR 5
#define MOTOR 6
#define GREEN_LAMP 7
#define RED_LAMP 8
#define EMERGENCY_BUTTON 9

bool onButton, levelSensor, qualitySensor, pressureSensor;
bool motor, greenLamp, redLamp, emergencyButton;
bool onBuffer, systemOn;

void setup()
{
    pinMode(ON_BUTTON, INPUT);
    pinMode(LEVEL_SENSOR, INPUT);
    pinMode(QUALITY_SENSOR, INPUT);
    pinMode(PRESSURE_SENSOR, INPUT);
    pinMode(EMERGENCY_BUTTON, INPUT);

    pinMode(MOTOR, OUTPUT);
    pinMode(GREEN_LAMP, OUTPUT);
    pinMode(RED_LAMP, OUTPUT);    
}

void io_mapping(){
    onButton = digitalRead(ON_BUTTON);
    emergencyButton = digitalRead(EMERGENCY_BUTTON);
    levelSensor = digitalRead(LEVEL_SENSOR);
    qualitySensor = digitalRead(QUALITY_SENSOR);
    pressureSensor = digitalRead(PRESSURE_SENSOR);
    
    digitalWrite(MOTOR, motor);
    digitalWrite(GREEN_LAMP, greenLamp);
    digitalWrite(RED_LAMP, redLamp);
}

void loop()
{
    io_mapping();

    //lógica da borda

    // 1- sinal chegou (botão pressionado)
    if(onButton){
        onBuffer = true;        
    } 
    // 2- sinal acabou de sair (botão solto)
    else if (onBuffer){
         onBuffer = false;
         //ação: ligar ou desligar o sistema (variável)
         systemOn = !systemOn;
    }

    // sistema em funcionamento
    if(systemOn){
        greenLamp = true;

        //botão de emergência pressionado!
        if(!emergencyButton){
            motor = false;
            redLamp = true;            
        }
        // botão de emergência está ok!
        else {        
            if(qualitySensor && levelSensor && !pressureSensor){
                motor = true;
                redLamp = false;  
            }
            // alguma condição dos sensores não está favorável!
            else{
                motor = false;
                redLamp = true;  
            }
        }
    }
    // sistema desligado
    else{
        motor = false;
        redLamp = false;
        greenLamp = false;
    }



    
}