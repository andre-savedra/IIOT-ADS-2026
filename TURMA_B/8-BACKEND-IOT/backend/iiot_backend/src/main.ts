import "dotenv/config";
import { NestFactory } from '@nestjs/core';
import { AppModule } from './app.module';

async function bootstrap() {
  const app = await NestFactory.create(AppModule);
  console.log("running on process.env " + JSON.stringify(process.env));
  await app.listen(process.env.PORT ?? 3000);
}
bootstrap();
