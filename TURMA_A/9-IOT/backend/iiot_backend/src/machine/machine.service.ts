import { Injectable } from '@nestjs/common';
import { CreateMachineDto } from './dto/create-machine.dto';
import { UpdateMachineDto } from './dto/update-machine.dto';
import { AppService } from 'src/app.service';

@Injectable()
export class MachineService {
  constructor(private readonly appService: AppService) {}

  create(createMachineDto: CreateMachineDto) {
    return this.appService.machine.create({
      data: {...createMachineDto}
    });
  }

  findAll() {
    return this.appService.machine.findMany();
  }
  // SELECT * FROM MACHINE WHERE ID = ID;
  findOne(id: string) {
    return this.appService.machine.findUnique({
      where: {
        id,
      },
    });
  }

  update(id: string, updateMachineDto: UpdateMachineDto) {
    return this.appService.machine.update({
      where: {
        id,
      },
      data: {...updateMachineDto},
    })
  }

  remove(id: string) {
    return this.appService.machine.delete({
      where: {
        id,
      },
    });
  }
}
