import { Injectable, OnModuleInit } from '@nestjs/common';
import { PrismaClient } from "@prisma/client"
import { PrismaPg } from '@prisma/adapter-pg';

@Injectable()
export class AppService extends PrismaClient implements OnModuleInit {

  constructor(){
    const connectionString = process.env.DATABASE_URL;
    if(!connectionString){
      throw new Error("DATABASE_URL was not found!");
    }

    const adapter = new PrismaPg({connectionString});
    super({ adapter });
  }

  async onModuleInit() {
    await this.$connect();
  }
}
