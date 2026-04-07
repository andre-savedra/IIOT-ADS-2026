import { IsNotEmpty, IsString } from "class-validator";


export class CreateMachineDto {
    @IsString({message: 'name deve existir'})
    @IsNotEmpty({message: 'name não pode ser vazio'})        
    name: string = "";
}
