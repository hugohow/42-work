import { ProcProperties } from "../types/ProcProperties";

export class Proc {
  key: string;
  json: any;

  constructor(key: string, json: any) {
    this.key = key;
    this.json = json;
  }

  print() {
    console.log(this);
  }
}