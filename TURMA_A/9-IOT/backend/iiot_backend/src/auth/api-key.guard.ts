import { CanActivate, ExecutionContext, Injectable, UnauthorizedException } from "@nestjs/common";
import { Reflector } from "@nestjs/core";
import { IS_PUBLIC_KEY } from "./public.decorator";


@Injectable()
export class ApiKeyGuard implements CanActivate {
    constructor(private readonly reflector: Reflector) {}

    canActivate(context: ExecutionContext): boolean {
        
        // identifica se o método interceptado tem a anotação isPublic
        const isPublic = this.reflector.getAllAndOverride<boolean>(IS_PUBLIC_KEY, [
            context.getHandler(),
            context.getClass(),
        ]);

        // se sim, autoriza!
        if(isPublic){
            return true;
        }

        // pego as chaves autorizadas
        const getApiKey = process.env.READ_API_KEY;
        const writeApiKey = process.env.WRITE_API_KEY;
       
        // pega as informações http que chegaram no interceptor
        const request = context.switchToHttp().getRequest<Request>();
        const requestApiKey = request.headers['X-API-KEY'.toLowerCase()];

        // se for método get e usar a api read certa OU se usar a api write certa
        if( (request.method === 'GET' && requestApiKey === getApiKey) || 
             requestApiKey === writeApiKey) {            
            return true
        }
        // usuário bloqueado!!!!
        throw new UnauthorizedException("Usuário não autorizado para chamar este endpoint!");
    }


}
