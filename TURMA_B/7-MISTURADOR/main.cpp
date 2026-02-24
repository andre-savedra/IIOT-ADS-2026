
#define ON_BUTTON 2
#define STOP_BUTTON 3
#define EMERGENCY_BUTTON 4
#define MOTOR 5
#define PUMP_A 6
#define PUMP_B 7
#define VALV_C 8
#define FINAL_VALV 9
#define PRESSURE_SENSOR 10

bool onButton, stopButton, emergencyButton, motor;
bool pumpA, pumpB, valvC, finalValv, pressureSensor;
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

int inputs[] = {ON_BUTTON, STOP_BUTTON, EMERGENCY_BUTTON, PRESSURE_SENSOR};
int outputs[] = {MOTOR, PUMP_A, PUMP_B, VALV_C, FINAL_VALV};

int var_inputs[] = {onButton, stopButton, emergencyButton, pressureSensor};
int var_outputs[] = {motor, pumpA, pumpB, valvC, finalValv};

void setup()
{
    //configura todo o array como entrada
   for(int i=0; i<inputs.length(); i++){
    pinMode(inputs[i], INPUT);
   }
   //configura todo o array como saída
   for(int i=0; i<outputs.length(); i++){
    pinMode(outputs[i], OUTPUT);
   }
}

void io_mapping(){
    //configura todo o array como entrada
//    for(int i=0; i<var_inputs.length(); i++){
//       var_inputs[i]  = digitalRead(inputs[i]);
//    }
//    //configura todo o array como saída
//    for(int i=0; i<var_outputs.length(); i++){
//     digitalWrite(outputs[i], var_outputs[i]);
//    }

}

void loop()
{
    io_mapping();  
    
    // lógica liga / desliga sistema
    if(onButton && !stopButton){
        systemOn = true;
    }
    else if(stopButton){
        systemOn = false;
    }

    // sistema em funcionamento
    if(systemOn){

        //emergência ok
        if(emergencyButton){
            
            switch (steps) {

            case STEP_STAND_BY:
                timer = millis(); //pega a referência
                steps++; //avanço de etapa
                break;

            case STEP_PRODUCT_A:
                 pumpA = true; // injeto produto A
                 
                 //conta 3 segundos
                 if( (millis()-timer)>= 3000){
                     pumpA = false; //desliga bomba
                     steps++; //avança etapa
                     timer = millis(); //pega nova referência
                 }
                 break;

            case STEP_PRODUCT_B:
             pumpB = true; // injeto produto B
                 
                 //conta 4 segundos
                 if( (millis()-timer)>= 4000){
                     pumpB = false; //desliga bomba
                     steps++; //avança etapa
                     timer = millis(); //pega nova referência
                 }
                 break;

            case STEP_WAITING_2:
            case STEP_WAITING:            
                 //conta 2 segundos
                 if( (millis()-timer)>= 2000){
                     steps++; //avança etapa
                     timer = millis(); //pega nova referência
                 }
                 break;

            case STEP_PRODUCT_C:
                valvC = true; // injeto produto C
                 
                 //conta 5 segundos
                 if( (millis()-timer)>= 5000){
                     valvC = false; //desliga valvula C
                     steps++; //avança etapa
                     timer = millis(); //pega nova referência
                 }
                 break;

            case STEP_MIXING:
                motor = true; // mistura
                 
                 //conta 10 segundos
                 if( (millis()-timer)>= 10000){
                     motor = false; //desliga valvula C
                     steps++; //avança etapa
                     timer = millis(); //pega nova referência
                 }
                 break;

            case STEP_EMPTING:
                finalValv = true; // liga válvula de escoamento do produto

                if(pressureSensor){
                 finalValv = false; // desliga válvula de escoamento do produto 
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
        }
    }
    // sistema desligado
    else{
        turnOff();
    }
}

void turnOff(){
    for(int i=0; i<outputs.length(); i++){
     digitalWrite(outputs[i], false);
    }
}

