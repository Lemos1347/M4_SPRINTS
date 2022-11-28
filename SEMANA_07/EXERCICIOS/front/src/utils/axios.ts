import axios from "axios";
import { type } from "os";

const api = axios.create({
  baseURL: "http://192.168.183.56:3001",
  headers: { 
    "content-type": "text/plain",
  },
});

export default api;
