#define WINDOW_SENSOR1 2
#define WINDOW_SENSOR2 3
#define ROOM_SENSOR 4
#define KITCHEN_SENSOR 5
#define GARAGE_SENSOR 6
#define HALL_SENSOR 7
#define ALARM 8
#define ON_BUTTON 9
#define BAR_SENSOR 10

bool systemOn = false;
bool buttonBuffer = false;
bool windowSensor1, windowSensor2, roomSensor, kitchenSensor;
bool garageSensor, hallSensor, alarm, onButton, barSensor;

void setup()
{
    pinMode(WINDOW_SENSOR1, INPUT);
    pinMode(WINDOW_SENSOR2, INPUT);
    pinMode(ROOM_SENSOR, INPUT);
    pinMode(KITCHEN_SENSOR, INPUT);
    pinMode(GARAGE_SENSOR, INPUT);
    pinMode(HALL_SENSOR, INPUT);
    pinMode(ALARM, OUTPUT);
    pinMode(ON_BUTTON, INPUT);
    pinMode(BAR_SENSOR, INPUT);
}

void loop()
{
    //chama a função que lê as entradas e saídas nas variáveis
    io_mapping();

    // começo da borda:
    if(onButton) {
        buttonBuffer = true;
    } else if (buttonBuffer){
        buttonBuffer = false;
        systemOn = !systemOn;
    }

    //sistema habilitado
    if(systemOn) {
        if (!barSensor || !windowSensor1 || !windowSensor2 ||
            roomSensor || kitchenSensor || garageSensor || hallSensor) {
           alarm = true;
        }       
    }
    // sistema desligado:
    else{
        alarm = false;
    }
}


void io_mapping(){
    // INPUTS
    onButton = digitalRead(ON_BUTTON);
    windowSensor1 = digitalRead(WINDOW_SENSOR1);
    windowSensor2 = digitalRead(WINDOW_SENSOR2);
    barSensor = digitalRead(BAR_SENSOR);
    hallSensor = digitalRead(HALL_SENSOR);
    garageSensor = digitalRead(GARAGE_SENSOR);
    kitchenSensor = digitalRead(KITCHEN_SENSOR);
    roomSensor = digitalRead(ROOM_SENSOR);

    // OUTPUTS
    digitalWrite(ALARM, alarm);
}