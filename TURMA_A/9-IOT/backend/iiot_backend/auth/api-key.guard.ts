import { CanActivate, ExecutionContext, Injectable, UnauthorizedException } from "@nestjs/common";
import { Reflector } from "@nestjs/core";
import { IS_PUBLIC_KEY } from "./public.decorator";

@Injectable()
export class ApiKeyGuard implements CanActivate {
    constructor(private readonly reflector: Reflector) {}

    canActivate(context: ExecutionContext): boolean {
        
        // 1 - checa se api está pública
        const isPublic = this.reflector.getAllAndOverride<boolean>(IS_PUBLIC_KEY, [
            context.getHandler(),
            context.getClass(),
        ]);

        if(isPublic){
            return true; // autoriza o acesso à api
        }

        // lê as chaves do .env
        const readApiKey = process.env.READ_API_KEY;
        const writeApiKey = process.env.WRITE_API_KEY;

        // lê a chave que está chegando na chamada da api (se existir!)
        const request = context.switchToHttp().getRequest<Request>();        
        const requestApiKey = request.headers['X-API-KEY'.toLowerCase()];

        // 2/3 - checa se a chave recebida é igual às válidas!
        if( (request.method === 'GET' && requestApiKey === readApiKey) ||
            (requestApiKey === writeApiKey) ) {
                return true; // autoriza o acesso
        }
        // se chegou até aqui, não está autorizado!!!
        throw new UnauthorizedException("Usuário não autorizado para chamar este endpoint!") 
    }

}