import { Global, Module } from '@nestjs/common';
import { AppController } from './app.controller';
import { AppService } from './app.service';
import { MachineModule } from './machine/machine.module';
import { SensorModule } from './sensor/sensor.module';
import { DataModule } from './data/data.module';
import { AuthModule } from './auth/auth.module';

@Global()
@Module({
  imports: [MachineModule, SensorModule, DataModule, AuthModule],
  controllers: [AppController],
  providers: [AppService],
  exports: [AppService],
})
export class AppModule {}
