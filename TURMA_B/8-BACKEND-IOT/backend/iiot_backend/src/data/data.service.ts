import { Injectable, NotFoundException } from '@nestjs/common';
import { CreateDataDto } from './dto/create-datum.dto';
import { UpdateDatumDto } from './dto/update-datum.dto';
import { AppService } from 'src/app.service';
import { SensorService } from 'src/sensor/sensor.service';

@Injectable()
export class DataService {
  constructor(private readonly appService: AppService){}

  async create(createDataDto: CreateDataDto) {

    const sensorService = new SensorService(this.appService);

    const sensorFound = await sensorService.findOne(createDataDto.sensorId);
    if(sensorFound === null){
      throw new NotFoundException(`Sensor com id: ${createDataDto.sensorId} não encontrado!`)
    }
    
    return this.appService.data.create({
      data: {...createDataDto},
    });
  }

  findAll() {
    return this.appService.data.findMany();
  }

  findOne(id: string) {
    return this.appService.data.findUnique({
      where:{
        id,
      }
    });
  }

  async update(id: string, updateDatumDto: UpdateDatumDto) {

    const sensorService = new SensorService(this.appService);

    const sensorFound = await sensorService.findOne(updateDatumDto.sensorId!);
      if(sensorFound === null){
        throw new NotFoundException(`Sensor com id: ${id} não encontrado!`)
      }

    return this.appService.data.update({
      where:{
        id,
      },
      data: {...updateDatumDto},
    })
  }

  remove(id: string) {
    return this.appService.data.delete({
      where: {
        id,
      }
    })
  }
}
