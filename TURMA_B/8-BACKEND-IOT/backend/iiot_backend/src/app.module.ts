import { Module } from '@nestjs/common';
import { AppController } from './app.controller';
import { AppService } from './app.service';
import { ConfigModule } from '@nestjs/config';
import { SensorsModule } from './sensors/sensors.module';

@Module({
  imports: [
    //configura o nest para ler .env
    ConfigModule.forRoot({
      isGlobal: true,
    }),
    SensorsModule,
  ],
  controllers: [AppController],
  providers: [AppService],
})
export class AppModule {}
