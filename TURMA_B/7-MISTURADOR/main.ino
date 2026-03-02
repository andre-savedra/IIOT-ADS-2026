
#define ON_BUTTON 9
#define STOP_BUTTON 1
#define EMERGENCY_BUTTON 2
#define MOTOR 3
#define PUMP_A 4
#define PUMP_B 5
#define VALV_C 6
#define FINAL_VALV 7
#define PRESSURE_SENSOR 8
#define EMERGENCY_LAMP 10

bool systemOn;
unsigned long timer;

unsigned int steps;
#define STEP_STAND_BY 0
#define STEP_PRODUCT_A 1
#define STEP_PRODUCT_B 2
#define STEP_WAITING 3
#define STEP_PRODUCT_C 4
#define STEP_MIXING 5
#define STEP_WAITING_2 6
#define STEP_EMPTING 7

int input_pins[] = {ON_BUTTON, STOP_BUTTON, EMERGENCY_BUTTON, PRESSURE_SENSOR};
int output_pins[] = {MOTOR, PUMP_A, PUMP_B, VALV_C, FINAL_VALV, EMERGENCY_LAMP};

void setup()
{
    //configura todo o array como entrada
   for(int i=0; i<input_pins.length(); i++){
    pinMode(input_pins[i], INPUT);
   }
   //configura todo o array como saída
   for(int i=0; i<output_pins.length(); i++){
    pinMode(output_pins[i], OUTPUT);
   }
}
// lê uma entrada
boolean in(int pin){
    return digitalRead(pin);
}
// liga uma saída
void on(int pin){
    digitalWrite(pin, true);
}
// desliga uma saída
void off(int pin){
    digitalWrite(pin, false);
}
// desliga tudo
void turnOff(){
    for(int i=0; i<output_pins.length(); i++){
     off(output_pins[i]);
    }
}
// desliga tudo
void turnOffExcept(int exception_pins[]){
    for(int i=0; i<output_pins.length(); i++){
        if(exception_pins.indexOf(output_pins[i]) == -1 ){
            off(output_pins[i]);
        }
    }
}

boolean timeout(int timing_sec){
    return (millis()-timer)>= (timing_sec * 1000);
}


void loop()
{    
    // lógica liga / desliga sistema
    if(in(ON_BUTTON) && !in(STOP_BUTTON)){
        systemOn = true;
    }
    else if(in(STOP_BUTTON)){
        systemOn = false;
    }

    // sistema em funcionamento
    if(systemOn){
        //emergência ok
        if(in(EMERGENCY_BUTTON)){
            
            switch (steps) {

            case STEP_STAND_BY:
                timer = millis(); //pega a referência
                steps++; //avanço de etapa
                break;

            case STEP_PRODUCT_A:
                 on(PUMP_A); // injeto produto A
                 
                 //conta 3 segundos
                 if(timeout(3)){
                     off(PUMP_A); //desliga bomba
                     steps++; //avança etapa
                     timer = millis(); //pega nova referência
                 }
                 break;

            case STEP_PRODUCT_B:
                on(PUMP_B); // injeto produto B
                 
                 //conta 4 segundos
                 if(timeout(4)){
                     off(PUMP_B); //desliga bomba
                     steps++; //avança etapa
                     timer = millis(); //pega nova referência
                 }
                 break;

            case STEP_WAITING_2:
            case STEP_WAITING:            
                 //conta 2 segundos
                 if(timeout(2)){
                     steps++; //avança etapa
                     timer = millis(); //pega nova referência
                 }
                 break;

            case STEP_PRODUCT_C:
                on(VALV_C); // injeto produto C
                 
                 //conta 5 segundos
                 if(timeout(5)){
                     off(VALV_C); //desliga valvula C
                     steps++; //avança etapa
                     timer = millis(); //pega nova referência
                 }
                 break;

            case STEP_MIXING:
                on(MOTOR); // mistura
                 
                 //conta 10 segundos
                 if(timeout(10)){
                     off(MOTOR); //desliga valvula C
                     steps++; //avança etapa
                     timer = millis(); //pega nova referência
                 }
                 break;

            case STEP_EMPTING:
                on(FINAL_VALV); // liga válvula de escoamento do produto

                if(in(PRESSURE_SENSOR)){
                 off(FINAL_VALV); // desliga válvula de escoamento do produto 
                 steps = STEP_STAND_BY;  //terminou recomeça
                 //systemOn = false; // se ativo, ao terminar tem que pressionar o botão liga novamente para recomeçar
                }
                 break;        
            }
        }
        //emergência acionado
        else{
            turnOff();
            steps = STEP_STAND_BY;
            systemOn = false;
        }
    }
    // sistema desligado
    else{
        turnOffExcept([EMERGENCY_LAMP]);
        if(in(EMERGENCY_BUTTON)){
            on(EMERGENCY_LAMP);
        }
        
    }
}


