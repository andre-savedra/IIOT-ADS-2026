
//troca os pinos numéricos por palavras mais fáceis
#define ON_BUTTON 2
#define BAR_SENSOR 3
#define WINDOW_SENSOR_1 4
#define WINDOW_SENSOR_2 5
#define ROOM_SENSOR 6
#define KITCHEN_SENSOR 7
#define GARAGE_SENSOR 8
#define HALL_SENSOR 9
#define ALARM 10

//cria variáveis para auxiliar nas entradas e saídas
bool onButton, barSensor, windowSensor1, windowSensor2, roomSensor;
bool kitchenSensor, garageSensor, hallSensor, alarm;

void setup()
{
    // configura os pinos como entrada e saída
    pinMode(ON_BUTTON, INPUT);
    pinMode(BAR_SENSOR, INPUT);
    pinMode(WINDOW_SENSOR_1, INPUT);
    pinMode(WINDOW_SENSOR_2, INPUT);
    pinMode(ROOM_SENSOR, INPUT);
    pinMode(KITCHEN_SENSOR, INPUT);
    pinMode(GARAGE_SENSOR, INPUT);
    pinMode(HALL_SENSOR, INPUT);
    pinMode(ALARM, OUTPUT);
}

// função criada para ler as entradas e acionar as saídas
void io_mapping(){
    // entradas:
    onButton = digitalRead(ON_BUTTON);
    barSensor = digitalRead(BAR_SENSOR);
    windowSensor1 = digitalRead(WINDOW_SENSOR_1);
    windowSensor2 = digitalRead(WINDOW_SENSOR_2);
    kitchenSensor = digitalRead(KITCHEN_SENSOR);
    roomSensor = digitalRead(ROOM_SENSOR);
    garageSensor = digitalRead(GARAGE_SENSOR);
    hallSensor = digitalRead(HALL_SENSOR);

    //saída
    digitalWrite(ALARM, alarm);
}


void loop()
{
    //lê as entradas e aciona as saídas
    io_mapping();

    //lógica se o botão liga estiver ativo
    if(onButton){

        if(!barSensor || !windowSensor1 || !windowSensor2 || 
            kitchenSensor || roomSensor || hallSensor || garageSensor) {
            alarm = true; // liga alarme
        }        
    }
    //se o botão liga estiver desativado
    else{
     alarm = false; // desliga alarme
    }
}