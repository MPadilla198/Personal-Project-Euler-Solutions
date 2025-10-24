package com.github.problem11;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class problem11 {

    @SuppressWarnings("CallToPrintStackTrace")
    public static void main(String[] args) {
        File file = new File("./com/github/problem11/numbers.txt");

        ArrayList<ArrayList<Integer>> matrix = new ArrayList<>();

        // try-with-resources: Scanner will be closed automatically
        try (Scanner reader = new Scanner(file)) {
            String line;
            while (reader.hasNext()) {
                line = reader.nextLine();

                String[] splitLine = line.split(" ");
                ArrayList<Integer> numbers = new ArrayList<>();
                for (String number : splitLine) {
                    numbers.add(Integer.valueOf(number));
                }

                matrix.add(numbers);
            }
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
            return;
        }

        final int SIZE = 20;
        final int DISPLACE_SIZE = 3;
        final int TRAVERSE_SIZE = SIZE - DISPLACE_SIZE;

        int maxProduct = 0;

        for (int r = 0; r < SIZE; r++) {
            for (int c = 0; c < SIZE; c++) {
                if (c < TRAVERSE_SIZE) {
                    final int horizontalProduct = matrix.get(r).get(c) * matrix.get(r).get(c+1) * matrix.get(r).get(c+2) * matrix.get(r).get(c+3);
                    if (horizontalProduct > maxProduct) {
                        maxProduct = horizontalProduct;
                    }
                }

                if (r < TRAVERSE_SIZE) {
                    final int verticalProduct = matrix.get(r).get(c) * matrix.get(r+1).get(c) * matrix.get(r+2).get(c) * matrix.get(r+3).get(c);
                    if (verticalProduct > maxProduct) {
                        maxProduct = verticalProduct;
                    }
                }

                if (c < TRAVERSE_SIZE && r < TRAVERSE_SIZE) {
                    final int diagonalProduct = matrix.get(r).get(c) * matrix.get(r+1).get(c+1) * matrix.get(r+2).get(c+2) * matrix.get(r+3).get(c+3);
                    if (diagonalProduct > maxProduct) {
                        maxProduct = diagonalProduct;
                    }
                }

                if (c >= DISPLACE_SIZE && r < TRAVERSE_SIZE) {
                    final int diagonalProduct = matrix.get(r).get(c) * matrix.get(r+1).get(c-1) * matrix.get(r+2).get(c-2) * matrix.get(r+3).get(c-3);
                    if (diagonalProduct > maxProduct) {
                        maxProduct = diagonalProduct;
                    }
                }
            }
        }

        System.out.println(maxProduct);
    }
}
