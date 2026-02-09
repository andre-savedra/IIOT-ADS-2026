
bool ledState = false;
bool buffer = false;

// AS CONFIGURAÇÕES (RODA 1x QUANDO LIGA)
void setup()
{
    pinMode(8, OUTPUT); //DEFINE COMO SAÍDA
    pinMode(3, INPUT); //DEFINE COMO ENTRADA
}

// A LÓGICA (EXECUTA CONSTANTEMENTE ENQUANTO ESTIVER LIGADO)
void loop()
{   
    // se o botão pulsante for pressionado (início da borda = liga buffer) 
    if(digitalRead(3) == true){
        buffer = true;
    } 
    // se o botão pulsante acabou de ser solto (fim da borda)
    else if(buffer == true){
        buffer = false; // reseta a variável auxiliar
        ledState = !ledState; // executa a ação da borda (neste caso, ligar e desligar led)
    }
   
    digitalWrite(8, ledState); // liga o led de acordo com a variável    
}