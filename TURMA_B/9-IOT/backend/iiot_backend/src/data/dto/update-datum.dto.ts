import { PartialType } from '@nestjs/mapped-types';
import { CreateDataDto } from './create-datum.dto';

export class UpdateDatumDto extends PartialType(CreateDataDto) {}
