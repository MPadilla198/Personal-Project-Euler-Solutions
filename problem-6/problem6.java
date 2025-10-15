public class problem6 {
    public static void main(String[] args) {
        long sum_of_squares = 0;
        long square_of_sum = 0;

        for (long i = 1; i <= 100; i++) {
            sum_of_squares += i*i;
            square_of_sum += i;
        }

        square_of_sum *= square_of_sum;

        System.err.println(square_of_sum - sum_of_squares);
    }
}
