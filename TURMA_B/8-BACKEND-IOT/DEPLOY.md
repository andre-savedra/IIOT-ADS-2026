# 👨‍💻 PASSOS PARA O DEPLOY DA API NO SERVIÇO DE APLICATIVO DA AZURE (PAAS)

## 1 - Logar na azure com `az login --use-device-code`

## 2 - Criar as variáveis de ambiente para serem usadas no command line:

```
$RG="andre-savedra2-rg"
$LOC="westus2"
$APP="andre-savedra2-iiot-app"
$SP="andre-savedra2-iiot-sp"
```

## 3 - Criar grupo de recurso:

```
az group create --name $RG --location $LOC
```

## 4 - Criar um plano de serviço:

```
az appservice plan create --resource-group $RG --name $SP --is-linux --sku "S2"
```

## 5 - Criar o app service (servidor onde realmente vai rodar o back):

```
az webapp create --resource-group $RG --plan $SP --name $APP --runtime "NODE:22-lts"
```

## 6 - Atualizar o generate do prisma com `npx prisma generate`

## 7 - Gerar o build do backend com `npm run build`

## 8 - Zipar a pasta `dist` gerada pelo backend

## 9 - Executar o deploy usando:

```
az webapp deploy --resource-group $RG --name $APP --src-path 'CAMINHO_PARA_A_PASTA_DIST.zip' --type zip
```

## 10 - Após executado o deploy com sucesso, crie as variáveis de ambiente dentro do seu app service (via portal da azure ou via command line abaixo):

```
az webapp config appsettings set --name $APP --resource-group $RG --settings DATABASE_URL=postgresql://postgres:CFP501@MANGE!!@db.cwlkijrphdpylvdgsuuc.supabase.co:5432/postgres
```

```
az webapp config appsettings set --name $APP --resource-group $RG --settings READ_API_KEY=8db790c7-70d6-4ab9-80d2-924207ecb6dc
```

```
az webapp config appsettings set --name $APP --resource-group $RG --settings WRITE_API_KEY=4247cca7-12cd-47d0-9ba8-a9a248a7003d
```

```
az webapp config appsettings set --name $APP --resource-group $RG --settings SCM_DO_BUILD_DURING_DEPLOYMENT=true
```

```
az webapp config appsettings set --name $APP --resource-group $RG --settings PORT=8080
```

```
az webapp config appsettings set --name $APP --resource-group $RG --settings NODE_ENV=production
```

```
az webapp config set --name $APP --resource-group $RG --startup-file "node dist/src/main.js"
```


## 11 - Dar restart no webapp:

```
az webapp restart --name $APP --resource-group $RG 
```