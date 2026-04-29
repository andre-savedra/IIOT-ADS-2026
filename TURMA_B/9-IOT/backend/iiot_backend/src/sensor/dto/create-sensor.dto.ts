import { IsNotEmpty, IsString, MaxLength, MinLength, IsUUID, ValidationOptions } from "class-validator";

export class CreateSensorDto {

    @IsString({message: 'name deve ser string'})
    @IsNotEmpty({message: 'name não pode ser vazio'})
    @MaxLength(100,{message: 'name excede 100 caracteres'})  
    name: string = "";

    @IsString({message: 'code deve ser string'})
    @IsNotEmpty({message: 'code não pode ser vazio'})
    @MaxLength(50,{message: 'code excede 50 caracteres'})
    @MinLength(5,{message: 'code deve ser maior que 5 caracteres'})  
    code: string = "";
    
    @IsString({message: 'description deve ser string'})
    @IsNotEmpty({message: 'description não pode ser vazio'})
    @MaxLength(200,{message: 'description excede 200 caracteres'})
    @MinLength(10,{message: 'description deve ser maior que 10 caracteres'})
    description: string = "";

    @IsUUID(undefined, {message: 'UUID deve ser válido'})
    @IsNotEmpty({message: 'machineId não pode ser vazio'})
    machineId: string = "";
}
