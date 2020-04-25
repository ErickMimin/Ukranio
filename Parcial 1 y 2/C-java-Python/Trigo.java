import java.math.*;

public class Trigo{
    public static void main(String[] args){
        double fA[] = {0f, 0f, 0f, 0f, 0f};
        double i = 1;
        while(i < 30000000){
            fA[0] += Math.sin(i);
            fA[1] += Math.cos(i);
            fA[2] += Math.tan(i);
            fA[3] += Math.log(i);
            fA[4] += Math.sqrt(i);
            i ++;
        }
        for(int x = 0;  x < 5; x++)
            System.out.println(fA[x] + "");
    }
}