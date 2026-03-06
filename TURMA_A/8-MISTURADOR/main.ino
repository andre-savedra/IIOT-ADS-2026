#define OFF_BUTTON 1
#define EMERGENCY_BUTTON 2
#define MOTOR 3
#define A_PUMP 4
#define B_PUMP 5
#define C_VALV 6
#define FINAL_PRODUCT_VALV 7
#define PRESSURE_SENSOR 8
#define ON_BUTTON 9
#define EMERGENCY_LAMP 10

int input_pins[] = { OFF_BUTTON, EMERGENCY_BUTTON, PRESSURE_SENSOR, ON_BUTTON };
int output_pins[] = { MOTOR, A_PUMP, B_PUMP, C_VALV, FINAL_PRODUCT_VALV, EMERGENCY_LAMP };

#define INITIAL 0
#define PRODUCT_A 1
#define PRODUCT_B 2
#define WAITING 3
#define PRODUCT_C 4
#define MIXING 5
#define WAITING_2 6
#define EMPTING 7

bool systemOn = false;
int steps = INITIAL;
unsigned long timer;

void setup()
{
    //configura as entradas
    for(int i=0; i<sizeof(input_pins); i++){
        pinMode(input_pins[i], INPUT);
    }
    //configura as saidas
    for(int i=0; i<sizeof(output_pins); i++){
        pinMode(output_pins[i], OUTPUT);
    }
}

// função que lê as entrada de maneira mais enxuta
bool in(int pin){
    return digitalRead(pin);
}

// função que liga uma saída
void on(int pin){
    digitalWrite(pin, true);
}

// função que desliga uma saída
void off(int pin){
    digitalWrite(pin, false);
}

void turnOff(){
   //desaciona todas as saídas
    for(int i=0; i<sizeof(output_pins); i++){
         off(output_pins[i]);
    } 
}

void turnOffExcept(int exceptions[]){
    for(int i=0; i<sizeof(output_pins); i++){
        bool isException = false;        
        for(int j=0; j<sizeof(exceptions);j++){
            if(output_pins[i] == exceptions[j]){
                isException = true;
                break;
            }
        }
        if(!isException){
            off(output_pins[i]);
        }
    } 
}

void loop()
{
    
    // se botão desliga pressionado ou emergência acionado
    if(in(OFF_BUTTON) || !in(EMERGENCY_BUTTON)){
        systemOn = false;        
    } 
    //só liga sistema se botão liga acionado com os demais OK
    else if(in(ON_BUTTON)){
        systemOn = true;        
    }

    // se sistema está ligado
    if(systemOn){
        switch (steps)
        {
            case INITIAL:
                turnOff(); // começa com tudo desligado                
                timer = millis(); // inicia a contagem de tempo
                steps++; //avanço de etapa
            break;

            case PRODUCT_A:
                on(A_PUMP);

                if( (millis() - timer) >= 3000){
                    off(A_PUMP);
                    timer = millis(); // reinicia a contagem de tempo                
                    steps++; //avanço de etapa
                }
            break;

            case PRODUCT_B:
                on(B_PUMP);

                if( (millis() - timer) >= 4000){
                    off(B_PUMP);
                    timer = millis(); // reinicia a contagem de tempo                     
                    steps++; //avanço de etapa
                }
            break;

            case WAITING:
            case WAITING_2:
                if( (millis() - timer) >= 2000){
                    timer = millis(); // reinicia a contagem de tempo                       
                    steps++; //avanço de etapa
                }
            break;

            case PRODUCT_C:
                 on(C_VALV);

                if( (millis() - timer) >= 5000){
                    off(C_VALV);
                    timer = millis(); // reinicia a contagem de tempo                     
                    steps++; //avanço de etapa
                }
            break;

            case MIXING:
                 on(MOTOR);

                if( (millis() - timer) >= 10000){
                    off(MOTOR);
                    timer = millis(); // reinicia a contagem de tempo                     
                    steps++; //avanço de etapa
                }
            break;

            case EMPTING:
                 on(FINAL_PRODUCT_VALV);

                if(in(PRESSURE_SENSOR)){
                    off(FINAL_PRODUCT_VALV);
                    steps = INITIAL; // volta para etapa inicial
                }
            break;        
        }       

    }
    // se sistema estiver desligado
    else{
        int except[] = { EMERGENCY_LAMP };        
        turnOffExcept(except);  

        //se botão de emergência está ok
        if(in(EMERGENCY_BUTTON)){
            off(EMERGENCY_LAMP);
        }
        //se botão de emergência for pressionado
        else{
            on(EMERGENCY_LAMP); // liga lâmpada
            steps = INITIAL; // volta na etapa inicial
        }      
    }


    
}