
// AS CONFIGURAÇÕES (RODA 1x QUANDO LIGA)
void setup()
{
    pinMode(8, OUTPUT); //DEFINE COMO SAÍDA
    pinMode(3, INPUT); //DEFINE COMO ENTRADA
}

// A LÓGICA (EXECUTA CONSTANTEMENTE ENQUANTO ESTIVER LIGADO)
void loop()
{
    if(digitalRead(3) == true){
        digitalWrite(8, true); // liga
    }
    else{
        digitalWrite(8, false); // desligar
    }

}