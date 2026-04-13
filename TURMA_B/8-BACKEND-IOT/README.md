
# 👨‍💻 PARA RODAR O PROJETO

## 1 - Dar `npm install` na pasta do nível do supabase (package.json)

## 2 - Abrir docker desktop

## 3 - Digitar `npx supabase start` para iniciar o banco local

## 4 - Dar `npm install` na pasta do nível do backend iiot (package.json)

## 5 - Criar o arquivo `.env` na raiz do backend iiot (package.json) e colocar as variáveis do banco e as chaves de autorização do backend, exemplo:
    ``
    DATABASE_URL=postgresql://postgres:postgres@127.0.0.1:54322/postgres

    READ_API_KEY= SUA_CHAVE

    WRITE_API_KEY= SUA_CHAVE
    ``

## 6 - Digitar `npm run start` para rodar o backend local

## 7 - Se quiser importar as requests do insomnia use o insomnia.json que está na raiz do projeto e importe-o dentro do insomnia.

