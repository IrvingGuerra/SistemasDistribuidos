
package ipn;

import java.util.ArrayList;
import java.util.Random;

public class IPN {
    
    public static char letras[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    public static String getPalabra(){
	String palabra = "";
	for(int i = 0; i < 3; i++){
                Random rnd = new Random();
		int random =  (int)(rnd.nextDouble() * 26 + 0);
		palabra += String.valueOf(letras[random]);
	}
	return palabra;
    }

    public static void main(String[] args) {
        //int semilla = time(NULL);
	//srand(semilla);
        
        System.out.println("Entra");
	StringBuilder palabrota = new StringBuilder();
	for(int i = 0; i < 1757600; i++){
            palabrota.append(getPalabra()).append(" ");
	}
	//cout << palabrota << endl;
	//cout << "El indice donde se encuentra la cadena IPN es: " << palabrota.find("IPN") << endl;
	//cout << palabrota[palabrota.find("IPN")] << palabrota[palabrota.find("IPN")+1] << palabrota[palabrota.find("IPN")+2] << endl;
	//cout << "la semilla fue :" << semilla << endl;
        
        String palabrotaString = palabrota.toString();
       
        int intIndex = palabrotaString.indexOf("IPN"); 
        
        while(intIndex != -1){

            System.out.println(intIndex);

            System.out.print(palabrotaString.charAt(intIndex));
            System.out.print(palabrotaString.charAt(intIndex+1));
            System.out.println(palabrotaString.charAt(intIndex+2));
            
            intIndex = palabrotaString.indexOf("IPN", intIndex+1);
        }

     
        
        /*
	while(palabrota.find("IPN",PrimeraPosicion) < 175760*4){
		System.out.println("El indice donde se encuentra la cadena IPN es: "); 	
		//cout << palabrota[palabrota.find("IPN",PrimeraPosicion)] << palabrota[palabrota.find("IPN",PrimeraPosicion)+1] << palabrota[palabrota.find("IPN",PrimeraPosicion)+2] << endl;
		PrimeraPosicion = palabrota.find("IPN",PrimeraPosicion) + 3;
	}
        */

    }
    
}
