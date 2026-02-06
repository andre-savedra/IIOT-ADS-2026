
bool led = false;

// roda uma única vez quando liga
void setup()
{
    pinMode(8, OUTPUT); //configura o pino 8 como saída
    pinMode(2, INPUT); //configura o pino 2 como entrada
    pinMode(3, INPUT); //configura o pino 3 como entrada
}

// roda à todo momento
void loop()
{    
    //se o botão estiver pressionado:
    if( digitalRead(2) == true ){
        led = true;
    }    
    else if ( digitalRead(3) == true ){
        led = false;        
    }
    
    digitalWrite(8, led); //aciona ou desaciona a saída
}
