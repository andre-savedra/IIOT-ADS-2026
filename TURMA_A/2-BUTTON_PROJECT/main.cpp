// roda uma única vez quando liga
void setup()
{
    pinMode(8, OUTPUT); //configura o pino 8 como saída
    pinMode(3, INPUT); //configura o pino 3 como entrada
}

// roda à todo momento
void loop()
{
    //se o botão estiver pressionado:
    if( digitalRead(3) == true ){
        digitalWrite(8, true); //aciona a saída
    }
    else{
        digitalWrite(8, false); //desaciona a saída
    }
}
