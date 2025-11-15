package com.github.problem13;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class problem13 {
    @SuppressWarnings("CallToPrintStackTrace")
    public static void main(String[] args) {
        File file = new File("./com/github/problem13/numbers.txt");

        ArrayList<String> lines = new ArrayList<>();

        // try-with-resources: Scanner will be closed automatically
        try (Scanner reader = new Scanner(file)) {
            String line;
            while (reader.hasNext()) {
                line = reader.nextLine();

                lines.add(line);
            }
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
            return;
        }

        final int lineLength = lines.get(0).length();

        int carryOver = 0;
        String result = "";

        for (int strIndex = lineLength - 1; strIndex >= 0; strIndex--) {
            int columnSum = carryOver;
            for (String line : lines) {
                columnSum += line.charAt(strIndex) - '0';
            }

            // Split between digit and carry over
            final String digit = Integer.toString(columnSum % 10);
            carryOver = columnSum / 10;

            // Append to beginning of resulting string
            result = digit + result;
        }

        // Append left over carry over to beginning of the result
        result = Integer.toString(carryOver) + result;

        System.out.println(result.substring(0, 10));
    }
}