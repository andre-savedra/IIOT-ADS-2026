
bool led = false;
bool buttonBuffer = false;

void setup()
{
    pinMode(3, INPUT);   
    pinMode(8, OUTPUT);
}

void loop()
{    
    //início da borda, botão foi pressionado!
    if(digitalRead(3) == true){
       buttonBuffer = true;    
    } 
    // fim da borda, botão foi solto e variável buffer está ativa
    else if (buttonBuffer == true){
        buttonBuffer = false; // reinicia o buffer para o estado inicial
        led = !led; // faz o oposto do que estava no led
    }
    // aciona o led de acordo com a variável
    digitalWrite(8, led);
}