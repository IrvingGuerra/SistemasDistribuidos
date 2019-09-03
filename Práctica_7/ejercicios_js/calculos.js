const MAX = 10000000;
let i = 0;
let seno = 0, coseno = 0, tangente = 0, logaritmo = 0, raiz = 0;
while (i++ < MAX) {
    seno += Math.sin(i);
    coseno += Math.cos(i);
    tangente += Math.tan(i);
    logaritmo += Math.log(i);
    raiz += Math.sqrt(i);
}