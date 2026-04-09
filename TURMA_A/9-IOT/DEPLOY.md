

# 😜 PASSOS PARA O DEPLOY EM APP SERVICE (PAAS):


## 1 - Fazer login na azure:

```bash
az login --use-device-code
```

## 2 - Criar variáveis para ajudar nos comandos (opcional):
```bash
$RG="andre-savedra-rg"
$APP="andre-savedra-iiot-app"
$SP="andre-savedra-iiot-sp"
$LOC="westus2"
```

## 3 - Criar um resource group:
```bash
az group create --name $RG --location $LOC
```

## 4 - Criar um app service plan:
```bash
az appservice plan create --resource-group $RG --name $SP --is-linux --sku "S2"
```

## 5 - Criar o app service:
```bash
az webapp create --resource-group $RG --name $APP --plan $SP --runtime "NODE:22-lts"
```

## 6 - Fazer o build do projeto:
```bash
npm run build
```

## 7 - Zipar a pasta dist que foi criada:
zip a pasta do backend

## 8 - Enviar o projeto para o app service:
```bash
az webapp deploy --name $APP --resource-group $RG --src-path .\dist.zip --type zip
```






## 11 - 👏 acesse o endpoint público e seu deploy está pronto!
```bash

```