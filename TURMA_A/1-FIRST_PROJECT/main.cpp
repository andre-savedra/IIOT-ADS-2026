// roda uma única vez quando liga
void setup()
{
    pinMode(8, OUTPUT); //configura o pino 8 como saída
}

// roda à todo momento
void loop()
{
    digitalWrite(8, true); //aciona a saída
    delay(5000); //espera 5 seg.

    digitalWrite(8, false); //desaciona a saída
    delay(5000); //espera 5 seg.
}
