import java.util.Arrays;

public class problem3 {
    public static void main(String[] args) {
        long given_composite = 600851475143L;
        int composite_sqrt = (int) Math.sqrt(given_composite);

        System.out.println(composite_sqrt);

        // Create prime sieve
        boolean[] prime_sieve = new boolean[composite_sqrt];

        // Populate the prime sieve to assume all numbers are prime
        Arrays.fill(prime_sieve, Boolean.TRUE);

        // Set all composite numbered indexes in the sieve to false
        int i = 2;
        while (i < composite_sqrt) {
            for (int index = i * i; index > 0 && index < composite_sqrt; index += i) {
                prime_sieve[index] = false;
            }

            // Update i to the next prime exposed by the sieve
            i++;
            while (i < composite_sqrt && !prime_sieve[i]) {
                i++;
            }

            System.out.println(i);
        }

        // Iterate sieve in reverse and mod the given composite until it equals 0
        for (int j = composite_sqrt -1; j > 0; j--) {
            if (prime_sieve[j] && given_composite % j == 0) {
                System.out.println(j);
                break;
            }
        }
    }
}
