import { Module } from "@nestjs/common";
import { APP_GUARD } from "@nestjs/core";
import { ApiKeyGuard } from "./api-key.guard";

//integra o guard do nest com a nossa classe!
@Module({
    providers: [{
        provide: APP_GUARD,
        useClass: ApiKeyGuard,
    }]
})
export class AuthModule {}