import { Global, Module } from '@nestjs/common';
import { AppController } from './app.controller';
import { AppService } from './app.service';
import { MachineModule } from './machine/machine.module';
import { SensorModule } from './sensor/sensor.module';
import { DataModule } from './data/data.module';

@Global()
@Module({
  imports: [MachineModule, SensorModule, DataModule],
  controllers: [AppController],
  providers: [AppService],
  exports: [AppService],
})
export class AppModule {}
