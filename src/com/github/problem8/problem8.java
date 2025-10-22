package com.github.problem8;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class problem8 {

    @SuppressWarnings("CallToPrintStackTrace")
    public static void main(String[] args) {
        File file = new File("./com/github/problem8/sequence.txt");

        String data;

        // try-with-resources: Scanner will be closed automatically
        try (Scanner reader = new Scanner(file)) {
            data = reader.nextLine();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
            return;
        }

        // Split on 0 because any segment with a 0 cannot be the largest
        String[] sequences = data.split("0");

        long maxProduct = 0;

        for (String sequence : sequences) {
            // Skip strings with length less than 13
            if (sequence.length() < 13) {
                continue;
            }

            long product = 1;
            int baseIndex = 0; // Tracks the index of the first digit being used
            int index = 0;
            for (char character : sequence.toCharArray()) {
                // Convert character to numerical value
                long digit = Character.getNumericValue(character);

                if (index < 13) {
                    product *= digit;

                    if (index != 12) {
                        index++;
                        // Do not check product against max product
                        continue;
                    }
                } else {
                    // Remove base from product
                    product /= Character.getNumericValue(sequence.charAt(baseIndex));

                    product *= digit;
                    baseIndex++;
                }

                if (maxProduct < product) {
                    maxProduct = product;
                }

                index++;
            }
        }

        System.out.println(maxProduct);
    }
}
