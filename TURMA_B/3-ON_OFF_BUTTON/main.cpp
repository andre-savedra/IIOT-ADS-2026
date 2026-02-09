
bool ledState = false;
// AS CONFIGURAÇÕES (RODA 1x QUANDO LIGA)
void setup()
{
    pinMode(8, OUTPUT); //DEFINE COMO SAÍDA
    pinMode(3, INPUT); //DEFINE COMO ENTRADA
    pinMode(2, INPUT); //DEFINE COMO ENTRADA
}

// A LÓGICA (EXECUTA CONSTANTEMENTE ENQUANTO ESTIVER LIGADO)
void loop()
{   
    // se botão pulsante pressionado
    if(digitalRead(3) == true){
        ledState = true; // liga
    } // se o outro botão pulsante pressionado
    else if(digitalRead(2) == true){
        ledState = false; // desliga        
    }
    digitalWrite(8, ledState); // liga o led de acordo com a variável
    
}