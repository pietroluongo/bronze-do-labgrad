import java.math.BigInteger;
import java.util.*;

public class fatorial {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        while(s.hasNext()) {
            int input = s.nextInt();
            if(!isValid(input)) {
                break;
            }
            BigInteger f = fatorial(BigInteger.valueOf(input));
            System.out.println(f);
        }
        return;
    }

    private static boolean isValid (int n) {
        return 0 <= n && 100 >= n;
    }

    private static BigInteger fatorial(BigInteger n) {
        if(n.compareTo(BigInteger.valueOf(1)) == 0) return BigInteger.valueOf(1);
        return n.multiply(fatorial(n.subtract(BigInteger.valueOf(1))));
    }

}