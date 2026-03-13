import { Injectable, OnModuleInit } from '@nestjs/common';
import { PrismaClient } from '@prisma/client/extension';

@Injectable()
export class AppService extends PrismaClient implements OnModuleInit {
  // quando meu back inicializar, vai se conectar com meu banco de dados pelo Prisma!
  async onModuleInit() {
    await this.$connect();
  }
}



