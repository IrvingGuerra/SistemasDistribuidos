
import static java.lang.Math.cos;
import static java.lang.Math.log;
import static java.lang.Math.sin;
import static java.lang.Math.sqrt;
import static java.lang.Math.tan;

public class Ejercicio2 {

    public static void main(String[] args) {
        
        double i = 0, Max = 9999999, seno = 0, coseno = 0, tangente = 0, logaritmo = 0, raizCuad = 0;
        
        while(i < Max){
            seno += sin(i);
            coseno += cos(i);
            tangente += tan(i);
            logaritmo += log(i);
            raizCuad += sqrt(i);
            i++;
        }
    }
    
}
