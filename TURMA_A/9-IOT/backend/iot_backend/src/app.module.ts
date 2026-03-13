import { Module } from '@nestjs/common';
import { AppController } from './app.controller';
import { AppService } from './app.service';
import { MachineModule } from './machine/machine.module';

@Module({
  imports: [MachineModule],
  controllers: [AppController],
  providers: [AppService],
})
export class AppModule {}
