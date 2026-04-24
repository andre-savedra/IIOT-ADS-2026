# 👨‍💻 PASSOS PARA O DEPLOY DA API NO SERVIÇO DE APLICATIVO DA AZURE (PAAS)

## 1 - Logar na azure com `az login --use-device-code`

## 2 - Criar as variáveis de ambiente para serem usadas no command line:

```
$RG="andre-savedra-turmab-rg"
$LOC="westus2"
$APP="andre-savedra-turmab-iiot-app"
$SP="andre-savedra-turmab-iiot-sp"
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

## 6 - Copiar a url gerada do seu backend através da resposta da linha de comando digitada anteriormente ("defaultHostName":) ou ir no portal da azure e achar em seu app service (embora basicamente a url do backend vai ser sempre o nome do seu $APP: `https://$APP.azurewebsites.net` )


## 7 - Crie as variáveis de ambiente dentro do seu app service (via portal da azure ou via command line abaixo):

```
az webapp config appsettings set --name $APP --resource-group $RG --settings DATABASE_URL=postgresql://postgres.hpexasnujsklxpkmcwmf:CFP501MANGE!!@aws-1-us-east-2.pooler.supabase.com:6543/postgres?pgbouncer=true
```

```
az webapp config appsettings set --name $APP --resource-group $RG --settings DIRECT_URL=postgresql://postgres.hpexasnujsklxpkmcwmf:CFP501MANGE!!@aws-1-us-east-2.pooler.supabase.com:5432/postgres
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
az webapp config set --name $APP --resource-group $RG --startup-file "cd /home/site/wwwroot && npm run start:prod"
```


## 8 - Acessar a interface Kudo da Azure acessando a url do seu backend com o sufixo `.scm`, exemplo: `https://$APP.scm.azurewebsites.net` (mude para o seu). Após acessar a interface, vá na página de deployments.

## 9 - Zipar o projeto do backend SEM selecionar a pasta `node_modules`

## 10 - Selecionar ou arrastar a pasta zipada na interface Kudo de deploy da azure

## 11 - Acompanhe o processo de deploy e os logs para ver se deu certo

## 12 - Teste sua API usando o Insomnia