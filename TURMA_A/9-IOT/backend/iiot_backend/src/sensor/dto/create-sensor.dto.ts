import { IsNotEmpty, MaxLength, IsString, MinLength, IsUUID }  from 'class-validator';


export class CreateSensorDto {
    @IsNotEmpty({message: 'Name não pode ser vazio'})
    @MaxLength(150,{message: 'Name excede 150 caracteres'})  
    @MinLength(5,{message: 'Name deve ser superior à 4 caracteres'})  
    @IsString({message: 'Name não é uma String Válida!'})  
    name: string = "";

    @IsNotEmpty({message: 'code não pode ser vazio'})
    @MaxLength(100,{message: 'code excede 100 caracteres'})  
    @MinLength(3,{message: 'code deve ser superior à 2 caracteres'})  
    @IsString({message: 'code não é uma String Válida!'})  
    code: string = "";

    @IsNotEmpty({message: 'description não pode ser vazio'})
    @MaxLength(200,{message: 'description excede 200 caracteres'})  
    @MinLength(5,{message: 'description deve ser superior à 4 caracteres'})  
    @IsString({message: 'description não é uma String Válida!'})
    description: string = "";

    @IsUUID(undefined, {message: 'machineId deve ser um UUID válido'})
    @IsNotEmpty({message: 'machineId não pode ser vazio'})
    machineId: string = "";
}
