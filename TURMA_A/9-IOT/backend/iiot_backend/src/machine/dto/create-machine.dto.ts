import { IsNotEmpty, MaxLength, IsString, MinLength }  from 'class-validator';


export class CreateMachineDto {
    @IsNotEmpty({message: 'Name não pode ser vazio'})
    @MaxLength(150,{message: 'Name excede 150 caracteres'})  
    @MinLength(5,{message: 'Name deve ser superior à 4 caracteres'})  
    @IsString({message: 'Name não é uma String Válida!'})  
    name: string = "";
}
