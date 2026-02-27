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

bool inputs[input_pins.length()];
bool outputs[output_pins.length()];

bool systemOn;
int steps;
unsigned long timer;

#define INITIAL 0
#define PRODUCT_A 1
#define PRODUCT_B 2
#define WAITING 3
#define PRODUCT_C 4
#define MIXING 5
#define WAITING_2 6
#define EMPTING 7

void setup()
{
    //configura as entradas
    for(int i=0; i<input_pins.length(); i++){
        pinMode(input_pins[i], INPUT);
    }
    //configura as saidas
    for(int i=0; i<output_pins.length(); i++){
        pinMode(output_pins[i], OUTPUT);
    }
}

void io_mapping(){
    //lê todas as entradas
    for(int i=0; i<input_pins.length(); i++){
        inputs[i] = digitalRead(input_pins[i]);
    }

    //aciona todas as saídas
    for(int i=0; i<output_pins.length(); i++){
        digitalWrite(output_pins[i], outputs[i]);
    }
}

void turnOff(){
   //desaciona todas as saídas
    for(int i=0; i<outputs.length(); i++){
        outputs[i] = false;
    } 
}

void loop()
{
    io_mapping();
        
    if(inputs[OFF_BUTTON] || !inputs[EMERGENCY_BUTTON]){
        systemOn = false;
        outputs[EMERGENCY_LAMP] = !inputs[EMERGENCY_BUTTON];        
    } 
    //só liga sistema se botão liga acionado com os demais OK
    else if(inputs[ON_BUTTON]){
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
                output[A_PUMP] = true;

                if( (millis() - timer) >= 3000){
                    output[A_PUMP] = false;
                    timer = millis();                     
                    steps++; //avanço de etapa
                }
            break;

            case PRODUCT_B:
                output[B_PUMP] = true;

                if( (millis() - timer) >= 4000){
                    output[B_PUMP] = false;
                    timer = millis();                     
                    steps++; //avanço de etapa
                }
            break;

            case WAITING:
                if( (millis() - timer) >= 2000){
                    timer = millis();                     
                    steps++; //avanço de etapa
                }
            break;
        
        }

       

    }
    // se sistema estiver desligado
    else{
        turnOff();
    }


    
}