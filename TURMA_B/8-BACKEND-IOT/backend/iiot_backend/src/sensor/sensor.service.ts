import { Injectable, NotFoundException } from '@nestjs/common';
import { CreateSensorDto } from './dto/create-sensor.dto';
import { UpdateSensorDto } from './dto/update-sensor.dto';
import { AppService } from 'src/app.service';

@Injectable()
export class SensorService {
  constructor(private readonly appService: AppService){ }

  async create(createSensorDto: CreateSensorDto) {
    const machineFound = await this.appService.machine.findUnique({
      where: {
        id: createSensorDto.machineId,
      }
    });

    if(machineFound === null){
        throw new NotFoundException(`Máquina com o id: ${createSensorDto.machineId} não encontrada!`);
    }

    return this.appService.sensor.create({
        data: {...createSensorDto,}
    })  
  }

  findAll() {
    return this.appService.sensor.findMany();
  }

  findOne(id: string) {
    return this.appService.sensor.findUnique({
      where: {
        id,
      }
    });
  }
  
  async update(id: string, updateSensorDto: UpdateSensorDto) {
     const machineFound = await this.appService.machine.findUnique({
      where: {
        id: updateSensorDto.machineId,
      }
    });

    if(machineFound === null){
        throw new NotFoundException(`Máquina com o id: ${updateSensorDto.machineId} não encontrada!`);
    }

    return this.appService.sensor.update({
        where:{
          id,
        },
        data: {...updateSensorDto},
      });    
  }

  remove(id: string) {
    return this.appService.sensor.delete({
      where:{
        id,
      }
    });
  }
}
