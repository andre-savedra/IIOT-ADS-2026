import { IsJSON, IsNotEmpty, MaxLength, IsUUID }  from 'class-validator';
export class CreateDataDto {
    @IsNotEmpty({message: 'JsonValue não pode ser vazio'})
    @MaxLength(500,{message: 'JsonValue excede 500 caracteres'})  
    @IsJSON({message: 'JsonValue não é um Json Válido!'})  
    jsonValue: string = "";

    @IsUUID(undefined, {message: 'sensorId deve ser um UUID válido'})
    @IsNotEmpty({message: 'sensorId não pode ser vazio'})
    sensorId: string = "";
}
