
// AS CONFIGURAÇÕES (RODA 1x QUANDO LIGA)
void setup()
{
    pinMode(8, OUTPUT); //DEFINE COMO SAÍDA
}

// A LÓGICA (EXECUTA CONSTANTEMENTE ENQUANTO ESTIVER LIGADO)
void loop()
{
   digitalWrite(8, true); // liga
   delay(5000); // espera 5 seg
   digitalWrite(8, false); // desligar
   delay(5000); // espera 5 seg
}